#pragma once

#include <iostream>

extern int countId;

class worker {
protected:
	char* name;
	int id;
	
public:
	//worker();
	//worker(const char* n);
	virtual int getId() const;
	virtual ~worker();
	virtual int calcSalary() = 0;
	virtual std::ostream& print(std::ostream& os) = 0;
	friend std::ostream& operator<<(std::ostream& os, worker& worker) { return worker.print(os); };
};

//developer
//sale
//accountant