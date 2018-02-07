#ifndef _7CHAPTER1_H__
#define _7CHAPTER1_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"


using namespace std;


struct Sales_data
{
	friend Sales_data add( const Sales_data &, const Sales_data & );
	friend ostream& print( ostream &, const Sales_data & );
	friend istream& read( istream &, Sales_data & );
	friend istream& operator >>( istream &is, Sales_data &s );
	friend ostream& operator<<( ostream &os, const Sales_data &s );

public:
	Sales_data() = default;
	Sales_data( const string &s );

	Sales_data( string s = "" ) : bookNO(s)
	{
	}; //默认实参构造函数
	Sales_data( const string &s, unsigned int n, double p );
	explicit Sales_data( istream &is ); //explicit取消掉隐式转换

	Sales_data( string &s ) : Sales_data("", 10, 3.14)
	{
	} //委托构造函数
	Sales_data( int a ); //委托构造函数  函数实现在类的外部作用域

	~Sales_data();
	string isbn() const;
	Sales_data& combine( const Sales_data &rhs );
	double avg_pice() const;
	Sales_data& operator=( const Sales_data &a );

private:
	string bookNO;
	unsigned int units_sold = 0;
	double revenus = 0.0; //使用struct声明时可以初始化
};

Sales_data add( const Sales_data &, const Sales_data & );
ostream& print( ostream &, const Sales_data & );
istream& read( istream &, Sales_data & );
istream& operator >>( istream &is, Sales_data &s );

#endif
