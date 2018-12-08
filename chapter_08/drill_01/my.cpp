#include "../../std_lib_facilities.h"
#include "my.h"

void print(int i)
{
    cout << i << '\n';
}

void print_foo()
{
    print(foo);
}

void swap_int(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

    print(a);
    print(b);
}

void swap_r(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

    print(a);
    print(b);
}

void swap_cr(const int& a, const int& b)
{
    // int temp;   
    // temp = a;
    // a = b;
    // b = temp;

    print(a);
    print(b);
}