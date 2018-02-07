#include "15.8.h"


void main_15_8()
{
	vector<quote> vector_quote;									//ʹ������ֱ�Ӵ�Ŷ���ʱ�����ಿ�ֱ��ض���

	vector_quote.push_back(quote("0001-a", 10.5));
	cout << vector_quote[0].net_price(10) << endl;

	vector_quote.push_back(Disc_quote("0002-a", 16.8, 5, 0.8));	//�����ಿ�ֱ��ض���
	cout << vector_quote[1].net_price(10) << endl;				//quote����麯��

	vector<shared_ptr<quote>> shared_quote;						//ʹ��������Ӵ�Ŷ���ָ��ʱ����������������汾���麯��

	shared_quote.push_back(make_shared<quote>(quote("0001-a", 10.5)));
	cout << shared_quote[0]->net_price(10) << endl;

	shared_quote.push_back(make_shared<Disc_quote>(Disc_quote("0002-a", 16.8, 5, 0.8)));
	cout << shared_quote[1]->net_price(10) << endl;				//Disc_quote����麯��
}



Basket::Basket()
{
}

Basket::~Basket()
{
}

double Basket::total_receipt(ostream &os) const
{
	double sum = 0.0;

	for (auto iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter))		//upper_bound������������ͬԪ�� ��ͬ���ж���multiset�ıȽ�ָ������
	{
		sum += print_total(os, **iter, items.count(*iter));										//count�����ǻ�ȡ��ͬԪ�صĸ���
	}
	os << "Total sale: " << sum << endl;
	return sum;
}

double Basket::print_total(ostream &os, quote &a, int num) const
{
	double slet = 0.0;

	for (auto i = 0; i < num; i++)
	{
		os << "The book " << a.bookNo << " price is: " << a.net_price(10) << endl;
		slet += a.net_price(10);
	}

	return slet;
}

int main_15_8_1()
{
	Basket a;												//���������ǹ涨�ıȽϹ�����compare��������bookNo����һ����Ϊ��ͬ���鱾��string��С�Ƚ�
	a.add_item(quote("0001-a", 10.5));

	quote b("0001-b", 11.5);								//�����ֲ�����b
	a.add_item(b);											//�Ծֲ�����b��ʼ��newһ���¶��󽻸�����ָ�����
	a.add_item(b);

	a.add_item(quote("0001-b", 11.5));						//������b����Ĳ�����һ���Ľ��
	a.add_item(quote("0001-b", 11.5));						//����ʱ��quote�����ʼ��newһ���¶��󽻸�����ָ�����

	a.add_item(Disc_quote("0002-a", 16.8, 5, 0.8));

	a.total_receipt(cout);

	return 0;
}














