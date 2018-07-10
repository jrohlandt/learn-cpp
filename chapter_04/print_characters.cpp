#include "../std_lib_facilities.h"

int main()
{
    int i = 0;
    char c = 'a';

    while (i < 100) 
    {
        cout << c+i << "\t" << char(c+i) << "\n";
        i++;
    }
    return 0;
}