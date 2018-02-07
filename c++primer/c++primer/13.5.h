#ifndef _13CHAPTER5_H__
#define _13CHAPTER5_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"
#include <memory>
#include <set>


using namespace std;

class StrVec
{
public:
	StrVec(initializer_list<string> a);
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
	StrVec(const StrVec&);						//拷贝构造函数
	StrVec(StrVec &&s) noexcept;				//移动构造函数  noexcept（它通知标准库我们的构造函数不抛出任何异常）
	StrVec & operator=(const StrVec&);			//赋值运算函数
	StrVec & operator=(StrVec &&s) noexcept;	//移动赋值运算函数
	~StrVec();
	void push_back(const string&);				//这两个push_back依据实参类型来调用不同版本
	void push_back(string &&);					//这两个push_back依据实参类型来调用不同版本
	size_t size() const { return first_free - elements; }
	size_t capacity()const {return cap - elements;}
	string *begin() const { return elements; }
	string* end()const { return first_free; }
	ostream &print(ostream &os) const;

	void test() &&{}							//&&表示只允许右值对象调用这个成员函数
//	void test() const &{}						//&表示只允许左值对象调用这个成员函数

private:
	allocator<string> alloc;
	void chk_n_alloc();
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	string *elements;
	string *first_free;
	string *cap;
};




#endif