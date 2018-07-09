#include "../std_lib_facilities.h"

int main()
{
    string val1;
    string val2;
    string val3;

    string first = "";
    string second = "";
    string third = "";

    cout << "Enter three words. e.g. Steinbeck Hemingway Fitzgerald \n";

    cin >> val1 >> val2 >> val3;

    cout << val1 << " " << val2 << " " << val3 << "\n";

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