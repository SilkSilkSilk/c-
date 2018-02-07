#include "6.3.h"

void err_msg( initializer_list < string > ls )
{
	for (auto i = ls.begin(); i < ls.end(); i++)
	{
		cout << *i << " ";
		cout << endl;
	}

	return a(); //return 返回一个void函数
}

/*int main()
{
	err_msg({ "fuck","okay" }); //initializer_list和vector一样是个模板容器，不同的是initializer_list可以放到函数实参中，使用{}能初始化initializer_list对象

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
	get_val(s, 0) = 'H';			//函数返回类型是引用，所以可以当作左值来使用
	cout << s << endl;

	return 0;
}*/

void showvector( vector < string > etc ) //递归显示vector内容  从前向后
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

vector < string > showvector1( vector < string > etc, int num ) //递归显示vector内容  另一种方式  从后往前
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


//typedef定以数组

typedef int arrt[10]; //arrt是int[10]的代表
using arrt = int[10];

arrt b[3]; //表示b[3][10]
arrt c; //表示c[10]
/*
int main()
{
	b[0][0] = 1;

	int(*a)[10];		//指向int[10]的指针
	a = b + 0;			//行地址 相等
	a = &b[0];			//行地址 相等

	cout << b[0][0] << endl;
	cout << a[0][0] << endl;
}*/


//都表示返回数组指针
arrt* func( int i )
{
	return nullptr;
}

int (* fund( int i ))[10]
{
	return nullptr;
}

auto funf( int i ) -> int(*)[10] //尾置返回类型
{
	return nullptr;
}

int unt[10];

decltype(unt)* fung( int i ) //函数返回数组指针
{
	return nullptr;
}
