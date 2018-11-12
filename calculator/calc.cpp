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
        "let" Name "=" Expression
        
    Name:
        e.g. abc or a1bc or Abc, ABC but not 1abc or ab_c or # or a bc

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

char prev_char = 's'; // first
const char number = '8'; // The value 8 represents a kind of number.
const char quit = 'q';
const char print = ';';

const char name = 'a'; // name token
const char let = 'L'; // declaration token
const string declKey = "let"; // declaration keyword

class Token {
    public:
        char kind;        // what kind of token
        double value;     // for numbers: a value 
        string name;      

        // Token(char ch)    // make a Token from a char
        //     :kind(ch), value(0) { }  

        // Token(char ch, double val)     // make a Token from a char and a double
        //     :kind(ch), value(val) { }

        Token() :kind{0} { }
        Token(char ch) :kind{ch} { }
        Token(char ch, double val) :kind{ch}, value{val} {}
        Token(char ch, string n) :kind{ch}, name{n} {}
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
        case '=': // Used for variable declaration only. E.g. let x = 3.4;
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
            if (isalpha(ch)) {
                // cin.putback(ch); // put back the character
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) {
                    s += ch;
                }
                cin.putback(ch); // why?
                
                if (s == declKey) {
                    return Token{let}; // return declaration keyword
                } else {
                    return Token{name,s};
                }
            }
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

// Check if variable is defined.
bool is_declared(string var)
{
    for (const Variable& v : var_table) {
        if (v.name == var)
            return true;
    }
    return false;
}

// Add {var,val} to var_table.
double define_name(string var, double val)
{
    if (is_declared(var))
        error(var, "declared twice");

    var_table.push_back(Variable{var,val});
    return val;
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

double declaration()
{
    Token t = ts.get();
    if (t.kind != name)
        error("name expected in declaration");

    Token t2 = ts.get();
    if (t2.kind != '=') 
        error("= missing in variable declaration of ", t.name);

    double d = expression();
    define_name(t.name, d);
    return d;
}

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
            {
                if (prev_char == '-') {
                    prev_char = 's';
                    return t.value * -1;
                }
                return t.value;  // return the number's value
            }
        case name:
            return get_value(t.name);
        case '-':
            {
                if (prev_char == 's') {
                    prev_char = '-';
                }
                return primary();   
            }
        case '+':
            return primary(); 
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
            left -= term();    // evaluate Term and subtract
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

double statement()
{
    Token t = ts.get();
    switch(t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
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
        cout << " = " << statement() << "\n";
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
        define_name("pi", 3.1415926535);
        define_name("e", 2.7182818284);
        
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