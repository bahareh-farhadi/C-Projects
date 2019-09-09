#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include "common.h"
#include "product.h"


using namespace std;
unordered_map<string, int> user_list;
map<int, users> user_data;
map<int, product> product_list;
map<int, orders> orders_list;
void user_management(int n);
void init_products();
int main() {
	cout << "Author: Bahareh Farhadi" << endl << "Welcome to the Online Orders Management System" << endl<<endl;
	cout << "Menu:" << endl;
	init_products();
	ifstream file_reader;
	file_reader.open("Menu Options.txt");
	if (!file_reader) {
		cerr << "Unable to display menu options" << endl;
		exit(1);
	}
	else {
		string option;
		while (getline(file_reader,option,'\0')) {
			cout << option<<endl;
		}
	}
	file_reader.close();
	cout << "Please Choose a Menu Item to Continue";
	int item;
	cin >> item;
	for (auto it = product_list.begin(); it != product_list.end(); it++) {
		it->second.display_prod();
	}
	int n;
	cin >> n;
	//user_management(item);
	return 0;

}

void user_management(int n) {

	////New Order 
	//if (n == 1) {
	//	cout << "New Online Order Menu" << endl;
	//	cout << "Enter your username: ";
	//	string username;
	//	cin >> username;
	//	while (user_list.find(username)==user_list.end()) {
	//		cout << "Username does not exist. Please create one";
	//		
	//	}
	//	int id = user_list.find(username)->second;
	//	string data;
	//	for (auto it = user_data.find(id);it->first == id && it != user_data.end(); it++) {
	//		data = it->second;
	//		cout << data << endl;
	//	}
	//	cout << "Is the information above correct?(y/n)";
	//	string answer;
	//	cin >> answer;
	//	while (answer != "y" || answer != "n") {
	//		cin >> answer;
	//	}
	//	if (answer == "n") {
	//		//make edits
	//	}
	//	
	//	/*else {
	//		cout << "Password: ";
	//		string pass;
	//		cin >> pass;
	//		while (user_list.find(username)->second != pass) {
	//			cout << "Wrong Password. Try Again";
	//			cin >> pass;
	//		}
	//		
	//		cout << "Enter your billing address: ";
	//	    
	//		


	//	}*/

	//}

	////Track Orders
	//else if (n == 2) {

	//}

	////Edit Orders
	//else if (n == 3) {

	//}

	////Cancel Orders
	//else if (n == 4) {

	//}

	////Show Accounts
	//else if (n == 5) {

	//}

	////Search Accounts
	//else if (n == 6) {

	//}

	////Edit Accounts
	//else if (n == 7) {

	//}

	////Delete Accounts
	//else if (n == 8) {

	//}

	////exit
	//else if (n == 9) {

	//}

}
void init_products() {
	product new_item(1, "Hanna Scallop Mini Dress", "Urban Outfitters", "Within 3-5 Business Days", "",59.00);
	product_list.insert({ 1,new_item});
	product new_item2(2, "High Rise Mom Jeans", "Abercrombie & Fitch", "Within 5-7 Business Days", "",73.00);
	product_list.insert({ 2,new_item2});
	product new_item3(3, "Faux Cropped Leather Jacket", "Zara", "Within 2-3 Business Days", "",120.00);
	product_list.insert({ 3,new_item3});
	
}