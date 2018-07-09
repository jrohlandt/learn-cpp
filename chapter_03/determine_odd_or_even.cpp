#include "../std_lib_facilities.h"

int main()
{
    int number;    
    string odd_or_even;

    cout << "Please enter a number to see if it is even or odd. \n";

    cin >> number;
    odd_or_even = number % 2 == 0 ? "even" : "odd";

    cout << number << " is " << odd_or_even << "\n";

    return 0;
}