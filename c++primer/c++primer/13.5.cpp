#pragma warning(disable:4996)
#include "13.5.h"


StrVec::StrVec(initializer_list<string> a)
{
	auto newdata = alloc_n_copy(a.begin(), a.end());
	elements = newdata.first;				//首指针
	first_free = newdata.second;			//尾指针
	cap = first_free;
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;				//首指针
	first_free = newdata.second;			//尾指针
	cap = first_free;
}

StrVec::StrVec(StrVec && s) noexcept
	:elements(s.elements),first_free(s.first_free),cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;		//取消原对象的资源控制权，当s销毁调用析构时，如果这些指针可用则抢占的动态内存就被释放了
}

StrVec & StrVec::operator=(const StrVec &s)
{
	auto data = alloc_n_copy(s.begin(), s.end());
	free();								//不先freed是防止自身赋值自身
	elements = data.first;				//首指针
	first_free = data.second;			//尾指针
	cap = first_free;


	return *this;
}

StrVec & StrVec::operator=(StrVec && s) noexcept
{
	if (this != &s)
	{
		free();					//既然是移动赋值运算，那么在定义我们时可能有数据了，所以先释放了
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;

		s.elements = s.first_free = s.cap = nullptr;		//取消原对象的资源控制权，当s销毁调用析构时，如果这些指针可用则抢占的动态内存就被释放了
	}
	return *this;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();								//确保有空间
	alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s)				//这两个push_back依据实参类型来调用不同版本
{
	chk_n_alloc();								//确保有空间
	alloc.construct(first_free++, move(s));		//使用移动操作
}

ostream & StrVec::print(ostream & os) const
{
	for (auto i = elements; i != first_free; i++)
	{
		os << *i << " ";
	}
	os << endl;
	return os;
}

void StrVec::chk_n_alloc()
{
	if (cap <= first_free || cap == nullptr )
	{
		reallocate();
	}
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
	auto data = alloc.allocate(e - b);						//分配e-b个string大小的内存
	return pair<string*, string*>(data, uninitialized_copy(b, e, data));	//使用uninitialized_copy快速构造string对象，返回尾指针
}

void StrVec::free()
{
	if (elements)
	{
		for (auto i = first_free; i != elements;)	//销毁数据
		{
			alloc.destroy(--i);						//first_free是尾后指针 要先--
		}
		alloc.deallocate(elements, cap - elements);	//释放空间
	}
}

void StrVec::reallocate()
{
	auto newcap = size() ? 2 * size() : 1;	
	auto newdata = alloc.allocate(newcap);		//分配新的内存空间，原来的内存空间还在，没有freed

	/*；两种方法都可以
	auto dest = newdata;
	auto elem = elements;

	for (size_t i = 0; i < size(); i++)
	{
		alloc.construct(dest++, move(*elem++));	//调用move返回的结果会令construct使用string的移动构造函数。由于我们使用了移动构造函数，这些string管理的内存将不会被拷贝
	}
	free();										//
	elements = newdata;
	first_free = dest;*/

	auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), newdata);	//uninitialized_copy是拷贝函数，但使用移动迭代器后就变成了移动操作
	elements = newdata;
	first_free = last;

	cap = elements + newcap;
}

/*	在StrVec中会使用alloc来分配一块string区域，模拟实现vector<string>的操作
int main()
{
	StrVec sv{ string("nzb"),string("for"),string("while"),string("laow") };
	StrVec sv1(sv);
	StrVec sv2;
	sv2 = sv;

	sv.push_back("dsb");
	sv.push_back("nb");

	sv1.push_back("wo");
	sv1.push_back("de");

	sv2.push_back("lao");
	sv2.push_back("jia");

	sv.print(cout);
	sv1.print(cout);
	sv2.print(cout);
}*/


/* 移动构造函数和移动赋值运算符函数的使用：
int main()
{
	StrVec sv{ string("nzb"),string("for"),string("while"),string("laow") };

	sv.push_back("dsb");
	sv.push_back("nb");

	sv.print(cout);
	StrVec sv1 = move(sv);			//使用move(sv)使sv1移动构造

	sv1.push_back("wo");
	sv1.push_back("de");
	sv1.print(cout);

	StrVec sv2;
	sv2 = move(sv1);				//使用move(sv1)使sv2移动赋值运算

	sv2.push_back("lao");
	sv2.push_back("jia");

	sv2.print(cout);
}*/


/*成员函数的拷贝版本和移动版本
int main()
{
	StrVec sv{ string("nzb"),string("for"),string("while"),string("laow") };

	string a("dsb");
	sv.push_back(a);			//push_back(const string &s)  a是变量
	sv.push_back("nb");			//push_back(string &&s)		"nb"是临时的右值

	sv.print(cout);
}
*/




















