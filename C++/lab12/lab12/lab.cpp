#include "lab.h"

///////////////////////////////////////////////////////////////
                      //METHODS
///////////////////////////////////////////////////////////////
fVector::fVector() {//Default costructor
    size = 5;
    vect = new float[size];
    for (int i = 0; i < size; i++) vect[i] = 0;
}

fVector::fVector(int s) { //Cuctom constructor
    size = s;
    if (size > 100 || size < 1) {
        cout << "Error size" << endl;
    }
    else {
        vect = new float[size];
        for (int i = 0; i < size; i++) vect[i] = 0;
    }
}

fVector::fVector(const fVector& b) {
    size = b.size;
    vect = new float[size];
    for (int i = 0; i < size; i++) vect[i] = b.vect[i];
}

fVector::fVector(float* arr, int s) {
    size = s;
    vect = new float[size];
    for (int i = 0; i < size; i++) vect[i] = arr[i];
}

fVector::~fVector() {//Destructor
    delete[] vect;
}

void fVector::set_size(int s) {//Set new size with saving old coordinates
    if (s <= 100 && s != size) {
        if (s > size) {
            fVector buf(size);
            for (int i = 0; i < size; i++) buf.vect[i] = vect[i];
            delete[] vect;
            vect = new float[s];
            for (int i = 0; i < size; i++) vect[i] = buf.vect[i];
            this->size = buf.size;
        }
        else if (s < size) {
            fVector buf(s);
            for (int i = 0; i < s; i++) buf.vect[i] = vect[i];
            delete[] vect;
            vect = new float[s];
            for (int i = 0; i < s; i++) vect[i] = buf.vect[i];
            this->size = buf.size;
        }
    }
}

int fVector::get_size() const {
    return size;
}

void fVector::set_coordinate(int i, float val) {//Set coordinate
    if (0 <= i < 100) {
        vect[i] = val;
    }
    else {
        cout << "Incorrect index" << endl;
    }
}

float fVector::get_coordinate(int i) const {
    if (0 <= i < 100) {
        return vect[i];
    }
    else {
        cout << "Error index" << endl;
    }
}

void fVector::print() const {//Get vector
    cout << "{";
    for (int i = 0; i < size; i++) {
        cout << vect[i] << " ";
    }
    cout << "}" << endl;
    cout << endl;
}

void fVector::read() {//Read vector
    cout << "Enter your coordinates vector(" << size << "): ";
    for (int i = 0; i < size; i++) cin >> vect[i];
    cout << endl;
}

///////////////////////////////////////////////////////////////
                      //OPERATORS
///////////////////////////////////////////////////////////////
fVector& fVector::operator=(const fVector& b) {//Overloaded =
    if (&b == this) return *this;
    size = b.size;
    vect = new float[size];
    for (size_t i = 0; i < size; i++) vect[i] = b.vect[i];
    return *this;
}

fVector& fVector::operator+=(const fVector& b) {//Overloaded +=
    if (b.size != this->size) {
        cout << "You cannot substract vectors with different sizes" << endl;
    }
    else {
        for (int i = 0; i < this->size; i++) {
            vect[i] += b.vect[i];
        }
        return (*this);
    }
}

fVector& fVector::operator-=(const fVector& b) {//Overloaded -=
    if (b.size != this->size) {
        cout << "You cannot substract vectors with different sizes" << endl;
    }
    else {
        for (int i = 0; i < this->size; i++) {
            vect[i] -= b.vect[i];
        }
        return (*this);
    }
}

fVector& fVector::operator*=(const fVector& b) {
    if (b.size != this->size) {
        cout << "You cannot multiplicate vectors with different sizes" << endl;
    }
    for (int i = 0; i < this->size; i++) {
        vect[i] *= b.vect[i];
    }
    return (*this);
}

fVector& fVector::operator*=(float b) {
    for (int i = 0; i < this->size; i++) {
        vect[i] *= b;
    }
    return (*this);
}

fVector operator+(fVector a, const fVector& b) {//Overloaded +
    return a += b;
}

fVector operator-(fVector a, const fVector& b) {//Overloaded -
    return a -= b;
}

fVector operator*(fVector a, const fVector& b) {//Overloaded +
    return a *= b;
}

fVector operator*(fVector a, float b) {//Overloaded +
    return a *= b;
}