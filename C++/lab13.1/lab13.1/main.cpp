#include "lab.h"
using namespace std;
int main() {
	/*Time b;
	cout << b << endl;
	Time a = b;
	a += 60;
	cout << a << endl;
	b = b + 150;
	cout << b << endl;
	bool c = (a <= b);
	cout << c << endl;*/
	Time b;
	b.printBigTime(31536000+3661);
	return 0;
}

//добавить метод принимающий на вход количество секунд, выводящий их на экран, как количество лет, месяцев, недель, дней и т.д.