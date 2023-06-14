// 220072233_Kibambe_CC2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "HandleStoreOwner.h"
#include "HandleStock.h"



string encryptText(string pwd) {
	string new_pwd;
	for (int i = 0; i < pwd.length(); i++) {
		int ascii_value = (int)pwd[i];
		char new_char = ascii_value ^ 42;
		new_pwd += new_char;
	}
	return new_pwd;
}

int main() {
	cout << "Stock Management System" << endl;
	HandleStoreOwner handleStoreOwner;

	while (true) {
		cout << endl << "-Menu" << endl;
		cout << "1. Stock Owner" << endl;
		cout << "2. Customer" << endl;
		cout << "Option: ";
		int menu; cin >> menu;

		if (menu == 1) {
			while (true) {
				cout << endl << "1. Login.";
				cout << endl << "2. Register.";
				cout << endl << "Option: ";
				int managerMenu; cin >> managerMenu;
				if (managerMenu == 1) {
					cout << endl << "- Shop owner Login" << endl;
					cout << endl << "Enter owner email: ";
					string phone; cin >> phone;
					cout << "Enter owner password: ";
					string pwd; cin >> pwd;
					// 
					pwd = encryptText(pwd);
					bool result = handleStoreOwner.login(phone, pwd);
					if (result) { 
						HandleStock handleStock;
						while (true) {
							cout << endl << "- Menu:" << endl;
							cout << "1. Add Stock." << endl;
							cout << "2. Delete Stock." << endl;
							cout << "3. Stock Value." << endl;
							cout << "4. Stock Size." << endl;
							cout << "5. Display." << endl;
							cout << "Option: ";
							int option; cin >> option;
							if (option < 1 || option > 5) { break; }

							switch (option) {
							case 1: {
								cout << endl << "Add Product" << endl;
								cout << "Product name: ";
								string name; cin >> name;
								cout << "Product price: ";
								double price; cin >> price;
								cout << "Product quantity: ";
								int quantity; cin >> quantity;

								Stock stock(name, price, quantity);
								bool result = handleStock.addProduct(stock);

								if (result == true) { cout << endl << "Product added" << endl; }
								else { cout << endl << "Product not added" << endl; }
								break;
							}
							case 2: {
								cout << endl << "Delete a product" << endl;
								cout << "Enter name of product to delete" << endl;
								string nameDel; cin >> nameDel;
								bool result = handleStock.removeProduct(nameDel);
								if (result == true) { cout << endl << "Product deleted" << endl; }
								else { cout << endl << "Product not deleted" << endl; }
								break;
							}
							case 3: {
								cout << endl << "Stock Value" << endl;
								double stock_val = handleStock.calculateStockValue();
								cout << "Stock Value: " << stock_val << endl;
								break;
							}
							case 4: {
								cout << endl << "Stock Size" << endl;
								double stock_size = handleStock.calculateStockSize();
								cout << "Stock Size: " << stock_size << endl;
								break;
							}
							case 5: {
								cout << endl << "Display" << endl;
								handleStock.displayProducts();
								break;
							}
							default: break;
							}
						}
					}
					else { cout << endl << "shop owner not found.." << endl; }
				}
				else if (managerMenu == 2) {
					cout << endl << endl << "Store Onwer Signup" << endl;
					cout << "Enter shop owner email: ";
					string email; cin >> email;
					cout << "Enter shop owner name: ";
					string name; cin >> name;
					cout << "Enter shop owner password: ";
					string pwd; cin >> pwd;
					pwd = encryptText(pwd);
					StoreOwner owner(email, name, pwd);
					bool res = handleStoreOwner.signup(owner);
					if (res) { cout << endl << "shop owner signed up." << endl; }
					else { cout << endl << "shop owner not signed up." << endl; }
				}
				else { break; }
			}
		}
		else if (menu == 2) {
			HandleStock handleStock;
			while (true) {
				cout << endl << "- Csutomers" << endl;
				cout << "1. Buy Items" << endl;
				cout << "2. Show Stocks" << endl;
				cout << "Menu: ";
				int choice; cin >> choice;

				if (choice == 1) {
					cout << endl << "- Buy Product" << endl;
					cout << "Enter name of product to buy: ";
					string name; cin >> name;
					cout << "Enter quantity to buy: ";
					int quant; cin >> quant;
					bool result = handleStock.purchase(name, quant);
					if (result) { cout << endl << "Purchase successful" << endl; }
					else { cout << endl << "Purchase unsuccessful" << endl; }
				}
				else if (choice == 2) {
					cout << endl << "Stocks" << endl;
					handleStock.displayProducts();
				}
				else { break; }
			}
		}
		else { return 0; }
	}
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file