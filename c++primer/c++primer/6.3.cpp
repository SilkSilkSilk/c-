#include "6.3.h"

void err_msg( initializer_list < string > ls )
{
	for (auto i = ls.begin(); i < ls.end(); i++)
	{
		cout << *i << " ";
		cout << endl;
	}

	return a(); //return ����һ��void����
}

/*int main()
{
	err_msg({ "fuck","okay" }); //initializer_list��vectorһ���Ǹ�ģ����������ͬ����initializer_list���Էŵ�����ʵ���У�ʹ��{}�ܳ�ʼ��initializer_list����

	return 0;
}*/

void a()
{
}


char& get_val( string &str, int ix )
{
	return str[ix];
}

/*int main()
{
	string s("hello nzb");
	cout << s << endl;
	get_val(s, 0) = 'H';			//�����������������ã����Կ��Ե�����ֵ��ʹ��
	cout << s << endl;

	return 0;
}*/

void showvector( vector < string > etc ) //�ݹ���ʾvector����  ��ǰ���
{
	if (etc.size() > 1)
	{
		cout << *etc.begin() << endl;
		etc.erase(etc.begin());
		showvector(etc);
	}
	else
	{
		cout << *etc.begin() << endl;
	}
	return;
}

/*int main()
{
	vector<string> a = { "a", "b", "c", "d", "e", "f", "g" };

	showvector(a);
}*/

vector < string > showvector1( vector < string > etc, int num ) //�ݹ���ʾvector����  ��һ�ַ�ʽ  �Ӻ���ǰ
{
	vector < string > etc1;

	if (num > 1)
	{
		etc1 = showvector1(etc, num - 1);
		cout << *(etc1.end() - 1) << endl;
		etc1.erase(etc1.end() - 1);
	}
	else
	{
		cout << *(etc.end() - 1) << endl;
		etc.erase(etc.end() - 1);
		return etc;
	}
	return etc1;
}

/*int main()
{
	vector<string> a = { "a", "b", "c", "d", "e", "f", "g" };

	showvector1(a, a.size());
}*/


//typedef��������

typedef int arrt[10]; //arrt��int[10]�Ĵ���
using arrt = int[10];

arrt b[3]; //��ʾb[3][10]
arrt c; //��ʾc[10]
/*
int main()
{
	b[0][0] = 1;

	int(*a)[10];		//ָ��int[10]��ָ��
	a = b + 0;			//�е�ַ ���
	a = &b[0];			//�е�ַ ���

	cout << b[0][0] << endl;
	cout << a[0][0] << endl;
}*/


//����ʾ��������ָ��
arrt* func( int i )
{
	return nullptr;
}

int (* fund( int i ))[10]
{
	return nullptr;
}

auto funf( int i ) -> int(*)[10] //β�÷�������
{
	return nullptr;
}

int unt[10];

decltype(unt)* fung( int i ) //������������ָ��
{
	return nullptr;
}
