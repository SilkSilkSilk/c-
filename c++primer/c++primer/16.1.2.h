#ifndef _16CHAPTER1_2_H__
#define _16CHAPTER1_2_H__

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

#include "16.1.h"

using namespace std;

template <typename T> class BlobPtr
{
public:
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

	T& operator*() const
	{
		auto p = check(curr, "derefernce past end");
		return (*p)[curr];
	}

	BlobPtr& operator++();					//��ģ������������п���ֱ��ʹ��BlobPtr��������BlobPtr<T>
	BlobPtr& operator--();

private:
	shared_ptr<vector<T>> check(size_t, const string&) const;
	weak_ptr<vector<T>> wptr;
	size_t curr;
};


template<typename T>
inline BlobPtr<T> & BlobPtr<T>::operator++()	//����Ͳ������������Χ����
{
	BlobPtr ret = *this;						//��ģ������������п���ֱ��ʹ��BlobPtr��������BlobPtr<T>

	return ret;
}
























#endif