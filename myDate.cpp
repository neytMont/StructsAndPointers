//Nathaniel Monte de Ramos
//CECS 282-07
//Program 2 - myDate Object
//Oct 2, 2019
#include "myDate.h"
int MyDate::jD(int y, int m, int d)//Gregorian to Julian conversion from prompt
{
	int I, J, K, jd;
	I = y;
	J = m;
	K = d;
	jd = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;
	return jd;
}
void MyDate::gDate(int jd, int& y, int& m, int& d)//Julian to Gregorian conversion from prompt
{
	int I, J, K, L, N;
	L = jd + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;
	y = I;
	m = J;
	d = K;
	return;
}
MyDate::MyDate()
{
	day = 11;
	month = 5;
	year = 1959;
}
MyDate::MyDate(int m, int d, int y)
{
	if (isValidDate(m, d, y)) {
		day = d;
		month = m;
		year = y;
	}
}
void MyDate::display()
{
	cout << getMonthName(month) << ' ' << getDay() << ", " << getYear();
}
//Iincrement the date by N days
void MyDate::incrDate(int n)
{
	int jd = jD(year, month, day);
	jd += n;
	gDate(jd, year, month, day);
}
//Decrement the date by N days
void MyDate::decrDate(int n)
{
	int jd = jD(year, month, day);
	jd -= n;
	gDate(jd, year, month, day);
}
//return the number of days between this date and the date D.
int MyDate::daysBetween(MyDate d)
{
	int jD1 = jD(year, month, day);
	int jD2 = jD(d.year, d.month, d.day);
	return jD2 - jD1;
}
//return the month in integer form
int MyDate::getMonth()
{
	return month;
}
//return the day of the month
int MyDate::getDay()
{
	return day;
}
//return the year
int MyDate::getYear()
{
	return year;
}
//return the number of days since the current year began. Example Jan 1 is 1, Feb 1 is 32
int MyDate::dayOfYear()
{
	int days = 0;
	MyDate temp(month, day, year);
	int jd = jD(temp.year, temp.month, temp.day);
	while (temp.year == year) 
	{
		jd--;
		temp.gDate(jd, temp.year, temp.month, temp.day);
		days++;
	}
	return days;
}
//returns Monday, Tuesday, etc according to the day of the week.
string MyDate::dayOfWeek()
{
	string dayName = "unknown";
	int jd = jD(year, month, day);
	int x = jd % 7;
	if (x == 0)
		return "Monday";
	else if (x == 1)
		return "Tuesday";
	else if (x == 2)
		return "Wednesday";
	else if (x == 3)
		return "Thursday";
	else if (x == 4)
		return "Friday";
	else if (x == 5)
		return "Saturday";
	else
		return "Sunday";
}
int MyDate::toJd()
{
	return MyDate::jD(year, month, day);
}
//return true or false if date is valid or not
bool MyDate::isValidDate(int m, int d, int y)
{
	bool validDay = false;
	bool validMonth = false;
	bool validYear = false;
	if (d >= 1 && d <= 31)validDay = true;
	if (m >= 1 && m <= 12)validMonth = true;
	if (y >= 1801 && y <= 2099) validYear = true;
	return validDay && validMonth && validYear;
}
//return the name of the month
string MyDate::getMonthName(int m)
{
	string result = "unknown";
	switch (m) {
	case 1:
		result = "January";
		break;
	case 2:
		result = "February";
		break;
	case 3:
		result = "March";
		break;
	case 4:
		result = "April";
		break;
	case 5:
		result = "May";
		break;
	case 6:
		result = "June";
		break;
	case 7:
		result = "July";
		break;
	case 8:
		result = "August";
		break;
	case 9:
		result = "September";
		break;
	case 10:
		result = "October";
		break;
	case 11:
		result = "November";
		break;
	case 12:
		result = "December";
		break;
	default:
		break;
	}
	return result;
}
string MyDate::getValue()
{
	ostringstream result;
	result << getMonthName(month) << ' ' << getDay() << ", " << getYear();
	return result.str();
}
