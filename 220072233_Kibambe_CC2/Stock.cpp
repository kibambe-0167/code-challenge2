#include "Stock.h"

Stock::Stock() {
	Stock::setPrice(0.0);
	Stock::setQuantity(0);
}

bool Stock::sortByStockName(const Stock& s1, const Stock& s2) { return s1.name < s2.name;  }

Stock::Stock(string name, double price, int quantity) {
	Stock::setName(name);
	Stock::setPrice(price);
	Stock::setQuantity(quantity);
}

double Stock::getPrice() { return Stock::price; }
int Stock::getQuantity() { return Stock::quantity; }
string Stock::getName() { return Stock::name; }

void Stock::setPrice(double price) { Stock::price = price; }
void Stock::setQuantity(int quantity) { Stock::quantity = quantity; }
void Stock::setName(string name) { Stock::name = name; }

void Stock::display() {
	cout << Stock::getName()
		<< "\tR" << Stock::getPrice()
		<< "\t" << Stock::getQuantity() << endl;
}