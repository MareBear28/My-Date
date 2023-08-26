#include "myDate.h" // X-code users change this to myDate.hpp
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cstdio>
using namespace std;

struct Student {
	char name[10];
	int SID;
	char grade;
	myDate birthday;
	string homeTown;
};

Student* createStudent(string name, int id, char grade, myDate bday, string ht) 
{
	struct Student* s = new Student;
	strcpy_s(s->name, name.c_str());
	s->SID = id;
	s->grade = grade;
	s->birthday = bday;
	s->homeTown = ht;
	return s;
}
void display(Student* myClass[]) 
{
	cout << setw(23) << left << "\033[4mName\033[0m";
	cout << setw(23) << left << "\033[4mStudent ID\033[0m";
	cout << setw(18) << left << "\033[4mGrade\033[0m";
	cout << setw(28) << left << "\033[4mBirthday\033[0m";
	cout << setw(28) << left << "\033[4mHome Town\033[0m" << endl;
	for (int i = 0; i < 10; i++) 
	{
		cout << setw(15) << left << myClass[i]->name ;
		cout << setw(15) << left << myClass[i]->SID ;
		cout << setw(10) << left << myClass[i]->grade ;
		cout << setw(20) ;
		myClass[i]->birthday.display();
		cout << setw(20) << left << myClass[i]->homeTown << endl;
	}
	cout << endl;
}

void sortAlph (Student* myclass[], string by)
{
	for (int i = 0; i < 10; i++) 
	{
		Student* s1 = myclass[i];
		for (int j = i+1; j < 10; j++) 
		{
			Student* s2 = myclass[j];
			if (strcmp(s1->name, s2->name) > 0 && by == "name")
			{
				Student temp = *s1;
				*myclass[i] = *s2;
				*myclass[j] = temp;
			}
			else if (strcmp(s1->homeTown.c_str(), s2->homeTown.c_str()) > 0 && by == "ht")
			{
				Student temp = *s1;
				*myclass[i] = *s2;
				*myclass[j] = temp;
			}
		}
	}
}

void sortID(Student* myclass[])
{
	
	for (int i = 0; i < 10; i++)
	{
		Student* s1 = myclass[i];
		for (int j = i + 1; j < 10; j++)
		{
			Student* s2 = myclass[j];
			if (s1->SID > s2->SID)
			{
				Student temp = *s1;
				*myclass[i] = *s2;
				*myclass[j] = temp;
			}
		}
	}
}

void sortGrade(Student* myclass[])
{

	for (int i = 0; i < 10; i++)
	{
		Student* s1 = myclass[i];
		for (int j = i + 1; j < 10; j++)
		{
			Student* s2 = myclass[j];
			if (s1->grade > s2->grade)
			{
				Student temp = *s1;
				*myclass[i] = *s2;
				*myclass[j] = temp;
			}
		}
	}
}



void sortBD(Student* myclass[])
{
	for (int i = 0; i < 10; i++)
	{
		Student* s1 = myclass[i];
		for (int j = i + 1; j < 10; j++)
		{
			Student* s2 = myclass[j];
			if (s1->birthday.getYear() > s2->birthday.getYear())
			{
				Student temp = *s1;
				*myclass[i] = *s2;
				*myclass[j] = temp;
			}
			else if (s1->birthday.getYear() == s2->birthday.getYear() && s1->birthday.dayOfYear() < s2->birthday.dayOfYear()) {
				Student temp = *s1;
				*myclass[i] = *s2;
				*myclass[j] = temp;
			}
		}
	}
}

void menu() {
	cout << "1) Display list sorted by Name" << endl;
	cout << "2) Display list sorted by Student ID" << endl;
	cout << "3) Display list sorted by Grade" << endl;
	cout << "4) Display list sorted by Birthday" << endl;
	cout << "5) Display list sorted by Home Town" << endl;
	cout << "6) Exit" << endl;
}

int main()
{
	Student* myClass[10];
	
	char grades[5] = { 'A', 'B', 'C', 'D', 'F' };
	int SID[10];
	string names[10] = {"Cayde-6", "Hibana", "Sova", "Aphelios", "Rosaria", "Valkyrie", "Rozzi", "Claptrap", "Erwin", "Palutena"};
	string ht[10] = {"Tower", "Nagoya", "Icebox", "Summoner's Rift", "Mondstadt", "Angelia", "Corda D’arco", "Sanctuary", "Grasscover Camp", "Skyworld"};
	srand(time(NULL));
	for (int i = 0; i < 10; i++) 
	{
		int num = rand() % 5;
		int month = (rand() % 12) + 1;
		int day = (rand() % 31) + 1;
		int year = (rand() % 24) + 2000;
		myDate bday(month, day, year);
		bool check = true;
		int sid = 0;
		while (check) {
			sid = (rand() % 899) + 100;
			check = find(begin(SID), end(SID), sid) != end(SID);
			SID[i] = sid;
		}
		myClass[i] = createStudent(names[i], sid, grades[num], bday, ht[i]);
	}
	int choice = 0;
	while (choice != 6) 
	{
		menu();
		cin >> choice;
		cout << endl;
		if (choice == 1) {
			sortAlph(myClass, "name");
			display(myClass);
		}
		else if (choice == 2) {
			sortID(myClass);
			display(myClass);
		}
		else if (choice == 3) {
			sortGrade(myClass);
			display(myClass);
		}
		else if (choice == 4) {
			sortBD(myClass);
			display(myClass);
		}
		else if (choice == 5) {
			sortAlph(myClass, "ht");
			display(myClass);
		}
	}
	
}
