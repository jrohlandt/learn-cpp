#include "../std_lib_facilities.h"

int main()
{
    int val1;
    int val2;
    int val3;

    int first = 0;
    int second = 0;
    int third = 0;

    cout << "Enter three numbers. e.g. 10 2 99 \n";

    cin >> val1 >> val2 >> val3;

    cout << val1 << " " << val2 << " " << val3 << "\n";

    // 8 4 10

    // 8 - 4 = 4
    // 4 - 10 = -6
    // 10 - 8 = 2
    // string ordered_output = "";
    if (val1 < val2 && val2 < val3 && val1 < val3) {
        // e.g. 1 2 3
        first = val1;
        second = val2;
        third = val3;
    } else if (val1 > val2 && val2 > val3 && val1 > val3) {
        // e.g. 3 2 1
        first = val3;
        second = val2;
        third = val1;
    } else if (val1 > val2 && val2 < val3 && val1 > val3) {
        // e.g. 3 1 2
        first = val2;
        second = val3;
        third = val1;
    } else if (val1 > val2 && val2 < val3 && val1 < val3) {
        // e.g. 2 1 3
        first = val2;
        second = val1;
        third = val3;
    } else if (val1 < val2 && val2 > val3 && val1 < val3) {
        // e.g. 1 3 2
        first = val1;
        second = val3;
        third = val2;
    } else if (val1 < val2 && val2 > val3 && val1 > val3) {
        // e.g. 2 3 1
        first = val3;
        second = val1;
        third = val2;
    }
     

    cout << " " << first << " " << second << " " << third << "\n";

    return 0;
}