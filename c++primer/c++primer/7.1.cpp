#include "7.1.h"


Sales_data::Sales_data( const string &s ) :
	bookNO(s)
{
}

Sales_data::Sales_data( const string &s, unsigned int n, double p ) :
	bookNO(s),
	units_sold(n),
	revenus(p * n)
{
}

Sales_data::Sales_data( istream &is )
{
	double price;
	cin >> this->bookNO >> this->units_sold >> price;
	this->revenus = units_sold * price;
}


Sales_data::Sales_data( int a ) : Sales_data("", a, a) //ί�й��캯��
{
}

Sales_data::~Sales_data()
{
}

string Sales_data::isbn() const //�����const��ʾ������thisָ��Ϊ����ָ�룬���Բ��ܸı����еı���ֵ  �������е�bookNO�������еı���
{
	return this->bookNO;
}

Sales_data& Sales_data::combine( const Sales_data &rhs )
{
	units_sold += rhs.units_sold;
	revenus += rhs.revenus;
	return *this;
}

double Sales_data::avg_pice() const
{
	return revenus / units_sold;
}

Sales_data& Sales_data::operator=( const Sales_data &a )
{
	bookNO = a.bookNO;
	units_sold = a.units_sold;
	revenus = a.revenus;
	return *this;
}

istream& operator >>( istream &is, Sales_data &s )
{
	double price;
	is >> s.bookNO >> s.units_sold >> price;
	if (is)									//����������Ƿ���ȷ
	{
		s.revenus = s.units_sold * price;
	}
	else
	{
		s = Sales_data("defuat", 10, 2.56);
	}
	
	return is;
}

ostream& operator<<( ostream &os, const Sales_data &s )
{
	os << "name is:" << s.bookNO << "  num:" << s.units_sold << "  vlue:" << s.revenus;
	return os;
}

Sales_data add( const Sales_data &a, const Sales_data &b )
{
	return a;
}

ostream& print( ostream &os, const Sales_data &a )
{
	os << "name is:" << a.bookNO << "  num:" << a.units_sold << "  vlue:" << a.revenus;
	return os;
}

istream& read( istream &is, Sales_data &a )
{
	double price;
	is >> a.bookNO >> a.units_sold >> price;
	if (is)									//����������Ƿ���ȷ
	{
		a.revenus = a.units_sold * price;
	}
	else
	{
		a = Sales_data("defuat", 10, 2.56);
	}
	return is;
}
