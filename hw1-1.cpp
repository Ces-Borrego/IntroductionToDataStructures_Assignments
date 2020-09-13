/*
* Title: hw1_1.cpp
* Abstract: This program displays a list if bold elements and the count of each important element after dictating the min number in the set.
* Author: Cesar Borrego
* Email: ceborrego@csumb.edu
* Estimate: 2 hours
* Date: 1/25/2020
*/

#include <iostream>
#include <fstream>
using namespace std;

int findMin(int nums[], int n);

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

	int size;

	text>>size;

	int nums[size];
	for(int count = 0; count<size; count++){
		text>>nums[count];
	}

	cout<<endl<<"Min Number: "<<findMin(nums, size)<<".\n"<<endl;

	int counts[size];
	cout<<endl<<"Number				Count"<<endl;
	for(int x = 0; x < size; x++){
		counts[x]=0;
	}

	for(int x = 0; x < size; x++){
		for(int y = 0; y < size; y++){
			if(nums[x] == nums[y]) counts[x]++;
		}
	}
/*
	for(int x = 0; x < size; x++){
		int check = nums[x];
		for (int y = 1; y < size; y++){
			bool f = false;
			if(check == nums[y]&&f==false) f = true;
			if(check == nums[y]&&f==true) nums[y] = 0; 
		}
	}*/
	
	for(int x = 0; x < size; x++){
		if(nums[x] != 0){
			cout<<nums[x]<<"					"<<counts[x];
		} 
		cout<<endl;
	}

	cout<<endl<<"Nums array: ";
	for(int x=0; x < size; x++){
		cout<<nums[x]<<" ";
	}

	cout<<endl<<"Counts array: ";
	for(int x =0; x < size; x++){
		cout<<counts[x]<<" ";
	}
}

int findMin(int nums[], int n){
	int min = nums[0];
	for(int x = 0; x < n; x++){
		if(min>nums[x+1]) min = nums[x+1];
	}
	return min;
}
