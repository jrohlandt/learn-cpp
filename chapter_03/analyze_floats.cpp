#include "../std_lib_facilities.h"

// determine larger, smaller, sum, difference, product, ratio.

int main()
{
    double val1;
    double val2;
    double smaller;
    double larger;
    bool equal = false;
    double difference = 0;
    int sum;
    double ratio1;
    double ratio2;

    cout << "Enter two numbers e.g. 5 10\n";

    cin >> val1 >> val2;

    sum = val1 + val2;

    if (val1 == val2) {
        equal = true;    
    } else if (val1 > val2) {
        larger = val1;
        smaller = val2;
    } else {
        smaller = val1;
        larger = val2;
    }

    difference = equal == true ? 0 : larger - smaller;
    ratio1 = val1 / sum * 100;
    ratio2 = val2 / sum * 100;

    cout << "You entered " << val1 << " and " << val2 << ".\n";
    cout << "Here is some information about the 2 numbers.\n";
    cout << "sum: " << sum << "\n";

    if (equal == true) {
        cout << val1 << " Is equal to " << val2 << "\n";
    } else {
        cout << larger << " is larger than " << smaller << "\n";
    }

    cout << "The difference between " << val1 << " and " << val2 << " is " << difference << ".\n";
    cout << "The product of " << val1 << " and " << val2 << " is " << val1 * val2 << "\n";
    cout << "The ratio of " << val1 << " is " << ratio1 << "%\n";
    cout << "The ratio of " << val2 << " is " << ratio2 << "%\n";

    return 0;
}