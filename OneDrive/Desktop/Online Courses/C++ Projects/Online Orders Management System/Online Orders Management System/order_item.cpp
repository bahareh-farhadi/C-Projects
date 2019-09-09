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




order_item::~order_item()
{
}
