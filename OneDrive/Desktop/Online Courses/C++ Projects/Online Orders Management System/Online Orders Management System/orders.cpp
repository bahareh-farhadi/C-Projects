#include "orders.h"
#include "common.h"


orders::orders(int item_id,int user_id)
{
	this->user_id;
	//to be calculated
	this->current_date = "";
	product chosen=product_list.find(item_id)->second;
	cout << "How many of this product are you requesting?";
	int num=0;
	cin >> num;
	while (num < 1) {
		cout << "ERROR: Number requested is invalid. Try again: ";
		cin >> num;
	}
	order_item new_item(num, chosen.get_name(), chosen.get_seller(), chosen.get_ship_date(), chosen.get_price());
	//order_item new_item(number,chosen.get_name(),chosen.get_seller(),chosen.get_ship_date(),chosen.get_price());
	
}



void orders::track_orders(int order_id) {
	if (orders_list.find(order_id) != orders_list.end()) {
		orders chosen = orders_list.find(order_id)->second;
		//iterating through the vector of maps
		for (auto it = chosen.items.begin(); it != chosen.items.end(); it++) {

			//iterating through each map; basically each map is one of the items in the order
			for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
				//status options:
				//1- shipping pending
				//2- shipped
				//3- delivered
				if (it2->second.get_ship_date() > this->current_date) {
					cout <<"The item: "<<(it2->second).get_name()<< " has not been shipped yet" << endl;
				}
				else if (it2->second.get_delivery_date() > this->current_date && it2->second.get_ship_date() <= this->current_date) {
					cout << "The item: " << it2->second.get_name() << " has been shipped. Estimated delivery: " <<it2->second.get_delivery_date()<< endl;
				}
				else if (it2->second.get_delivery_date() <= this->current_date) {
					cout << "The item: " << it2->second.get_name() << " has been delivered" << endl;
				}
				
			}
		}
	}
	else {
		cout << "ERROR: Order ID does not exist. No Tracking Found" << endl;
	}
	

}

void orders::edit_order(int order_id) {
	cout << "Choose the information you want to edit from the list below" << endl;
	if (orders_list.find(order_id) != orders_list.end()) {
		auto it = orders_list.find(order_id);

	}
	else {
		cout << "ERROR: Order ID Not Found!" << endl;
	}

}

void orders::cancel_order(int order_id) {
	/*if (orders_list.find(order_id) != orders_list.end()) {
		auto it = orders_list.find(order_id);
		if (current_date > it->second.) {
			cout << "ERROR: The item has already shipped. The order cannot be cancelled at this point." << endl;
		}
		else {
			delete &(it->second);
			orders_list.erase(order_id);
		}
		
	}
	else {
		cout << "ERROR: Order ID Not Found!" << endl;
	}*/

	auto it = orders_list.find(order_id);
	if (it != orders_list.end()) {
		orders chosen = it->second;
		//looping through the items in an order('items' is a vector)
		for (auto it = chosen.items.begin(); it != chosen.items.end(); it++) {
			//looping through the map
			for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
				if (it2->second.get_ship_date() >= this->current_date) {
					cout << "ERROR: The item has already shipped. It cannot be cancelled at this point";
				}
				else {
					delete &(it2->second);
					it = it - 1;
					(*it).erase(it2->first);
				}
			}
		}
	}
	else {
		cout << "ERROR: Order ID Not Found" << endl;
	}
}

orders::~orders()
{
}
