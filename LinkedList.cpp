/**
This is base code for Homework 09 for CST238 Fall 2019
Sections 2 & 3
This file DOES need to be modified and handed in
ONLY RECURSION can be used; any iteration will result
in a zero for the assignment
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;
/**
* Implement these functions IN ORDER
*/

// implement these two first
bool Node::hasNext() const {
  return myNext != nullptr;
}

bool LinkedList::empty() const {
    return myFirst == nullptr;
}

// then these two
void Node::display() const {
	if(myNext != nullptr){
		cout<<myData<<" ";
		myNext->display();
	} else {
		cout<<myData<<endl;
	}
}

void LinkedList::display() const {
  if(!empty()){
		Node* np = myFirst;
		np->display();
	} else cout<<"Empty!\n";
}

// then these two
// only append if this is the last node
// otherwise, recurse
void Node::append(int data) {
    if(myNext == nullptr){
			myNext = new Node(data);
		} else {
			myNext->append(data);
		}
}

void LinkedList::append(int data) {
    if(empty()){
			myFirst = new Node(data);
		} else {
			myFirst->append(data);
		}
}

// then these two
bool Node::search(int data) const {
    if(myNext == nullptr&&myData != data){
			return false;
		} else if(myData == data){
			return true;
		} else {
			return myNext->search(data);
		}
}

bool LinkedList::search(int data) const {
    if(empty()){
			return false;
		} else {
			return myFirst->search(data);
		}
}

// then these two
bool Node::insertAfter(int oldData, int newData) {
    if(myData == oldData){
			Node* np = new Node(newData);
			np->myNext = myNext;
			myNext = np;
			return true;
		} else if(myNext == nullptr&&myData != oldData){
			return false;
		} else {
			return myNext->insertAfter(oldData, newData);
		}
}

bool LinkedList::insertAfter(int oldData, int newData) {
    if(empty()){
			return false;
		} else {
			return myFirst->insertAfter(oldData, newData);
		}
}

// then these two
bool Node::removeNext(int data) {
    if(myNext == nullptr){
			return false;
		} else if(myNext->myData!=data){
			return myNext->removeNext(data);
		} else {
			Node* np = myNext;
			myNext = np->getNext();
			np->myNext = nullptr;
			delete np;
			return true;
		}
}

bool LinkedList::remove(int data) {
    if(empty()){
			return false;
		} else if(myFirst->getData()==data){
			Node* np = myFirst;
			myFirst = myFirst->getNext();
			np = nullptr;
			delete np;
			return true;
		} else { 
			return myFirst->removeNext(data);
		}
}

// then these two
Node::~Node() {
	delete myNext;
}

LinkedList::~LinkedList() {
	delete myFirst;
}

// then these two
Node::Node(const Node & source) {
	if(source.myNext!=nullptr){
		myData = source.myData;
		myNext = new Node(*source.myNext);
	} else {
		myData = source.myData;
	}
}

LinkedList::LinkedList(const LinkedList & source) {
	if(source.myFirst == nullptr){
		myFirst = nullptr;
	} else {
		myFirst = new Node(*source.myFirst);
	}
}

// then this one
LinkedList LinkedList::operator=(const LinkedList & source) {
	if(source.myFirst == nullptr){
		myFirst = nullptr;
	} else {
		delete myFirst;
		myFirst = new Node(*source.myFirst);
	}
    return * this;
}

/**
* Implement the functions above, shouldn't need to change anything below,
but look at this for good examples!
*/

Node::Node(int data) {
    myData = data;
}

void Node::setNext(Node * next) {
    myNext = next;
}

LinkedList::LinkedList() {
    myFirst = nullptr; 
}

