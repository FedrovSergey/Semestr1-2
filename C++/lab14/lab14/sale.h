#pragma once
#include "worker.h"

class sale : public worker {
private:
	int num;
	double percent;
	int price;
	char* place;
public:
	sale(const char* n, int num, double percent, int price, const char* place);
	~sale();
	int calcSalary();
	char* getName() const;
	int getId() const;
	int getNum() const;
	int getPercent() const;
	int getPrice() const;
	char* getPlace() const;
	std::ostream& print(std::ostream& os);
};
