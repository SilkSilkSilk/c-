#ifndef _16CHAPTER1_3_H__
#define _16CHAPTER1_3_H__

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

template<class T> class les
{
public:
	int operator()(const T & v1, const T & v2);

private:

};

template<class T>
int les<T>::operator()(const T & v1, const T & v2)
{
	return v1 > v2;
}


#endif
