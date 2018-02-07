#ifndef _16CHAPTER1_H__
#define _16CHAPTER1_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <functional>



using namespace std;

template <typename> class BlobPtr;
template <typename> class Blob;

template <typename T>								//模板的友元
	bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob					//模板类的定义格式
{
	//一对一的友元
	friend class BlobPtr<T>;						//T类型版本的BlobPtr是友元于Blob
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);//T类型版本的operator==是友元于Blob
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;			//typename的作用是告诉编译器size_type是一个类型而不是static的静态变量或其他
	Blob();
	Blob(initializer_list<T> il);

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();

	T& back();
	T& operator[](size_type i);

private:
	shared_ptr<vector<T>> data;
	void check(size_type i, const string &msg) const;
};

//和普通的类不一样的是类的定义和成员函数的定义都在.h里面
template<typename T>												//模板类的成员函数定义格式和普通类有些区别
inline Blob<T>::Blob() :data(make_shared<vector<T>>())
{

}

template<typename T>
inline Blob<T>::Blob(initializer_list<T> il) :data(new vector<T>(il))
{

}

template<typename T>
inline void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template<typename T>
inline T & Blob<T>::back()
{
	check(0, "back on empty Blop");
	return data->back();
}

template<typename T>
inline T & Blob<T>::operator[](size_type i)
{
	check(i, "subscirpt out of range");
	return (*data)[i];
}

template<typename T>
inline void Blob<T>::check(size_type i, const string &msg) const
{
	if (i >= data->size())
	{
		throw out_of_range(msg);
	}
}


int main_16_1_1();


template <typename T> class pa1;
template <typename T> class pa2;
class pa3;

class C
{
	friend class pa1<C>;						//以C为类型是C的友元
	template <typename T> friend class pa2;		//所有类型都是C的友元
};

template<typename T> class C2
{
	friend class pa1<T>;						//一对一
	template <typename X> friend class pa2;		//所有类型都是C2的友元
	friend class pa3;							//pa3是普通类，所以全部是友元
};

#endif