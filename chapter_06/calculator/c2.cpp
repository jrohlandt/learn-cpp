#include "../../std_lib_facilities.h"

/*
    Grammar
    -------

    Expression:
        Term
        Expression "+" Term
        Expression "-" Term
    Term:
        Primary
        Term "*" Primary
        Term "/" Primary
        Term "%" Primary
    Primary:
        Number
        "(" Expression ")"
    Number:
        floating-point-literal

*/ 

class Token {
    public:
        char kind;
        double value;
};

double primary()
{
    Token t = get_token();
    switch(t.kind) {
        case '(': 
        {
            double d = expression();
            t = get_token();
            if ( t.kind != ')' )
                error("Expected ')' ");
            return d;
        }
        case '8':
            return t.value;
        default:
            error("Expected primary.");
    }
}

double term()
{
    double left = primary();
    Token t = get_token();
    while (true) {
        switch(t.kind) {
            case '*':
                left *= primary();
                t = get_token();
                break;
            case '/': {
                double d = primary();
                if (d == 0) 
                    error("Cannot divide by zero.");
                    left /= d;
                    t = get_token();
                    break;
            }
            default:
                return left;
        }
    }   
}

double expression()
{
    double left = term();
    Token t = get_token();

    while (true) {
        switch(t.kind) {
            case '+':
                left += term();
                t = get_token();
                break;
            case '-':
                left -= term();
                t = get_token();
                break;
            default: 
                return left;
        }
    }
}

int main() {

    try {
        while (cin) {
            cout << "=" << expression() << '\n';
        }
        keep_window_open();
    }
    catch (exception& e) {
        cerr << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "exception \n";
        keep_window_open();
        return 2;
    }
    return 0;
}