#include "13.1.h"

sales_data::sales_data() : bookNO(""), units_sold(0), revenus(0.0)
{
}

sales_data::sales_data( string &s ) : bookNO(s), units_sold(0), revenus(0.0)
{
}

sales_data::sales_data( const sales_data &a )
{
	bookNO = a.bookNO + "hello nzb!"; //自己定义函数选择性拷贝
	units_sold = a.units_sold;
	revenus = a.revenus;
}

sales_data::~sales_data() //在对象被销毁时调用析构函数
{
	//在析构函数中。首先执行函数体，然后按照初始化的逆序来销毁成员
}

sales_data& sales_data::operator=( const sales_data &a )
{
	bookNO = a.bookNO;
	units_sold = a.units_sold;
	revenus = a.revenus;
	return *this;
}

void sales_data::print()
{
	cout << bookNO << " " << units_sold << " " << revenus << endl;
}


HasPtr& HasPtr::operator=( const HasPtr &p ) //一个好的赋值运算函数即使是a = a;也要正常工作
{
	this->i = p.i;
	this->ps = new string(*p.ps);

	this->ptr = p.ptr; //因为是智能指针，所以不需要每次都分配内存空间,即使p销毁了，ptr指向的动态内存也是在的

	return *this;
}

void HasPtr::swap(HasPtr & hs1, HasPtr & hs2)
{
	::swap(hs1.i, hs2.i);	//因为先在类中作用域寻找swap						
	::swap(hs1.ps, hs2.ps);
}
