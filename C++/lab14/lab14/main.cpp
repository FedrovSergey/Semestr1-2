#include "workerBase.h"
#include "developer.h"
#include "sale.h"
#include "accountant.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream outputFile("file.txt");
	workerBase base;
	developer d1("mixa", 1000, 2, 1.1, 1);
	sale s1("max", 100, 0.1, 100, "gre");
	accountant a1("masha", 1000);
	developer d2("mixa2", 10000, 2, 1.1, 1);
	base.add(&d1);
	base.add(&s1);
	base.add(&a1);
	base.add(&d2);
	/*cout << base.calcTotalSalary() << endl;
	base.erase(2);
	cout << base.calcTotalSalary();*/
	base.save(outputFile);
	return 0;
}

//метод save, который сохраняет информацию о workerах в текстовый файл, реализовать на основе перегрузки <<