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

/*	//��ͬ���͵ĺ����ŵ�һ��ģ����һ�����
int main()
{
	map <string, int(*)(int, int)> bin;																				//����map��ֵ����һ������ָ��

	bin.insert({ "+",add });																						//string("+")�ؼ��ֶ�Ӧadd����ָ��
	bin.insert({ "%",mod });
	//	bin.insert({ "-",divde() });																					//����map��ֵ����һ������ָ�룬divde()�����ʱ���󲢲��Ǻ���ָ��

	cout << bin["+"](10, 20) << endl;
	cout << bin["%"](10, 20) << endl;

	function<int(int, int)> f1 = add;																				//function<int(int, int)>��ʾһ���������� f1����һ����������
	function<int(int, int)> f2 = mod;
	function<int(int, int)> f3 = divde();
	divde a;
	function<int(int, int)> f4 = a;																					//a������()����  ���Կ��԰�a����һ����������

	cout << f1(10, 20) << endl;																						//�൱��add(10,20);
	cout << f2(10, 20) << endl;
	cout << f3(10, 20) << endl;
	cout << f4(10, 20) << endl;

	map<string, function<int(int, int)>> binops = {																	//����map��ֵ����һ����������
		{ "+", add },
		{ "-", [](int i,int j) {return i - j; } },
		{ "*", [](int i,int j) {return i * j; } },
		{ "/", divde() },
		{ "%", mod }
	};
	for (auto &i : binops)																							//for�������� pair
	{
		cout << "10 " << i.first << " 5" << " = " << i.second(10, 5) << endl;
	}
	binops["+"](10, 5);																								//��������
}*/






























