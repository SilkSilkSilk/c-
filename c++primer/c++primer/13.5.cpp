#pragma warning(disable:4996)
#include "13.5.h"


StrVec::StrVec(initializer_list<string> a)
{
	auto newdata = alloc_n_copy(a.begin(), a.end());
	elements = newdata.first;				//��ָ��
	first_free = newdata.second;			//βָ��
	cap = first_free;
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;				//��ָ��
	first_free = newdata.second;			//βָ��
	cap = first_free;
}

StrVec::StrVec(StrVec && s) noexcept
	:elements(s.elements),first_free(s.first_free),cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;		//ȡ��ԭ�������Դ����Ȩ����s���ٵ�������ʱ�������Щָ���������ռ�Ķ�̬�ڴ�ͱ��ͷ���
}

StrVec & StrVec::operator=(const StrVec &s)
{
	auto data = alloc_n_copy(s.begin(), s.end());
	free();								//����freed�Ƿ�ֹ����ֵ����
	elements = data.first;				//��ָ��
	first_free = data.second;			//βָ��
	cap = first_free;


	return *this;
}

StrVec & StrVec::operator=(StrVec && s) noexcept
{
	if (this != &s)
	{
		free();					//��Ȼ���ƶ���ֵ���㣬��ô�ڶ�������ʱ�����������ˣ��������ͷ���
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;

		s.elements = s.first_free = s.cap = nullptr;		//ȡ��ԭ�������Դ����Ȩ����s���ٵ�������ʱ�������Щָ���������ռ�Ķ�̬�ڴ�ͱ��ͷ���
	}
	return *this;
}

StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc();								//ȷ���пռ�
	alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s)				//������push_back����ʵ�����������ò�ͬ�汾
{
	chk_n_alloc();								//ȷ���пռ�
	alloc.construct(first_free++, move(s));		//ʹ���ƶ�����
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
	auto data = alloc.allocate(e - b);						//����e-b��string��С���ڴ�
	return pair<string*, string*>(data, uninitialized_copy(b, e, data));	//ʹ��uninitialized_copy���ٹ���string���󣬷���βָ��
}

void StrVec::free()
{
	if (elements)
	{
		for (auto i = first_free; i != elements;)	//��������
		{
			alloc.destroy(--i);						//first_free��β��ָ�� Ҫ��--
		}
		alloc.deallocate(elements, cap - elements);	//�ͷſռ�
	}
}

void StrVec::reallocate()
{
	auto newcap = size() ? 2 * size() : 1;	
	auto newdata = alloc.allocate(newcap);		//�����µ��ڴ�ռ䣬ԭ�����ڴ�ռ仹�ڣ�û��freed

	/*�����ַ���������
	auto dest = newdata;
	auto elem = elements;

	for (size_t i = 0; i < size(); i++)
	{
		alloc.construct(dest++, move(*elem++));	//����move���صĽ������constructʹ��string���ƶ����캯������������ʹ�����ƶ����캯������Щstring������ڴ潫���ᱻ����
	}
	free();										//
	elements = newdata;
	first_free = dest;*/

	auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), newdata);	//uninitialized_copy�ǿ�����������ʹ���ƶ���������ͱ�����ƶ�����
	elements = newdata;
	first_free = last;

	cap = elements + newcap;
}

/*	��StrVec�л�ʹ��alloc������һ��string����ģ��ʵ��vector<string>�Ĳ���
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


/* �ƶ����캯�����ƶ���ֵ�����������ʹ�ã�
int main()
{
	StrVec sv{ string("nzb"),string("for"),string("while"),string("laow") };

	sv.push_back("dsb");
	sv.push_back("nb");

	sv.print(cout);
	StrVec sv1 = move(sv);			//ʹ��move(sv)ʹsv1�ƶ�����

	sv1.push_back("wo");
	sv1.push_back("de");
	sv1.print(cout);

	StrVec sv2;
	sv2 = move(sv1);				//ʹ��move(sv1)ʹsv2�ƶ���ֵ����

	sv2.push_back("lao");
	sv2.push_back("jia");

	sv2.print(cout);
}*/


/*��Ա�����Ŀ����汾���ƶ��汾
int main()
{
	StrVec sv{ string("nzb"),string("for"),string("while"),string("laow") };

	string a("dsb");
	sv.push_back(a);			//push_back(const string &s)  a�Ǳ���
	sv.push_back("nb");			//push_back(string &&s)		"nb"����ʱ����ֵ

	sv.print(cout);
}
*/




















