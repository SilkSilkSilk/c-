#ifndef _7CHAPTER3_H__
#define _7CHAPTER3_H__


#include <iostream>
#include <vector>
#include <cstring>
#include "string"
#include <stdint.h>


using namespace std;

//int cursor;										//错误，类中定义的名字在整个内层作用域和外层作用域中都是独一无二的

class Screen
{
	friend class Window_mgr; //Window_mgr是Screen的友元类
public:
	typedef uint32_t pos;

	Screen() = default;
	Screen( pos ht, pos wd, char c = ' ' );
	explicit Screen( string );
	char get() const;
	inline char get( pos ht, pos wd ) const; //成员函数是自动内联的
	Screen& move( pos r, pos c );
	Screen& set( char );
	Screen& set( pos, pos, char );
	Screen& display( ostream &os );
	const Screen& display( ostream &os ) const;
	void aaaa( Window_mgr &wind ); //aaaa函数在Screen类中是成员函数，需要使用Window_mgr的私有变量则在Window_mgr类中声明为友元
	~Screen();


private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	string contents;
	mutable pos access_ctr; //可变声明，即使是const函数也能改变它

	void do_display( ostream &os ) const;
};


class Window_mgr
{
	friend void Screen::aaaa( Window_mgr &wind ); //Screen类中成员函数aaaa需要使用Window_mgr的私有变量则在Window_mgr类中声明为友元
public:
	using index = uint32_t;
	Window_mgr();
	void clear( index );
	~Window_mgr();

private:
	vector < Screen > screens{Screen(10, 20, ' ')};
};


class a; //不完全类型


#endif
