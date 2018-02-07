#include "6.4.h"


//函数的作用域：	-----------------------------------
void func( int i )
{
	cout << "num is:" << i << endl;
}

void func( string a )
{
	cout << "string is:" << a << endl;
}

/*int main()
{
	func(string("hello"));
	func(3);
	void func(int i);

	func(string("hello"));		//函数重载是从内层作用域开始寻找，一旦找到一个同名函数就会停止寻找  报错显示无法将string转换成int类型
	func(3);
}*/
//---------------------------------------------------------

//函数的默认实参：	-----------------------------------
void show_num( int i, int j, double k )
{
	cout << "num i:" << i << "	num j:" << j << "	num k:" << k << endl;
}

//void show_num(int i, int j = 10, double k = 3.14);		注意的是需要把默认参数放到形参的后面，如果第一个参数有默认值，那么后面的每个参数都要有默认值

/*int main()
{
	show_num(10);
}*/
//---------------------------------------------------------


constexpr int funf() //constexpr返回类型函数
{
	return 1;
}

constexpr int funh( int i ) //funh接受的参数为变量那返回的就是变量，是常量那返回的就是常量
{
	return (funf() * i);
}

//指针函数用法
/*
void funo(int i);
void(*func)(int i);

int main()
{
	func = funo;		//赋值方法
	func = &funo;		//
	func(10);			//调用方法
	(*func)(10);		//
}

void funo(int i)
{
	cout << "hello nzb" << endl;
}*/


//函数作为参数
/*void func(int i, void funp(string a))
{
	cout << "funcion is start:" << i << endl;
	funp(string("nizhibing"));
}

void func(int i, void(*funp)(string a))
{
	cout << "funcion is start:" << i << endl;
	funp(string("nizhibing"));
}

void funq(string a)
{
	cout << "hello " << a << endl;
}

int main()
{
	func(1, funq);
}*/


//函数作为返回类型
using F = int( int ); //函数类型
using PF = int(*)( int ); //指针类型

/*PF f1(int i)
{

}

F f2(int i)			//错误
{

}

F *f3(int i)
{

}

int(*f4(int i))(int)	//直接定义
{

}

auto f5(int i) -> int(*)(int)		//尾置返回类型
{

}*/

/*
int main()
{

}
*/
