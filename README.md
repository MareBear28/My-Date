# Student List Sory using My-Date 🗓️
Using Julian and Gregorian Dates, MyDate class helps with sorting based on dates. In this example, myDate is used to help sort a list of students. From a list of students, we can sort a list based on:
- Name
- Student ID
- Grade
- Birthday
- Home Town

## About My-Date Class 💡
When creating a myDate object, there are 2 constructors that can be used:
- myDate() - This is a default constructor. This is will create a myDate object with the date May 5, 1959.
- myDate(int m, int d, int y) - This contructor will create a myDate object based on the 3 given integers that represents the month, the day, and the year.

Following creating a myDate object, the myDate object can acess several functions:
- display() - Displays the date in Month Day, Year format. (ex. May 5, 1959)
- increaseDate(int num) - Increases date by num days.
- decreaseDate(int num) - Decreases date by num days.
- daysBetween(myDate d) - Returns the number of days between this date compared to the given date. When the given date, d, is in the future then this function will return a positive number. When the given date is in the past, then this function will return a negative number. 
- getMonth() - Returns the month as an integer.
- getDay() - Returns the day as an integer.
- getYear() - Returns the year.
- dayOfYear() - Returns the day of the year this date is. (ex. Jan 1 is 1 and Feb 2 is 33)
- dayName() - Returns what day of the week this date is. (ex. Monday, Tuesday, etc.)
