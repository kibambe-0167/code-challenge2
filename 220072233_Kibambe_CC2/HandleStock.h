#pragma once
#include "Stock.h"
#include <vector>
#include <algorithm>
#include <fstream>

class HandleStock {
private:
	int stock_size;
	double stock_value;
	vector<Stock> stocks;
	string file_path = "stocks.txt";
public:
	HandleStock();
	bool addProduct(Stock);
	bool removeProduct(string);
	void displayProducts();
	bool purchase(string, int);
	double calculateStockValue();
	int calculateStockSize();
	void load();
	void save();
	void delete_save();
	void sort_stocks_name();
};
