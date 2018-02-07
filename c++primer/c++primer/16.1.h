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

template <typename T>								//ģ�����Ԫ
	bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T> class Blob					//ģ����Ķ����ʽ
{
	//һ��һ����Ԫ
	friend class BlobPtr<T>;						//T���Ͱ汾��BlobPtr����Ԫ��Blob
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);//T���Ͱ汾��operator==����Ԫ��Blob
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;			//typename�������Ǹ��߱�����size_type��һ�����Ͷ�����static�ľ�̬����������
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

//����ͨ���಻һ��������Ķ���ͳ�Ա�����Ķ��嶼��.h����
template<typename T>												//ģ����ĳ�Ա���������ʽ����ͨ����Щ����
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
	friend class pa1<C>;						//��CΪ������C����Ԫ
	template <typename T> friend class pa2;		//�������Ͷ���C����Ԫ
};

template<typename T> class C2
{
	friend class pa1<T>;						//һ��һ
	template <typename X> friend class pa2;		//�������Ͷ���C2����Ԫ
	friend class pa3;							//pa3����ͨ�࣬����ȫ������Ԫ
};

#endif