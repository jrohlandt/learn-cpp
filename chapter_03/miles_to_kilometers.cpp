#include "../std_lib_facilities.h"

int main()
{
    double miles;
    double kilometers_per_mile = 1.609;
    double kilometers = 0;

    cout << "\n------------------------------------\n";
    cout << " Convert miles to kilometers ";
    cout << "\n------------------------------------\n";

    cout << "Type the number of miles followed by ENTER:\n";

    cin >> miles;

    kilometers = miles * kilometers_per_mile;

    cout << miles << " miles converts to " << kilometers << " kilometers.\n";

    return 0;
}