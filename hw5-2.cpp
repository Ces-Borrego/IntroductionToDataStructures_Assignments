/* Title: hw5-2.cpp
* Abstract: create a program that contains a class Time and holds hours and minutes using military time.
* Author: Cesar Borrego
* Email: ceborregoc@csumb.edu 
* Estimate: 1 hour 
* Date: 1/29/2020
*/

#include <iostream>
#include <sstream>
using namespace std;

class Time{
	public:
		Time():hour(0), minute(0) {};
		Time(int hr, int min);
		int getHour() const{return hour;};
		int getMinute() const{return minute;};
		string getStandard() const;
		string getMilitary() const;
		const Time operator + (const Time & time2) const;
		friend ostream & operator<<(ostream & out, const Time & t);
	private:
		int hour;
		int minute;
};

ostream & operator<<(ostream & out, const Time & t){
	if(t.hour < 10){
		out<<0<<t.hour;
	} else if(t.hour == 24){
		out<<0<<0;
	} else out<<t.hour;

	if(t.minute < 10){
		out<<0<<t.minute;
	} else {
		out<<t.minute;
	}

	return out;
}

int main() {
  // Time a(6, 30);
	// Time b(14,45);
	// cout<<b.getStandard();
	// cout<<endl;

	// Time c = a + b;
	// cout<<c.getStandard()<<endl;
	// cout << c<<endl;
	// cout << b;
	Time t1(12, 55);
Time t2(24, 00);
Time t3(3, 45);
Time t4(22, 33);
cout << t1.getStandard() << " - " << t1 << endl;
cout << t2.getStandard() << " - " << t2 << endl;
cout << t3.getStandard() << " - " << t3 << endl;
cout << t4.getStandard() << " - " << t4 << endl;
Time t5 = t3 + t4;
cout << t5.getStandard() << " - " << t5 << endl;
}

Time::Time(int hr, int min){
	if(hr > 24 || hr < 0){
		hour = hr - 24;
	} else hour = hr;

	if(min > 60 || min < 0){
		minute = 0;
	} else minute = min;
}

string Time::getStandard() const{
	stringstream ss;
	string myTime;
	if(hour>=12){
		if(hour == 12) {
			ss<<(12)<<":";
			if(minute < 10) ss<<0<<minute<<"PM";
			else ss<<minute<<"PM";
		} else {
			ss<<(hour-12)<<":";
			if(minute < 10) ss<<0<<minute<<"AM";
			else ss<<minute<<"AM";
		}
	} else {
		ss<<(hour)<<":";
		if(minute < 10) ss<<0<<minute<<"AM";
		else ss<<minute<<"AM";
	}

	ss>>myTime;
	return myTime;
}

string Time::getMilitary() const{
	stringstream ss;
	string myTime;
	if(hour == 24) ss<<00;
	else if(hour < 10) ss<<0<<hour;
	else ss<<hour;

	if(minute < 10) ss<<0<<minute;
	else ss<<minute;

	ss>>myTime;
	return myTime;
}

Time const Time::operator + (const Time & b) const{
	int newHour = hour + b.getHour();
	if(newHour > 24) newHour = newHour - 24;
	int newMin = minute + b.getMinute();
	if(newMin > 60) {
		newHour++;
		newMin = newMin - 60;
	}

	return Time(newHour, newMin);
}

