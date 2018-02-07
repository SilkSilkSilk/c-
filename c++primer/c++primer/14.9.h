#ifndef _14CHAPTER9_H__
#define _14CHAPTER9_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"
 

using namespace std;


class SmallInt
{
public:
	SmallInt(int i = 0) :val(i) {}			//int转换成SmallInt类
	~SmallInt();
	explicit operator int() const { return val; }	//SmallInt类转转成int 显式转换

private:
	int val;
};








#endif