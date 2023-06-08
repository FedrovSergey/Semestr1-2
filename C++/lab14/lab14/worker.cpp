#include "worker.h"
#include <iostream>

using namespace std;

//worker::worker() {
//	name = new char[5];
//	*name = (char)"None\0";
//	id = countId++;
//}
//
//worker::worker(const char* n) {
//	name = new char[strlen(n) + 1];
//	strcpy(name, n);
//	id = countId++;
//}

worker::~worker() {
	delete[]name;
}

int worker::getId() const{
	return this->id;
}