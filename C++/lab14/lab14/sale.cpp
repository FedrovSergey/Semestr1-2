#include "sale.h"
#include <iostream>

using namespace std;

sale::sale(const char* n, int a, double b, int c, const char* l) {
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	id = countId++;
	this->num = a;
	this->percent = b;
	this->price = c;
	this->place = new char[strlen(l) + 1];
	strcpy(this->place, l);
}

sale::~sale() {
	delete[] place;
}

int sale::calcSalary() {
	return this->percent * this->price * this->num;
}

char* sale::getName() const{
	return this->name;
}

int sale::getId() const {
	return this->id;
}

int sale::getNum() const {
	return this->num;
}

int sale::getPercent() const {
	return this->percent;
}

int sale::getPrice() const {
	return this->price;
}

char* sale::getPlace() const {
	return this->place;
}

ostream& sale::print(ostream& os) {
	os << this->id << ' ' << this->name << ' ' << this->num << ' '
		<< this->percent << ' ' << this->price << ' ' << this->place << endl;
	return os;
}
