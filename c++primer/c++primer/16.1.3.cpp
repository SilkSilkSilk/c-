#include "16.1.3.h"


double A;

template<typename A, typename B>			//�;ֲ������Ĺ������ƣ�����֮ǰ���屻�Ҹ��ǣ�����֮���帲���ң���������
void fun(A a, B b)
{
	A tem = a;
	//	double B;			//����
}

/*template<class A,class A>					//һ��ģ������б��в����ظ���������һ����ģ�����
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
typename T::value_type top(const T& c)			//�����ķ���������T::value_type���ͣ�typenameָ������
{
	if (!c.empty())
	{
		return c.back();
	}
	else
	{
		return typename T::value_type(100);		//T::value_type(100)����value_type��ʼ���¶�����Ϊ���أ�typenameָ������
	}
}

void fu(int a, int b = 10)				//ΪʲôĬ��ֵ�����ŵ��˺����Ķ������Ϊ�����Ƕ���Ҳ������
{

}


void main_fu()
{
	fun(1, 2);
}



template <class T, typename F = les<T>> int compare(const T &v1, const T &v2, F f = F());
//les�����Լ������ģ���࣬ʵ���˱Ƚ�����������������ã�����std���less��׼ģ��������ͬ��Ч��

void main_com()
{
	cout << compare(-2, 1) << endl;
}


template <class T, typename F>
int compare(const T &v1, const T &v2, F f)			//��Ϊ���������Ѿ�����Ĭ��ֵ�ˣ����ﲻ��Ĭ��ֵ
{
	if (f(v1, v2))									//les<T> ������()���űȽ���������Ĵ�С
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






















