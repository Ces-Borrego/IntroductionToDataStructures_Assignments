/*
* Title: hw2_2.cpp
* Abstract:  Program determines the average of quiz scores of all 
* students in a course. 
* Author: Cesar Borrego
* Email: ceborrego@csumb.edu
* Estimate: 1 hours
* Date: 1/31/2020
*/

#include <iostream>
#include <fstream>
using namespace std;

struct student{
	string name;
	int id;
	double scores[5];
	double average;
};

student myArr[30];

int main() {
  string file_name;
  cout << "Enter input file name: ";
  cin >> file_name; 

  ifstream text(file_name);
  if (text.fail()) 
   {
       cout << "Error: Input file open failed.\n";
       return 0;
   }

  for (int x = 0; x < 30; x++)
  {
    text >> myArr[x].name;
    text >> myArr[x].id;
    for(int y = 0; y < 5; y++)
    {
      text >> myArr[x].scores[y];
    }
    if(myArr[x].name == "STOP") break;
    
  }

  double average;

  for(int x = 0; x < 30; x++)
  {
    if(myArr[x].name == "STOP") break;
    double sum = 0, low = myArr[x].scores[0];
    for(int y = 0; y < 5; y++)
    {
      if(low > myArr[x].scores[y]) low = myArr[x].scores[y];
    }
    for(int y = 0; y < 5; y++)
    {
      if(myArr[x].scores[y] == low) continue;
      sum+= myArr[x].scores[y];
    }
    myArr[x].average = sum/4;
  }
	cout<<"--------------------------------------------------"<<endl;
	cout<<"   Course Report: Quiz Average"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	for(int x = 0; x <= 30; x++){
		if(myArr[x].name=="STOP") break;
		cout<<myArr[x].name<<" ("<<myArr[x].id<<"): "<<myArr[x].average<<endl;
	}
	cout<<"--------------------------------------------------"<<endl;
	 
}
