#include "../std_lib_facilities.h"

int main()
{
    try {
        // string s = "ape"; s += "fool"; if (s.size()) cout << "Success!\n";
        // vector<char> v(5); for (int i=0; i < v.size(); ++i) cout << "Success!\n";
        // string s = "Success!\n"; for (int i=0; i < s.size(); ++i) cout << s[i];
        // if (true) cout << "Success\n"; else cout << "Fail!\n";
        // int x = 98; char c = x; cout << (int)c << "\n"; if (c == 98) cout << "Success!\n";
        // string s = "Success!\n"; for (int i=0; i < 15; ++i) cout << s[i]; // supposed to get range error ???

        keep_window_open();
        return 0;
    }
    catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Exception: Unkown exception!\n";
        keep_window_open();
        return 2;
    }
}