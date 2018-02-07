#ifndef _15CHAPTER5_H__
#define _15CHAPTER5_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"


using namespace std;


class Base
{
public:
	void public_mem();

private:
	int privat_data;
protected:
	int protected_data;
};


class public_Base : public Base		//����Base�����ݵķ���˵�������̳�  Base�е�public�ŵ�public_Base�е�public	 protected�ŵ�protected��
{
public:
	int f()
	{
		public_mem();
		return protected_data;
	}
	using Base::protected_data;		//��ԭ��Ӧ����protected���protected_data�����ŵ�public��
	//Base���public��������
private:
	
protected:
	using Base::public_mem;			//��ԭ��Ӧ����public���public_mem�����ŵ�protected��
	//Base���protected��������
};

class private_Base : private Base	//��Base��public��protected���ݶ��ŵ��Լ���private��
{
public:
	int f()
	{
		public_mem();				//�൱��ʹ���Լ��е�private����
		return protected_data;
	}
	int num_test;
private:
	//Base�����������
protected:

};

class protected_Base : protected Base	//��Base��public��protected���ݶ��ŵ��Լ���protected��
{
public:
	int f()
	{
		public_mem();					//�൱��ʹ���Լ��е�protected����
		return protected_data;
	}

private:

protected:
	//Base�����������
};

class Bulk2_public : public public_Base		//����public��ʽ���̳�public_Base
{
public:
	int g()
	{
		public_mem();						//public_Base�ǰ���public�ķ�ʽ�̳�Base�ģ����������ܹ�ʹ�ü�ӻ����������
		return protected_data;
	}
private:

};

class Bulk2_private : public private_Base	//����public��ʽ���̳�private_Base
{
public:
	int g()
	{
//		public_mem();						//private_Base���Base��public��protected���ݶ��ŵ��Լ���private��಻�ܼ̳�private�������
//		return protected_data;				//���󣬲���ʹ�ü�ӻ������������
		return num_test;					//����������ֱ�ӻ���������ݵ�,��Ϊpublic�ķ�ʽ�̳�ֱ�ӻ���
	}
private:

};

class Bulk2_protected : public protected_Base //����public��ʽ���̳�protected_Base
{
public:
	int g()
	{
		public_mem();						//protected_Base���Base��public��protected���ݶ��ŵ��Լ���protected�protected�ǿ��Ա��̳е�
		return protected_data;				//���Կ���ʹ��
	}
private:

protected:
	//Base�����������
};


class B
{
public:
	int a;
	int memco(int n) { return n; }
	virtual int fun(int a) { return a; }
private:
	int pri_B;

protected:
	int pro_B;
};

class Blue : public B
{
public:
	int f()
	{
		a = 10;				//a�����˻����е�a
		return B::a;		//B::ָ�������е�a
	}
	int memco(int n) { return n; }	//���麯����ͬ��memcoֱ�Ӹ��ǵ���B��memco���������ֵĲ���

	int fun(int a) { return a + 1; }	//�麯��������Ĵ��ڣ����Թ�������

	int fun(double num, int b) { return (int)num; }

private:
	double a;
	int pri_num;
};

#endif