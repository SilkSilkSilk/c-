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
	sales_data( const sales_data &a ); //�������캯��,����û����������������һ��Ĭ�Ͽ������캯��  ������û��д�κβ�����Ҳ���ǲ����´������
	~sales_data();
	sales_data& operator=( const sales_data &a ); //��ֵ����   û�и�ֵ���㺯�������������һ��Ĭ�ϸ�ֵ���㺯��
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
