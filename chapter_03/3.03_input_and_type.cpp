#include "../std_lib_facilities.h"

// --------------------------
// Some commonly used types:
// --------------------------
// int
// double (floating point number)
// char (a single character like 'a' or '@')
// string (a sequence of characters in double quotes e.g. '123' or '123abc')
// bool (true or false)
// --------------------------

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