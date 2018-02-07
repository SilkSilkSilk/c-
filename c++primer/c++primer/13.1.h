#ifndef _13CHAPTER1_H__
#define _13CHAPTER1_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"
#include <memory>


using namespace std;


class sales_data
{
public:
	sales_data();
	sales_data( string &s );
	sales_data( const sales_data &a ); //拷贝构造函数,如果用户不定义编译器生成一个默认拷贝构造函数  但我们没有写任何操作，也就是并不会拷贝数据
	~sales_data();
	sales_data& operator=( const sales_data &a ); //赋值运算   没有赋值运算函数则编译器生成一个默认赋值运算函数
	void print();

private:
	string bookNO;
	unsigned int units_sold;
	double revenus;
};

class HasPtr
{
public:
	HasPtr( const string &s = string() ) : ps(new string(s)), i(0), ptr(new string(s))
	{
	}

	HasPtr( const HasPtr &p ): ps(new string(*p.ps)),i(p.i), ptr(new string(*p.ps))
	{
	}

	~HasPtr() { delete ps; }

	HasPtr& operator=( const HasPtr & );

	void swap(HasPtr &hs1, HasPtr &hs2);
private:
	string *ps;
	shared_ptr < string > ptr;
	int i;
};


#endif
