#include "StoreOwner.h"


void StoreOwner::displayStoreOwner() {
	cout << "ShopOwner Name: " << StoreOwner::name << " "
		<< "ShopOwner Email: " << StoreOwner::email << " "
		<< "ShopOwner Password: " << StoreOwner::password << endl;
}

StoreOwner::StoreOwner() {
	StoreOwner::email = "";
	StoreOwner::password = "";
	StoreOwner::name = "";
}

StoreOwner::StoreOwner(string email, string name, string password) {
	StoreOwner::email = email;
	StoreOwner::password = password;
	StoreOwner::name = name;
}