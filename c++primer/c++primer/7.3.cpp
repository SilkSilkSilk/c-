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
	access_ctr = 1; //�ɱ�����
	pos row = ht * width + wd;
	return contents[row];
}

Screen& Screen::move( pos r, pos c )
{
	cursor = r * width + c;
	return *this;
}

uint16_t ab = 0; //��������֮���ab

Screen& Screen::set( char c )
{
	int cursor = 0; //��Ա�����������п��Գ���ͬ���������滻
	contents[cursor] = c; //cursor�Ǿֲ�int
	contents[Screen::cursor] = c; //cursor���������ָ��Screen���б���

	int ab = 0;
	contents[ab] = c; //ab�Ǿֲ�int
	contents[::ab] = c; //ab��ȫ��uint16_t��
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

const Screen& Screen::display( ostream &os ) const //������const�͵�������汾��display
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
	s.contents = string(s.height * s.width, ' '); //�ܹ�����Screen��private����
}

Window_mgr::~Window_mgr()
{
}
