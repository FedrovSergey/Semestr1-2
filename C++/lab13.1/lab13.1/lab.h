#ifndef _lab_
#define _lab_
#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;
public:
    Time(const Time&);
    Time(int s = 0);
    void setHours(int i);
    void setMinutes(int i);
    void setSeconds(int i);
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    void printBigTime(int a);
    Time& operator=(const Time& b);
    friend std::istream& operator >> (std::istream& is, Time& a);
    friend std::ostream& operator<<(std::ostream& os, const Time& time);
    Time& operator+=(int b);
    Time& operator++();
    Time& operator--();
    Time operator++(int);
    Time operator--(int);

};
Time operator +(Time a, int b);
std::ostream& operator<<(std::ostream& strm, const Time& time);
bool operator ==(const Time& a, const Time& b);
bool operator <(const Time& a, const Time& b);
bool operator >(const Time& a, const Time& b);
bool operator >=(const Time& a, const Time& b);
bool operator <=(const Time& a, const Time& b);
bool operator !=(const Time& a, const Time& b);
#endif
