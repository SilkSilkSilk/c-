#include "14.9.h"


/*

class SmallInt
{
public:
SmallInt(int i = 0) :val(i) {}			//int转换成SmallInt类  
~SmallInt();
operator int() const { return val; }	//SmallInt类转转成int  隐式转换

private:
int val;
};


int main()
{
	SmallInt s;
	s = 4;	//先将3构造成SmallInt，然后赋值运算函数赋值给s
	int a = s + 3; //s转换成int	这里3也可以转换成SmallInt，但是SmallInt没有+符号冲在函数，所以没有二义性问题
}*/


/*	二义性问题
 *
struct B;
struct  A
{
	A() = default;
	A(const B&);
};

struct B
{
	operator A() const;
};


void f(const A&);


int main()
{
	B b;
	A a = f(b);	//A类定义了B的构造函数，B类又定义了A的类型转换函数
}*/


/*	二义性问题
struct  A
{
	A(int = 0);
	A(double);

	operator int() const;
	operator double() const;
};

void f(long double);			//这里long double是有歧义的，要么就int，要么就double


int main()
{
	A a;
	f(a);			//a既可以转换成int也可以转换成double,再给long double

	long double lg = 0;
	A a1(lg);		//long double既可以转换成int构造a，也可以转换成double构造a
}*/


/*	二义性问题
 *
struct  A
{
	A(int = 0);
};

struct  B
{
	B(int = 0);
};

void f(const A);
void f(const B);


int main()
{
	f(10);			//A和B都能将int10转换成自己类
	f(A(10));		//显式的构造
}*/






















