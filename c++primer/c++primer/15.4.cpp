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

//	a.quantity = 10;	//����  Disc_quote���͵Ķ������Ⲣ������friend�����������ܷ���Disc_quote�����˽�����ݺ�protected���ݣ�ֻ�ܷ���public
}

/*
int main()
{
	quote *a = new Bulk_quote();

	delete a;		//�����������������ʾ����Bulk_quote��������
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

Disc_quote::Disc_quote(const Disc_quote & d) :quote(d)		//���û���Ŀ������캯����ʼ���������еĻ��ಿ��
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
