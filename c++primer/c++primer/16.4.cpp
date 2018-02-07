#include "16.4.h"



template<class T, class ...Args>		//...��ʾһ��ģ��������������������ɶ������
void foo(const T&, const Args& ... rest)		//...rest��һ�������������������������ɶ������
{
	cout << sizeof...(Args) << endl;		//��ӡģ����������͸���
	cout << sizeof...(rest) << endl;		//��ӡ�������������͸���
}

void main_foo()
{
	foo(1, 2, 3, 4);		//������3������
	foo(1, 2);				//������2������
	foo(1);					//�հ�
}


//ʹ�õݹ�ķ�����������������ȡ������


void main_prin()
{
	prin(cout, 10, string("nzb"), 1, 10, "hello", 666);
}

//template<class T> string debug_rep(const T& st);
//template<class T, class ...Args> ostream& prin(ostream& os, const T& t, const Args&... rest);
//template<class T> ostream &prin(ostream &os, const T& t);

void main_error_msg()
{
	errorMsg(cout, 10, string("nzb"), 1, 10, "hello", 666);
}










