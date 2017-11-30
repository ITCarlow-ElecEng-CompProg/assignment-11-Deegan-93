/** Tomorrows Date Calculator
 *  Exercise 11
 *  Luke Deegan
 *  09/10/17
 */

/** preprocessor directives */
#include <iostream>
#include <math.h>

using namespace std;

/** structure definition */
struct date
{
	int month;
	int day;
	int year;
};

/** Declare array for all month lengths */
int monthlength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/** Main Function */
int main()
{
    /** Declare the various iterations of the structure "date" */
    struct date today, tomorrow;

    cout << "\n\nPrograme to calculate tomorrow's date" << endl;

    /** do while loop to ensure a valid month is entered 8*/
    do
    {
        cout << "\n\nEnter current month (1-12): ";
        cin >> today.month;
    }
    while ((today.month <= 0)||(today.month > 12));

    /** do while loop to ensure correct day is enetered */
    do
    {
        cout << "\n\nEnter day (1 - 28/31): ";
        cin >> today.day;
    }
    while ((today.day <= 0)||(today.day > monthlength[today.month - 1]));

    cout << "\n\nEnter year: ";
    cin >> today.year;

	/** display today's date */
	cout << "\n\nToday's date is " << 	today.day << "/" << 	today.month << "/" << 	today.year << endl;


        /** If statement to check if it is a leap year */
    if(today.year % 4 == 0)
    {
        if(today.year % 100 == 0)
        {
            if(today.year % 400 == 0)
            {
                monthlength[1] = 29;
            }
        }
        else
        {
            monthlength[1] = 29;
        }
    }



    /** If statement to check if it is the end of the year,
        followed by a check to see if it is the end of the month */
    if (today.day >= monthlength[today.month - 1])
    {
        if (today.month == 12)
        {
            tomorrow.day = 1;
            tomorrow.month = 1;
            tomorrow.year = today.year + 1;
        }

        else
        {
            tomorrow.day = 1;
            tomorrow.month = today.month + 1;
            tomorrow.year = today.year;
        }
    }
    else
    {
        tomorrow.day = today.day +1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }

    /** display the result to the user */
	cout << "Tomorrows's date is " << 	tomorrow.day << "/" << 	tomorrow.month << "/" << 	tomorrow.year << endl;

    return 0;
}
