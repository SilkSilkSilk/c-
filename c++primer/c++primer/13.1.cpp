#include "13.1.h"

sales_data::sales_data() : bookNO(""), units_sold(0), revenus(0.0)
{
}

sales_data::sales_data( string &s ) : bookNO(s), units_sold(0), revenus(0.0)
{
}

sales_data::sales_data( const sales_data &a )
{
	bookNO = a.bookNO + "hello nzb!"; //�Լ����庯��ѡ���Կ���
	units_sold = a.units_sold;
	revenus = a.revenus;
}

sales_data::~sales_data() //�ڶ�������ʱ������������
{
	//�����������С�����ִ�к����壬Ȼ���ճ�ʼ�������������ٳ�Ա
}

sales_data& sales_data::operator=( const sales_data &a )
{
	bookNO = a.bookNO;
	units_sold = a.units_sold;
	revenus = a.revenus;
	return *this;
}

void sales_data::print()
{
	cout << bookNO << " " << units_sold << " " << revenus << endl;
}


HasPtr& HasPtr::operator=( const HasPtr &p ) //һ���õĸ�ֵ���㺯����ʹ��a = a;ҲҪ��������
{
	this->i = p.i;
	this->ps = new string(*p.ps);

	this->ptr = p.ptr; //��Ϊ������ָ�룬���Բ���Ҫÿ�ζ������ڴ�ռ�,��ʹp�����ˣ�ptrָ��Ķ�̬�ڴ�Ҳ���ڵ�

	return *this;
}

void HasPtr::swap(HasPtr & hs1, HasPtr & hs2)
{
	::swap(hs1.i, hs2.i);	//��Ϊ��������������Ѱ��swap						
	::swap(hs1.ps, hs2.ps);
}
