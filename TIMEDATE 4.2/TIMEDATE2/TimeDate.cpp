#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <assert.h>
#include <stdexcept>
#include "TimeDate.hpp"

using namespace std;

#define DEBUG assert(false)


TimeClass::TimeClass(int hour, int minute, int second) //contructor
{
    TimeClass::setHour(hour);
    TimeClass::setMinute(minute);
    TimeClass::setSecond(second);
}

TimeClass::TimeClass() //default
{
    TimeClass::setHour();
    TimeClass::setMinute();
    TimeClass::setSecond();
}



void TimeClass::addTime(int n) //add time by seconds
{
    if (n < 0)
    {
        throw invalid_argument("Incorrect added time.");
    }
    second += n;
    while (second > 60)
    {
        second -= 60;
        ++minute;
        if (minute >= 60)
        {
            minute -= 60;
            ++hour;
        }
        if (hour >= 24)
        {
            hour -= 24;
        }
    }
} 


string TimeClass::showTimeLT() //Show time based on location
{
    stringstream ss;
    int buffer = hour + 2;
    if (buffer >= 24)
    {
        buffer -= 24;
    }
    if (buffer < 10)
    {
        ss << "0" << buffer;
    }
    else
    {
        ss << buffer;
    }
    buffer = minute;
    if (buffer < 10)
    {
        ss << ":0" << buffer;
    }
    else
    {
        ss << ":" << buffer;
    }
    buffer = second;
    if (buffer < 10)
    {
        ss << ":0" << buffer;
    }
    else
    {
        ss << ":" << buffer;
    }
    ss << " val.";
    return ss.str();
}

string TimeClass::showTimeGER()
{
    int buffer = hour + 1;
    stringstream ss;
    if (hour < 10)
    {
        ss << "0" << hour;
    }
    else
    {
        ss << hour;
    }
    if (minute < 10)
    {
        ss << ":0" << minute;
    }
    else
    {
        ss << ":" << minute;
    }
    if (second < 10)
    {
        ss << ":0" << second;
    }
    else
    {
        ss << ":" << second;
    }
    ss << " Uhr";
    return ss.str();
}

string TimeClass::showTimeUK()
{
    stringstream ss;
    if (hour >= 12)
    {
        if (hour > 12)
        {
            hour -= 12;
        }
        if (hour < 10)
        {
            ss << "0" << hour;
        }
        else
        {
            ss << hour;
        }
        if (minute < 10)
        {
            ss << ":0" << minute;
        }
        else
        {
            ss << ":" << minute;
        }
        if (second < 10)
        {
            ss << ":0" << second;
        }
        else
        {
            ss << ":" << second;
        }
        ss << " PM";

    }
    else if (hour < 12)
    {
        if (hour == 0)
        {
            hour += 12;
        }
        if (hour < 10)
        {
            ss << "0" << hour;
        }
        else
        {
            ss << hour;
        }
        if (minute < 10)
        {
            ss << ":0" << minute;
        }
        else
        {
            ss << ":" << minute;
        }
        if (second < 10)
        {
            ss << ":0" << second;
        }
        else
        {
            ss << ":" << second;
        }
        ss << " AM";
    }
    else
    {
        cout << "Error showTimeUK" << endl;
        DEBUG;
    }
    return ss.str();
}

string TimeClass::showTimeUSA()
{
    int buffer=hour-7;
    if (buffer < 0)
    {
        buffer += -24;
    }
    stringstream ss;
    if (buffer > 12)
    {
        buffer -= 12;
        if (buffer < 10)
        {
            ss << "0" << buffer;
        }
        else
        {
            ss << buffer;
        }
        buffer = minute;
        if (buffer < 10)
        {
            ss << ":0" << buffer;
        }
        else
        {
            ss << ":" << buffer;
        }
        buffer = second;
        if (buffer < 10)
        {
            ss << ":0" << buffer;
        }
        else
        {
            ss << ":" << buffer;
        }
        ss << " PM";

    }
    else if (buffer <= 12)
    {
        if (buffer < 10)
        {
            ss << "0" << buffer;
        }
        else
        {
            ss << buffer;
        }
        buffer = minute;
        if (buffer < 10)
        {
            ss << ":0" << buffer;
        }
        else
        {
            ss << ":" << buffer;
        }
        buffer = second;
        if (buffer < 10)
        {
            ss << ":0" << buffer;
        }
        else
        {
            ss << ":" << buffer;
        }
        ss << " AM";
    }
    return ss.str();
}

string TimeClass::showTimeCA()
{

    int buffer = hour - 7;
    if (buffer < 0)
    {
        buffer += -24;
    }
    stringstream ss;
    if (buffer > 12)
    {
        buffer -= 12;
        if (buffer < 10)
        {
            ss << "0" << buffer;
        }
        else
        {
            ss << buffer;
        }
        buffer = minute;
        if (buffer < 10)
        {
            ss << ":0" << buffer;
        }
        else
        {
            ss << ":" << buffer;
        }
        buffer = second;
        if (buffer < 10)
        {
            ss << ":0" << buffer;
        }
        else
        {
            ss << ":" << buffer;
        }
        ss << " PM";

    }
    else if (buffer <= 12)
    {
        if (buffer < 10)
        {
            ss << "0" << buffer;
        }
        else
        {
            ss << buffer;
        }
        buffer = minute;
        if (buffer < 10)
        {
            ss << ":0" << buffer;
        }
        else
        {
            ss << ":" << buffer;
        }
        buffer = second;
        if (buffer < 10)
        {
            ss << ":0" << buffer;
        }
        else
        {
            ss << ":" << buffer;
        }
        ss << " AM";
    }
    return ss.str();
}

void TimeClass::setHour() //default hour
{
    hour = 0;
}

void TimeClass::setHour(int hour) //Set specific time
{
    if (hour >= 0 && hour < 24)
    {
        this->hour = hour;
    }
    else
    {
        throw invalid_argument("Invalid hour.");
    }
}

int TimeClass::getHour()
{
    return hour;
}

void TimeClass::setMinute()
{
    minute = 0;
}

void TimeClass::setMinute(int minute)
{
    if (minute < 0 || minute >= 60)
    {
        throw invalid_argument("Invalid minute.");
    }
    else
    {
        this->minute = minute;
    }
}

int TimeClass::getMinute()
{
    return minute;
}

void TimeClass::setSecond()
{
    second = 0;
}

void TimeClass::setSecond(int second)
{
    if (second >= 0 && second < 60)
    {
        this->second = second;
    }
    else
    {
        throw invalid_argument("Invalid second.");
    }
}

int TimeClass::getSecond()
{
    return second;
}


TimeClass::~TimeClass() //destructor
{
    //cout << "destructor" << endl;
}