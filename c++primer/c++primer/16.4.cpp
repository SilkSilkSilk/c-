#include "16.4.h"



template<class T, class ...Args>		//...表示一个模板参数包，可以智能生成多个参数
void foo(const T&, const Args& ... rest)		//...rest是一个函数参数包，可以智能生成多个参数
{
	cout << sizeof...(Args) << endl;		//打印模板参数包类型个数
	cout << sizeof...(rest) << endl;		//打印函数参数包类型个数
}

void main_foo()
{
	foo(1, 2, 3, 4);		//包里有3个参数
	foo(1, 2);				//包里有2个参数
	foo(1);					//空包
}


//使用递归的方法将参数包的内容取出来：


void main_prin()
{
	prin(cout, 10, string("nzb"), 1, 10, "hello", 666);
}

//template<class T> string debug_rep(const T& st);
//template<class T, class ...Args> ostream& prin(ostream& os, const T& t, const Args&... rest);
//template<class T> ostream &prin(ostream &os, const T& t);

void main_error_msg()
{
	errorMsg(cout, 10, string("nzb"), 1, 10, "hello", 666);
}










