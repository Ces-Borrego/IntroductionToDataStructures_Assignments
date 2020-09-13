/* Title: hw7-1.cpp
* Abstract: Use dynamic arrays to implement a list. Resizing the 			* underlying dynamic array
* Author: Cesar Borrego
* Email: ceborregoc@csumb.edu 
* Estimate: 3 hours
* Date: 4/14/2020
*/

#include "List.h"

//--- Definition of class constructor
List::List()     
: mySize(0), myCapacity(50) {
    myArray = new int[myCapacity];
}

List::List(int capacityValue)     
: mySize(0), myCapacity(capacityValue) {
    myArray = new int[myCapacity];
}

List::List(const List& org){
	mySize = org.getSize();
	myCapacity = org.getCapacity();
	myArray = new int[myCapacity];
	for(int x = 0; x < mySize; x++){
		myArray[x] = org.myArray[x];
	}
}

List& List::operator =(const List& rightSide){
	if(this != &rightSide){
		if(myCapacity != rightSide.getCapacity()){
			myCapacity = rightSide.getCapacity();
			delete [] myArray;
			myArray = new int[myCapacity];
		}
		mySize = rightSide.getSize();
		for(int x = 0; x < mySize; x++){
			myArray[x] = rightSide.myArray[x];
		}
	}
	return *this;
}

//--- Definition of empty()
bool List::empty() const {
    return mySize == 0;
}

//--- Definition of display()
void List::display() const {
    for (int i = 0; i < mySize; i++) {
        cout << myArray[i] << "  ";
    }
    cout << endl;
}


//--- Definition of insert()
void List::insert(int item, int pos) {
    if (mySize == myCapacity) {
        cerr << "*** No more space for a list element -- increase capacity ***\n";
        return;
    }

    if (pos < 0 || pos > mySize) {
        cerr << "*** Illegal location to insert -- " << pos 
            << ".  List unchanged. ***\n";
        return;
    }

    // First shift array elements right to make room for item
    for(int i = mySize; i > pos; i--) {
        myArray[i] = myArray[i - 1];
    }

    // Now insert item at position pos and increase list size  
    myArray[pos] = item;
    mySize++;
}


//--- Definition of erase()
void List::erase(int pos) {
    if (mySize == 0) {
        cerr << "*** List is empty ***\n";
        return;
    }
    if (pos < 0 || pos >= mySize) {
        cerr << "Illegal location to delete -- " << pos
            << ".  List unchanged. ***\n";
        return;
    }

    // Shift array elements left to close the gap
    for(int i = pos; i < mySize; i++) {
        myArray[i] = myArray[i + 1];
    }

    // Decrease list size
    mySize--;
}

void List::resize(int cap){
	if(cap < mySize){
		int* newArr;
		mySize = cap;
		myCapacity = cap;
		newArr = new int[myCapacity];
		for(int x = 0; x < mySize; x++){
			newArr[x] = myArray[x];
		}
		delete [] myArray;
		myArray = newArr;
	} else {
		int* newArr;
		myCapacity = cap;
		newArr = new int[myCapacity];
		for(int x = 0; x < mySize; x++){
			newArr[x] = myArray[x];
		}
		delete [] myArray;
		myArray = newArr;
	}
}

int List::getCapacity() const{
	return myCapacity;
}

int List::getSize() const{
	return mySize;
}

void List::append(int item){
	if(mySize == myCapacity){
		int* newArr = new int[myCapacity*2];
		for(int x = 0; x < mySize; x++){
			newArr[x] = myArray[x];
		}
		delete [] myArray;
		myArray = newArr;
		myArray[mySize] = item;
		mySize++;
	} else {
		myArray[mySize] = item;
		mySize++;
	}
}

bool List::removeLast(){
	if(empty()){
		return false;
	} else {
		mySize--;
		return true;
	}
}

void List::setCapacity (int newCapacity){
	if(mySize > newCapacity){
		myCapacity = newCapacity;
		int* newArr = new int[myCapacity];
		for(int x = 0; x < mySize; x++){

		}
	}
}

List::~List(){
	delete [] myArray;
}



