#include "12.1.1.h"


StrBlob::StrBlob() : data(make_shared < vector < string > >())
{
}

StrBlob::StrBlob( initializer_list < string > il ) : data(make_shared < vector < string > >(il))
{
}

StrBlob::~StrBlob()
{
}

void StrBlob::pop_back()
{
	check(0, "pop_back");
	return data->pop_back();
}

string& StrBlob::front()
{
	check(0, "front");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "back");
	return data->back();
}

void StrBlob::print()
{
	for (auto i : *data)
	{
		cout << i << " ";
	}
	cout << endl;
}

void StrBlob::check( size_type i, const string &msg ) const
{
	if (i >= data->size())
	{
		throw out_of_range(msg);
	}
}


/*StrBlob����չ������ָ������ƣ������ж�̬�ڴ棬a = b��Ȼ��b�����ˣ�a�еĶ�̬�ڴ�ָ�벻��ʹ���ˣ���Ϊa�еĶ�̬�ڴ�ָ���Ǳ�b�ж�̬�ڴ�ָ���ʼ���ģ�b����ʱ�ͷ��������ڴ�
							 ����ʹ������ָ�������涯̬�ڴ�ָ�룬a = b��b�ڲ�������Ϊ2��Ȼ��b�����ˣ�b�ڲ�������Ϊ1>0����b����ʱû���ͷ�bָ����ڴ�ռ�
int main()
{
	StrBlob str;
	{
		StrBlob str1{ "nzb", "for" };
		str = str1;							//str1�е�����ָ�������+1 str����ԭ��ָ��Ķ���ԭ����û��ָ��
		str1.push_back("nizhibing");
	}
	//str1������֮������ָ�������-1������Ϊ0������vector<string>�ڴ滹����
	//str1������֮���ڴ汻�ͷţ���������vector<string>�ڴ滹���ڣ���Ϊstr = str1;  �൱��str�е�����ָ���ʼ��Ϊstr1�е�����ָ�룬str�е�����ָ�뻹��ָ��str1�е�vector<string>��

	str.print();
}*/
