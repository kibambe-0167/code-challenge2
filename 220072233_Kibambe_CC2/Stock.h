#pragma once
#include <iostream>
#include <string>
using namespace std;


class Stock {
private:
	string name;
	double price;
	int	quantity;
public:
	Stock();
	Stock(string, double, int);
	void display();
	void setPrice(double);
	void setQuantity(int);
	void setName(string);
	double getPrice();
	int getQuantity();
	string getName();
	static bool sortByStockName(const Stock& stock1, const Stock& stock2);
};

