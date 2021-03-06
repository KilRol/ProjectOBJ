#pragma once
#include <fstream>
#include <string>
using namespace std;

class Price {
private: 
	string name;
	string shop;
	int cost;
public:

	//Constructors
	Price();
	Price(string name, string shop, int cost);
	Price(const Price& a);

	//Methods
	string getName();
	string getShop();

	//Compare
	bool operator>(const Price a);
	bool operator<(const Price a);
	bool operator==(const Price a);
	bool operator!=(const Price a);

	//I/O
	friend istream& operator>>(istream& is, Price& a);
	friend ostream& operator<<(ostream& os, const Price a);

	//binary I/O
	void writeBin(fstream& file);
	void readBin(fstream& file);
};