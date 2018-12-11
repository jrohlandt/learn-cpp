#include "my.h"
#include "../../Chrono/Chrono.h"


int foo;

int main()
{
    foo = 7;
    print_foo();
    print(99);

    int a = 1;
    int b = 2;
    swap_int(a,b);
    swap_r(a,b);
    swap_cr(a,b);

    Chrono::Date d = Chrono::Date(1978, Chrono::Month::jun, 25);

    std::cout << d;
}