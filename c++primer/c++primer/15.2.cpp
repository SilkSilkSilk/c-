#include "15.2.h"



Bulk_Quote::Bulk_Quote(const string& book, double p, size_t qty, double disc) :Quote(book, p), min_qty(qty), discount(disc)
{
//	price = 10.01;		//�̳��ڻ����protected���ݣ�������protected�ģ��������û���˵��private��
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

















