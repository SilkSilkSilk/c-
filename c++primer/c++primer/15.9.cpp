#include "15.9.h"
#include <iterator>


Query operator~(const Query &operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));		//operand�Ѿ������˵����࣬�ٰ�����ʼ������NotQuery����ת��������ָ��ͨ��Query��˽�й��캯��ת����Query
																//��ʱQuery�Ļ�������ָ��ָ�����NotQuery��NotQuery�е�Query������WordQuery�ĵ��ʲ���
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
	auto left = lhs.eval(text), right = rhs.eval(text);		//lhs��rhs��eval��һ������׷�ݵĹ��̣��ǵ���Query�������ָ��q��eval������qָ�����ײ���WordQuery�����࣬�߲���or��and��~�࣬��Щ�����ײ���WordQuery������
	auto re_line = make_shared<set<line_no>>();		//Ĭ�ϳ�ʼ��
	//set_intersectio�Ǳ�׼�㷨��ĺ�������ȡ����
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

	Query b = a & Query("Alice");			//b�Ļ���ָ��qָ��AndQuery�࣬AndQuery���������Query��a�Ļ���ָ��ָ��NotQuery�࣬NotQuery����ָ��WordQuery��
											//Query("Alice")�Ļ���ָ��qָ��WordQuery�࣬WordQuery���eval����ִ����������
	b.eval(TextQuery(ifstream("input_file.txt"))).print();
	return true;
}

