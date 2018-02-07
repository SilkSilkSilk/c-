#include "16.1.2.h"


template<typename T>
using win = Blob<T>;						//����ģ�嶨�����ͱ���win

void main_16_1_2()
{
	typedef Blob<string> StrBlob;			//StrBlob����Blob<string>����

	//	typedef Blob<T> StrBlob;				//���ܴ���һ������ȷ���͵�ģ��

	win<int> a;								//�൱��Blob<int> a
											//ע���ھֲ����ǲ��ܶ�����ģ���
}

class MyClass			//��ͨ���ж���������һ��static��Ա
{
public:
	static int count() { return a; }

private:
	static int a;
};

int MyClass::a = 100;			//��ʼ����̬����

template<typename T> class FOO
{									//ģ�����ж��ͬģ�����͵Ķ�����һ��static��Ա
public:
	static int count() { return a; }

private:
	static int a;
	T b;
};

//int FOO<T>::a = 10;				//static�����ʼ��ʹ�úͳ�Ա����һ���ķ�ʽָ��T����ʼ��
template<class T> int FOO<T>::a = 10;


void main_16_1_2(int num)
{
	MyClass a;
	a.count();						//�������
	MyClass::count();				//�����������

	FOO<int> b;
	b.count();						//�������
	FOO<int>::count();				//�����������
									//	FOO::count();					//����foo��ͬ��ģ�����Ͷ�����count��������������֪�������ĸ��汾
}























