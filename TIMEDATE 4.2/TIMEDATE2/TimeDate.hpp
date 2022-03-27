#include <string>

using namespace std;

#ifndef TIMEDATE_H
#define TIMEDATE_H

class TimeClass
{
public:
    TimeClass(int v, int m, int s);
    TimeClass();
    ~TimeClass();
    void addTime(int n);
    string showTimeLT();
    string showTimeGER();
    string showTimeUSA();
    string showTimeUK();
    string showTimeCA();
    void setHour();
    void setHour(int n);
    void setMinute();
    void setMinute(int n);
    void setSecond();
    void setSecond(int n);
    int getHour();
    int getMinute();
    int getSecond();


private:
    int hour;
    int minute;
    int second;
    int* h = &hour;
    int* m = &minute;
    int* s = &second;
};

#endif
