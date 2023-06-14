#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class StoreOwner {
public:
	string email;
	string password;
	string name;
	StoreOwner();
	StoreOwner(string email, string name, string pwd);
	void displayStoreOwner();
};

