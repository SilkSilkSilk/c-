#ifndef _14CHAPTER_H__
#define _14CHAPTER_H__

#include <iostream>
#include <vector>
#include <cstring>
#include "string"
#include <memory>


using namespace std;


class Mybook_data
{
	friend ostream& operator<<(ostream &os, const Mybook_data& a);
	friend istream& operator >> (istream &is, Mybook_data &a);
	friend bool operator==(const Mybook_data &a, const Mybook_data &b);
	friend bool operator<(const Mybook_data &a, const Mybook_data &b);
public:
	Mybook_data();
	Mybook_data(const string &s, unsigned int n, double p);
	Mybook_data(const Mybook_data &a);						//�������캯��
	Mybook_data& operator=(const Mybook_data &a);			//��ֵ����
	Mybook_data(Mybook_data &&a) noexcept;					//�ƶ����캯��
	Mybook_data& operator=(Mybook_data &&a) noexcept;		//�ƶ���ֵ����
	Mybook_data& operator=(const initializer_list<string> &il);//const�����ÿ��Խ�����ʱ������ֵ��  
	~Mybook_data();
	Mybook_data& operator+=(const Mybook_data &b);			//��Ա������+=��ߵĶ�����this
	string& operator[](size_t n) { return (*ptr)[n]; }		//[]����  ֻ�������������������Ա����
	const string& operator[](size_t n)const { return (*ptr)[n]; }	//const������������Ա����		���������ܵ���const�汾�ͱ����汾����const����ֻ�ܵ���const�汾
	Mybook_data& operator++();								//ǰ��++
	Mybook_data& operator--();								//ǰ��--
	Mybook_data operator++(int);							//����++  ǰ�úͺ��ò���������һ����ʹ�ò������������ǣ�����������ʹ��int�Ͳ�����ʾ����
	Mybook_data operator--(int);							//����--
	vector<string>& operator*() const;						//*���� ����ptr��ָ��
	vector<string>* operator->() const;						//->���� ��a->������vector<string>&
	string& operator()(size_t n) { return (*ptr)[n]; }				// a(2) ����(*ptr)[2]
	const string& operator()(size_t n) const { return (*ptr)[n]; }	//const������������Ա����
	void print(ostream & os) const;
	void insert(vector<string>::iterator j, vector<string>::iterator k) const;		//����һ��vector<string>������ֵ

private:
	shared_ptr<vector<string>> ptr;
	string bookNO;
	unsigned int units_sold;
	double revenus;
};

ostream& operator<<(ostream &os, const Mybook_data& a);
istream& operator >> (istream &is, Mybook_data &a);
Mybook_data operator+(const Mybook_data &a, const Mybook_data &b);
bool operator==(const Mybook_data &a, const Mybook_data &b);
bool operator!=(const Mybook_data &a, const Mybook_data &b);
bool operator<(const Mybook_data &a, const Mybook_data &b);	//<�ŵ�����,���������ʹ��<�Ƚ���ĵ���

#endif
