#include "../std_lib_facilities.h"

int main() 
{
    cout << "usage:  yourname age e.g. 36.8 (then press ENTER):\n";
    string name = "???";
    double age = 0;

    cin >> name >> age;

    double age_in_months = 0;
    age_in_months = age * 12;

    cout << "Hello, ";
    cout << name;
    cout << " (age ";
    cout << age;
    cout << " years ";
    cout << age_in_months;
    cout << " months )\n";
    // Or cout << "Hello, " << name << "(age " << age << ")\n";
}