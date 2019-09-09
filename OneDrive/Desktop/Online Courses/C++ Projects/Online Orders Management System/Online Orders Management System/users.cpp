#include "users.h"
#include "common.h"
#include <algorithm>
users::users()
{
	std::map<int,users >::reverse_iterator last_it;
	int id = last_it->first;
	id = id + 1;
	cout << "choose a username: ";
	cin >> username;
	while (user_list.find(username) != user_list.end()) {
		cout << "Username already exists. Try again: ";
		cin >> username;
	}
	cout << "Choose a password: ";
	cin >> pass;
	cout << "Enter your full name: ";
	cin >> name;
	cout << "Enter your billing address: ";
	cin >> address;
	cout << "Enter your phone number: ";
	cin >> number;
	cout << "Enter your email address: ";
	cin >> email;
	cout << "Enter your credit card information: ";
	cin >> credit;
	user_data.insert({ id,*this });
		
}


void users::show_accounts() {
	cout << "Displaying all accounts:" << endl << endl;


	for (auto it = user_data.begin(); it != user_data.end(); it++) {
		cout << "Username = " << it->second.username;
		cout << "Name = " << it->second.name;
		cout << "Email = " << it->second.email;
		cout << "Phone Number = " << it->second.number;
		cout << "Billing Address = " << it->second.address;
		cout << "credit Card Info = " << it->second.username;
	}

}

//gets username or the first few characters and applies autocomplete in order to find the user id
//returns the user id if found
//ERROR handling:
//if no user in the database: create one
//if username not found: try again
int users::search_accounts (string n) {
	int id;
	if (user_list.size() > 0) {
		//autocomplete
		int size = n.size();
		if (size > 0) {
			unordered_map<string, int> temp_list;
			transform(n.begin(), n.end(), n.begin(), [](unsigned char c) { return tolower(c); });
			string temp;
			for (auto it = user_list.begin(); it != user_list.end(); it++) {
				if (it->first.size() >= size) {
					temp = it->first.substr(0, size);
					temp_list.insert({ temp,it->second });
			 }
				
			}
			
			map<string, int> temp_list_ordered(temp_list.begin(), temp_list.end());
			if (temp_list_ordered.find(n) != temp_list_ordered.end()) {
				id = temp_list_ordered.find(n)->second;
			}
			else {
				cout << "ERROR: username not found. Try again" << endl;

				//ID=0 means that the username should try again and search a new username
				id =0;
			}
			
			
		}
	}
	else {
		cout << "No username in the list yet. Try adding a username";

		//ID=-1 means the user should add a username to the list since it is empty
		id = -1;
	}
	return id;

}
void users::edit_accounts(int id) {

}
void users::delete_accounts(int id) {
	delete &(user_data.find(id)->second);
	user_data.erase(id);
}

users::~users()
{
}
