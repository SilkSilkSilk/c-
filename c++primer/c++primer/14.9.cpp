#include "14.9.h"


/*

class SmallInt
{
public:
SmallInt(int i = 0) :val(i) {}			//intת����SmallInt��  
~SmallInt();
operator int() const { return val; }	//SmallInt��תת��int  ��ʽת��

private:
int val;
};


int main()
{
	SmallInt s;
	s = 4;	//�Ƚ�3�����SmallInt��Ȼ��ֵ���㺯����ֵ��s
	int a = s + 3; //sת����int	����3Ҳ����ת����SmallInt������SmallIntû��+���ų��ں���������û�ж���������
}*/


/*	����������
 *
struct B;
struct  A
{
	A() = default;
	A(const B&);
};

struct B
{
	operator A() const;
};


void f(const A&);


int main()
{
	B b;
	A a = f(b);	//A�ඨ����B�Ĺ��캯����B���ֶ�����A������ת������
}*/


/*	����������
struct  A
{
	A(int = 0);
	A(double);

	operator int() const;
	operator double() const;
};

void f(long double);			//����long double��������ģ�Ҫô��int��Ҫô��double


int main()
{
	A a;
	f(a);			//a�ȿ���ת����intҲ����ת����double,�ٸ�long double

	long double lg = 0;
	A a1(lg);		//long double�ȿ���ת����int����a��Ҳ����ת����double����a
}*/


/*	����������
 *
struct  A
{
	A(int = 0);
};

struct  B
{
	B(int = 0);
};

void f(const A);
void f(const B);


int main()
{
	f(10);			//A��B���ܽ�int10ת�����Լ���
	f(A(10));		//��ʽ�Ĺ���
}*/






















