#ifndef _15CHAPTER5_H__
#define _15CHAPTER5_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"


using namespace std;


class Base
{
public:
	void public_mem();

private:
	int privat_data;
protected:
	int protected_data;
};


class public_Base : public Base		//按照Base中数据的访问说明符来继承  Base中的public放到public_Base中的public	 protected放到protected中
{
public:
	int f()
	{
		public_mem();
		return protected_data;
	}
	using Base::protected_data;		//把原来应该在protected里的protected_data变量放到public里
	//Base类的public数据在这
private:
	
protected:
	using Base::public_mem;			//把原来应该在public里的public_mem函数放到protected里
	//Base类的protected数据在这
};

class private_Base : private Base	//把Base中public和protected数据都放到自己的private里
{
public:
	int f()
	{
		public_mem();				//相当于使用自己中的private数据
		return protected_data;
	}
	int num_test;
private:
	//Base类的数据在这
protected:

};

class protected_Base : protected Base	//把Base中public和protected数据都放到自己的protected里
{
public:
	int f()
	{
		public_mem();					//相当于使用自己中的protected数据
		return protected_data;
	}

private:

protected:
	//Base类的数据在这
};

class Bulk2_public : public public_Base		//按照public方式来继承public_Base
{
public:
	int g()
	{
		public_mem();						//public_Base是按照public的方式继承Base的，所以这里能够使用间接基类里的数据
		return protected_data;
	}
private:

};

class Bulk2_private : public private_Base	//按照public方式来继承private_Base
{
public:
	int g()
	{
//		public_mem();						//private_Base类把Base中public和protected数据都放到自己的private里，类不能继承private里的数据
//		return protected_data;				//错误，不能使用间接基类里的数据了
		return num_test;					//但还是能用直接基类里的数据的,因为public的方式继承直接基类
	}
private:

};

class Bulk2_protected : public protected_Base //按照public方式来继承protected_Base
{
public:
	int g()
	{
		public_mem();						//protected_Base类把Base中public和protected数据都放到自己的protected里，protected是可以被继承的
		return protected_data;				//所以可以使用
	}
private:

protected:
	//Base类的数据在这
};


class B
{
public:
	int a;
	int memco(int n) { return n; }
	virtual int fun(int a) { return a; }
private:
	int pri_B;

protected:
	int pro_B;
};

class Blue : public B
{
public:
	int f()
	{
		a = 10;				//a覆盖了基类中的a
		return B::a;		//B::指定基类中的a
	}
	int memco(int n) { return n; }	//与虚函数不同，memco直接覆盖掉了B的memco，基于名字的查找

	int fun(int a) { return a + 1; }	//虚函数是特殊的存在，可以构成重载

	int fun(double num, int b) { return (int)num; }

private:
	double a;
	int pri_num;
};

#endif