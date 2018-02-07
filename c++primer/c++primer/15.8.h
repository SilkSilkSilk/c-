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
		items.insert(shared_ptr<quote>(sale.clone()));					//sale.clone()返回的是new出来的空间首地址，不能直接放到集合里，需要转化成智能指针
	}

	void add_item(quote &&sale)
	{
		items.insert(shared_ptr<quote>(move(sale).clone()));			//右值引用调用右值版本的clone函数
	}

	double total_receipt(ostream &) const;

	double print_total(ostream&, quote &, int) const;

private:
	static bool compare(const shared_ptr<quote> &lhs, const shared_ptr<quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}

	multiset<shared_ptr<quote>, decltype(compare)*> items{ compare };		//第二个参数指定的是集合的比较规则，因为集合会自动排序
};


void main_15_8();
int main_15_8_1();

#endif
