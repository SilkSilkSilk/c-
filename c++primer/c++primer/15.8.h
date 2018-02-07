#ifndef _15CHAPTER8_H__
#define _15CHAPTER8_H__


#include "15.4.h"
#include <memory>
#include <set>


class Basket
{
public:
	Basket();
	~Basket();

	void add_item(shared_ptr<quote> &sale)
	{
		items.insert(sale);
	}

	void add_item(const quote &sale)
	{
		items.insert(shared_ptr<quote>(sale.clone()));					//sale.clone()���ص���new�����Ŀռ��׵�ַ������ֱ�ӷŵ��������Ҫת��������ָ��
	}

	void add_item(quote &&sale)
	{
		items.insert(shared_ptr<quote>(move(sale).clone()));			//��ֵ���õ�����ֵ�汾��clone����
	}

	double total_receipt(ostream &) const;

	double print_total(ostream&, quote &, int) const;

private:
	static bool compare(const shared_ptr<quote> &lhs, const shared_ptr<quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}

	multiset<shared_ptr<quote>, decltype(compare)*> items{ compare };		//�ڶ�������ָ�����Ǽ��ϵıȽϹ�����Ϊ���ϻ��Զ�����
};


void main_15_8();
int main_15_8_1();

#endif
