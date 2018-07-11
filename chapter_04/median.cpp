#include "../std_lib_facilities.h"

bool is_even(int val)
{
    return val % 2 == 0;
}

int main()
{
    vector<double> temperatures = { 32, 4, 28, 19, 17, 10, 22, 13, 9, 38, 7, 41 };
    double median = 0;
    int middle = temperatures.size() / 2;

    sort(temperatures);

    if (is_even(temperatures.size())) {
        double val1 = temperatures[middle];
        double val2 = temperatures[middle+1];
        median = (val1 + val2) / 2; 
    } else {
        median = temperatures[middle];
    }

    cout << "\nEvaluated " << temperatures.size() << " values.\n";
    for (double temp : temperatures) {
        cout << " " << temp << "\n";
    }
    cout << "The median temp is " << median << "\n";
   
    return 0;
}