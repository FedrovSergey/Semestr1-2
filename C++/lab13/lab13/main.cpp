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
	cout << b.bigTime(31536000);
	return 0;
}
//int f = 100;
////char* r = (char*)malloc(4);
//char r[4];
//itoa(f, r, 10);
//cout << r;

/*int k = 100;
	char t[4];
	char* f = NULL;
	itoa(k, t, 10);
	for (int i = 0; i < 4; i++) {
		f = (char*)realloc(f, i + 1);
		f[i] = t[i];
	}
	cout << f;*/

//добавить метод принимающий на вход количество секунд, переводит это в строку, как количество лет, месяцев, недель, дней и т.д.

//14 лаба (1)