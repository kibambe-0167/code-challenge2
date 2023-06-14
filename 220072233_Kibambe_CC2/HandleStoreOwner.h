#pragma once
#include "StoreOwner.h"
#include <fstream>

class HandleStoreOwner {
	public:
		string file_path;
		vector<StoreOwner> storeOwners;
		HandleStoreOwner();
		bool signup(StoreOwner);
		bool removeManager(string email, string pwd);
		void displayManagers();
		bool login(string, string);
		void load();
		void save();
		void trunc_save();
};