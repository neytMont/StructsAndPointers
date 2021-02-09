//Nathaniel Monte de Ramos
//CECS 282-07
//Program 3 - Structs and Pointers
//Oct 14, 2019
#include <iostream>
#include "student.h"
#include "studentList.h"
void menu(int choice, StudentList& studentList)
{
	switch (choice) 
	{
	case 1:
		studentList.displayByOriginalValues();
		break;
	case 2:
		studentList.displayByStudentId();
		break;
	case 3:
		studentList.displayByName();
		break;
	case 4:
		studentList.displayByGrade();
		break;
	case 5:
		studentList.displayByBirthDay();
		break;
	case 6:
		studentList.displayByHomeTown();
		break;
	case 7:
		cout << "Goodbye!" << endl;
		system("Pause");
		break;
	default:
		break;
	}
}
int displayMainMenu(StudentList& studentList)
{
	int choice;
	bool choiceIsInt = false;
	cout << "------------------------------------" << endl;
	cout << "\t\tMenu" << endl;
	cout << "------------------------------------" << endl;
	cout << "\n1) Display original list" << endl;
	cout << "2) Display list sorted by Student ID" << endl;
	cout << "3) Display list sorted by Name" << endl;
	cout << "4) Display list sorted by Grade" << endl;
	cout << "5) Display list sorted by Birthday" << endl;
	cout << "6) Display list sorted by HomeTown" << endl;
	cout << "7) Exit\n" << endl;
	cout << "------------------------------------" << endl;
	cout << "Choose menu option (1-7): " << endl;
	while (!choiceIsInt) 
	{
		choiceIsInt = true;
		cin >> choice;
		if (cin.fail() || choice > 7) {
			cin.clear();
			cin.ignore();
			cout << "Please enter an Integer (1-7) only: " << endl;
			choiceIsInt = false;
		}
	}
	cout << "------------------------------------" << endl << endl ;
	menu(choice, studentList);
	cout << endl;
	return choice;
}
int main()
{
	StudentList students;

	int choice = displayMainMenu(students);
	while (choice < 7)
	{
		choice = displayMainMenu(students);
	}
	return 0;
}