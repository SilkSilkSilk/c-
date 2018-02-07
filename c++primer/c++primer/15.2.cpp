#include "15.2.h"



Bulk_Quote::Bulk_Quote(const string& book, double p, size_t qty, double disc) :Quote(book, p), min_qty(qty), discount(disc)
{
//	price = 10.01;		//继承于基类的protected数据，它还是protected的，对其它用户来说是private的
	test();
}

double Bulk_Quote::net_price(size_t n) const
{
	if (n >= min_qty)
	{
		return discount * price *n;
	}
	cout << "hello nzb" << endl;
	return n * price;
}

















