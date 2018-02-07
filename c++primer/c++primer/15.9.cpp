#include "15.9.h"
#include <iterator>


Query operator~(const Query &operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));		//operand已经定义了单词类，再把它初始化构造NotQuery，再转换成智能指针通过Query的私有构造函数转换成Query
																//此时Query的基类智能指针指向的是NotQuery，NotQuery中的Query对象含有WordQuery的单词操作
}

Query operator&(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

Query operator|(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

ostream& operator<<(ostream & os, const Query & query)
{
	return os << query.rep();
}

Query::Query(const string &s) :q(new WordQuery(s))
{

}

QueryResult OrQuery::eval(const TextQuery & text) const
{
	auto right = rhs.eval(text), left = lhs.eval(text);

	auto re_line = make_shared<set<line_no>>(left.begin(), left.end());
	re_line->insert(right.begin(), right.end());

	return QueryResult(rep(), re_line, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text) const
{
	auto left = lhs.eval(text), right = rhs.eval(text);		//lhs和rhs的eval是一个向上追溯的过程，是调用Query对象基类指针q的eval方法，q指向的最底层是WordQuery单词类，高层是or、and、~类，这些类的最底层是WordQuery单词类
	auto re_line = make_shared<set<line_no>>();		//默认初始化
	//set_intersectio是标准算法库的函数，是取交集
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*re_line, re_line->begin()));

	return QueryResult(rep(), re_line, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
	auto result = query.eval(text);

	auto ret_lines = make_shared<set<line_no>>();

	auto beg = result.begin(), end = result.end();

	auto sz = result.get_file()->size();

	for (size_t i = 0; i < sz; i++)
	{
		if (beg == end || *beg != i)
		{
			ret_lines->insert(i);
		}
		else
		{
			++beg;
		}
	}

	return QueryResult(rep(), ret_lines, result.get_file());
}

int main_15_9()
{
	Query a = ~Query("hair");
	a.eval(TextQuery(ifstream("input_file.txt"))).print();

	Query b = a & Query("Alice");			//b的基类指针q指向AndQuery类，AndQuery类包含两个Query，a的基类指针指向NotQuery类，NotQuery类又指向WordQuery类
											//Query("Alice")的基类指针q指向WordQuery类，WordQuery类的eval方法执行搜索操作
	b.eval(TextQuery(ifstream("input_file.txt"))).print();
	return true;
}

