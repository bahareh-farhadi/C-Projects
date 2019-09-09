#pragma once
#include <map>
#include <unordered_map>
#include <string>
#include "users.h"
#include "product.h"
#include "orders.h"
using namespace std;
extern unordered_map<string, int> user_list;
extern map<int, users> user_data;
extern map<int, product> product_list;
extern map<int, orders> orders_list;



