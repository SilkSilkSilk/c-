#ifndef _15CHAPTER4_H__
#define _15CHAPTER4_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"


using namespace std;

class quote
{
public:							//�������ܷ��ʹ��г�Ա�������ܷ���˽�г�Ա
	quote();
	quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
	quote(const quote&);
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n * price; }
	virtual ~quote() = default;	//������������ʾ��������ʱ����������������������� �������������������಻���Զ����ɺϳɲ������������츳ֵ�����ƶ��ȣ�����default������
	static void test() {}		//��̬����
	virtual quote * clone() const & { return new quote(*this); }		//�������캯��
	virtual quote * clone() && {return new quote(move(*this)); }	//��ֵ����Ҳ���ÿ�������quote(const quote&)����Ϊû����ֵ���ð汾��

	string bookNo;

private:

protected:						//��������Ȩ����,�����û���ֹ����
	double price = 0.0;
};

class Disc_quote : public quote
{
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double price, size_t qty, double disc) : quote(book, price), quantity(qty), discount(disc) {}
	Disc_quote(const Disc_quote& d);
//	double net_price(size_t n) const = 0;		//���麯�� ǿ��Ҫ�������า�ǻ����麯�������Bulk_quote������net_price�麯������Disc_quote�����ܶ���
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