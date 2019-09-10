#include "order_item.h"

order_item::order_item(int number,string name,string seller, string ship_date,double price)
{
	this->number = number;
	this->name = name;
	this->seller = seller;
	this->ship_date = ship_date;
	this->price = price;
	//to be calculated: using the shipping date and current date inheritted from the product class 
	this->delivery_date = "";
	//this->delivery_date = ship_date + "";
}

string order_item::get_ship_date() {
	return this->ship_date;

}
string order_item::get_delivery_date() {
	return this->delivery_date;

}
string order_item::get_name() {
	return this->name;
}




order_item::~order_item()
{
}
