#pragma warning(disable : 4996)
#include "lab.h"
using namespace std;
///////////////////////////////////////////////////////////////
                      //METHODS
///////////////////////////////////////////////////////////////

Time::Time(int s) { //constructor
    hours = s / 3600;
    minutes = (s - hours * 3600) / 60;
    seconds = s - hours * 3600 - minutes * 60;
}

Time::Time(const Time& b) {
    hours = b.hours;
    minutes = b.hours;
    seconds = b.seconds;
}

void Time::setHours(int i) {//Set hours
    hours = i;
}

void Time::setMinutes(int i) {//Set minutes
    if (0 <= i < 60) {
        minutes = i;
    }
    else {
        cout << "Incorrect amount of minutes" << endl;
    }
}

void Time::setSeconds(int i) {//Set seconds
    if (0 <= i < 60) {
        seconds = i;
    }
    else {
        cout << "Incorrect amount of secondes" << endl;
    }
}

int Time::getHours() const {
    return hours;
}

int Time::getSeconds() const {
    return seconds;
}

int Time::getMinutes() const {
    return minutes;
}
//year = 31536000 / 8760
//month = 2592000 / 720
//week = 604800 / 168
//day = 86400 / 24
void Time::printBigTime(int a) {
    char* string = (char*)malloc(1);
    char temp[4];
    int i = 0;
    int j = 0;
    *this += a;
    if (hours >= 8760) {
        a = hours / 8760;
        hours = hours - a * 8760;
        itoa(a, temp, 10);
        while (temp[j] != '\0') {
            string = (char*)realloc(string, i + 2);
            string[i++] = temp[j++];
        }
    }
    else {
        string = (char*)realloc(string, i + 2);
        string[i++] = '0';
    }
    string[i++] = ':';
    j = 0;
    char temp2[3];
    if (hours >= 720) {
        a = hours / 720;
        hours = hours - a * 720;
        itoa(a, temp2, 10);
        while (temp2[j] != '\0') {
            string = (char*)realloc(string, i + 2);
            string[i++] = temp2[j++];
        }
    }
    else {
        string = (char*)realloc(string, i + 2);
        string[i++] = '0';
    }
    string[i++] = ':';
    j = 0;
    if (hours >= 168) {
        a = hours / 168;
        hours = hours - a * 168;
        itoa(a, temp2, 10);
        while (temp2[j] != '\0') {
            string = (char*)realloc(string, i + 2);
            string[i++] = temp2[j++];
        }
    }
    else {
        string = (char*)realloc(string, i + 2);
        string[i++] = '0';
    }
    string[i++] = ':';
    j = 0;
    if (hours >= 24) {
        a = hours / 24;
        hours = hours - a * 24;
        itoa(a, temp2, 10);
        while (temp2[j] != '\0') {
            string = (char*)realloc(string, i + 2);
            string[i++] = temp2[j++];
        }
    }
    else {
        string = (char*)realloc(string, i + 2);
        string[i++] = '0';
    }
    string[i++] = ':';
    j = 0;
    itoa(hours, temp2, 10);
    while (temp2[j] != '\0') {
        string = (char*)realloc(string, i + 2);
        string[i++] = temp2[j++];
    }
    string[i++] = ':';
    j = 0;
    itoa(minutes, temp2, 10);
    while (temp2[j] != '\0') {
        string = (char*)realloc(string, i + 2);
        string[i++] = temp2[j++];
    }
    string[i++] = ':';
    j = 0;
    itoa(seconds, temp2, 10);
    while (temp2[j] != '\0') {
        string = (char*)realloc(string, i + 1);
        string[i++] = temp2[j++];
    }
    string[i] = '\0';
    cout << string << endl;
}

///////////////////////////////////////////////////////////////
                      //OPERATORS
///////////////////////////////////////////////////////////////

Time& Time::operator=(const Time& b) {//Overloaded =
    if (&b == this) return *this;
    hours = b.hours;
    minutes = b.minutes;
    seconds = b.seconds;
    return *this;
}

bool operator ==(const Time& a, const Time& b) {//Overloaded ==
    return a.getHours() == b.getHours() && a.getMinutes() == b.getMinutes() && a.getSeconds() == b.getSeconds();
}

bool operator <(const Time& a, const Time& b) {
    return a.getHours() < b.getHours() || a.getHours() == b.getHours() && a.getMinutes() < b.getMinutes() || a.getHours() == b.getHours() && a.getMinutes() == b.getMinutes() && a.getSeconds() < b.getSeconds();
}

bool operator >(const Time& a, const Time& b) {
    return b < a;
}

bool operator >=(const Time& a, const Time& b) {
    return !(a < b);
}

bool operator <=(const Time& a, const Time& b) {
    return !(a > b);
}

bool operator !=(const Time& a, const Time& b) {
    return !(a == b);
}

ostream& operator<<(ostream& os, const Time& time) {
    os << time.hours << ':' << time.minutes << ':' << time.seconds;
    return os;
}

istream& operator >> (istream& is, Time& a) {
    is >> a.hours >> a.minutes >> a.seconds;
    if (a.seconds >= 60) {
        a.minutes += a.seconds / 60;
        a.seconds = a.seconds % 60;
    }
    if (a.minutes >= 60) {
        a.hours += a.minutes / 60;
        a.minutes = a.minutes % 60;
    }
    return is;
}

Time& Time::operator+=(int b) {//Overloaded +=
    seconds += b;
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds %= 60;
    }
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    return (*this);
}

Time operator +(Time a, int b) {
    a += b;
    return a;
}

// prefix
Time& Time::operator++() {
    (*this).seconds++;
    return (*this);
}


Time& Time::operator--() {
    (*this).seconds--;
    return (*this);
}


// postfix
Time Time::operator++(int) {
    Time a(*this);
    (*this).seconds++;
    return a;
}


Time Time::operator--(int) {
    Time a(*this);
    (*this).seconds--;
    return a;
}

//Создайте класс Time с операциями + (int), +=(int), == , != , > , < , >= , <= , ++, --. (int)-секунды.