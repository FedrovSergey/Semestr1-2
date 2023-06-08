#pragma once
#include "worker.h"

class accountant : public worker {
private:
	int salary;
public:
	accountant(const char* n, int salary);
	int calcSalary();
	char* getName() const;
	int getId() const;
	int getSalary() const;
	std::ostream& print(std::ostream& os);
};