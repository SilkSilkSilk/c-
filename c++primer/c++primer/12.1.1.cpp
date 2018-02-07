#include "12.1.1.h"


StrBlob::StrBlob() : data(make_shared < vector < string > >())
{
}

StrBlob::StrBlob( initializer_list < string > il ) : data(make_shared < vector < string > >(il))
{
}

StrBlob::~StrBlob()
{
}

void StrBlob::pop_back()
{
	check(0, "pop_back");
	return data->pop_back();
}

string& StrBlob::front()
{
	check(0, "front");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "back");
	return data->back();
}

void StrBlob::print()
{
	for (auto i : *data)
	{
		cout << i << " ";
	}
	cout << endl;
}

void StrBlob::check( size_type i, const string &msg ) const
{
	if (i >= data->size())
	{
		throw out_of_range(msg);
	}
}


/*StrBlob类来展现智能指针的优势：类中有动态内存，a = b；然后b销毁了，a中的动态内存指针不能使用了，因为a中的动态内存指针是被b中动态内存指针初始化的，b销毁时释放了所有内存
							 这里使用智能指针来代替动态内存指针，a = b；b内部计数器为2，然后b销毁了，b内部计数器为1>0所有b销毁时没有释放b指向的内存空间
int main()
{
	StrBlob str;
	{
		StrBlob str1{ "nzb", "for" };
		str = str1;							//str1中的智能指针计数器+1 str销毁原来指向的对象（原来并没有指向）
		str1.push_back("nizhibing");
	}
	//str1作用域之外智能指针计数器-1，但不为0，所以vector<string>内存还存在
	//str1作用域之外内存被释放，但是它的vector<string>内存还存在，因为str = str1;  相当于str中的智能指针初始化为str1中的智能指针，str中的智能指针还是指向str1中的vector<string>的

	str.print();
}*/
