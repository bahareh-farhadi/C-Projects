#pragma once
#include <string>
#include <iostream>
using namespace std;
class users
{
private:
	string username, pass, address, email, credit,number,name;
public:
	//for adding new users

	users();
	void show_accounts();
	//returns id
	int search_accounts(string n);
	void edit_accounts(int id);
	void delete_accounts(int id);

	~users();
};

