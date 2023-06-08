#include "accountant.h"
#include <iostream>

using namespace std;

accountant::accountant(const char* n, int a) {
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	id = countId++;
	this->salary = a;
}

int accountant::calcSalary() {
	int bonus = 0;
	cout << "enter bonus of accountant " << name<< ':';
	cin >> bonus;
	return this->salary + bonus;
}

char* accountant::getName() const {
	return this->name;
}

int accountant::getId() const {
	return this->id;
}

int accountant::getSalary() const {
	return this->salary;
}

ostream& accountant::print(ostream& os) {
	os << this->id << ' ' << this->name << ' ' << this->salary << endl;
	return os;
}
