/*
* Title: hw1_3.cpp
* Abstract: This program displays a Vertical Histogram of the numbers taken by a file whos name is input by the user.
* Author: Cesar Borrego
* Email: ceborrego@csumb.edu
* Estimate: 3 hours
* Date: 1/27/2020
*/


#include <iostream>
#include <fstream>
using namespace std;

static int size = 7;

void printHist(int nums[]);
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
	for(int x = 0; x < size; x++){
		text>>nums[x];
	}

	cout<<endl<<"=====Vertical Histogram=====\n";
	printHist(nums);

}

void printHist(int nums[]){
	int maxInt = 0;
	for(int x = 0; x < size; x++){
		if(maxInt < nums[x]) maxInt = nums[x];
	}

	int pace = maxInt;
	for(int x = 0; x < maxInt; x++){
		for(int y = 0; y< size; y++){
			if(nums[y]<pace) cout<<"  ";
			else if(nums[y]==pace) cout<<" *";
			else cout<<" *";
		}
		pace--;
		cout<<endl;
	}

	for(int x = 0; x < size; x++){
		cout<<"--";
	}
	cout<<endl;
	for(int x = 0; x < size; x++){
		cout<<" "<<nums[x];
	}
	cout<<endl;
}