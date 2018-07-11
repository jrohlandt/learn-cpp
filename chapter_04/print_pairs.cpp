#include "../std_lib_facilities.h"

int main()
{

    // e.g. 1 2 5 6 2.10 2.11 5 5 | (3 pairs)

    double val1;
    double val2;
    double smaller;
    double larger;
    constexpr double tolerance = 0.01;


    while (cin >> val1 >> val2) {
        
        cout << val1 << " " << val2 << "\n";

        if ( val1 == val2 ) {
            cout << val1 << " is equal to " << val2 << ".\n";
        } else {
            if (val1 > val2) {
                larger = val1;
                smaller = val2;
            } else {
                larger = val2;
                smaller = val1;
            }
            
            cout << larger << " is larger than " << smaller << ".\n";
            if (larger - smaller <= tolerance) {
                cout << "But " << larger << " is almost equal to " << smaller << ".\n";
            }
        }
    }

    return 0;
}