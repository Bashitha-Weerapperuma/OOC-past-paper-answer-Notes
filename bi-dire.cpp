#include <iostream>
#include <cstring>

using namespace std;

// Bi-directional Association

#define SIZE 10

class Customer;
class Order;

class Customer
{
private:
	string name;
	string address;
	Order *order[SIZE];
	int noOfOrders;

public:
	Customer();
	Customer(string pname, string paddress);
	void addOrder(Order *O);
	void displayCustomer();
};

class Order
{
private:
   	string orderID;
   	Customer *Cus;
   
public:  
   	Order(string	porderID,  Customer *pCus);
   	void displayOrders();
};

Order::Order (string porderID,  Customer *pCus) 
{  
    orderID = porderID;
    Cus = pCus;
    Cus->addOrder(this);
}

void Order::displayOrders()
{
	cout << "\t\tOrder ID : " << orderID << endl;
}

Customer::Customer(string pname, string paddress)
{
    name = pname;
    address = paddress;
    noOfOrders = 0;
}

void Customer::addOrder(Order *O)
{
    if (noOfOrders < SIZE) {
    	order[noOfOrders] = O;
	}
    noOfOrders++;
}

void Customer::displayCustomer()
{
    cout << "\tCustomer Name  = " << name << endl;
    cout << "\tCustomer Address  = " << address << endl;
    for( int i = 0; i < noOfOrders; i++) {
        order[i]-> displayOrders();
	}
}



int main()
{
	Customer *C1 = new Customer("Bashitha", "galle");
	Customer *C2 = new Customer("Weerapperuma" , "ambalangoda");

	Order *O1 = new Order("001", C1);
	Order *O2 = new Order("002",  C2);
	Order *O3 = new Order("003",  C2);

	cout << "\nOrders of C1" << endl;
	C1->displayCustomer();
	
	cout << "\nOrders of C2" << endl;
	C2->displayCustomer();

	return 0;
}
