#include "6.4.h"


//������������	-----------------------------------
void func( int i )
{
	cout << "num is:" << i << endl;
}

void func( string a )
{
	cout << "string is:" << a << endl;
}

/*int main()
{
	func(string("hello"));
	func(3);
	void func(int i);

	func(string("hello"));		//���������Ǵ��ڲ�������ʼѰ�ң�һ���ҵ�һ��ͬ�������ͻ�ֹͣѰ��  ������ʾ�޷���stringת����int����
	func(3);
}*/
//---------------------------------------------------------

//������Ĭ��ʵ�Σ�	-----------------------------------
void show_num( int i, int j, double k )
{
	cout << "num i:" << i << "	num j:" << j << "	num k:" << k << endl;
}

//void show_num(int i, int j = 10, double k = 3.14);		ע�������Ҫ��Ĭ�ϲ����ŵ��βεĺ��棬�����һ��������Ĭ��ֵ����ô�����ÿ��������Ҫ��Ĭ��ֵ

/*int main()
{
	show_num(10);
}*/
//---------------------------------------------------------


constexpr int funf() //constexpr�������ͺ���
{
	return 1;
}

constexpr int funh( int i ) //funh���ܵĲ���Ϊ�����Ƿ��صľ��Ǳ������ǳ����Ƿ��صľ��ǳ���
{
	return (funf() * i);
}

//ָ�뺯���÷�
/*
void funo(int i);
void(*func)(int i);

int main()
{
	func = funo;		//��ֵ����
	func = &funo;		//
	func(10);			//���÷���
	(*func)(10);		//
}

void funo(int i)
{
	cout << "hello nzb" << endl;
}*/


//������Ϊ����
/*void func(int i, void funp(string a))
{
	cout << "funcion is start:" << i << endl;
	funp(string("nizhibing"));
}

void func(int i, void(*funp)(string a))
{
	cout << "funcion is start:" << i << endl;
	funp(string("nizhibing"));
}

void funq(string a)
{
	cout << "hello " << a << endl;
}

int main()
{
	func(1, funq);
}*/


//������Ϊ��������
using F = int( int ); //��������
using PF = int(*)( int ); //ָ������

/*PF f1(int i)
{

}

F f2(int i)			//����
{

}

F *f3(int i)
{

}

int(*f4(int i))(int)	//ֱ�Ӷ���
{

}

auto f5(int i) -> int(*)(int)		//β�÷�������
{

}*/

/*
int main()
{

}
*/
