#ifndef _14CHAPTER_H__
#define _14CHAPTER_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"
#include <memory>


using namespace std;


class Mybook_data
{
	friend ostream& operator<<(ostream &os, const Mybook_data& a);
	friend istream& operator >> (istream &is, Mybook_data &a);
	friend bool operator==(const Mybook_data &a, const Mybook_data &b);
	friend bool operator<(const Mybook_data &a, const Mybook_data &b);
public:
	Mybook_data();
	Mybook_data(const string &s, unsigned int n, double p);
	Mybook_data(const Mybook_data &a);						//拷贝构造函数
	Mybook_data& operator=(const Mybook_data &a);			//赋值运算
	Mybook_data(Mybook_data &&a) noexcept;					//移动构造函数
	Mybook_data& operator=(Mybook_data &&a) noexcept;		//移动赋值运算
	Mybook_data& operator=(const initializer_list<string> &il);//const的引用可以接受临时对象（右值）  
	~Mybook_data();
	Mybook_data& operator+=(const Mybook_data &b);			//成员函数即+=左边的对象是this
	string& operator[](size_t n) { return (*ptr)[n]; }		//[]重载  只允许变量对象调用这个成员函数
	const string& operator[](size_t n)const { return (*ptr)[n]; }	//const对象调用这个成员函数		变量对象能调用const版本和变量版本，而const对象只能调用const版本
	Mybook_data& operator++();								//前置++
	Mybook_data& operator--();								//前置--
	Mybook_data operator++(int);							//后置++  前置和后置操作函数都一样，使用参数来区分它们，编译器允许使用int型参数表示后置
	Mybook_data operator--(int);							//后置--
	vector<string>& operator*() const;						//*重载 返回ptr的指向
	vector<string>* operator->() const;						//->重载 （a->）返回vector<string>&
	string& operator()(size_t n) { return (*ptr)[n]; }				// a(2) 返回(*ptr)[2]
	const string& operator()(size_t n) const { return (*ptr)[n]; }	//const对象调用这个成员函数
	void print(ostream & os) const;
	void insert(vector<string>::iterator j, vector<string>::iterator k) const;		//接受一个vector<string>的区域赋值

private:
	shared_ptr<vector<string>> ptr;
	string bookNO;
	unsigned int units_sold;
	double revenus;
};

ostream& operator<<(ostream &os, const Mybook_data& a);
istream& operator >> (istream &is, Mybook_data &a);
Mybook_data operator+(const Mybook_data &a, const Mybook_data &b);
bool operator==(const Mybook_data &a, const Mybook_data &b);
bool operator!=(const Mybook_data &a, const Mybook_data &b);
bool operator<(const Mybook_data &a, const Mybook_data &b);	//<号的重载,在这个类中使用<比较书的单价

#endif
