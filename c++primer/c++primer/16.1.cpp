#include "16.1.h"



template <typename T>										//模板函数--在程序编译时生成参数类型
int compare(const T &v1, const T &v2)
{
	if (v1 > v2)
	{
		return 1;
	}
	else if (v1 < v2)
	{
		return -1;
	}
	return 0;
}

template <typename T, typename Q>							//参数列表可以有多个参数--参数列表不能为空
int compare(const T &v1, const Q &v2)
{
	return 0;
}

template <uint8_t N, uint8_t M>								//非类型声明
int compare(const char(&p1)[N], const char(&p2)[M])			//根据输入字符串的长度生成N和M，定义指向长度为NM的一维数组的指针
{
	return strcmp(p1, p2);
}

int main_16_1_1()
{
	cout << compare(1, 2) << endl;									//T是int
	cout << compare(string("abc"), string("123")) << endl;			//T是string

	compare("nzb", "1");											//只能输入常量

	Blob<int> names{ 0,1,2,3 };			//模板类只有在使用时才会实例化对应类型版本的，包括它的成员函数也是这样，现在实例化Blob(initializer_list<T> il);

	names.push_back(1);					//实例化push_back成员函数

	return 0;
}


template<class T = int > class Numbers
{
public:
	Numbers(T v = 0) : val(v) {}		//T v = 0 表示T类型是数值相关变量类型

private:
	T val;
};

typedef char CTR;				//在class CTR之前定义就和全局变量一样
template<class CTR> CTR f5(CTR a)
{
	return a;					//
}

void main_nu()
{
	Numbers<double> loets;				//有double类型的输入就不使用默认参数
	Numbers<> average;					//<>中不加任何参数表示使用模板类的默认参数类型

										//	Numbers<string> str;				//出错
	f5(10);
}



template class Blob<string>;









