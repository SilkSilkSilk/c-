#ifndef _15CHAPTER4_H__
#define _15CHAPTER4_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"


using namespace std;

class quote
{
public:							//派生类能访问公有成员，而不能访问私有成员
	quote();
	quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
	quote(const quote&);
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n * price; }
	virtual ~quote() = default;	//虚析构函数表示能在析构时区分派生类或基类的析构函数 定义了虚析构函数的类不会自动生成合成操作（拷贝构造赋值构造移动等）就是default不可用
	static void test() {}		//静态函数
	virtual quote * clone() const & { return new quote(*this); }		//拷贝构造函数
	virtual quote * clone() && {return new quote(move(*this)); }	//右值引用也调用拷贝构造quote(const quote&)，因为没有右值引用版本的

	string bookNo;

private:

protected:						//派生类有权访问,其他用户禁止访问
	double price = 0.0;
};

class Disc_quote : public quote
{
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double price, size_t qty, double disc) : quote(book, price), quantity(qty), discount(disc) {}
	Disc_quote(const Disc_quote& d);
//	double net_price(size_t n) const = 0;		//纯虚函数 强制要求派生类覆盖基类虚函数，如果Bulk_quote不定义net_price虚函数，则Disc_quote对象不能定义
	double net_price(size_t n) const;
	~Disc_quote();

	Disc_quote* clone() const & { return new Disc_quote(*this); }
	Disc_quote* clone() && {return new Disc_quote(move(*this)); }

protected:
	size_t quantity = 0;
	double discount = 1;
};

class Bulk_quote : public Disc_quote
{
	friend void get_test(Bulk_quote &s, Disc_quote &a);
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double price, size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}
	double net_price(size_t n) const override;
	void test();
	~Bulk_quote();
private:

};

void get_test(Bulk_quote &s,Disc_quote &a);




#endif