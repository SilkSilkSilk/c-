#include "14.h"


Mybook_data::Mybook_data() : ptr(new vector<string>()), bookNO(""), units_sold(0), revenus(0.0)
{
}

Mybook_data::Mybook_data(const string &s, unsigned int n, double p) : ptr(new vector<string>()), bookNO(s), units_sold(n), revenus(p)
{
}

Mybook_data::Mybook_data(const Mybook_data &a) : ptr(new vector<string>()), bookNO(a.bookNO), units_sold(a.units_sold), revenus(a.revenus)
{
//	ptr->clear();
//	ptr->insert(ptr->begin(), a.ptr->begin(), a.ptr->end());
	ptr->assign(a.ptr->begin(), a.ptr->end());
}

Mybook_data& Mybook_data::operator=(const Mybook_data &a)
{
	bookNO = a.bookNO;
	units_sold = a.units_sold;
	revenus = a.revenus;
	ptr->assign(a.ptr->begin(), a.ptr->end());
	return *this;
}

Mybook_data::Mybook_data(Mybook_data && a) noexcept :ptr(a.ptr), bookNO(a.bookNO), units_sold(a.units_sold), revenus(a.revenus)
{
	//ptr的计算器=2，所以源对象不会销毁ptr指向的vector
}

Mybook_data & Mybook_data::operator=(Mybook_data && a) noexcept	//移动方式的函数其实是根据函数内容来实现的，在这个函数中ptr = a.ptr;是移动操作，如果换成复制操作那这个函数就是拷贝赋值方式的函数了
{																//函数中的Mybook_data && a右值引用是为了和左值引用进行区分而已
	bookNO = a.bookNO;
	units_sold = a.units_sold;
	revenus = a.revenus;
	ptr = a.ptr;		//this的ptr之前指向的vector被释放了

	return *this;
}

Mybook_data & Mybook_data::operator=(const initializer_list<string>& il)
{
	ptr->assign(il.begin(), il.end());
	return *this;
}

Mybook_data::~Mybook_data() //在对象被销毁时调用析构函数
{
	//在析构函数中。首先执行函数体，然后按照初始化的逆序来销毁成员
}

Mybook_data& Mybook_data::operator+=(const Mybook_data & b)
{
	bookNO += b.bookNO;
	units_sold += b.units_sold;
	revenus += b.revenus;
	ptr->insert(ptr->end(), b.ptr->begin(), b.ptr->end());

	return *this;			//调用拷贝构造函数构造一个Mybook_data返回值
}

Mybook_data & Mybook_data::operator++()
{
	revenus += revenus / units_sold++;
	return *this;
}

Mybook_data & Mybook_data::operator--()
{
	revenus -= revenus / units_sold--;
	return *this;
}

Mybook_data Mybook_data::operator++(int)
{
	Mybook_data a = *this;
	++*this;		//套用前置操作
	return a;		//返回++之前的数据
}

Mybook_data Mybook_data::operator--(int)
{
	Mybook_data a = *this;
	--*this;
	return a;		
}

vector<string>& Mybook_data::operator*() const
{
	return *ptr;			//返回ptr指向的vector<string>
}

vector<string>* Mybook_data::operator->() const
{
	return & this->operator*();			//它的返回类型必须是一个指针
}

void Mybook_data::print(ostream & os) const
{
	for (auto i : *ptr)
	{
		os << i << " ";
	}
	os << endl;
}

void Mybook_data::insert(vector<string>::iterator j, vector<string>::iterator k) const
{
	ptr->insert(ptr->end(), j, k);
}

ostream& operator<<(ostream & os, const Mybook_data & a)
{
	os << a.bookNO << " " << a.units_sold << " " << a.revenus << endl;
	return os;
}

istream& operator >> (istream & is, Mybook_data & a)
{
	double price;
	is >> a.bookNO >> a.units_sold >> price;
	if (is)									//检查输入流是否正确
	{
		a.revenus = a.units_sold * price;
	}
	else
	{
		a = Mybook_data("defuat", 10, 25.6);
	}

	return is;
}

Mybook_data operator+(const Mybook_data & a, const Mybook_data & b)
{
	Mybook_data sum = a;
	sum += b;
	return sum;
}

bool operator==(const Mybook_data & a, const Mybook_data & b)
{
	//对象中数据比较多，我们选取单价进行比较
	return a.revenus / a.units_sold == b.revenus / b.units_sold;
}

bool operator!=(const Mybook_data & a, const Mybook_data & b)
{
	return !(a == b);
}

bool operator<(const Mybook_data & a, const Mybook_data & b)	//<号的重载,在这个类中使用<比较书的单价
{
	return a.revenus / a.units_sold < b.revenus / b.units_sold;
}



/*Mybook_data类测试它的移动赋值和拷贝赋值函数
int main()
{
	Mybook_data a;
	vector<string> ve(10, "nzb");
	cin >> a;
	a.insert(ve.begin(), ve.end());
	cout << a;		//打印a的书本单价和价格
	a.print(cout);	//打印vector的数据

	Mybook_data c;
	{
		Mybook_data b(a);
		cout << b;
		b.print(cout);
		c = move(b);		//使用移动赋值运算函数  b离开作用域会销毁，但是会保留ptr指向的vector，因为使用了移动赋值
	}
	cout << c;
	c.print(cout);
}*/

/*  +的操作
int main()
{
	Mybook_data a("unix", 1, 25.6);
	vector<string> ve(6, "666");
	a.insert(ve.begin(), ve.end());
	cout << a;		//打印a的书本单价和价格
	a.print(cout);	//打印vector的数据

	Mybook_data b("nzb", 3, 60);
	vector<string> ve1(6, "six");
	b.insert(ve1.begin(), ve1.end());
	cout << b;
	b.print(cout);

	Mybook_data c;
	c = a + b;		// +的操作
	cout << c;
	c.print(cout);
}*/


/* []符合重载
int main()
{
	Mybook_data a("unix", 1, 25.6);
	a = { "nzb","666","for","hii","z11" };

	cout << a[0];

	a[0] = "dsb";					//正确，因为b是变量，所以会调用变量版本的[]符合重载，返回的是引用

	cout << a[0];
	const Mybook_data b(a);

	b[0] = "nzb";					//错误，因为b是const的，所以会调用const版本的[]符合重载，返回的是const引用
}*/

/*   *和->的符号重载
int main()
{
	Mybook_data a("unix", 1, 25.6);
	a = { "nzb","666","for","hii","z11" };

	(*a)[0] = "dsb";
	cout << a;
	a.print(cout);

	cout << a->size() << endl;	//5  a->size()表示 a->重载函数返回一个vector指针s， (*s).size()
	cout << (*a).size() << endl;
}*/

/*  ()符号重载
int main()
{
	Mybook_data a("unix", 1, 25.6);
	a = { "nzb","666","for","hii","z11" };

	cout << a(2) << endl;
	a(2) = "999";			//变量对象a调用()变量版本函数，所以能改变
	cout << a(2) << endl;

	const Mybook_data b = a;

	b(1) = "555";			//错误  常量对象b调用()const版本函数，所以不能改变
	cout << b(1) << endl;

	vector<int> ve{ 0,1,2,3 };
	for_each(ve.begin(), ve.end(), [&](const int n) {cout << a(n) << endl; });
}*/


/*	lambda函数使用 类的方式 和函数的方式 来实现：
 *
class MyClass
{
public:
	MyClass(const Mybook_data& a):c(a){}
	void operator()(const int n)const
	{
		cout << c(n) << endl;
	}
private:
	const Mybook_data &c;
};

void prin(Mybook_data &a, int n)
{
	cout << a(n) << endl;
}

int main()
{
	Mybook_data a("unix", 1, 25.6);
	a = { "nzb","666","for","hii","z11" };

	vector<int> ve{ 0,1,2,3 };
	for_each(ve.begin(), ve.end(), [&](const int n) {cout << a(n) << endl; });		//无名lambda函数b  b(int)
	for_each(ve.begin(), ve.end(), MyClass(a));										//lambda函数是用类来实现的 无名的MyClass对象c c(int)
	auto pin_a = bind(prin, a, placeholders::_1);;									//bind使接受两个参数的prin函数变成接受一个参数的pin_a函数
	for_each(ve.begin(), ve.end(), pin_a);											//使用普通函数来实现lambda函数
}*/

