#include "../../std_lib_facilities.h"

int main()
{
    cout << "Please enter expression (we can handle +,-,* and, /): ";
    cout << "\n add and x to the end of the expression (e.g. 1 + 2 * 3x).\n";

    int lval = 0;
    int rval;
    int res;

    cin >> lval;
    if (!cin) 
        error("no first operand");

    for (char op; cin >> op;) {
        
        if (op != 'x') 
            cin >> rval;

        if (!cin) 
            error("No second operand.");

        switch (op) {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *= rval;
                break;
            case '/':
                lval /= rval;
                break;
            default: cout << "Result: " << lval << '\n';
            keep_window_open();
            return 0;
        }
    }

    error("Bad expression.");
}