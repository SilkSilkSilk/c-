#include "7.6.h"


Account::pst Account::come = 11; //静态成员的赋值  和全局变量的定义初始化一样，只不过加上作用域运算符说明出自哪个类，静态变量的类型使用类中的pst需要使用作用域操作符制定出Account类
double Account::interestRate = initRate(); //这里initRate不需要使用作用域运算符说明出自哪个类是因为前面的interestRate已经指定了Account类了。
//和Account类中函数一样，rate函数在类外定义需要作用域运算符说明出自Account类，但是后面参数列表里面使用的类中类型和变量则不需要作用域运算符说明，但是函数的返回类型并不享有这种权利
constexpr int Account::period; //值在类中已经给定了，如果只是把period当作常量来使用则不需要在类外部定义，如果period要给引用或者指针这需要在类外定义

Account::Account() //静态成员不是在构造函数开始时创建的 是程序运时创建的，一直出现在程序的生命周期中，一个类只有一个同名的静态成员
{
	const int &num = period;
}

void Account::rate( double newRate ) //类外部定义静态成员函数不需要重复static的声明
{
	interestRate = newRate;
}

Account::~Account()
{
}

double Account::initRate()
{
	return 0.0;
}
