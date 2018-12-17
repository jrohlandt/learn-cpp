#include<vector>
#include<iostream>
#include<fstream>
#include<string>

const int not_a_reading = 7777;
const int not_a_month = -1;

struct Day {
    std::vector<double> hour {std::vector<double>(24, not_a_reading)};
};

struct Month { // a month of temperature readings.
    int month {not_a_month}; // [0:11] Jan is 0.
    std::vector<Day> day {32}; // [1:31] one vector of readings per day. 31 days (index 0 is not used).
};

std::vector<std::string> month_input_table = {
    "jan", "feb", "mar", "apr", "may", "jun", "jul",
    "aug", "sep", "oct", "nov", "dec"
};

int month_to_int(std::string s)
// Search for month name and return it's index.
{
    for (int i=0; i < 12; ++i) if (month_input_table[i] == s) return i;
    return -1;
}

struct Year { // a year of temperature readings, organised by month.
    int year; // positive == A.D.
    std::vector<Month> month {12}; // [0:11] Jan is 0.
};

struct Reading {
    int day;
    int hour;
    double temperature;
};


void end_of_loop(std::istream& i_stream, char terminator, const std::string& message)
{
    if (i_stream.fail()) {
        i_stream.clear();
        char ch;

        if (i_stream >> ch && ch == terminator)
            return; // all is fine.

        throw std::runtime_error(message);
    }
}

std::istream& operator>>(std::istream& i_stream, Reading& r)
// Read a temperature from input stream into r.
// format: (3 4 9.7)
// Check format, but don't bother with data validity.
{
    char ch1;
    if (i_stream >> ch1 && ch1 != '(') {
        i_stream.putback(ch1);
        i_stream.clear(std::ios_base::failbit);

        return i_stream;
    }

    char ch2;
    int day;
    int hour;
    double temp;

    i_stream >> day >> hour >> temp >> ch2;

    if ( ! i_stream || ch2 != ')' )
        throw std::runtime_error("Bad reading");

    r.day = day;
    r.hour = hour;
    r.temperature = temp;

    return i_stream;
}

bool is_valid(const Reading& r, int min_temp, int max_temp)
{
    if (r.day < 1 || r.day > 31)
        return false;

    if (r.hour < 0 || r.hour > 23)
        return false;

    if (r.temperature < min_temp || r.temperature > max_temp)
        return false;

    return true;
}


bool is_valid(const Reading& r)
// rough test
{
    return is_valid(r, -200, 200);
}

std::istream& operator>>(std::istream& i_stream, Month& m)
// read a month from input stream into m.
// format: { month feb ... }
{
    char ch = 0;
    if (i_stream >> ch && ch != '{') {
        i_stream.putback(ch);
        i_stream.clear(std::ios_base::failbit);
        
        return i_stream;
    }

    std::string month_marker;
    std::string mm;
    i_stream >> month_marker >> mm;

    if ( ! i_stream || month_marker != "month")
        throw std::runtime_error("Invalid month marker.");

    m.month = month_to_int(mm);

    int duplicates = 0;
    int invalids = 0;

    for (Reading r; i_stream >> r;) {
        if (is_valid(r)) {
            if (m.day[r.day].hour[r.hour] != not_a_reading)
                ++duplicates;
            m.day[r.day].hour[r.hour] = r.temperature;
        }
        else 
            ++invalids;
    }

    if (invalids)
        throw std::runtime_error(invalids + " invalid readings in month.");

    if (duplicates)
        throw std::runtime_error(duplicates + " duplicate readings in month.");

    end_of_loop(i_stream, '}', "bad end of month");

    return i_stream;
}



std::istream& operator>>(std::istream& i_stream, Year& y)
// Read a year from input stream into y.
// format: { year 1981 ... }
{
    char ch;
    i_stream >> ch;
    if (ch != '{') {
        i_stream.unget();
        i_stream.clear(std::ios::failbit);

        return i_stream;
    }

    std::string year_marker;
    int yy;

    i_stream >> year_marker >> yy;

    if ( ! i_stream || year_marker != "year")
        throw std::runtime_error("Bad year marker.");

    y.year = yy;

    while (true) {
        Month m;
        if (!(i_stream >> m))
            break;

        y.month[m.month] = m;
    }

    end_of_loop(i_stream, '}', "bad end of year");

    return i_stream;
}

int main()
{
    std::cout << "Enter input file name:\n";
    std::string input_file_name;
    std::cin >> input_file_name;

    std::ifstream ifs {input_file_name};

    if ( ! ifs ) throw std::runtime_error("Can't open input file " + input_file_name);

    ifs.exceptions(ifs.exceptions()|std::ios_base::badbit); // throw error for bad()

    std::vector<Year> years;
    while(true) {
        Year y;
        if (!(ifs >> y)) break;
        years.push_back(y);
    }

    std::cout << "Read " << years.size() << " years of readings\n";

}

