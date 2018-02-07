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

template<class T, class ...Args>		//...��ʾһ��ģ��������������������ɶ������
ostream& prin(ostream& os, const T& t, const Args&... rest)		//...rest��һ�������������������������ɶ������
{
	os << t << ", ";
	return prin(os, rest...);		//�ݹ����,��rest�ܳ�ʱ��rest�ĵ�һ��������oconst T& t,����Ĳ������µ�rest���ٴεݹ飬ֱ��rest����Ϊ1����ʱ���������prin����returnһ���������ݹ�
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

template<class T>	//�볢����ʹ��initializer_list�б�����debug_rep��string���󣬵���û�гɹ�����Ϊprin(os, debug_rep(a1), debug_rep(a1), debug_rep(a1), debug_rep(an));��debug_rep�ķ���û��ʹ��{}���������������ڶ������
ostream& frin(ostream& os, const initializer_list<T>& t)	//initializer_list��Ҫ{}��ʼ������debug_repʹ��{}��������frin(os, {debug_rep(rest)...}),�ͳɹ���
{
	for (auto i : t)
	{
		os << i << endl;
	}
	return os;
}

void main_error_msg();




#endif
