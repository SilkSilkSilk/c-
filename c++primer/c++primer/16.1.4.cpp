#include "16.1.4.h"


void main_debugdelete()
{
	double *a = new double(0.012);

	DebugDelete d;
	//	d.operator()(a);						//����һ��	template<class T> void operator()(double* a) const
	//	d(a);									//����һ��
	DebugDelete()(a);						//�ȴ����ն����ٵ���()����

	unique_ptr<int, DebugDelete> p(new int, DebugDelete());		//����ָ��ָ����������������pʱ��ʹ��DebugDeleteɾ��

																//	ʵ����DebugDelete::operator() < int > (int *);
}

template<class T> class blob
{
public:
	template<class Q> blob(Q &a, Q& b);

private:
	shared_ptr<vector<T>> p;
};



void main_blob()
{
	vector<int> a(6, 6);
	blob<int> b(a.begin(), a.end());
}

template<class T>						//��д���ģ���������
template<class Q>						//��д��ĳ�Ա������ģ������
blob<T>::blob(Q & a, Q & b) :p(make_shared<vector<T>>(a, b))			//�����������QҪ��T����ƥ�䣬��Ϊvector��a��b��ʼ��
{
	for (auto i : *p)
	{
		cout << i << " ";
	}
	cout << endl;
}























