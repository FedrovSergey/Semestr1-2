#include "lab.h"
int main() {

    float arr[] = { 12.3, 16.98, 15 };
    fVector v2(arr, sizeof(arr)/ sizeof (arr[0]));
    v2.set_coordinate(2, 26.7);
    v2 *= 2;
    v2.print();
}
//создать ещё 1 конструктор, принимающий на вход массив float