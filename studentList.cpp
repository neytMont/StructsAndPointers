#pragma warning(disable:4996)
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "studentlist.h"
using namespace std;
StudentList::StudentList()
{
    srand ( (unsigned) time(NULL) );
    createStudents(cecs282);
    for (int i = 0; i < 10; ++i) 
	{
        idPtr[i] = &cecs282[i];
        namePtr[i] = &cecs282[i];
        gradePtr[i] = &cecs282[i];
        birthdayPtr[i] = &cecs282[i];
        homeTownPtr[i] = &cecs282[i];
    }
    bubbleSortById(idPtr, 9);
    bubbleSortByName(namePtr, 9);
    bubbleSortByBirthDay(birthdayPtr, 9);
    bubbleSortByGrade(gradePtr, 9);
    bubbleSortByHomeTown(homeTownPtr, 9);
}
void StudentList::createStudents(Student students[])
{
    char sNames[10][15] = {"Luke Vader", "Tom Finger", "Coca Cola", "Alien Head", "Steve Ee", "Kobe Beef", "Tim Tin", "Java Rules", "Cplus plus"};
    string sHomeTowns[10] = {"Down Town", "At The Crossing", "Pallet Town", "Camelot","Los Angeles", "Nacipit", "Area 51", "Solomon's Castle", "Bikini Bottom"};
    int ids[10];
    createIds(ids);
    for (int i = 0; i < 10; i++) 
	{
        students[i].id = ids[i];
        strcpy(students[i].name, sNames[i]);
        students[i].bDay = createRandomBirthday();
        students[i].grade = createRandomGrade();
        students[i].homeTown = sHomeTowns[i];
    };
}
bool StudentList::contains(int ids[], int value)
{
    for(int i = 0; i < 10; i++)
	{
         if(ids[i] == value){
             return true;
         }
    }
    return false;
}
void StudentList::createIds(int ids[])
{
    for (int i = 0; i < 10; ++i) 
	{
		int x = 0;
		int y = 0;
		x = rand() % 9 + 1;
		for (int z = 1; z < 3; z++) 
		{
			x = x * 10 + rand() % 10;
		}
		for (int z = 0; z < 3; z++)
		{
			y = y * 10 + rand() % 10;
		}
		int randomNumber = x * 1000 + y;
        while(contains(ids, randomNumber))
		{
            randomNumber = x * 1000 + y;
        }
        ids[i]= randomNumber;
    }
}
MyDate StudentList::createRandomBirthday()
{
    int year;
    int month;
    int day;
    int j1 = MyDate::jD(1999, 1, 1);
    int j2 = MyDate::jD(2004,12, 31);
    int randomJd = j1 + ( rand() % ( j2 - j1 + 1 ) );
    MyDate::gDate(randomJd, year, month, day);
    MyDate result = MyDate(month, day, year);
    return result;
}
char StudentList::createRandomGrade()
{
    char const grades[6] = "ABCDF";
    return grades[rand() % 4];
}
void StudentList::displayByHomeTown()
{
	cout << left << setw(20) << "Student ID";
	cout << left << setw(20) << "Name";
	cout << left << setw(20) << "Grade";
	cout << left << setw(30) << "Birthday";
	cout << left << setw(20) << "Home Town" << endl << endl;
	for (int j = 0; j < 9; ++j) 
	{
		cout << left << setw(20) << homeTownPtr[j]->id;
		cout << left << setw(20) << homeTownPtr[j]->name;
		cout << left << setw(20) << homeTownPtr[j]->grade;
		cout << left << setw(30) << homeTownPtr[j]->bDay.getValue();
		cout << left << setw(20) << homeTownPtr[j]->homeTown << endl;
	}
}
void StudentList::displayByGrade()
{
	cout << left << setw(20) << "Student ID";
	cout << left << setw(20) << "Name";
	cout << left << setw(20) << "Grade";
	cout << left << setw(30) << "Birthday";
	cout << left << setw(20) << "Home Town" << endl << endl;
	for (int j = 0; j < 9; ++j)
	{
		cout << left << setw(20) << gradePtr[j]->id;
		cout << left << setw(20) << gradePtr[j]->name;
		cout << left << setw(20) << gradePtr[j]->grade;
		cout << left << setw(30) << gradePtr[j]->bDay.getValue();
		cout << left << setw(20) << gradePtr[j]->homeTown << endl;
	}
}
void StudentList::displayByBirthDay()
{
	cout << left << setw(20) << "Student ID";
	cout << left << setw(20) << "Name";
	cout << left << setw(20) << "Grade";
	cout << left << setw(30) << "Birthday";
	cout << left << setw(20) << "Home Town" << endl << endl;
	for (int j = 0; j < 9; ++j) 
	{
		cout << left << setw(20) << birthdayPtr[j]->id;
		cout << left << setw(20) << birthdayPtr[j]->name;
		cout << left << setw(20) << birthdayPtr[j]->grade;
		cout << left << setw(30) << birthdayPtr[j]->bDay.getValue();
		cout << left << setw(20) << birthdayPtr[j]->homeTown << endl;
	}
}
void StudentList::displayByName()
{
	cout << left << setw(20) << "Student ID";
	cout << left << setw(20) << "Name";
	cout << left << setw(20) << "Grade";
	cout << left << setw(30) << "Birthday";
	cout << left << setw(20) << "Home Town" << endl << endl;
	for (int j = 0; j < 9; ++j)
	{
		cout << left << setw(20) << namePtr[j]->id;
		cout << left << setw(20) << namePtr[j]->name;
		cout << left << setw(20) << namePtr[j]->grade;
		cout << left << setw(30) << namePtr[j]->bDay.getValue();
		cout << left << setw(20) << namePtr[j]->homeTown << endl;
	}
}
void StudentList::displayByStudentId()
{
	cout << left << setw(20) << "Student ID";
	cout << left << setw(20) << "Name";
	cout << left << setw(20) << "Grade";
	cout << left << setw(30) << "Birthday";
	cout << left << setw(20) << "Home Town" << endl << endl;
	for (int j = 0; j < 9; ++j)
	{
		cout << left << setw(20) << idPtr[j]->id;
		cout << left << setw(20) << idPtr[j]->name;
		cout << left << setw(20) << idPtr[j]->grade;
		cout << left << setw(30) << idPtr[j]->bDay.getValue();
		cout << left << setw(20) << idPtr[j]->homeTown << endl;
	}
}
void StudentList::displayByOriginalValues()
{
	cout << left << setw(20) << "Student ID";
	cout << left << setw(20) << "Name";
	cout << left << setw(20) << "Grade";
	cout << left << setw(30) << "Birthday";
	cout << left << setw(20) << "Home Town" << endl << endl;
	for (int j = 0; j < 9; ++j)
	{
		cout << left << setw(20) << cecs282[j].id;
		cout << left << setw(20) << cecs282[j].name;
		cout << left << setw(20) << cecs282[j].grade;
		cout << left << setw(30) << cecs282[j].bDay.getValue();
		cout << left << setw(20) << cecs282[j].homeTown << endl;
	}
}
//swap function for the bubble sorts
void StudentList::swap(Student **x, Student **y)
{
    Student *temp = *x;
    *x = *y;
    *y = temp;
}
//sorts the randomly generated ID numerically
void StudentList::bubbleSortById( Student *values[9], int length )
{
	// iterate over the while array beginning at the 1st element
	for(int i = 0; i < length; i++ )
	{
		// iterate over the while array beginning at the last element, looking for the lowest item
		for(int j = length - 1; j > i; j-- )
		{
			// checks if element is smaller as the previous one
			if( values[j]->id < values[j - 1]->id )
			{
				// swap references
				this->swap(&values[j], &values[j-1]);
			}
		}
	}
}
//sorts the names on the list alphabetically
void StudentList::bubbleSortByName( Student *values[9], int length )
{
	// iterate over the while array beginning at the 1st element
	for(int i = 0; i < length; i++ )
	{
		// iterate over the while array beginning at the last element, looking for the lowest item
		for(int j = length - 1; j > i; j-- )
		{
			//using strcmp to compare the value of the names
			if( strcmp (values[j]->name, values[j-1]->name) < 0)
			{
				//swap the names
				this->swap(&values[j], &values[j-1]);
			}
		}
	}
}
//sorts by birthday 
void StudentList::bubbleSortByBirthDay( Student *values[9], int length )
{
	for(int i = 0; i < length; i++ )
	{
		for(int j = length - 1; j > i; j-- )
		{
			int j1 = values[j]->bDay.toJd();
			int j2 = values[j-1]->bDay.toJd();
			if( j1 < j2)
			{
				this->swap(&values[j], &values[j-1]);
			}
		}
	}
}
//sorts by grades from A to F
void StudentList::bubbleSortByGrade( Student *values[9], int length )
{
	for(int i = 0; i < length; i++ )
	{
		for(int j = length - 1; j > i; j-- )
		{
			if(values[j]->grade < values[j-1]->grade)
			{
				this->swap(&values[j], &values[j-1]);
			}
		}
	}
}
//sorts by home town alphabetically
void StudentList::bubbleSortByHomeTown( Student *values[9], int length )
{
	for(int i = 0; i < length; i++ )
	{
		for(int j = length - 1; j > i; j-- )
		{
			if(values[j]->homeTown < values[j-1]->homeTown)
			{
			this->swap(&values[j], &values[j-1]);
			}
		}
	}
}