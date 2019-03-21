#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "../../Chrono/Chrono.h"

struct Reading 
{
    Chrono::Date datetime;
    int temp;
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
        int temp;
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

}