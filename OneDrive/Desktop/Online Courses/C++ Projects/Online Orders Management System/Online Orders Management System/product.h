#pragma once
#include <string>
#include <iostream>
using namespace std;
class product
{
protected:
	int id;
	string name, seller,shipping,ship_date;
	double price;
public:
	product(int id,string name,string seller,string shipping,string ship_date,double price);
	string get_name();
	string get_seller();
	string get_ship_date();
	double get_price();
	void display_prod();
	~product();
};

