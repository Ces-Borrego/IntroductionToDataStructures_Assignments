/* Title: hw5-1.cpp
* Abstract: read two array and array sizes from a text file an combine them into one array. 
* Author: Cesar Borrego
* Email: ceborregoc@csumb.edu 
* Estimate: 1 hour 
* Date: 1/29/2020
*/

#include <iostream>
#include <fstream>
using namespace std;

void display(int* a, int size);

int main() {
  cout << "Enter input file name: ";
  string file_name;
  cin >> file_name;

	ifstream f_input(file_name);
    if (f_input.fail()) 
    {
      cout << "Error: Input file open failed.\n";
      return 0;
    }
	int size;
	int size2;
	int* myArray = new int[size];
	int* myArr = new int[size2];
	
	f_input>>size;
	for(int x = 0; x < size; x++){
		f_input>>myArray[x];
	}
	f_input>>size2;
	for(int x = 0; x < size; x++){
		f_input>>myArr[x];
	}

	int* myFinalArray = new int[size+size2];
	int newSize = size + size2;
	for(int x = 0; x < size; x++){
		myFinalArray[x] = myArray[x];
	}
	display(myArray, size);
	delete [] myArray;

	for(int x = 0; x < size2; x++){
		myFinalArray[x+size] = myArr[x];
	}

	display(myArr, size2);
	delete [] myArr;


	display(myFinalArray, newSize);
	
	
}

void display(int* a, int size){
	for(int x = 0; x < size; x++){
		cout<<a[x]<<" ";
	}
	cout<<endl;

}