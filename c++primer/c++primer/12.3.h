#ifndef _7CHAPTER6_H__
#define _7CHAPTER6_H__


#include <iostream>
#include <vector>
#include <cstring>
#include "string"
#include <stdint.h>
#include <memory>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class QueryResult;

class TextQuery
{
public:
	using line_no = vector < string >::size_type;
	TextQuery( ifstream &isf );
	~TextQuery();
	QueryResult query( const string &a ) const;

private:
	shared_ptr < vector < string > > file; //定义成智能指针是为了传递时不拷贝
	map < string, shared_ptr < set < line_no > > > wm;
};

class QueryResult
{
public:
	QueryResult( string s, shared_ptr < set < TextQuery::line_no > > p, shared_ptr < vector < string > > f );
	~QueryResult();
	void print();
	set < TextQuery::line_no >::iterator begin();
	set < TextQuery::line_no >::iterator end();
	shared_ptr<vector<string>> get_file() const;

private:
	string sought;
	shared_ptr < set < TextQuery::line_no > > lines;
	shared_ptr < vector < string > > file;
};


#endif
