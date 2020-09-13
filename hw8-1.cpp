#include <iostream>
#include <fstream>
using namespace std;

int * readInts(string filename, int & size);
void sort(int * a, int size);
void printFolded(int * a, int size);
void printReg(int* a, int size);

int main() {
  string filename = "t3"; 
	int size = 0;
	int* myArray = readInts(filename, size);
	sort(myArray, size);
	printReg(myArray, size);
	printFolded(myArray, size);
}

int * readInts(string filename, int & size){
	ifstream text(filename);
  if (text.fail()) 
   {
     cout << "Error: Input file open failed.\n";
     return 0;
   }
	 text>>size;
	int* myArr = new int[size];
	for(int x = 0; x<size; x++){
		text>>myArr[x];
	}
	return myArr; 
}

void sort(int * a, int size){
	int x, k, y;
	for(x = 1; x < size; x++){
		k = a[x];
		y = x - 1;

		while (y >= 0 && a[y] > k){
			a[y + 1] = a[y];
			y = y - 1;
		}
		a[y+1] = k;
	}
}
void printFolded(int* a, int size){
	for(int x = 0; x < size; x++){
		if(a[x+1] == (a[x]+1)){
			cout << a[x] << "-";
			while(a[x+1] == (a[x]+1)){
				x++;
			}
			cout<<a[x]<<" ";
		}else {
			cout << a[x] << " ";
		}
	}
}
void printReg(int* a, int size){
	for(int x = 0; x < size; x++){
		cout<<a[x]<<" ";
	}
	cout<<endl;
}
