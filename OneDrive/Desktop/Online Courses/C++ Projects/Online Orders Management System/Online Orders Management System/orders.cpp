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
	if (orders_list.find(order_id) != orders_list.end()) {
		auto it = orders_list.find(order_id);
		if (current_date > it->second.shipping_date) {
			cout << "ERROR: The item has already shipped. The order cannot be cancelled at this point." << endl;
		}
		else {
			delete &(it->second);
			orders_list.erase(order_id);
		}
		
	}
	else {
		cout << "ERROR: Order ID Not Found!" << endl;
	}
}

orders::~orders()
{
}
