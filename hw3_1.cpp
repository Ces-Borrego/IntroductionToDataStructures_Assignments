/*
* Title: hw3-1.cpp
* Abstract:Program defines and uses two classes: Course and Student.
* Author: Cesar Borrego 
* Email: ceborrego@csumb.edu
* Estimate: 4 hours
* Date: 2/6/2020
*/


#include <iostream>
using namespace std;

class student {
	public:
		student();
		student(string name, int x);
		string getName() const;
		int getId() const;
		void setName(string name);
	private:
		string myName;
		int myId;
};

class course {
	public:
		course();
		course(string name, int num, string a);
		string getTitle() const;
		int getNumber() const;
		string getTeacherName() const;
		bool add(student s);
		bool remove(student s);
		void printAll() const;
	private:
		string title;
		int number;
		string instructorName;
		student myRoster[30];
		int cSize;
};

int main() {
	/*
  course c1("Intro to Everything", 1234, "Dr.Gross");
	student James("James", 19);
	student Alice("Alice", 20);
	student Bob("Bob", 21);
	student Josh("Josh", 22);
	student Trinidad("Trinidad", 23);

	c1.add(James);
	c1.add(Josh);

	c1.printAll();
	*/
	course c1("Intro to Everything", 123, "Dr. Gross");
	student s1("Jane", 1234);
	student s2("Phillipe", 1235);
	student s3("Lu", 1236);
	student s4("Enrique", 1237);
	c1.add(s1);
	c1.add(s2);
	c1.add(s3);
	c1.add(s4);
	c1.printAll();
	c1.remove(s2);
	c1.printAll();
}

course::course(): title(" "), number(0), instructorName(" "){}

course::course(string name, int num, string a): title(name), number(num), instructorName(a){}

string course::getTitle() const{
	return title;
}

int course::getNumber() const{
	return number;
}

string course::getTeacherName() const{
	return instructorName;
}

bool course::add(student s){
	if(cSize==30) return false;
	else {
		for(int x = 0; x < cSize; x++){
			if(myRoster[x].getId()==s.getId()) return false;
		}
		myRoster[cSize] = s;
		cSize++;
		return true;
	}
}

bool course::remove(student s){
	if(cSize==0){
		return false;
	} else {
		for(int x = 0; x < cSize; x++){
			if(s.getId()== myRoster[x].getId()){
				for(int y = x; y < cSize; y++){
					myRoster[y] = myRoster[y+1];
				}
				cSize--;
				return true;
			} else return false;
		}
	}
}

void course::printAll() const{
	cout<<"Course Title: "<<title<<endl;
	cout<<"Course number: "<<number<<endl;
	cout<<"Instructor: "<<instructorName<<endl;
	cout<<"Enrollment: "<<cSize<<endl;
	for(int x = 0; x < cSize; x++){
		cout<<"\t"<<myRoster[x].getName()<<": "<<myRoster[x].getId()<<endl;
	}
	cout<<endl;
}

student::student(): myName(" "), myId(0) {}

student::student(string name, int x){
	myName = name;
	myId = x;
}

string student::getName() const{
	return myName;
}

int student::getId() const{
	return myId;
}

void student::setName(string name){
	myName = name;
}