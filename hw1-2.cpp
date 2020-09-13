/*
* Title: hw1_2.cpp
* Abstract: This program displays a Horizontal Histogram of the numbers taken by a file whos name is input by the user.
* Author: Cesar Borrego
* Email: ceborrego@csumb.edu
* Estimate: 1 hour
* Date: 1/27/2020
*/


#include <iostream>
#include <fstream>
using namespace std;

static int size = 5;


void display(int num);
int main() {
  cout << "Enter input file name: ";
  string file_name;
  cin >> file_name;

	ifstream text(file_name);
    if (text.fail()) 
    {
      cout << "Error: Input file open failed.\n";
      return 0;
    }

	int nums[size];
	for(int x =0; x < size; x++){
		text>>nums[x];
	}


	cout<<"=====Horizontal Histogram=====\n";
	for(int x = 0; x < size; x++){
		cout<<nums[x]<<": ";
		display(nums[x]);
	}
}

void display(int num){
	for(int x = 0; x < num; x++){
		cout<<"*";
	}
	cout<<endl;
}