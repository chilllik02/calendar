#include <locale.h>
#include <iostream>
#include <ctime>
#include <random>
using namespace std;

int FirstDayWeek(int month1, int year1)
{
    time_t now = time(0);
    tm* nowLocal = localtime(&now);
    tm tm1{};
    tm1.tm_year = year1 - 1900;
    tm1.tm_mon = month1 - 1;
    tm1.tm_mday = 1;
    time_t t = mktime(&tm1);
    tm* date = localtime(&t);
    return date->tm_wday;  
}

void print_monthyear(int month1,int year1)
{
    time_t now = time(0);
    tm* nowLocal = localtime(&now);
    tm tm1{};
    tm1.tm_year = year1 - 1900;
    tm1.tm_mon = month1 - 1;
    time_t t = mktime(&tm1);
    tm* date = localtime(&t);

    string month;
    switch (month1-1)
    {
    case 0:
        month = "January";
        break;
    case 1:
        month = "February";
        break;
    case 2:
        month = "March";
        break;
    case 3:
        month = "April";
        break;
    case 4:
        month = "May";
        break;
    case 5:
        month = "June";
        break;
    case 6:
        month = "July";
        break;
    case 7:
        month = "August";
        break;
    case 8:
        month = "September";
        break;
    case 9:
        month = "October";
        break;
    case 10:
        month = "November";
        break;
    case 11:
        month = "December";
        break;

    default:
        break;
    }
    cout << month << "\t" <<(date->tm_year + 1900) << endl;
}





int main()
{
    setlocale(LC_ALL, "ru");

    unsigned rows = 6;
    unsigned cols = 7;

    int year1;
    cout << "Введите год : ";
    cin >> year1;
    int month1;
    cout << "Введите месяц : ";
    cin >> month1;
    print_monthyear(month1,year1);
    
    string* daysofweek{ new string[7]{"\x1b[31mВс\x1b[0m","Пн","Вт","Cр","Чт","Пт","\x1b[31mСб\x1b[0m"}};
    int counter = 1;
    const int end_day = 31;

    const int first_dayweek = FirstDayWeek(month1, year1);

    int** numbers{ new int* [rows] {} };
    for (unsigned i{}; i < rows; i++)
    {
        numbers[i] = new int[cols] {};
        
    }

    for (unsigned i{}; i < rows; i++)
    {
        for (unsigned j{}; j < cols; j++)
        {
            if (i == 0)
            {
                if (j >= first_dayweek)
                {
                    numbers[i][j] = counter++;
                }
                
            }
            
            

            else
            {
                if (counter <= end_day)
                {
                    numbers[i][j] = counter++;
                }
            }
        }
        
    }

    for (unsigned i{}; i < 7; i++)
    {
        cout << daysofweek[i] << "\t";
    }
    cout << endl;
    for (unsigned i{}; i < rows; i++)
    {
        for (unsigned j{}; j < cols; j++)
        {
            cout << numbers[i][j] << "\t";
        }
        cout << endl;
    }

    
}

