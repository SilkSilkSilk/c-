#include "16.1.h"



template <typename T>										//ģ�庯��--�ڳ������ʱ���ɲ�������
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

template <typename T, typename Q>							//�����б�����ж������--�����б���Ϊ��
int compare(const T &v1, const Q &v2)
{
	return 0;
}

template <uint8_t N, uint8_t M>								//����������
int compare(const char(&p1)[N], const char(&p2)[M])			//���������ַ����ĳ�������N��M������ָ�򳤶�ΪNM��һά�����ָ��
{
	return strcmp(p1, p2);
}

int main_16_1_1()
{
	cout << compare(1, 2) << endl;									//T��int
	cout << compare(string("abc"), string("123")) << endl;			//T��string

	compare("nzb", "1");											//ֻ�����볣��

	Blob<int> names{ 0,1,2,3 };			//ģ����ֻ����ʹ��ʱ�Ż�ʵ������Ӧ���Ͱ汾�ģ��������ĳ�Ա����Ҳ������������ʵ����Blob(initializer_list<T> il);

	names.push_back(1);					//ʵ����push_back��Ա����

	return 0;
}


template<class T = int > class Numbers
{
public:
	Numbers(T v = 0) : val(v) {}		//T v = 0 ��ʾT��������ֵ��ر�������

private:
	T val;
};

typedef char CTR;				//��class CTR֮ǰ����ͺ�ȫ�ֱ���һ��
template<class CTR> CTR f5(CTR a)
{
	return a;					//
}

void main_nu()
{
	Numbers<double> loets;				//��double���͵�����Ͳ�ʹ��Ĭ�ϲ���
	Numbers<> average;					//<>�в����κβ�����ʾʹ��ģ�����Ĭ�ϲ�������

										//	Numbers<string> str;				//����
	f5(10);
}



template class Blob<string>;









