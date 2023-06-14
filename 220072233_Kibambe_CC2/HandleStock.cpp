#include "HandleStock.h"



HandleStock::HandleStock() {
	stock_size = 0;
	stock_value = 0.0;
	load();
}

void HandleStock::sort_stocks_name() {
	sort(stocks.begin(), stocks.end(), Stock::sortByStockName);
}

bool HandleStock::purchase(string name, int quant) {
	for (Stock& product : stocks) {
		if (product.getName() == name) {
			if (product.getQuantity() >= quant) {
				product.setQuantity(product.getQuantity() - quant);
				delete_save();
				return true;
			}
			else {
				cout << endl << "Quantity not enough or Product not found." << endl;
				return false;
			}
		}
	}
	return false;
}

bool HandleStock::removeProduct(string name) {
	int i = 0;
	for (Stock product : stocks) {
		if (product.getName() == name) {
			stocks.erase(stocks.begin() + i);
			HandleStock::delete_save(); // update stock items
			HandleStock::sort_stocks_name(); // sort the news items
			return true;
		}
		i++;
	}
	return false;
}

bool HandleStock::addProduct(Stock product) {
	for (Stock& prod : stocks) {
		if (prod.getName() == product.getName()) {
			prod.setQuantity(prod.getQuantity() + product.getQuantity());
			HandleStock::delete_save();
			return true;
		}
	}
	stocks.push_back(product);
	HandleStock::save();
	return true;
}

int HandleStock::calculateStockSize() { return (int)stocks.size();  }

double HandleStock::calculateStockValue() {
	for (Stock prod : stocks) {
		stock_value += prod.getPrice() * prod.getQuantity();
	}
	return stock_value;
}

void HandleStock::displayProducts() {
	if ((int)stocks.size() < 1) { cout << "No products in stock" << endl; return; }
	for (Stock prod : stocks) { prod.display(); }
}

void HandleStock::load() {
	ifstream file(HandleStock::file_path, ios::app);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			string name = line.substr(0, line.find(","));
			line.erase(0, line.find(",") + 1);
			double price = stod(line.substr(0, line.find(",")));
			line.erase(0, line.find(",") + 1);
			int quant = stoi(line.substr(0, line.find(",")));
			line.erase(0, line.find(",") + 1);

			Stock stock(name, price, quant);
			stocks.push_back(stock);
		}
		// sort stock by name
		sort_stocks_name();
	}
	else { cout << endl << "Can't open file.." << endl; }
}

void HandleStock::save() {
	ofstream file(HandleStock::file_path, ios::app);
	if (file.is_open()) {
		for (Stock prod : stocks) {
			file << prod.getName() << "," << prod.getPrice() << "," << prod.getQuantity() << endl;
		}
	}
	else { cout << endl << "Can't open file" << endl; }
}

void HandleStock::delete_save() {
	ofstream file(HandleStock::file_path, ios::trunc);
	if (file.is_open()) {
		for (Stock prod : stocks) {
			file << prod.getName() << "," << prod.getPrice() << "," << prod.getQuantity() << endl;
		}
	}
	else { cout << endl << "Can't open file" << endl; }
}