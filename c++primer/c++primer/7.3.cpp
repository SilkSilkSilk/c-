#include "7.3.h"

Screen::Screen( pos ht, pos wd, char c ) : height(ht), width(wd), contents(ht * wd, c)
{
}

Screen::Screen( string a )
{
}

char Screen::get() const
{
	return contents[cursor];
}

char Screen::get( pos ht, pos wd ) const
{
	access_ctr = 1; //可变声明
	pos row = ht * width + wd;
	return contents[row];
}

Screen& Screen::move( pos r, pos c )
{
	cursor = r * width + c;
	return *this;
}

uint16_t ab = 0; //类作用域之外的ab

Screen& Screen::set( char c )
{
	int cursor = 0; //成员函数作用域中可以出现同名，并且替换
	contents[cursor] = c; //cursor是局部int
	contents[Screen::cursor] = c; //cursor用作用域符指定Screen类中变量

	int ab = 0;
	contents[ab] = c; //ab是局部int
	contents[::ab] = c; //ab是全局uint16_t的
	return *this;
}

Screen& Screen::set( pos w, pos h, char c )
{
	contents[w * width + h] = c;
	return *this;
}

Screen& Screen::display( ostream &os )
{
	do_display(os);
	return *this;
}

const Screen& Screen::display( ostream &os ) const //对象是const就调用这个版本的display
{
	do_display(os);
	return *this;
}

void Screen::aaaa( Window_mgr &wind )
{
	cout << "aaaa test" << endl;
	wind.screens[0].set(5, 10, '9').display(cout);
}

Screen::~Screen()
{
}

void Screen::do_display( ostream &os ) const
{
	uint16_t i, j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			os << contents[i * width + j];
		}
		os << endl;
	}
}


Window_mgr::Window_mgr()
{
}

void Window_mgr::clear( index i )
{
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' '); //能够访问Screen的private区域
}

Window_mgr::~Window_mgr()
{
}
