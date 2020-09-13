/*
* Title: hw2_3.cpp
* Abstract: Program finds the customer’s information from a bank data.
* Author: Cesar Borrego
* Email: ceborrego@csumb.edu
* Estimate: 2 hours
* Date: 2/2/2020
*/

#include <iostream>
#include <fstream>
using namespace std;

struct account{
	string name;
	int id;
	double bal;
};


account myArr[30];


int main() {
  string file_name;
  cout << "Enter input file name: ";
  cin >> file_name; 

  ifstream text(file_name);
  if (text.fail()) 
   {
       cout << "Error: Input file open failed.\n";
       return 0;
   }

		for(int x = 0; x <= 30; x ++){
			text>>myArr[x].name;
			text>>myArr[x].id;
			text>>myArr[x].bal;
			if(myArr[x].name=="STOP") break;
		}

	string cont = "y";
	while(cont=="y"||cont=="Y"){
		string myName;
		cout<<"---------------------------------------------------"<<endl;
		cout<<"    Record Finder - Enter a customer name: ";
		cin>>myName;
		cout<<endl;
		cout<<"---------------------------------------------------"<<endl;

		bool found = false;

		for(int x = 0; x <= 30; x++){
			if(myArr[x].name=="STOP") break;
			if(myArr[x].name==myName){
				cout<<"Name: "<<myArr[x].name<<endl;
				cout<<"Account: "<<myArr[x].id<<endl;
				cout<<"Balance: "<<myArr[x].bal<<endl;
				found = true;
			}
			cout<<endl;
		}

		if(found==false)  cout<<"Fail. "<<myName<<" doesn't exist."<<endl;
		cout<<"---------------------------------------------------"<<endl;
		cout<<endl;
		cout<<"Do you want to continue? (Y/N): ";
		cin>>cont;

/*
	for(int x = 0; x <= 30; x++){
		if(myArr[x].name=="STOP") break;
		cout<<myArr[x].name<<" "<<myArr[x].id<<" $"<<myArr[x].bal<<endl;
	}
*/
	}
	cout<<"BYE!";

}