
#include <string>
using namespace std;
#include <iostream>
#include <cmath>
#include "myDate.h"

int Greg2Julian(int m, int d, int y) 
{
	int I = y;
	int J = m;
	int K = d;

	int JD = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;

	return JD;
}

void Julian2Greg(int JD, int& m, int& d, int& y) 
{
	int I = 0;
	int J = 0;
	int K = 0;
	int L = JD + 68569;
	int N = 4 * L / 146097;
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
}

bool isLeap(int y) 
{
	if (y % 4 == 0) 
	{
		if (y % 100 == 0) 
		{
			if (y % 400 == 0) 
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
		else 
		{
			return true;
		}
	}
	else 
	{
		return false;
	}
}

myDate::myDate()
{
	month = 5;
	day = 11;
	year = 1959;
}

myDate::myDate(int m, int d, int y)
{
	if (isLeap(y) && m == 2 && d > 29)
	{
		month = 5;
		day = 11;
		year = 1959;
	}
	else if ((m < 1) || (m > 12) || (d < 1) || (d > days[m - 1]) || (y < -4712))
	{
		month = 5;
		day = 11;
		year = 1959;
	}
	else 
	{
		month = m;
		day = d;
		year = y;
	}
}

void myDate::display() 
{
	//cout << left; convert integer to string to make everything in the line below, one string
	cout << months[month - 1] + " " + to_string(day) + ", " + to_string(year);
}

void myDate::increaseDate(int num) 
{
	int JD = Greg2Julian(month, day, year) + num;
	Julian2Greg(JD, month, day, year);
}

void myDate::decreaseDate(int num) 
{
	int JD = Greg2Julian(month, day, year) - num;
	Julian2Greg(JD, month, day, year);
}

int myDate::daysBetween(myDate d) 
{
	int JD_this = Greg2Julian(month, day, year);
	int JD_other = Greg2Julian(d.month, d.day, d.year);
	return abs(JD_this - JD_other);
}

int myDate::getMonth()
{
	return month;
}

int myDate::getDay()
{
	return day;
}

int myDate::getYear()
{
	return year;
}

int myDate::dayOfYear()
{
	int start = Greg2Julian(1, 1, year);
	int end = Greg2Julian(month, day, year);
	return end - start + 1;
}

string myDate::dayName() 
{
	int JD = Greg2Julian(month, day, year);
	int d = JD % 7;
	return week[d];

}
