#ifndef _12CHAPTER1_1_H__
#define _12CHAPTER1_1_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"
#include <memory>


using namespace std;


class StrBlob
{
public:
	typedef vector < string >::size_type size_type;
	StrBlob();
	StrBlob( initializer_list < string > il );
	~StrBlob();

	size_type size() const { return data->size(); }

	bool empty() const { return data->empty(); }

	void push_back( const string &t ) { data->push_back(t); }

	void pop_back();
	string& front();
	string& back();
	void print();

private:
	shared_ptr < vector < string > > data;
	void check( size_type i, const string &msg ) const;
};


#endif
