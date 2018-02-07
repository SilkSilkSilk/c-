#include "12.3.h"

QueryResult::QueryResult( string s, shared_ptr < set < TextQuery::line_no > > p, shared_ptr < vector < string > > f ) : sought(s), lines(p), file(f)
{
}

QueryResult::~QueryResult()
{
	//因为使用的是智能指针，所以不需要来delete掉new出来的动态空间
}

void QueryResult::print()
{
	cout << sought << " occurs " << lines->size() << " times" << endl;

	for (auto i : *lines)
	{
		cout << "(line " << i + 1 << ")   " << *(file->begin() + i) << endl;
	}
}

set < TextQuery::line_no >::iterator QueryResult::begin()
{
	return lines->begin();
}

set < TextQuery::line_no >::iterator QueryResult::end()
{
	return lines->end();
}

shared_ptr<vector<string>> QueryResult::get_file() const
{
	return file;
}


TextQuery::TextQuery( ifstream &isf ) : file(new vector < string >)
{
	string text;
	while (getline(isf, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string world;
		while (line >> world)
		{
			string word("");
			for (char &i : world)
			{
				if ((i >= 48 && i << 57) || (i >= 65 && i <= 90) || (i >= 97 && i <= 122))
				{
					word.push_back(i);
				}
			}

			auto &se = wm[word];
			if (!se) //指针为空
			{
				se.reset(new set < line_no >);
			}
			se->insert(n); //添加行号
		}
	}
}

TextQuery::~TextQuery()
{
	//因为使用的是智能指针，所以不需要来delete掉new出来的动态空间
}

QueryResult TextQuery::query( const string &a ) const
{
	static shared_ptr < set < line_no > > nodata(new set < line_no >);

	auto loc = wm.find(a);
	if (loc == wm.end())
	{
		return QueryResult(a, nodata, file);
	}
	else
	{
		return QueryResult(a, loc->second, file);
	}
}


/* 读取input_file.txt的内容，为每一个单词用map存储起来，并保存他们的行号，由于可能有相同的单词出现在不同的行中，所有map的值要是一个数组，我们定义成了set<int> 
int main()
{
	TextQuery te(ifstream("input_file.txt"));
	te.query("k").print();
}*/
