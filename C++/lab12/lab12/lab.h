#ifndef _lab_
#define _lab_
#include <iostream>
using namespace std;

class fVector {
private:
    int size;
    float* vect;
public:
    fVector();
    fVector(const fVector&);
    fVector(int);
    fVector(float* arr, int s);
    ~fVector();
    void set_size(int);
    int get_size() const;
    void set_coordinate(int, float);
    float get_coordinate(int) const;
    void print() const;
    void read();
    fVector& operator=(const fVector&);
    fVector& operator+=(const fVector&);
    fVector& operator-=(const fVector&);
    fVector& operator*=(const fVector&);
    fVector& operator*=(float);
};

fVector operator+(fVector, const fVector&);
fVector operator-(fVector, const fVector&);
fVector operator*(fVector, const fVector&);
fVector operator*(fVector, float);

#endif