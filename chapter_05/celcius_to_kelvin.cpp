#include "../std_lib_facilities.h"

// Converts celcius to kelvin.
// pre-condition: c cannot be less that -273.15.
// post-condition: the return value cannot be less than 0.
double ctok(double c)
{
    if (c < -273.15) 
        error("ctok() pre-condition: c cannot be less than -273.15");

    double k = c + 273.15;

    if (k < 0) 
        error("ctok() post-condition: k cannot be less than 0");
    return k;
}

// Converts celcius to kelvin.
// pre-condition: k cannot be less than 0.
// post-condition: the return value cannot be less than -273.15.
double ktoc(double k)
{
    if (k < 0) 
        error("ktoc() pre-condition: k cannot be less than 0");

    double c = k - 273.15;

    if (c < -273.15) 
        error("ktoc() post-condition: the return value cannot be less than -273.15");
    return c;
}

int main()
{
    cout << "\n-------------------------------------------------\n";
    cout << "  Convert from Celcius to Kelvin and vice versa.";
    cout << "\n-------------------------------------------------\n";
    cout << "\n usage: 100 k or 30 c \n";

    try {
        double temp;
        char unit;

        cin >> temp >> unit;

        if (unit == 'c')
            cout << temp << unit << " is " << ctok(temp) << "k\n";
        else if (unit == 'k')
            cout << temp << unit << " is " << ktoc(temp) << "c\n";
        else
            cout << "\n Invalid temperature unit " << unit << "\n";

        keep_window_open();
        return 0;
    }
    catch(exception& e) {
        cerr << "Error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch(...) {
        cerr << "Exception: Unkown exception!\n";
        keep_window_open();
        return 2;
    }
    
}