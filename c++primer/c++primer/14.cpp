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
	//ptr�ļ�����=2������Դ���󲻻�����ptrָ���vector
}

Mybook_data & Mybook_data::operator=(Mybook_data && a) noexcept	//�ƶ���ʽ�ĺ�����ʵ�Ǹ��ݺ���������ʵ�ֵģ������������ptr = a.ptr;���ƶ�������������ɸ��Ʋ���������������ǿ�����ֵ��ʽ�ĺ�����
{																//�����е�Mybook_data && a��ֵ������Ϊ�˺���ֵ���ý������ֶ���
	bookNO = a.bookNO;
	units_sold = a.units_sold;
	revenus = a.revenus;
	ptr = a.ptr;		//this��ptr֮ǰָ���vector���ͷ���

	return *this;
}

Mybook_data & Mybook_data::operator=(const initializer_list<string>& il)
{
	ptr->assign(il.begin(), il.end());
	return *this;
}

Mybook_data::~Mybook_data() //�ڶ�������ʱ������������
{
	//�����������С�����ִ�к����壬Ȼ���ճ�ʼ�������������ٳ�Ա
}

Mybook_data& Mybook_data::operator+=(const Mybook_data & b)
{
	bookNO += b.bookNO;
	units_sold += b.units_sold;
	revenus += b.revenus;
	ptr->insert(ptr->end(), b.ptr->begin(), b.ptr->end());

	return *this;			//���ÿ������캯������һ��Mybook_data����ֵ
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
	++*this;		//����ǰ�ò���
	return a;		//����++֮ǰ������
}

Mybook_data Mybook_data::operator--(int)
{
	Mybook_data a = *this;
	--*this;
	return a;		
}

vector<string>& Mybook_data::operator*() const
{
	return *ptr;			//����ptrָ���vector<string>
}

vector<string>* Mybook_data::operator->() const
{
	return & this->operator*();			//���ķ������ͱ�����һ��ָ��
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
	if (is)									//����������Ƿ���ȷ
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
	//���������ݱȽ϶࣬����ѡȡ���۽��бȽ�
	return a.revenus / a.units_sold == b.revenus / b.units_sold;
}

bool operator!=(const Mybook_data & a, const Mybook_data & b)
{
	return !(a == b);
}

bool operator<(const Mybook_data & a, const Mybook_data & b)	//<�ŵ�����,���������ʹ��<�Ƚ���ĵ���
{
	return a.revenus / a.units_sold < b.revenus / b.units_sold;
}



/*Mybook_data����������ƶ���ֵ�Ϳ�����ֵ����
int main()
{
	Mybook_data a;
	vector<string> ve(10, "nzb");
	cin >> a;
	a.insert(ve.begin(), ve.end());
	cout << a;		//��ӡa���鱾���ۺͼ۸�
	a.print(cout);	//��ӡvector������

	Mybook_data c;
	{
		Mybook_data b(a);
		cout << b;
		b.print(cout);
		c = move(b);		//ʹ���ƶ���ֵ���㺯��  b�뿪����������٣����ǻᱣ��ptrָ���vector����Ϊʹ�����ƶ���ֵ
	}
	cout << c;
	c.print(cout);
}*/

/*  +�Ĳ���
int main()
{
	Mybook_data a("unix", 1, 25.6);
	vector<string> ve(6, "666");
	a.insert(ve.begin(), ve.end());
	cout << a;		//��ӡa���鱾���ۺͼ۸�
	a.print(cout);	//��ӡvector������

	Mybook_data b("nzb", 3, 60);
	vector<string> ve1(6, "six");
	b.insert(ve1.begin(), ve1.end());
	cout << b;
	b.print(cout);

	Mybook_data c;
	c = a + b;		// +�Ĳ���
	cout << c;
	c.print(cout);
}*/


/* []��������
int main()
{
	Mybook_data a("unix", 1, 25.6);
	a = { "nzb","666","for","hii","z11" };

	cout << a[0];

	a[0] = "dsb";					//��ȷ����Ϊb�Ǳ��������Ի���ñ����汾��[]�������أ����ص�������

	cout << a[0];
	const Mybook_data b(a);

	b[0] = "nzb";					//������Ϊb��const�ģ����Ի����const�汾��[]�������أ����ص���const����
}*/

/*   *��->�ķ�������
int main()
{
	Mybook_data a("unix", 1, 25.6);
	a = { "nzb","666","for","hii","z11" };

	(*a)[0] = "dsb";
	cout << a;
	a.print(cout);

	cout << a->size() << endl;	//5  a->size()��ʾ a->���غ�������һ��vectorָ��s�� (*s).size()
	cout << (*a).size() << endl;
}*/

/*  ()��������
int main()
{
	Mybook_data a("unix", 1, 25.6);
	a = { "nzb","666","for","hii","z11" };

	cout << a(2) << endl;
	a(2) = "999";			//��������a����()�����汾�����������ܸı�
	cout << a(2) << endl;

	const Mybook_data b = a;

	b(1) = "555";			//����  ��������b����()const�汾���������Բ��ܸı�
	cout << b(1) << endl;

	vector<int> ve{ 0,1,2,3 };
	for_each(ve.begin(), ve.end(), [&](const int n) {cout << a(n) << endl; });
}*/


/*	lambda����ʹ�� ��ķ�ʽ �ͺ����ķ�ʽ ��ʵ�֣�
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
	for_each(ve.begin(), ve.end(), [&](const int n) {cout << a(n) << endl; });		//����lambda����b  b(int)
	for_each(ve.begin(), ve.end(), MyClass(a));										//lambda������������ʵ�ֵ� ������MyClass����c c(int)
	auto pin_a = bind(prin, a, placeholders::_1);;									//bindʹ��������������prin������ɽ���һ��������pin_a����
	for_each(ve.begin(), ve.end(), pin_a);											//ʹ����ͨ������ʵ��lambda����
}*/

