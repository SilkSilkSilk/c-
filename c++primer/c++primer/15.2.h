#ifndef _15CHAPTER2_H__
#define _15CHAPTER2_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"


using namespace std;

class Bulk_Quote;				//�����������
class Quote
{
public:							//�������ܷ��ʹ��г�Ա�������ܷ���˽�г�Ա
	Quote() = default;
	Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n * price; }
	virtual ~Quote() = default;
	static void test() {}		//��̬����

private:
	string bookNo;

protected:						//��������Ȩ����,�����û���ֹ����
	double price = 0.0;
};

class Bulk_Quote : public Quote
{
public:
	Bulk_Quote() = default;
	Bulk_Quote(const string&, double, size_t, double);
	double net_price(size_t n) const override;		//override��ʾ��д�����麯��  ��������಻���ǻ�������麯������ô�ǿ����������õ�

private:
	size_t min_qty = 0;		//���ٹ���min_qty��������ۿ�
	double discount = 0.0;	//�洢�ۿ�
};






#endif