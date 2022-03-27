#include <iostream>
#include <string>
#include <stdexcept>

#include "Tvarkarastis.hpp"

using namespace std;
//tema - Tvarkarastis

int main()
{
    try
    {
        tvark* monday = new tvark(3);
        //monday.
        monday->addClass("Math", 8, 0, 0);
        cout << monday->getClass(1) << endl;
        monday->addClass("Science", 10, 0, 0);
        cout << monday->getClass(2) << endl;
        monday->changeMinute(1, 59);
        cout << monday->getClass(1) << endl;

        cout << endl;

        tvark tuesday(2);
        tuesday.addClass("Math", 9, 0, 0);
        cout << "In all, there are " << tuesday.classQuantity << " classes." << endl;
        tuesday.addClass("Science", 11, 0, 0);
        cout << "In all, there are " << tuesday.classQuantity << " classes." << endl;
        //tuesday.addClass("P.E.", 13, 0, 0);

        delete monday;
        cout << "In all, there are " << tuesday.classQuantity << " classes." << endl;
    }
    catch (invalid_argument a)
    {
        cout << "An error has occured: " << a.what() << endl;
    }
    /*
    vector<tvark> week;
    week.push_back(tvark(2));
    week[0].addClass("Math", 8, 0, 0);
    cout << "Classes: " << week[0].classQuantity << endl;
    week.push_back(tvark(1));
    week[1].addClass("Science", 8, 0, 0);
    cout << "Classes: " << week[0].classQuantity << endl;*/
    return 0;
}
