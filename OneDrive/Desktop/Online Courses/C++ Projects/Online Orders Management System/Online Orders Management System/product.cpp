#include "product.h"



product::product(int id, string name, string seller, string shipping,string ship_date,double price)
{
	this->id = id;
	this->name = name;
	this->seller = seller;
	this->shipping = shipping;
	this->ship_date = ship_date;
	this->price = price;
	
	
}

string product::get_name() {
	return this->name;
}
double product::get_price() {
	return this->price;
}
string product::get_seller() {
	return this->seller;
}
string product::get_ship_date() {
	return this->ship_date;
}



void product::display_prod() {
	cout << "Product ID: " << this->id<<endl;
	cout << "Product Name: " << this->name << endl;
	cout << "Seller: " << this->seller << endl;
	cout << "Shipping Information: " << this->shipping << endl;
	cout << "--------------------------------------------------------------------" << endl << endl;

}

product::~product()
{
}
