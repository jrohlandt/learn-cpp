#include "../std_lib_facilities.h"
#include <limits>
#include <stdexcept>

int main()
{
    // 
    int current = 1;
    int prev_current = 1;
    int prev = 0;
    int i = 0;

    cout << "\n The maximum value of an int is: " << std::numeric_limits<int>::max() << '\n';
    try {
        while(i < 100)
        {
            prev_current = current;
            if (0 > current + prev) 
                throw std::overflow_error("Integer overlow.");
            current = current + prev;
            prev = prev_current;
            cout << current << "\n";
            ++i;
        }

        return 0;
    }
    catch(std::overflow_error& e) {
        cerr << "Error: " << e.what() << '\n';
        cout << "And the largest Fibonacci number we are able to store in type int is: " << prev_current << "\n";
        keep_window_open();
        return 1;
    }
    catch(exception& e) {
        cerr << "Error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch(...) {
        cerr << "\nUnkown exception occurred.\n";
        keep_window_open();
        return 2;
    }
    
}