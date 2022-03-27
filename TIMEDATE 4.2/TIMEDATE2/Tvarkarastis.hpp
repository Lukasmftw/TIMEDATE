#include <string>
#include <vector>
#include <stdexcept>
#include "TimeDate.hpp"

using namespace std;

class tvark
{
private:
	int howMany;
	vector<string> className;
	friend class TimeClass;
	vector<TimeClass> laikai;
public:
	static int classQuantity;
	tvark();
	tvark(int n);

	void addClass(string name, int hour, int minute, int second);
	void changeMinute(int i, int minute);

	void setHowMany(int howMany);
	void setName(string name);
	string getClass(int i);
	bool areClasses();


	~tvark();
};
