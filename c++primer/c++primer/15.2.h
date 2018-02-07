#ifndef _15CHAPTER2_H__
#define _15CHAPTER2_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"


using namespace std;

class Bulk_Quote;				//派生类的声明
class Quote
{
public:							//派生类能访问公有成员，而不能访问私有成员
	Quote() = default;
	Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n * price; }
	virtual ~Quote() = default;
	static void test() {}		//静态函数

private:
	string bookNo;

protected:						//派生类有权访问,其他用户禁止访问
	double price = 0.0;
};

class Bulk_Quote : public Quote
{
public:
	Bulk_Quote() = default;
	Bulk_Quote(const string&, double, size_t, double);
	double net_price(size_t n) const override;		//override表示改写基类虚函数  如果派生类不覆盖基类里的虚函数，那么是可以正常调用的

private:
	size_t min_qty = 0;		//最少购买min_qty本书才有折扣
	double discount = 0.0;	//存储折扣
};






#endif