#ifndef myDate_h
#define myDate_h
#include <string>
using namespace std;
#include <iostream>

class myDate
{
	private:
		int month;
		int day;
		int year;
		string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		string week[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	public:
		myDate();
		myDate(int, int, int);
		void display();
		void increaseDate(int);
		void decreaseDate(int);
		int daysBetween(myDate);
		int getMonth();
		int getDay();
		int getYear();
		int dayOfYear();
		string dayName();
};
#endif