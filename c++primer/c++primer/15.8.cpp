#include "15.8.h"


void main_15_8()
{
	vector<quote> vector_quote;									//使用容器直接存放对象时派生类部分被截断了

	vector_quote.push_back(quote("0001-a", 10.5));
	cout << vector_quote[0].net_price(10) << endl;

	vector_quote.push_back(Disc_quote("0002-a", 16.8, 5, 0.8));	//派生类部分被截断了
	cout << vector_quote[1].net_price(10) << endl;				//quote版的虚函数

	vector<shared_ptr<quote>> shared_quote;						//使用容器间接存放对象指针时能正常调用派生类版本的虚函数

	shared_quote.push_back(make_shared<quote>(quote("0001-a", 10.5)));
	cout << shared_quote[0]->net_price(10) << endl;

	shared_quote.push_back(make_shared<Disc_quote>(Disc_quote("0002-a", 16.8, 5, 0.8)));
	cout << shared_quote[1]->net_price(10) << endl;				//Disc_quote版的虚函数
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

	for (auto iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter))		//upper_bound方法是跳过相同元素 相同的判断是multiset的比较指定函数
	{
		sum += print_total(os, **iter, items.count(*iter));										//count方法是获取相同元素的个数
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
	Basket a;												//集合中我们规定的比较规则是compare函数，即bookNo书名一样视为相同的书本，string大小比较
	a.add_item(quote("0001-a", 10.5));

	quote b("0001-b", 11.5);								//创建局部对象b
	a.add_item(b);											//以局部对象b初始化new一个新对象交给智能指针管理
	a.add_item(b);

	a.add_item(quote("0001-b", 11.5));						//和上面b对象的操作是一样的结果
	a.add_item(quote("0001-b", 11.5));						//以临时的quote对象初始化new一个新对象交给智能指针管理

	a.add_item(Disc_quote("0002-a", 16.8, 5, 0.8));

	a.total_receipt(cout);

	return 0;
}














