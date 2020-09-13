#include <time.h>
#include <iostream>
#include "mysorts.h"
using namespace std;

bool isSorted(int * values, int size) {
	bool sorted = true;
	for(int x = 0; x < size; x++){
		if(values[x] > values[x+1]) sorted = false;
	}
    return sorted;
}

int * copyArray(int * source, int size) {
	int* a = new int[size];
	for(int x = 0; x < size; x++) a[x] = source[x];
    return a;
}

void bubble_sort (int * values, int size) {
    int comps = 0;
    int swaps = 0;
    clock_t startClock;
    clock_t elapsedTime;
    
    cout << "Start the bubble sorting..." << endl;
    // Measure the starting clock and conduct the bubble sorting
    startClock = clock();
    // sorting code goes here
		int i, k; 
    bool s; 
    for (i = 0; i < size-1; i++) 
    { 
      s = false; 
      for (k = 0; k < size-i-1; k++) 
      { 
         if (values[k] > values[k+1]) 
         { 
            int temp = values[k];
						values[k] = values[k+1]; 
						values[k+1]= temp;
						swaps++;
            s = true; 
         } 
				 comps++;
      } 
      if (s == false) break; 
    } 

    elapsedTime = clock() - startClock;
    cout << "Bubble sort completed. Is sorted: " << boolalpha <<
        isSorted(values, size) << endl;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
        << " seconds" << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Comps: " << comps << endl << endl;
}
void insertion_sort (int * values, int size) {
    int comps = 0;
    int swaps = 0;
    clock_t startClock;
    clock_t elapsedTime;
    
    cout << "Start the insertion sorting..." << endl;
    // Measure the starting clock and conduct the bubble sorting
    startClock = clock();
    // sorting code goes here
	int temp;
	int k;
	for(int x = 1; x < size; x++){
		temp = values[x];
		k = x - 1;
		while(k >= 0 && values[k] > temp) {
			values[k+1] = values[k];
			k = k - 1;
			comps++;
		}
		values[k+1] = temp;
		swaps++;
	}
    elapsedTime = clock() - startClock;
    cout << "Insertion sort completed. Is sorted: " << boolalpha <<
        isSorted(values, size) << endl;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
        << " seconds" << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Comps: " << comps << endl << endl;
}
void selection_sort (int * values, int size) {
    int comps = 0;
    int swaps = 0;
    clock_t startClock;
    clock_t elapsedTime;
    
    cout << "Start the selection sorting..." << endl;
    // Measure the starting clock and conduct the bubble sorting
    startClock = clock();
    // sorting code goes here
    int i, k, min;
    for (i = 0; i < size-1; i++)  
    {  
        min = i;  
        for (k = i+1; k < size; k++){
					if (values[k] < values[min]) min = k;  
					comps++;
				}
				int temp = values[min];
				values[min] = values[i];
				values[i] = temp;
				swaps++;
    }  
    elapsedTime = clock() - startClock;
    cout << "Selection sort completed. Is sorted: " << boolalpha <<
        isSorted(values, size) << endl;
    cout << "Elapsed time: " << (((double)elapsedTime)/CLOCKS_PER_SEC) 
        << " seconds" << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Comps: " << comps << endl << endl;
}
void print(int* values, int size){
	for(int x = 0; x < size; x++) cout<<values[x]<<" ";
	cout<<endl;
}