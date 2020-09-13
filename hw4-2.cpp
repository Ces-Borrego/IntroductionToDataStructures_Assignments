/*
* Title: hw4-2.cpp
* Abstract:  program that prompts the user to enter an integer number, and uses a stack to 
* convert that number to binary.
* Author: Cesar Borrego 
* Email: ceborrego@csumb.edu 
* Estimate: 1 hours
* Date: 2/13/2020
*/

/**********************************************************
 * Queue implementation with a static array.
 * Original code: https://cs.calvin.edu/activities/books/c++/ds/2e/SourcePrograms/Chap08/Figure8.2/
 * Updated by Dr. Byun for CST238.
 * Basic operations:
 *   Constructor: Constructs an empty queue
 *   empty:       Checks if a queue is empty
 *   enqueue:     Modifies a queue by adding a value at the back
 *   front:       Accesses the front queue value; leaves queue unchanged
 *   dequeue:     Modifies a queue by removing the value at the front
 *   display:     Displays the queue elements from front to back
 *
 **********************************************************/ 
#include <iostream>
using namespace std;

const int QUEUE_CAPACITY = 7;
typedef char QueueElement;

class Queue
{
public:
    Queue();
    bool empty() const;
    void enqueue(QueueElement value);
    void display() const;
    QueueElement front() const;
    void dequeue();
    void printPrivateInfo();
		bool isSorted() const;
		bool drop(QueueElement index);

private:
    int myFront;
    int myBack;
    QueueElement myArray[QUEUE_CAPACITY];
}; // end of class declaration


//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}


//--- Definition of empty()
bool Queue::empty() const
{ 
    return (myFront == myBack); 
}

void Queue::printPrivateInfo() {
    cout << "myFront: " << myFront << endl;
    cout << "myBack: " << myBack << endl;
    cout << "Elements: " << endl;
    for (int i = 0; i < QUEUE_CAPACITY; i++) {
        cout << "\t" << i << ": " << myArray[i] << endl;
    }
}


//--- Definition of enqueue()
void Queue::enqueue(QueueElement value)
{
    int newBack = (myBack + 1) % QUEUE_CAPACITY;
    if (newBack != myFront)     // queue isn't full
    { 
        myArray[myBack] = value;
        myBack = newBack;
    }
    else
    {
        cerr << "*** Queue full -- can't add new value ***\n"
            "Must increase value of QUEUE_CAPACITY.\n";
    }
}


//--- Definition of display()
void Queue::display() const
{
    for (int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY) 
    {
        cout << myArray[i] << "  ";
    }
    cout << endl;
}


//--- Definition of front()
QueueElement Queue::front() const
{
    if ( !empty() ) 
    {
        return (myArray[myFront]);
    }
    else
    {
        cerr << "*** Queue is empty -- returning garbage value ***\n";
        QueueElement garbage;
        return garbage;
    }
}


//--- Definition of dequeue()
void Queue::dequeue()
{
    if ( !empty() )
    {
        myFront = (myFront + 1) % QUEUE_CAPACITY;
    }
    else
    {
        cerr << "*** Queue is empty -- "
            "can't remove a value ***\n";
    }
}

bool Queue::isSorted() const{
	if(empty()||(myBack-myFront)==1) return true;
	else {
		if(myArray[myFront]<myArray[myFront + 1]){
			for(int y = myFront; y != myBack; y = (y + 1) % QUEUE_CAPACITY){
				if(myArray[y]>myArray[y+1]) return false;
			}
		} else if(myArray[myFront]>myArray[myFront+1]){
			for(int y = myFront; y != myBack; y = (y + 1) % QUEUE_CAPACITY){
				if(myArray[y]<myArray[y+1]) return false;
			}
		}
		return true;
	}
}

bool Queue::drop(QueueElement index){
	
}




int main()
{
    // Queue q1;
    // cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;

    // cout << "How many elements to add to the queue? ";
    // int numItems;
    // cin >> numItems;
    // for (int i = 1; i <= numItems; i++) 
    //     q1.enqueue(100*i);

    // cout << "Contents of queue:\n";
    // q1.display(); 
    // cout << "Queue q1 empty? " << q1.empty() << endl;

    // cout << "\nFront value in q1: " << q1.front() << endl << endl;

    // while (!q1.empty())
    // {
    //     cout << "Remove front -- Queue contents: ";
    //     q1.dequeue();
    //     q1.display();
    // }
    // cout << "\nQueue q1 empty? " << q1.empty() << endl;
    // cout << "Now try to retrieve front value in q1" << endl;
    // cout << "Front value in q1?" << endl << q1.front() << endl;
    // cout << "\nNow Try to remove front of q1: " << endl;
    // q1.dequeue();
    Queue myQueue;
    myQueue.enqueue('A');
		myQueue.enqueue('C');
		myQueue.enqueue('C');

		cout<<boolalpha<<myQueue.isSorted()<<endl;
		cout<<boolalpha<<('A' < 'B');
}

