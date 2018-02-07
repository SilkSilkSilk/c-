#include "16.2.h"






template <class T1, class T2, class T3>	//ע��ģ���������
T1 alt_sum(const T2 &a, const T3 &b)						//����ֵ��ģ�����ͣ���Ҫ�Լ�ָ����û���ƶϳ���
{
	return a;
}

void main_alt_sum()
{
	auto a = alt_sum<int>(10, 20);				//alt_sum<int>ָ������������int
}


template<class T>
int fun(int (*p)(const T&,const T&))
{
	return p(10, 20);
}

template<class T> int comp(const T &v1, const T &v2)
{
	return v1*v2;
}

void main_pf1()
{
	int(*pf1)(const int&, const int&) = comp;			//pf1->comp<int>

	cout << pf1(10, 20) << endl;						//pf1(int,int) ->  comp(int,int);

	cout << fun(pf1) << endl;							//��������һ������
	fun(comp<int>);										//comp<int>��ʾһ��int (*comp)(const int &v1, const int &v2)
}

//ģ�庯���Ĳ�����Ϊ��ֵ���ã�
template<class T> int seu(T &&v1)
{
	T a = v1;
	a = 90;
	return v1;
}

void main_seu()
{
	cout << seu(10) << endl;			//���볣��T->int
	cout << seu(int(10)) << endl;		//������ʱ�ı���const int   T->int
	int a = 6;
	cout << seu(a) << endl;				//���������  T->int&
}

template<class T>
typename remove_reference<T>::type&& mve(T&& t)				//move��ʵ��
{
	return static_cast<typename remove_reference<T>::type&&>(t);
}

void main_mve()
{
	string s1("hello"), s2;
	s2 = mve(string("11"));
	cout << s2 << endl;

	s2 = mve(s1);				//ʵ�����ƶ���ֵ������string��=������������ֵ���ð汾
	cout << s2 << endl;
	cout << s1 << endl;
}

template<class T>
int filp1(T&& t)
{
	return 0;
}

void main_folp1()
{
	int b = 10;
	//	int &&a = b;	//���ܰѱ�����ֵ����ֵ����

	filp1(10);		//ģ�����͵�T&&������ֵʱΪint
	filp1(b);		//������ֵ����ʱΪint&
}

