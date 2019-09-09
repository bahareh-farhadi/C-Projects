#pragma once
#include <string>
#include <vector>
#include "order_item.h"
#include <map>
using namespace std;
class orders
{
private:
	//data for creating a new order
	int user_id;
	typedef map<int, order_item> map_inside_vect;

	vector<map_inside_vect> items;
	string current_date;

public:
	orders(int item_id,int user_id);
	void track_orders(int order_id);

	//changes made: add items, edit numbers of each product, delete items
	void edit_order(int order_id);
	void cancel_order(int order_id);
	~orders();
};

