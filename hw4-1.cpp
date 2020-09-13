/*
* Title: hw4-1.cpp
* Abstract:  program that prompts the user to enter an integer number, and uses a stack to 
* convert that number to binary.
* Author: Cesar Borrego 
* Email: ceborrego@csumb.edu 
* Estimate: 1 hours
* Date: 2/13/2020
*/

#include <iostream>
using namespace std;

const int STACK_CAPACITY = 15;
typedef int elem;

class Stack {
	public:
		Stack(); 
		bool empty();
		void push(elem value);
		void pop();
		elem top();
		void display();
		void reset();
	private:
		int myTop;
		elem myArray[STACK_CAPACITY];
};

Stack::Stack():myTop(-1){};

bool Stack::empty(){
	return myTop==-1;
}

void Stack::push(elem value){
	if(myTop==STACK_CAPACITY){
		cout<<"ERROR: Stack is full."<<endl;
	} else {
		++myTop;		
		myArray[myTop] = value;
	}
}

void Stack::pop(){
	if(empty()){
		cout<<"ERROR: Stack is empty."<<endl;
	} else {
		myTop--;
	}
}

elem Stack::top() {
	return myArray[myTop];
}

void Stack::display(){
	for(int x = myTop; x >= 0; x--){
		cout<< myArray[x];
	}
}

void Stack::reset(){
	myTop = -1;
}



int main() {
	Stack bin;

	bool cont = true;
	while(cont){
		int num;
  	cout<<"Enter a number: ";
		cin>>num;

		if(num==0) {
			cout<<"Exiting";
			break;
		}
		cout<<num<<" => ";

		while(num!=0){
			int r = num%2;
			num = num/2;

			bin.push(r);
		}

		bin.display();
		bin.reset();
		cout<<endl<<endl;
	}
	
}