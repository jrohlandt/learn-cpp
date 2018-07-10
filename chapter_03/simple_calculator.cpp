#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter your sum. e.g. 1 + 1 or 2 * 2 :";

    double val1;
    double val2;
    char oper;
    double result;

    cin >> val1 >> oper >> val2;

    if (oper == '+') {
        result = val1 + val2;
    }

    if (oper == '-') {
        result = val1 - val2;
    }

    if (oper == '*') {
        result = val1 * val2;
    }

    if (oper == '/') {
        result = val1 / val2;
    }

    cout << "The result is: " << result << "\n";

    return 0;
}