/*
    This is a simple calculator.

    The grammar for input is:

    Calculation:
        Statement
        Print
        Quit
        Calculation Statement

    Statement:
        Declaration
        Expression
        Print
        Quit

    Declaration:
        "let" Name = "=" Expression
        
    Print: 
        ;

    Quit:
        q

    Expression:
        Term
        Expression + Term
        Expression - Term
    Term:
        Primary
        Term * Primary
        Term / Primary
        Term % Primary
    Primary:
        Number
        ( Expression )
        - Primary
        + Primary
    Number:
        floating-point-literal

    Input comes from cin through the Token_stream called ts.
*/ 

#include "../std_lib_facilities.h"

const char number = '8'; // The value 8 represents a kind of number.
const char quit = 'q';
const char print = ';';

class Token {
    public:
        char kind;        // what kind of token
        double value;     // for numbers: a value 
        Token(char ch)    // make a Token from a char
            :kind(ch), value(0) { }    
        Token(char ch, double val)     // make a Token from a char and a double
            :kind(ch), value(val) { }
};

class Token_stream {
    public: 
        Token_stream();   // make a Token_stream that reads from cin
        Token get();      // get a Token (get() is defined elsewhere)
        void putback(Token t);    // put a Token back
        void ignore(char c); // discard all characters up to and including c.
    private:
        bool full;        // is there a Token in the buffer?
        Token buffer;     // here is where we keep a Token put back using putback()
};

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) {
        error("putback() into a full buffer");
    }

    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

Token Token_stream::get()
{
    // Check if buffer already has a token?
    if (full) {       
        full = false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case print:    // for "print"
    case quit:    // for "quit"
    case '(': 
    case ')': 
    case '+': 
    case '-': 
    case '*': 
    case '/': 
    case '%':
        return Token{ch};        // let each character represent itself
    case '.': 
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token{number, val}; 
        }
    default:
        error("Bad token");
    }
}

void Token_stream::ignore(char c)
{
    // First look in buffer.
    if (full && c == buffer.kind) {
        full = false;
        return;
    }

    full = false;

    // Now search input:
    char ch = 0;
    while (cin >> ch) 
        if (ch == c) 
            return;
}

class Variable {
    public: 
        string name;
        double value;
};

vector<Variable> var_table;

double get_value(string s)
{
    for (const Variable& v : var_table) {
        if (v.name == s)
            return v.value;
    }

    error("get: undefined variable ", s);
}

void set_value(string s, double d)
{
    for (Variable& v : var_table) {
        if (v.name == s) {
            v.value = d;
            return;
        }
    }

    error("set: undefined variable ", s);
}

Token_stream ts;        // provides get() and putback() 

double expression();    // declaration so that primary() can call expression()

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
        case '(':    // handle '(' expression ')'
            {    
                double d = expression();
                t = ts.get();
                if (t.kind != ')') {
                    error("')' expected");
                }
                return d;
            }
        case number:            // we use '8' to represent a number
            return t.value;  // return the number's value
        case '-':
            return primary();
        case '+':
            return primary(); // todo 2-2 = 4 after adding the - and + case to primary, need to fix. 
        default:
            error("primary expected");
    }
}

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
                {    
                    double d = primary();
                    if (d == 0) error("divide by zero");
                    left /= d; 
                    t = ts.get();
                    break;
                }
            case '%':
                {
                    double d = primary();
                    if (d == 0)
                        error("%: divide by zero");

                    left = fmod(left, d);
                    t = ts.get();
                    break;
                }
            default: 
                ts.putback(t);     // put t back into the token stream
                return left;
        }
    }
}

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left += term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

void calculate()
{
    while (cin)
    try {
        cout << "> ";
        Token t = ts.get();
        
        while (t.kind == print)
            t = ts.get(); // eat ';'
        
        if (t.kind == quit)
            return;
        
        // now that we know the Token is not 'q' or ';' we put it 
        // back in ts buffer so that expression() can read it.
        ts.putback(t);  
        cout << " = " << expression() << "\n";
    }
    catch (exception& e) {
        cerr << e.what() << '\n';
        clean_up_mess();
    }
}

int main() 
{
    try 
    {
        calculate();
	    keep_window_open();
        return 0;
    }
    catch (exception& e) {
        cerr << e.what() << '\n'; 
        keep_window_open("~~");
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n"; 
        keep_window_open();
        return 2;
    }
}