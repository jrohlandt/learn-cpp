#include "../std_lib_facilities.h"

int main()
{
    cout << "Please enter your name (then press enter):\n";
    string first_name;
    
    // Character Standard Input Stream: Read characters from input.
    cin >> first_name; // read charcters into first_name

    // Character Standard Output Stream
    cout << "Hello, " << first_name << "!\n";
}