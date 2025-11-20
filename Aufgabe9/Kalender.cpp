#include<iostream>
using namespace std;

class Date {
	
	int _day, _month, _year;

public:
	Date(int day = 0, int month = 0, int year = 0):_day{day}, _month{month}, _year{year}
    {

    };
	Date operator+(int days){
        Date new_date;
        new_date._day = _day + days;
        if(new_date._day > 30){
            new_date._month += new_date._day / 30;
            int temp = new_date._day % 30;
            if(temp == 0){
                temp++;
            }
            new_date._day = temp;
        }
        new_date._month += _month;
        if(new_date._month > 12){
            new_date._year += new_date._month / 12;
            int temp = new_date._month % 12;
            if(temp == 0){
                temp++;
            }
            new_date._month = temp;
        }
        new_date._year += _year;

        return new_date;
    };
	friend ostream & operator<<(ostream & text, const Date & datum);
};

ostream & operator<<(ostream & text, const Date & datum){
    return text << datum._day << "." << datum._month << "." << datum._year;
}

int main(int argc, char *argv[])
{
    Date begin_task = Date(26,10,2023);
    cout << "Die Aufgabe beginnt am " << begin_task << endl;
    Date end_task = begin_task + 6;
    cout << "Die Aufgabe endet am " << end_task << endl;
    Date one_year_and_one_month_later = begin_task + 390;
    cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
    Date three_years_and_eleven_months_later = begin_task + 1410;
    cout << "Drei Jahre und 11 Monate nach Aufgabenbeginn ist der " << three_years_and_eleven_months_later << endl;
}

