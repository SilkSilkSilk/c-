#include "16.2.h"






template <class T1, class T2, class T3>	//注意模板类参数的
T1 alt_sum(const T2 &a, const T3 &b)						//返回值是模板类型，需要自己指定，没法推断出来
{
	return a;
}

void main_alt_sum()
{
	auto a = alt_sum<int>(10, 20);				//alt_sum<int>指定返回类型是int
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

	cout << fun(pf1) << endl;							//和下面是一个作用
	fun(comp<int>);										//comp<int>表示一个int (*comp)(const int &v1, const int &v2)
}

//模板函数的参数设为右值引用：
template<class T> int seu(T &&v1)
{
	T a = v1;
	a = 90;
	return v1;
}

void main_seu()
{
	cout << seu(10) << endl;			//输入常量T->int
	cout << seu(int(10)) << endl;		//输入临时的变量const int   T->int
	int a = 6;
	cout << seu(a) << endl;				//输入变量后  T->int&
}

template<class T>
typename remove_reference<T>::type&& mve(T&& t)				//move的实现
{
	return static_cast<typename remove_reference<T>::type&&>(t);
}

void main_mve()
{
	string s1("hello"), s2;
	s2 = mve(string("11"));
	cout << s2 << endl;

	s2 = mve(s1);				//实现了移动赋值操作，string的=符号重载有右值引用版本
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
	//	int &&a = b;	//不能把变量赋值给右值引用

	filp1(10);		//模板类型的T&&接受右值时为int
	filp1(b);		//接受左值变量时为int&
}

