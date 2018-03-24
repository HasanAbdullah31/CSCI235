/* Hasan Abdullah: Date.cpp - implementation of class Date */

#include <iostream>
#include <cstdlib>
#include "Date.h"
using namespace std;

Date::Date() {month=1; day=1; year=2017; date="01-01-2017";}
Date::Date(string d) {
  if (d.size()!=10 || d[2]!='-' || d[5]!='-') {
    cout<<"Invalid format for date!"<<endl;
    exit(1);
  }
  string input_month="";
  if (d[0]!='0') input_month+=d[0];
  input_month+=d[1];
  month=stoi(input_month);
  if (month>12 || month<1) {
    cout<<"Invalid month!"<<endl;
    exit(1);
  }
  string input_day="";
  if (d[3]!='0') input_day+=d[3];
  input_day+=d[4];
  day=stoi(input_day);
  if (day>31 || day<1) {
    //more precise to check days AND month (Feb. can't have 31 days); but lazy
    cout<<"Invalid day!"<<endl;
    exit(1);
  }
  string input_year="";
  input_year+=d.substr(6,4);   //substr(startpos,length)
  year=stoi(input_year);
  date=d;
}

usi Date::getMonth()   { return month; }
usi Date::getDay()     { return day;   }
usi Date::getYear()    { return year;  }
string Date::getDate() { return date;  }

Date& Date::operator++() {   //prefix (++date)
  if (month==12 && day==31) {
    month=1; day=1; year=year+1;
    date="01-01-"+to_string(year);
  }
  else if ( day==31 && (month==1 || month==3 || month==5 ||
	                month==7 || month==8 || month==10) ) {
    month=month+1; day=1; date="";   //year stays the same
    if (month<10) date+="0";
    date+=to_string(month); date+="-01-"; date+=to_string(year);
  }
  else if ( day==30 && (month==4 || month==6 ||
			month==9 || month==11) ) {
    month=month+1; day=1; date="";   //same code as above
    if (month<10) date+="0";
    date+=to_string(month); date+="-01-"; date+=to_string(year);
  }
  else if (month==2 && day==28) {   //does not take into account leap year
    month=3; day=1; date="03-01-"; date+=to_string(year);
  }
  else {
    day=day+1; string temp=to_string(day); if (temp.length()==1) temp="0"+temp;
    date=date.substr(0,3)+temp+date.substr(5,5);   //substr(startpos,length)
  }
  return *this;
}
Date Date::operator++(int) {   //postfix (date++)
  Date result(*this);   //result is a copy of current Date object
  operator++();   //use prefix ++, implemented above
  return result;
}
Date Date::operator+=(int x) {
  Date result(*this);
  for (int i=0; i<x; i++)
    operator++();
  return result;
}
Date& Date::operator--() {   //prefix (--date); similar code as the ++()
  if (month==1 && day==1) {
    month=12; day=31; year=year-1;
    date="12-31-"+to_string(year);
  }
  else if ( day==1 && (month==2 || month==4 || month==6 ||
	               month==8 || month==9 || month==11) ) {
    month=month-1; day=31; date="";   //year stays the same
    if (month<10) date+="0";
    date+=to_string(month); date+="-31-"; date+=to_string(year);
  }
  else if ( day==1 && (month==5  || month==7 ||
		       month==10 || month==12) ) {
    month=month-1; day=30; date=""; //almost same code as above, but day=30 here
    if (month<10) date+="0";
    date+=to_string(month); date+="-30-"; date+=to_string(year);
  }
  else if (day==1 && month==3) {   //does not take into account leap year
    month=2; day=28; date="02-28-"; date+=to_string(year);
  }
  else {
    day=day-1; string temp=to_string(day); if (temp.length()==1) temp="0"+temp;
    date=date.substr(0,3)+temp+date.substr(5,5);   //substr(startpos,length)
  }
  return *this;
}
Date Date::operator--(int) {   //postfix (date--)
  Date result(*this);   //result is a copy of current Date object
  operator--();   //use prefix --, implemented above
  return result;
}
Date Date::operator-=(int x) {
  Date result(*this);
  for (int i=0; i<x; i++)
    operator--();
  return result;
}
/* Friend overloaded operators: */
Date operator+(Date d, int x) {   //e.g. cout<<d+5<<endl; (original d unchanged)
  for (int i=0; i<x; i++)
    d++;   //use post ++
  return d;   //original d is NOT changed, since we did pass by value
}
Date operator-(Date d, int x) {   //e.g. cout<<d-5<<endl; (original d unchanged)
  for (int i=0; i<x; i++)
    d--;   //use post --
  return d;   //original d is NOT changed, since we did pass by value
}

bool operator<(Date a, Date b) {
  if (a.year<b.year)
    return true;
  else if (a.year==b.year) {
    if (a.month<b.month)
      return true;
    else if (a.month==b.month) {
      if (a.day<b.day)
	return true;
      else
	return false;
    }
    else   //if a.month>b.month
      return false;
  }
  else   //if a.year>b.year
    return false;
}
bool operator>(Date a, Date b) {
  return !(a<=b);
}
bool operator==(Date a, Date b) {
  if (a.month==b.month && a.day==b.day && a.year==b.year)
    return true;
  else
    return false;
}
bool operator!=(Date a, Date b) {
  return !(a==b);
}
bool operator<=(Date a, Date b) {
  return (a<b || a==b);
}
bool operator>=(Date a, Date b) {
  return (a>b || a==b);
}

ostream &operator<<(ostream &output, const Date &d) {
  return output<<d.date;
}
