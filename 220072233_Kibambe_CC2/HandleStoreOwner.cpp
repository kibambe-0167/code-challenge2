#include "HandleStoreOwner.h"
using namespace std;

HandleStoreOwner::HandleStoreOwner() { 
	file_path = "storeowners.txt";
	load();
}

void HandleStoreOwner::displayManagers() {
	for (StoreOwner storeOwner : storeOwners) {
		storeOwner.displayStoreOwner();
	}
}

bool HandleStoreOwner::signup(StoreOwner owner) {
	storeOwners.push_back(owner);
	save();
	return true;
}

bool HandleStoreOwner::removeManager(string email, string password) {
	int i = 0;
	for (StoreOwner& owner: storeOwners) {
		if (owner.email == email && password == owner.password) {
			storeOwners.erase(storeOwners.begin() + i);
			trunc_save();
			return true;
		}
		i++;
	}
	return false;
}

bool HandleStoreOwner::login(string email, string password) {
	for (StoreOwner owner : storeOwners) {
		if (owner.email == email && owner.password == password) { return true; } 
	}
	return false;
}

void HandleStoreOwner::load() {
	ifstream file(file_path, ios::app);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			string email = line.substr(0, line.find(","));
			line.erase(0, line.find(",") + 1);
			string name = line.substr(0, line.find(","));
			line.erase(0, line.find(",") + 1);
			string passowrd = line.substr(0, line.find(","));
			line.erase(0, line.find(",") + 1);

			StoreOwner owner(email, name, passowrd);
			storeOwners.push_back(owner);
		}
	}
	else { cout << endl << "Unable to open file" << endl; }
}

void HandleStoreOwner::trunc_save() {
	ofstream file(file_path, ios::trunc);
	if (file.is_open()) {
		for (StoreOwner owner : storeOwners) {
			file << owner.email << "," << owner.name << "," << owner.password << endl;
		}
	}
	else { cout << endl << "Unable to open file" << endl; }
}

void HandleStoreOwner::save() {
	ofstream file(file_path, ios::app);
	if (file.is_open()) {
		for (StoreOwner owner : storeOwners) {
			file << owner.email << "," << owner.name << "," << owner.password << endl;
		}
	}
	else { cout << endl << "unable to open file" << endl; }
}