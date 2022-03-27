#include <iostream>
#include <sstream>
#include <string>
#include "Tvarkarastis.hpp"

int tvark::classQuantity = 0;

tvark::tvark()
{
	setHowMany(0);
}

tvark::tvark(int howMany)
{
	setHowMany(howMany);
}


void tvark::setName(string name) { className.push_back(name); }
void tvark::setHowMany(int howMany) { this->howMany = howMany; }


bool tvark::areClasses()
{
	if (className.size() != 0)
	{
		return true;
	}
	return false;
}

void tvark::addClass(string name, int hour, int minute, int second)
{
	if (laikai.size() == howMany)
	{
		throw invalid_argument("Max classes has been already added!");
	}
	setName(name);
	laikai.push_back(TimeClass(hour, minute, second));
	++classQuantity;
	
}

void tvark::changeMinute(int i, int minute)
{
	laikai[i - 1].setMinute(minute);
}



string tvark::getClass(int i)
{ 
	if (!areClasses())
	{
		throw invalid_argument("There are no classes!");
	}
	else if (i > laikai.size())
	{
		throw invalid_argument("There is no such class!");
	}
	else
	{
		stringstream ss; 
		ss << className[i - 1] << " at " << laikai[i - 1].showTimeUK();
		return ss.str();
	}
	
}

tvark::~tvark()
{
	cout << "deleted a day" << endl;
	classQuantity -= laikai.size();
}
