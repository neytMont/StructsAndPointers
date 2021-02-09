#pragma once
#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "student.h"
class StudentList
{
public:
	StudentList();
	void displayByStudentId();
	void displayByName();
	void displayByOriginalValues();
	void displayByBirthDay();
	void displayByGrade();
	void displayByHomeTown();
private:
	Student cecs282[10];
	Student* idPtr[10];
	Student* namePtr[10];
	Student* gradePtr[10];
	Student* homeTownPtr[10];
	Student* birthdayPtr[10];
	void createStudents(Student students[]);
	void createIds(int ids[]);
	void swap(Student** x, Student** y);
	void bubbleSortById(Student* values[9], int length);
	void bubbleSortByName(Student* values[9], int length);
	void bubbleSortByBirthDay(Student* values[9], int length);
	void bubbleSortByGrade(Student* values[9], int length);
	void bubbleSortByHomeTown(Student* values[9], int length);
	bool contains(int ids[], int value);
	char createRandomGrade();
	MyDate createRandomBirthday();
};
#endif