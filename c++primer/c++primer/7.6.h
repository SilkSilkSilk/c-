#ifndef _7CHAPTER6_H__
#define _7CHAPTER6_H__


#include <iostream>
#include <vector>
#include <cstring>
#include "string"
#include <stdint.h>

using namespace std;


class Account
{
public:
	typedef uint32_t pst;
	Account();

	void calculate() { amount += amount * interestRate; }; //成员函数不用作用域运算符就能使用静态成员
	static double rate() { return interestRate; }

	static void rate( double newRate );

	void test( pst a = come )
	{
	} //come静态成员可以当作默认参，因为它不属于对象早有值
	~Account();

	static pst come;
	static constexpr int period = 30; //可以类内使用常量表达式来初始化constexpr类型静态成员		如果只是把period当作常量来使用则不需要在类外部定义，如果period要给引用或者指针这需要在类外定义
	double daily_tbl[period];

private:
	string owner;
	double amount;
	static double interestRate; //如何赋初值?
	static double initRate(); //不包含this指针 不能声明成const型

	//	Account a;						//普通成员不能是自己类的类型，除静态成员和指针
	static Account a;
	Account *ptr;
};


#endif
