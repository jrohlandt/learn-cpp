#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include "../../Chrono/Chrono.h"

struct Reading 
{
    Chrono::Date datetime;
    float temp;
};

std::ostream& operator<<(std::ostream& os, Reading& r)
{
    os << "Timestamp: " << r.datetime.datetimestring() 
        << " Temperature: " << r.temp;

    return os;
}

int main()
{
    std::string filename = "date_temp.txt";
    std::fstream ifs {filename};
    std::vector<Reading> readings;

    while(true)
    {
        std::string date, time;
        float temp;
        ifs >> date >> time >> temp;
        if (!ifs) break;

        std::string datetime = date + " " + time;
        Chrono::Date d {datetime};

        Reading r {d, temp};
        readings.push_back(r);
    }
    

    for (Reading r : readings) {
        std::cout << r << '\n';
    }

    std::vector<float> sorted;
    for (Reading r : readings) {
        sorted.push_back(r.temp);
    }

    std::sort(sorted.begin(), sorted.end());
    for (int i=0; i < sorted.size(); i++) {
        std::cout << sorted[i] << '\n';
    }

    float median;
    if (sorted.size() % 2 == 0) {
        int middle = (sorted.size() / 2) - 1;
        median = (sorted[middle] + sorted[middle + 1]) / 2;
    } else {
        int i = (sorted.size() + 1) / 2;
        median = sorted[i - 1];
    }

    std::cout 
        << "number of readings: " << sorted.size() << '\n'
        << "Median: " << median << '\n';

    float sum = 0;
    for (float s : sorted) {
        sum += s;
    }

    float mean = sum / sorted.size();

    std::cout 
        << "sum: " << sum << '\n'
        << "Mean: " << mean << '\n';



}