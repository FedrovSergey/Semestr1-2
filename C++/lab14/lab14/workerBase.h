#pragma once
//����� save, ������� ��������� ���������� � worker�� � ��������� ����, ����������� �� ������ ���������� <<
#include "worker.h"

class workerNode {
private:
	workerNode* next;
	worker* worker;
public:
	friend class workerBase;
};

class workerBase {
private:
	workerNode* head;
	size_t size;
public:
	workerBase();
	~workerBase();
	void add(worker* pers);
	bool find(int id)const;
	void erase(int id);
	int calcTotalSalary();
	void save(std::ofstream& outputFile);
};

//Class WorkerBase{
//private:
//?
//public:
//	void add(? );
//	void erase(? );
//	? find(? );
//	int calcTotalSalary(); //������ ������ ������ ���������� ����� � �����
//};
