#include "15.4.h"


double Bulk_quote::net_price(size_t n) const
{

	return 0.0;
}

void Bulk_quote::test()
{
	price = 10;
	quantity = 10;
}

void get_test(Bulk_quote &s, Disc_quote &a)
{
	s.price;
	s.quantity;

//	a.quantity = 10;	//错误  Disc_quote类型的对象在这并不享受friend操作，它不能访问Disc_quote类里的私有数据和protected数据，只能访问public
}

/*
int main()
{
	quote *a = new Bulk_quote();

	delete a;		//基类虚析构函数会表示调用Bulk_quote析构函数
}*/

quote::quote()
{
	this->net_price(2);
}

quote::quote(const quote &a)
{
	bookNo = a.bookNo;
	price = a.price;
}

Disc_quote::Disc_quote(const Disc_quote & d) :quote(d)		//调用基类的拷贝构造函数初始化派生类中的基类部分
{
	quantity = d.quantity;
	discount = d.discount;
}

double Disc_quote::net_price(size_t n) const
{
	if(n >= quantity)
	{
		if (discount >= 0 && discount <= 1)
		{
			return n * price * discount;
		}
		else
		{
			return n * price;
		}
	}
	else
	{
		return n * price;
	}

	return 0.0;
}

Disc_quote::~Disc_quote()
{
}
