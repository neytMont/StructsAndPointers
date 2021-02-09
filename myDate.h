#pragma once
#ifndef MYDATE_H
#define MYDATE_H
#include<iostream>
#include <string>
#include <sstream>
using namespace std;
class MyDate
{
private:
	int day;
	int month;
	int year;
	bool isValidDate(int y, int m, int d);
	string getMonthName(int m);
public:
	MyDate();
	MyDate(int m, int d, int y);
	void display();
	void incrDate(int n);
	void decrDate(int n);
	int daysBetween(MyDate d);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	string dayOfWeek();
	static void gDate(int jd, int& y, int& m, int& d);
	static int jD(int y, int m, int d);
	string getValue();
	int toJd();
};
#endif MYDATE_H