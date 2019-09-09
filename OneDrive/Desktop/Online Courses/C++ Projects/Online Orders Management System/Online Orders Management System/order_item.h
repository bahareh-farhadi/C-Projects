#pragma once
#include "product.h"
class order_item
{
private:
	int number;
	string delivery_date;
	string name, seller, ship_date;
	double price;
public:
	order_item(int number, string name, string seller, string ship_date, double price);
	~order_item();
};

