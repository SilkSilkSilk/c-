#include "14.8.h"



int add(int i, int j)
{
	return i + j;
}

auto mod = [](int i, int j)
{
	return i%j;
};

struct divde
{
	int operator()(int i, int j)
	{
		return i / j;
	}
};

/*	//不同类型的函数放到一个模板中一起调用
int main()
{
	map <string, int(*)(int, int)> bin;																				//这里map的值接受一个函数指针

	bin.insert({ "+",add });																						//string("+")关键字对应add函数指针
	bin.insert({ "%",mod });
	//	bin.insert({ "-",divde() });																					//这里map的值接受一个函数指针，divde()这个临时对象并不是函数指针

	cout << bin["+"](10, 20) << endl;
	cout << bin["%"](10, 20) << endl;

	function<int(int, int)> f1 = add;																				//function<int(int, int)>表示一个函数类型 f1接受一个函数对象
	function<int(int, int)> f2 = mod;
	function<int(int, int)> f3 = divde();
	divde a;
	function<int(int, int)> f4 = a;																					//a重载了()符号  所以可以把a当作一个函数对象

	cout << f1(10, 20) << endl;																						//相当于add(10,20);
	cout << f2(10, 20) << endl;
	cout << f3(10, 20) << endl;
	cout << f4(10, 20) << endl;

	map<string, function<int(int, int)>> binops = {																	//这里map的值接受一个函数对象
		{ "+", add },
		{ "-", [](int i,int j) {return i - j; } },
		{ "*", [](int i,int j) {return i * j; } },
		{ "/", divde() },
		{ "%", mod }
	};
	for (auto &i : binops)																							//for遍历调用 pair
	{
		cout << "10 " << i.first << " 5" << " = " << i.second(10, 5) << endl;
	}
	binops["+"](10, 5);																								//单个调用
}*/






























