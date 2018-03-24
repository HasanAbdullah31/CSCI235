/* Hasan Abdullah: Date.h - header file for class Date */

#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

typedef unsigned short int usi;

class Date {
private:
 usi month;
 usi day;
 usi year;
 string date;
public:
 Date();
 Date(string d);
 usi getMonth();
 usi getDay();
 usi getYear();
 string getDate();
 Date& operator++();    //prefix (++date)
 Date operator++(int); //postfix (date++)
 Date operator+=(int x);   //does postfix ++ x times
 Date& operator--();    //prefix (--date)
 Date operator--(int); //postfix (date--)
 Date operator-=(int x);   //does postfix -- x times
 friend Date operator+(Date d, int x); //returns Date that is x more days than d
 friend Date operator-(Date d, int x); //returns Date that is x less days than d
 friend bool operator<(Date a, Date b);
 friend bool operator>(Date a, Date b);
 friend bool operator==(Date a, Date b);
 friend bool operator!=(Date a, Date b);
 friend bool operator<=(Date a, Date b);
 friend bool operator>=(Date a, Date b);
 friend ostream &operator<<(ostream &output, const Date &d);
};

#endif /* DATE_H */
