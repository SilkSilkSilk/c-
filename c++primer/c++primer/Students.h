#ifndef __STUDENTS_H__
#define __STUDENTS_H__


#include <string>


struct students
{
	std::string name;
	unsigned sold = 0; //struct类中可以给初始值的,不给初始值则默认初始化
	float revenue = 2.0;
};


#endif // __STUDENTS_H__
