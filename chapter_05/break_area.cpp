// This is the "Try this" exercise 5.10.1 .
// The goal is to supply two arguments to area() that will pass the pre-condition test but still fail the post-condition test.

// Answer is to supply large enough values so that the multiplication caluction returns a large enough value to cause a overflow in the "int a".

#include "../std_lib_facilities.h"

int area(int length, int width)
// Calculate the area of a rectangle.
// Pre-conditions: Length and width are positive.
// Post-condition: Returns a positive value.
{
    if (length <= 0 || width <= 0) 
        error("area() pre-condition");

    int a = length * width;

    if (a <= 0) 
        error("area() post-condition");

    return a;
}

int main()
{
    int length;
    int width;

    cin >> length >> width;

    try {
        int a = area(length, width);
        cout << "\n" << a << "\n";
    } 
    catch (exception& e) {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}