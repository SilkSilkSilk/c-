#ifndef _16CHAPTER4_H__
#define _16CHAPTER4_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"
#include <fstream>
#include <sstream>
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <memory>
#include <algorithm>
#include <functional>


using namespace std;

template<class T>
ostream &prin(ostream &os, const T& t)
{
	return os << t;
}

template<class T, class ...Args>		//...表示一个模板参数包，可以智能生成多个参数
ostream& prin(ostream& os, const T& t, const Args&... rest)		//...rest是一个函数参数包，可以智能生成多个参数
{
	os << t << ", ";
	return prin(os, rest...);		//递归操作,但rest很长时，rest的第一个参数给oconst T& t,后面的参数给新的rest，再次递归，直到rest长度为1，此时重载上面的prin函数return一步步结束递归
}

template<class ...Args>
ostream& errorMsg(ostream &os, const Args& ...rest)
{
	return prin(os, debug_rep(rest)...);		//prin(os, debug_rep(a1), debug_rep(a1), debug_rep(a1), debug_rep(an));
}

template<class T>
string debug_rep(const T& st)
{
	ostringstream ret;
	ret << st;
	return ret.str();
}

template<class T>	//想尝试着使用initializer_list列表来存debug_rep的string对象，但是没有成功，因为prin(os, debug_rep(a1), debug_rep(a1), debug_rep(a1), debug_rep(an));中debug_rep的返回没有使用{}包起来，它们属于多个参数
ostream& frin(ostream& os, const initializer_list<T>& t)	//initializer_list需要{}初始化，把debug_rep使用{}包起来后，frin(os, {debug_rep(rest)...}),就成功了
{
	for (auto i : t)
	{
		os << i << endl;
	}
	return os;
}

void main_error_msg();




#endif
