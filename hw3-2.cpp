/*
* Title: hw3-2.cpp
* Abstract: add the proper member functions to the class and test.
* Author: Cesar Borrego 
* Email: ceborrego@csumb.edu 
* Estimate: 2 hours
* Date: 2/10/2020
*/


/*-----------------------------------------------------------------
  Original source: https://cs.calvin.edu/activities/books/c++/ds/2e/SourcePrograms/Chap06/Figure6.1/
  Updated by Dr. Byun & Dr. Gross for CST238.

  Basic operations are:
    Constructor
    empty:    Check if list is empty
    insert:   Insert a value into the list at a given position.
    erase:    Remove a value from the list at a given position.
    display:  Output the list
-------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

const int CAPACITY = 16; // Maximum capacity of a list.

/*
	List of int based on an underlying static array
*/
class List {
public:
    List(); // Class constructor
    bool empty() const; 
    void insert(int item, int pos);
    void erase(int pos);  
    void display() const; 
		int find(int value) const;
		int sum() const;
		bool append(int value);
		int getSize() const;
		int getValue(int pos) const;
		bool hasDuplicates() const;
		bool isSorted() const;
		bool append(const List l);
		bool remove(int value);

private:
    int mySize;  // Current size of elements stored in the list
    int myArray[CAPACITY];  
}; 


//--- Definition of class constructor
List::List() : mySize(0) {}


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
    if (mySize == CAPACITY) {
        cerr << "*** No space for list element -- terminating "
            "execution ***\n";
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
	
    if (pos < 0 || pos >= mySize){
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

//--find()
int List::find(int value) const{
	int index = -1;
	for(int x = 0; x < mySize; x++){
		if(myArray[x] == value) {
			index = x;
			break;
		}
	}
	return index;
}

//--sum()
int List::sum() const{
	int sum = 0;
	for(int x = 0; x < mySize; x++){
		sum += myArray[x];
	}
	return sum;
}

//--append()
bool List::append(int value){
	if(mySize==CAPACITY){
		cout<<"Failed. Cannot append because List is full."<<endl;
		return false;
	} else {
		myArray[mySize] = value;
		mySize++;
		return true;
	}
}

//--getSize()
int List::getSize() const{
	return mySize;
}

//--getValue()
int List::getValue(int pos) const{
	if(pos>mySize) return -1;
	else return myArray[pos];
}

//--hasDupliactes()
bool List::hasDuplicates() const{
	for(int x = 0; x < mySize; x++){
		for(int y = x+1; y < mySize; y++){
			if(myArray[x]==myArray[y]) return true;
		}
	}
	return false;
}

//--isSorted()
bool List::isSorted() const{
	if(empty()) return true;
	else if(mySize==1) return true;
	else {
		for(int x = 0; x < mySize; x++){
			if(myArray[x]>myArray[x+1]) return false;
		}
		return true;
	}
}

//--append(const List a)
bool List::append(const List a){
	if((a.getSize()+mySize)>CAPACITY) return false;
	else {
		for(int x = 0; x < a.getSize(); x++){
			append(a.myArray[x]);
		}
		return true;
	} 
}

//--remove(int value)
bool List::remove(int value){
	bool found = false;
	for(int x = 0; x < mySize; x++){
		if(myArray[x] == value){
			erase(x);
			found = true;
		}
	}
	return found;
}


//--- Client program to test List class.
int main()
{
	/*
    // Test the class constructor
    List intList;
    cout << "Constructing intList\n";

    // Test empty() and output of empty list
    if (intList.empty()) {
        cout << "Empty List: \n";
        intList.display();
        cout<< endl;
    }

    // Test insert()
    for (int i = 0; i < 9; i++) {
        cout << "Inserting " << i << " at position " << i/2 << endl;
        intList.insert(i, i/2);       //  -- Insert i at position i/2
        //Test output
        intList.display();
    }
	
    cout << "List empty? " << (intList.empty() ? "Yes" : "No") << endl;

    cout << "\nTry to insert at position -1" << endl;
    intList.insert(0, -1);
    cout << "\nTry to insert at position 10" << endl;
    intList.insert(0, 10);

		//Test sum()
		cout<<endl<<"The sum of the current array is: "<<intList.sum()<<endl;

		//Test find()
		int num;
		cout<<endl<<"Enter a number to find: ";
		cin>>num;
		if(intList.find(num)!=-1){
			cout<<endl<<num<<" is at position "<<intList.find(num)<<endl;
		} else {
			cout<<num<<" was not found."<<endl;
		}

    // Test erase()
    int index;
    cout << "\nGive an index of a list element to remove: ";
    cin >> index;
    intList.erase(index);
    intList.display();

    // Test erase() one more time.
    cout << "\nGive an index of a list element to remove: ";
    cin >> index;
    intList.erase(index);
    intList.display();
		
		//Test append()
		cout<<"Enter a number to append: ";
		cin>>num;
		intList.append(num);
		intList.display();
	*/

	List myList;

	myList.append(20);
	myList.append(30);
	myList.append(10);

	List urList;
	for(int x = 1; x < 5; x++){
		urList.append(x*10);
	}

	myList.display();
	cout<<myList.getSize()<<endl;
	urList.display();
	cout<<urList.getSize()<<endl;

	cout<<myList.getValue(0)<<endl;
	cout<<urList.getValue(0)<<endl;

	cout<<endl;

	urList.append(40);
	myList.display();
	if(myList.hasDuplicates()) cout<<"Has Duplicates."<<endl;
	else cout<<"Nope"<<endl;
	urList.display();
	if(urList.hasDuplicates()) cout<<"Has Duplicates."<<endl;
	else cout<<"Nope"<<endl;

	cout<<endl;

	if(myList.isSorted()) cout<<"Yuuup"<<endl;
	else cout<<"Naah"<<endl;
	if(urList.isSorted()) cout<<"Yuuup"<<endl;
	else cout<<"Naah"<<endl;

	cout<<endl;

	myList.append(urList);
	myList.display();

	myList.remove(40);
	myList.display();
	myList.remove(10);
	myList.display();


  return 0;
}
