/*
* Title: hw2_1.cpp
* Abstract: This program shows the values of an array and provides 
* three options (1) delete the max, (2) append a number, (3) reverse 
* array
* Author: Cesar Borrego
* Email: ceborrego@csumb.edu
* Estimate: 3 hours
* Date: 1/30/2020
*/

#include <iostream>
using namespace std;

int myArray[10] = {10,20,30,40,50,15,25,30,45,55};
static int size = 10;

void printArray(int nums[], int n);
void delMax(int numsp[], int n);
void append(int nums[], int n);
void revArray(int nums[], int n);

int main() {
  cout<<"Array Values:";
	printArray(myArray, size);

	cout<<"This is a list of operations"<<endl;
	cout<<"\t1. Delete the max"<<endl;
	cout<<"\t2. Append a number"<<endl;
	cout<<"\t3. Revers arrray\n"<<endl;

	string con = "Y";
	while (con == "Y"||con == "y"){
		int choose;
		cout<<"Enter your option: ";
		cin>>choose;

		if(choose==1) delMax(myArray, size);
		else if (choose==2)	append(myArray, size);
		else revArray(myArray, size);

		cout<<"Continue? (Y/N): ";
		cin>>con;
		cout<<endl;
	}	
}

void printArray(int nums[], int n){
	for(int x = 0; x < size; x++){
		cout<<" "<<myArray[x];
	}
	cout<<endl;
}

void delMax(int nums[], int n){
	int max = nums[0];
	for(int x = 0; x < n; x++){
		if(nums[x]>max) max = nums[x];
	}

	for(int x = 0; x < n; x++){
		if(nums[x]==max){
			nums[x] = 0;
			for(int y = x; y < n; y++){
				nums[y] = nums[y+1];
			}
			nums[n-1] = 0;
			break;
		}
	}

	cout<<"New Array Values: ";
	printArray(nums, n);
}

void append(int nums[], int n){
	
	if(nums[n-1]!=0){
		cout<<"Array is full and can't append anymore.\n";
	} else {
		int choose;
		cout<<"Enter the number to append: ";
		cin>>choose;
		for(int x = 0; x < n; x++){
			if(nums[x]==0){
				nums[x] = choose;
				break;
			}
		}
	}

	cout<<"New Array Values: ";
	printArray(nums, n);
}

void revArray(int nums[], int n){
	int arr[n];
	for(int x = 0; x < n; x++){
		arr[x] = nums[x];
	}

	int count = 0;
	for(int x = n-1; x >= 0; x--){
		nums[x] = arr[count];
		count++;
	}

	while(nums[0]==0){
		for(int x = 0; x < n; x++){
			nums[x] = nums[x+1];
		}
		nums[n-1] = 0;
	}

	cout<<"New Array Values: ";
	printArray(nums,n);
}