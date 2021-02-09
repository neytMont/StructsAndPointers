#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include "myDate.h"
struct Student {
	char name[11];
	char grade;
	int id;
	MyDate bDay;
	string homeTown;
};
#endif