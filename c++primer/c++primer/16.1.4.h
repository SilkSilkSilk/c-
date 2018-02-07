#ifndef _16CHAPTER1_4_H__
#define _16CHAPTER1_4_H__

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


class DebugDelete						//在普通类中把成员函数定义成模板函数
{
public:
	DebugDelete(ostream &s = std::cout) :os(s) {}

	template<class T> void operator()(T* a) const
	{
		os << "delete unique_ptr" << endl;
		delete a;
	}

private:
	ostream &os;
};




void main_blob();




#endif
