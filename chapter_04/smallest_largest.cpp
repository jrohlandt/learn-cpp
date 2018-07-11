#include "../std_lib_facilities.h"

int main()
{
    double val1;
    string unit;
    vector<double> distances;
    double converted_val = 0;
    double largest = 0;
    double smallest = 0;
    int i = 0;
    bool unit_is_valid = false;
    vector<string> valid_units = {"cm", "m", "in", "ft"};
    constexpr double cm_in_inch = 2.54;
    constexpr double cm_in_meter = 100;
    constexpr double cm_in_foot = cm_in_inch * 12;


    while (cin >> val1 >> unit) {
        
        cout << val1 << unit << "\n";

        unit_is_valid = false;
            for (string u : valid_units) {
                if (unit == u) 
                    unit_is_valid = true;
            }

            if (unit_is_valid == false) {
                cout << "Invalid unit " << unit << " entered. \n";
                return 1;
            } else {

                if (unit == "in") {
                    converted_val = val1 * cm_in_inch / cm_in_meter;
                } else if (unit == "cm") {
                    converted_val = val1 / cm_in_meter;
                } else if (unit == "ft") {
                    converted_val = val1 * cm_in_foot / cm_in_meter;
                } else if (unit == "m") {
                    converted_val = val1;
                }

                distances.push_back(converted_val);

                if (unit != "m") {
                    cout << val1 << " " << unit << " is " << converted_val << "m\n";
                }

                if (converted_val > largest) {
                    largest = converted_val;
                    cout << converted_val << "m is the longest distance so far.\n";
                }

                if (i == 0) {
                    smallest = converted_val;
                } else if (converted_val < smallest) {
                    smallest = converted_val;
                    cout << converted_val << "m is the shortest distance so far.\n";
                }
            }
        
        i++;
    }

    sort(distances);
    cout << "\nDistances from low to high\n";
    for (double dist : distances) {
        cout << "\t" << dist << "m\n";
    }

    cout << "\n The shortest distance is " << smallest << " and the longest distance is " << largest << ".\n";
    return 0;
}