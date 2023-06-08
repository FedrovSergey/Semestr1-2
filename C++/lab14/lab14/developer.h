#pragma once
#include "worker.h"

class developer : public worker {
private:
	int base;
	int experience;
	double level;
	bool bonus;
public:
	developer(const char* n, int base, int experience, double level, bool bonus);
	int calcSalary();
	char* getName() const;
	int getId() const;
	int getBase() const;
	int getExperience() const;
	int getLevel() const;
	bool getBonus() const;
	std::ostream& print(std::ostream& os);
};