#include "16.1.4.h"


void main_debugdelete()
{
	double *a = new double(0.012);

	DebugDelete d;
	//	d.operator()(a);						//功能一样	template<class T> void operator()(double* a) const
	//	d(a);									//功能一样
	DebugDelete()(a);						//先创建空对象，再调用()方法

	unique_ptr<int, DebugDelete> p(new int, DebugDelete());		//智能指针指定析构方法，析构p时会使用DebugDelete删除

																//	实例化DebugDelete::operator() < int > (int *);
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

template<class T>						//先写类的模板参数声明
template<class Q>						//后写类的成员函数的模板声明
blob<T>::blob(Q & a, Q & b) :p(make_shared<vector<T>>(a, b))			//在这个函数中Q要与T类型匹配，因为vector中a和b初始化
{
	for (auto i : *p)
	{
		cout << i << " ";
	}
	cout << endl;
}























