#ifndef _15CHAPTER9_H__
#define _15CHAPTER9_H__

#include "12.3.h"


class Query;


class Query_base				//eval��rep���Ǵ��麯�������Query_base��һ���������,��Ϊ���ǲ�ϣ���û�����������ֱ��ʹ��Query_base��������û��public��Ա��
{
	friend Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;

private:
	virtual QueryResult eval(const TextQuery &) const = 0;		//���麯��
	virtual string rep() const = 0;
};

class Query
{
	friend Query operator~(const Query &);
	friend Query operator&(const Query &, const Query &);
	friend Query operator|(const Query &, const Query &);
public:
	Query(const string&);			//ʹ��string����Query��ʱ��newһ��WordQuery�࣬����query�ĺ��ģ�WordQuery��������Ҫ�����ĵ��ʺͲ��ҽ��
	QueryResult eval(const TextQuery& t) const
	{
		return q->eval(t);			//eval���麯����ͨ��������Ե��ö�Ӧ��������麯��
	}

	string rep() const
	{
		return q->rep();
	}

private:
	Query(shared_ptr<Query_base> query) :q(query) {}	//��no or and�๹���Query�࣬����ͨ��rep��eval���������ǵ��麯��

	shared_ptr<Query_base> q;		//���������ָ���ܽ�����������������ָ��
};

ostream& operator<<(ostream &os, const Query& query);


class WordQuery: public Query_base
{
	friend Query;

	WordQuery(const string &s) :query_word(s) {  }

	QueryResult eval(const TextQuery &t) const
	{
		return t.query(query_word);				//��������
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
	QueryResult eval(const TextQuery &) const;			//��left��right���������ȡ����
};

class OrQuery: public BinaryQuery
{
	friend Query operator|(const Query &, const Query &);

	OrQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery &) const;			//��left��right���������ȡ����
};



int main_15_9();










#endif
