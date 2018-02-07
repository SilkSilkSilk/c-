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
	StrVec(const StrVec&);						//�������캯��
	StrVec(StrVec &&s) noexcept;				//�ƶ����캯��  noexcept����֪ͨ��׼�����ǵĹ��캯�����׳��κ��쳣��
	StrVec & operator=(const StrVec&);			//��ֵ���㺯��
	StrVec & operator=(StrVec &&s) noexcept;	//�ƶ���ֵ���㺯��
	~StrVec();
	void push_back(const string&);				//������push_back����ʵ�����������ò�ͬ�汾
	void push_back(string &&);					//������push_back����ʵ�����������ò�ͬ�汾
	size_t size() const { return first_free - elements; }
	size_t capacity()const {return cap - elements;}
	string *begin() const { return elements; }
	string* end()const { return first_free; }
	ostream &print(ostream &os) const;

	void test() &&{}							//&&��ʾֻ������ֵ������������Ա����
//	void test() const &{}						//&��ʾֻ������ֵ������������Ա����

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