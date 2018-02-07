#ifndef _7CHAPTER3_H__
#define _7CHAPTER3_H__


#include <iostream>
#include <vector>
#include <cstring>
#include "string"
#include <stdint.h>


using namespace std;

//int cursor;										//�������ж���������������ڲ������������������ж��Ƕ�һ�޶���

class Screen
{
	friend class Window_mgr; //Window_mgr��Screen����Ԫ��
public:
	typedef uint32_t pos;

	Screen() = default;
	Screen( pos ht, pos wd, char c = ' ' );
	explicit Screen( string );
	char get() const;
	inline char get( pos ht, pos wd ) const; //��Ա�������Զ�������
	Screen& move( pos r, pos c );
	Screen& set( char );
	Screen& set( pos, pos, char );
	Screen& display( ostream &os );
	const Screen& display( ostream &os ) const;
	void aaaa( Window_mgr &wind ); //aaaa������Screen�����ǳ�Ա��������Ҫʹ��Window_mgr��˽�б�������Window_mgr��������Ϊ��Ԫ
	~Screen();


private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	string contents;
	mutable pos access_ctr; //�ɱ���������ʹ��const����Ҳ�ܸı���

	void do_display( ostream &os ) const;
};


class Window_mgr
{
	friend void Screen::aaaa( Window_mgr &wind ); //Screen���г�Ա����aaaa��Ҫʹ��Window_mgr��˽�б�������Window_mgr��������Ϊ��Ԫ
public:
	using index = uint32_t;
	Window_mgr();
	void clear( index );
	~Window_mgr();

private:
	vector < Screen > screens{Screen(10, 20, ' ')};
};


class a; //����ȫ����


#endif
