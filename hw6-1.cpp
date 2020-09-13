/*********************************************************
* A program to store grades and calculate GPA
* This version will need the Big 3:
* - Destructor
* - Copy constructor
* - Overloaded assignment operator
*********************************************************/#include <iostream>
#include<string>
using namespace std;
#include "GpaCalculator.h" // need this line!

GpaCalculator::GpaCalculator(){
	myCourseCount = 0;
	myCoursesEntered = 0;
	myCredits = new int[0];
	myGradePoints = new double[0];
}

GpaCalculator::GpaCalculator(int courseCount){
	myCourseCount = courseCount;
	myCoursesEntered = 0;
	myCredits = new int[courseCount];
	myGradePoints = new double[courseCount];
}

void GpaCalculator::addCourse(int credits, string grade){
	myCredits[myCoursesEntered] = credits;
	
	if(grade == "A+"){
		myGradePoints[myCoursesEntered] = 4.0;
	} else if (grade == "A-"){
		myGradePoints [myCoursesEntered] = 3.7;
	} else if (grade == "B+"){
		myGradePoints [myCoursesEntered] = 3.3;
	} else if (grade == "B-"){
		myGradePoints [myCoursesEntered] = 2.7;
	} else if (grade == "C+"){
		myGradePoints [myCoursesEntered] = 2.3;
	} else if (grade == "C-"){
		myGradePoints [myCoursesEntered] = 1.7;
	} else if (grade == "D"){
		myGradePoints [myCoursesEntered] = 1.0;
	} else if (grade == "F"){
		myGradePoints [myCoursesEntered] = 0.0;
	} 

	myCoursesEntered++;
}

double GpaCalculator::getTotalGradePoints(){
	for(int x = 0; x < myCourseCount; x++){

	}
}

double GpaCalculator::getGradePoints(string grade) {
    for (int i = 0; i < SIZE; i++) {
        if(GRADES[i] == grade) {
            return GRADEPOINTS[i];
        }
    }
    return 0;
}