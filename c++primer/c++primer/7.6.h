#ifndef _7CHAPTER6_H__
#define _7CHAPTER6_H__


#include <iostream>
#include <vector>
#include <cstring>
#include "string"
#include <stdint.h>

using namespace std;


class Account
{
public:
	typedef uint32_t pst;
	Account();

	void calculate() { amount += amount * interestRate; }; //��Ա�����������������������ʹ�þ�̬��Ա
	static double rate() { return interestRate; }

	static void rate( double newRate );

	void test( pst a = come )
	{
	} //come��̬��Ա���Ե���Ĭ�ϲΣ���Ϊ�������ڶ�������ֵ
	~Account();

	static pst come;
	static constexpr int period = 30; //��������ʹ�ó������ʽ����ʼ��constexpr���;�̬��Ա		���ֻ�ǰ�period����������ʹ������Ҫ�����ⲿ���壬���periodҪ�����û���ָ������Ҫ�����ⶨ��
	double daily_tbl[period];

private:
	string owner;
	double amount;
	static double interestRate; //��θ���ֵ?
	static double initRate(); //������thisָ�� ����������const��

	//	Account a;						//��ͨ��Ա�������Լ�������ͣ�����̬��Ա��ָ��
	static Account a;
	Account *ptr;
};


#endif
