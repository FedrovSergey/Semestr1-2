#include "developer.h"
#include <iostream>

using namespace std;

int countId = 1;

developer::developer(const char* n, int a, int b, double c, bool d) {
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	id = countId++;
	this->base = a;
	this->experience = b;
	this->level = c;
	this->bonus = d;
}

int developer::calcSalary() {
	if (bonus == 1) {
		int i = 0;
		std::cout << "enter bonus of developer " << name << ':';
		std::cin >> i;
		return this->base + this->level * 1000 + i;
	}
	else return this->base + this->level * 1000;
}

//(ставка + квалификация * 1000$ + премия за проект)

char* developer::getName() const {
	return this->name;
}

int developer::getId() const {
	return this->id;
}

int developer::getBase() const {
	return this->base;
}

int developer::getExperience() const {
	return this->experience;
}

int developer::getLevel() const {
	return this->level;
}

bool developer::getBonus() const {
	return this->bonus;
}


ostream& developer::print(ostream& os) {
	os<< this->id << ' ' << this->name << ' ' << this->base << ' '
		<< this->experience << ' ' << this->level << ' ' << this->bonus << endl;
	return os;
}

