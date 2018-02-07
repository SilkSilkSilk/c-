#include "16.1.2.h"


template<typename T>
using win = Blob<T>;						//给类模板定义类型别名win

void main_16_1_2()
{
	typedef Blob<string> StrBlob;			//StrBlob代表Blob<string>类型

	//	typedef Blob<T> StrBlob;				//不能代表一个不明确类型的模板

	win<int> a;								//相当于Blob<int> a
											//注意在局部内是不能定义类模板的
}

class MyClass			//普通类中多个类对象共享一个static成员
{
public:
	static int count() { return a; }

private:
	static int a;
};

int MyClass::a = 100;			//初始化静态变量

template<typename T> class FOO
{									//模板类中多个同模板类型的对象共享一个static成员
public:
	static int count() { return a; }

private:
	static int a;
	T b;
};

//int FOO<T>::a = 10;				//static对象初始化使用和成员函数一样的方式指出T来初始化
template<class T> int FOO<T>::a = 10;


void main_16_1_2(int num)
{
	MyClass a;
	a.count();						//对象调用
	MyClass::count();				//域操作符调用

	FOO<int> b;
	b.count();						//对象调用
	FOO<int>::count();				//域操作符调用
									//	FOO::count();					//错误，foo不同的模板类型都会有count函数，编译器不知道调用哪个版本
}























