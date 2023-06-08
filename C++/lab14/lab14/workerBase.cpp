#include "workerBase.h"
#include <iostream>
#include <fstream>

using namespace std;

workerBase::workerBase(){
	head = nullptr;
	size = NULL;
}

workerBase::~workerBase()
{
	workerNode* cur = head;
	if (cur == nullptr)return;
	while (cur->next != nullptr){
		head = cur;
		cur = cur->next;
		delete head;
	}
}

void workerBase::add(worker* pers){
	workerNode* cur = new workerNode;
	cur->worker = pers;
	if (head == nullptr){
		head = cur;
		cur->next = nullptr;
	}
	else{
		cur->next = head;
		head = cur;
	}
}

bool workerBase::find(int id)const{
	workerNode* cur = head;
	if (cur == nullptr)return false;
	while (cur != nullptr){
		if (cur->worker->getId() == id) {
			return true;
		}
		cur = cur->next;
	}
	return false;
}

void workerBase::erase(int id){
	workerNode* cur = head, * n;
	if (cur->worker->getId() == id){
		head = cur->next;
		delete cur;
	}
	while (cur->next->worker->getId() != id){
		cur = cur->next;
		if (cur->next == nullptr)return;
	}
	n = cur->next;
	cur->next = cur->next->next;
	delete n;
}

int workerBase::calcTotalSalary() {
	int k = 0;
	workerNode* cur = head;
	while (cur != nullptr){
		k += cur->worker->calcSalary();
		cur = cur->next;
	}
	return k;
}

void workerBase::save(ofstream& outputFile) {
	workerNode* cur = head;
	if (cur == nullptr)outputFile << "List is empty";
	else {
		while (cur != nullptr) {
			outputFile << *(cur->worker);
			cur = cur->next;
		}
	}
}