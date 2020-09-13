/*
* Title: project1.cpp
* Abstract: Create a working and functioning Automat.
* Author: Cesar Borrego 
* Email: ceborrego@csumb.edu 
* Estimate: 10 hours
* Date: 3/3/2020
*/

#include <iostream>
using namespace std;

//=============================FOOD CLASS==================================================

class Food{
	public:
		Food();
		Food(string name, int calories, double price);
		string getName();
		int getCalories();
		double getPrice();
		void setName(string name);
		void setCalories(int calories);
		void setPrice(double price);
		void display();
	private:
		string myName;
		int myCalories;
		double myPrice;
};
Food::Food(){
	myName = " ";
	myCalories = 0;
	myPrice = 0.0;
}

Food::Food(string name, int calories, double price){
	myName = name;
	myCalories = calories;
	myPrice = price;
}

string Food::getName(){
	return myName;
}

int Food::getCalories(){
	return myCalories;
}

double Food::getPrice(){
	return myPrice;
}

void Food::setName(string name){
	myName = name;
}

void Food::setCalories(int calories){
	myCalories = calories;
}

void Food::setPrice(double price){
	myPrice = price;
}

void Food::display(){
	cout<<myName<<": "<<myCalories<<" calories, $"<<myPrice<<endl;
}

//============================DRINK CLASS==================================================

class Drink{
	public:
		Drink();
		Drink(string name, int ounces, double price);
		string getName();
		int getOunces();
		double getPrice();
		void setName(string name);
		void setOunces(int ounces);
		void setPrice(double price);
		void display();
	private:
		string myName;
		int myOunces;
		double myPrice;
};

Drink::Drink(){
	myName = " ";
	myOunces = 0;
	myPrice = 0.0;
}

string Drink::getName(){
	return myName;
}

int Drink::getOunces(){
	return myOunces;
}

double Drink::getPrice(){
	return myPrice;
}

Drink::Drink(string name, int ounces, double price){
	myName = name;
	myOunces = ounces;
	myPrice = price;
}

void Drink::setName(string name){
	myName = name;
}

void Drink::setOunces(int ounces){
	myOunces = ounces;
}

void Drink::setPrice(double price){
	myPrice = price;
}

void Drink::display(){
	cout<<myName<<": "<<myOunces<<" ounces, $"<<myPrice<<endl;
}

//============================AUTOMAT CLASS=================================================

static int const AUTOMAT_MAX = 10;

class Automat{
	public:
		Automat();
		bool emptyFood();
		bool emptyDrink();
		void enqueue(Food a);
		void enqueue(Drink b);
		void dequeueFood();
		void dequeueDrink();
		Food frontFood();
		Drink frontDrink();
		int foodCount();
		int drinkCount();
		int getTotalCalories();
		int getTotalOunces();
		double getTotalPrice();
		void display();
	private:
		int myFoodFront;
		int myFoodBack;
		int myDrinkFront;
		int myDrinkBack;
		int numFood;
		int numDrink;

		Food myFood[AUTOMAT_MAX];
		Drink myDrink[AUTOMAT_MAX];
};
Automat::Automat(){
	myFoodFront = 0;
	myFoodBack = 0;
	myDrinkFront = 0;
	myDrinkBack = 0;
	numFood = 0;
	numDrink = 0;
}

bool Automat::emptyFood(){
	return myFoodFront == myFoodBack;
}

bool Automat::emptyDrink(){
	return myDrinkFront == myDrinkBack;
}

void Automat::enqueue(Food a){
	int newBack = (myFoodBack + 1) % AUTOMAT_MAX;
	if(newBack != myFoodFront){
		myFood[myFoodBack] = a;
		myFoodBack = newBack;
		numFood++;
	} else {
		cout<<"ERROR: Reached Max Food Items.\n";
	}
}

void Automat::enqueue(Drink b){
	int newBack = (myDrinkBack + 1) % AUTOMAT_MAX;
	if(newBack != myDrinkFront){
		myDrink[myDrinkBack] = b;
		myDrinkBack = newBack;
		numDrink++;
	} else {
		cout<<"ERROR: Reached Max Drink Items.\n";
	}
}

void Automat::dequeueFood(){
	if(!emptyFood()){
		myFoodFront = (myFoodFront + 1) % AUTOMAT_MAX;
		numFood--;
	} else {
		cout<<"ERROR: No Food Items Selected.";
	}
}

void Automat::dequeueDrink(){
	if(!emptyDrink()){
		myDrinkFront = (myDrinkFront + 1) % AUTOMAT_MAX;
		numDrink--;
	} else {
		cout<<"ERROR: No Drink Items Selected.";
	}
}

Food Automat::frontFood(){
	return myFood[myFoodFront];
}

Drink Automat::frontDrink(){
	return myDrink[myDrinkFront];
}

int Automat::foodCount(){
	return numFood;
}

int Automat::drinkCount(){
	return numDrink;
}

int Automat::getTotalCalories(){
	int sum = 0;
	for(int x = myFoodFront; x != myFoodBack; x = (x+1)%AUTOMAT_MAX){
		sum+=myFood[x].getCalories();
	}
	return sum;
}

int Automat::getTotalOunces(){
	int sum = 0;
	for(int x = myDrinkFront; x != myDrinkBack; x = (x+1)%AUTOMAT_MAX){
		sum+=myDrink[x].getOunces();
	}
	return sum;
}

double Automat::getTotalPrice(){
	double foodPrice = 0.0;
	for(int x = myFoodFront; x != myFoodBack; x = (x+1)%AUTOMAT_MAX){
		foodPrice+=myFood[x].getPrice();
	}
	double drinkPrice = 0.0;
	for(int x = myDrinkFront; x != myDrinkBack; x = (x+1)%AUTOMAT_MAX){
		drinkPrice+=myDrink[x].getPrice();
	}
	return foodPrice + drinkPrice;
}

void Automat::display(){
	cout<<"Automat: "<<endl;
	cout<<"   Food: "<<endl;
	for(int x = myFoodFront; x != myFoodBack; x = (x+1)%AUTOMAT_MAX){
		cout<<"\t\t"; myFood[x].display();
	}
	cout<<"\t\t"<<numFood<<" food items - Total Calories: "<<getTotalCalories()<<endl;
	cout<<"   Drinks: "<<endl;
	for(int x = myDrinkFront; x !=  myDrinkBack; x = (x+1)%AUTOMAT_MAX){
		cout<<"\t\t"; myDrink[x].display();
	}
	cout<<"\t\t"<<numDrink<<" drinks - Total Ounces: "<<getTotalOunces()<<endl<<endl;
}

//============================ORDER CLASS==================================================

static int const ORDER_MAX = 5;

class Order{
	public:
		Order();
		bool emptyFood();
		bool emptyDrink();
		void push(Food f);
		void push(Drink d);
		void popFood();
		void popDrink();
		Food topFood();
		Drink topDrink();
		int foodCount();
		int drinkCount();
		double getTotalPrice();
		void display();
		void cancel(Automat& a);
		void purchase();
		static int getTotalOrders();
	private:
		int myFoodTop;
		int myDrinkTop;
		Food myFood[ORDER_MAX];
		Drink myDrink[ORDER_MAX];
		static int myTotalOrders;
};

Order::Order(){
	myFoodTop = -1;
	myDrinkTop = -1;
	myTotalOrders++;
}

int Order::myTotalOrders = 0;

bool Order::emptyFood(){
	return myFoodTop == -1;
}

bool Order::emptyDrink(){
	return myDrinkTop == -1;
}

void Order::push(Food f){
	if(myFoodTop+1 != ORDER_MAX){
		myFoodTop++;
		myFood[myFoodTop] = f;
	} else cout<<"Food order full; new food not added."<<endl;
}

void Order::push(Drink d){
	if(myDrinkTop+1 != ORDER_MAX){
		myDrinkTop++;
		myDrink[myDrinkTop] = d;
	} else cout<<"Drink order full; new drink not added."<<endl;
}

void Order::popFood(){
	myFoodTop--;
}

void Order::popDrink(){
	myDrinkTop--;
}

Food Order::topFood(){
	return myFood[myFoodTop];
}

Drink Order::topDrink(){
	return myDrink[myDrinkTop];
}

int Order::foodCount(){
	return myFoodTop+1;
}

int Order::drinkCount(){
	return myDrinkTop+1;
}

double Order::getTotalPrice(){
	double price = 0.0;
	for(int x = 0; x <= myFoodTop; x++){
		price += myFood[x].getPrice();
	}
	for(int x = 0; x <= myDrinkTop; x++){
		price += myDrink[x].getPrice();
	}
	return price;
}

void Order::display(){
	cout<<"Order: "<<endl;
	cout<<"\tFood ("<<foodCount()<<" items):"<<endl;
	for(int x = 0; x <= myFoodTop; x++){
		cout<<"\t\t"; myFood[x].display();
	}
	cout<<"\tDrink ("<<drinkCount()<<" items):"<<endl;
	for(int x = 0; x <= myDrinkTop; x++){
		cout<<"\t\t"; myDrink[x].display();
	}
	cout<<"\tOrder total: $"<<getTotalPrice()<<endl<<endl;
}

void Order::cancel(Automat & a){
	for(int x = 0; x <= myFoodTop; x++){
		a.enqueue(topFood());
		popFood();
	}
	for(int x = 0; x<= myDrinkTop; x++){
		a.enqueue(topDrink());
		popDrink();
	}
}

void Order::purchase(){
	myFoodTop = -1;
	myDrinkTop = -1;
}

int Order::getTotalOrders(){
	return myTotalOrders;
}


//===================================MAIN==================================================

int main() {

	Automat a;
	a.enqueue(Food("Let's Potato Chips", 300, 1.50));
	a.enqueue(Food("Mini Donuts", 500, 1));
	a.enqueue(Drink("Coffee", 6, 5.50));
	a.enqueue(Drink("Nacho Drink", 22, 2.50));
	cout << "Starting Automat\n";
	a.display();


	Order o;
	o.push(a.frontFood());
	a.dequeueFood();
	o.push(a.frontDrink());
	a.dequeueDrink();
	cout << "Ordered one food, one drink\n";
	o.display();
	a.display();
	cout << "Canceled order\n";
	o.cancel(a);
	o.display();
	a.display();
	cout << "Ordered one food, one drink, purchased\n";
	o.push(a.frontFood());
	a.dequeueFood();
	o.push(a.frontDrink());
	a.dequeueDrink();
	o.purchase();
	o.display();
	a.display();



}