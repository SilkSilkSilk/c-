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
	SmallInt(int i = 0) :val(i) {}			//intת����SmallInt��
	~SmallInt();
	explicit operator int() const { return val; }	//SmallInt��תת��int ��ʽת��

private:
	int val;
};








#endif