#ifndef _15CHAPTER9_H__
#define _15CHAPTER9_H__

#include "12.3.h"


class Query;


class Query_base				//eval和rep都是纯虚函数，因此Query_base是一个抽象基类,因为我们不希望用户或者派生类直接使用Query_base，所以它没有public成员。
{
	friend Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;

private:
	virtual QueryResult eval(const TextQuery &) const = 0;		//纯虚函数
	virtual string rep() const = 0;
};

class Query
{
	friend Query operator~(const Query &);
	friend Query operator&(const Query &, const Query &);
	friend Query operator|(const Query &, const Query &);
public:
	Query(const string&);			//使用string构造Query类时会new一个WordQuery类，这是query的核心，WordQuery保存着需要搜索的单词和查找结果
	QueryResult eval(const TextQuery& t) const
	{
		return q->eval(t);			//eval是虚函数，通过基类可以调用对应派生类的虚函数
	}

	string rep() const
	{
		return q->rep();
	}

private:
	Query(shared_ptr<Query_base> query) :q(query) {}	//将no or and类构造成Query类，可以通过rep和eval来调用它们的虚函数

	shared_ptr<Query_base> q;		//基类的智能指针能接受派生类对象的智能指针
};

ostream& operator<<(ostream &os, const Query& query);


class WordQuery: public Query_base
{
	friend Query;

	WordQuery(const string &s) :query_word(s) {  }

	QueryResult eval(const TextQuery &t) const
	{
		return t.query(query_word);				//调用搜索
	}

	string rep() const
	{
		return query_word;
	}

	string query_word;
};

class NotQuery: public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q) :query(q) {}

	string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const;

	Query query;
};

class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, string s) :lhs(l), rhs(r), opSym(s) {}
	string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }

	Query lhs, rhs;
	string opSym;
};

class AndQuery: public BinaryQuery
{
	friend Query operator&(const Query &, const Query &);

	AndQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "&") {}
	QueryResult eval(const TextQuery &) const;			//将left和right的搜索结果取交集
};

class OrQuery: public BinaryQuery
{
	friend Query operator|(const Query &, const Query &);

	OrQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery &) const;			//将left和right的搜索结果取并集
};



int main_15_9();










#endif
