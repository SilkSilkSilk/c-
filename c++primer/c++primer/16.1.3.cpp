#include "16.1.3.h"


double A;

template<typename A, typename B>			//和局部变量的规则类似，在我之前定义被我覆盖，在我之后定义覆盖我（产生错误）
void fun(A a, B b)
{
	A tem = a;
	//	double B;			//错误
}

/*template<class A,class A>					//一个模板参数列表中不能重复定义名称一样的模板参数
void fu()
{

}*/

void main_fun()
{
	fun(1, 2);
}

template<class T> typename T::value_type top(const T& c);

void main_typename()
{
	cout << top(vector<int>()) << endl;
}

template<class T>
typename T::value_type top(const T& c)			//函数的返回类型是T::value_type类型，typename指定类型
{
	if (!c.empty())
	{
		return c.back();
	}
	else
	{
		return typename T::value_type(100);		//T::value_type(100)是用value_type初始化新对象作为返回，typename指定类型
	}
}

void fu(int a, int b = 10)				//为什么默认值参数放到了函数的定义里？因为它既是定义也是声明
{

}


void main_fu()
{
	fun(1, 2);
}



template <class T, typename F = les<T>> int compare(const T &v1, const T &v2, F f = F());
//les类是自己定义的模板类，实现了比较两个输入参数的作用，它和std里的less标准模板类有相同的效果

void main_com()
{
	cout << compare(-2, 1) << endl;
}


template <class T, typename F>
int compare(const T &v1, const T &v2, F f)			//因为声明部分已经给了默认值了，这里不给默认值
{
	if (f(v1, v2))									//les<T> 重载了()符号比较输入参数的大小
	{
		return 1;
	}
	else if (f(v2, v1))
	{
		return -1;
	}
	else
	{
		return 0;
	}
}






















