#include <iostream>
namespace Chrono {

    enum class Day {
        sunday, monday, tuesday, wednesday, thursday, friday, saturday
    };
    
    enum class Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    class Date {
        public:
            class Invalid {};

            Date(int y, Month m, int d);
            Date(); // default constructor

            // non modifying operations:
            int day() const { return d; }
            Month month() const { return m; }
            int year() const { return y; }

            // modifying operations:
            void add_day(int n);
            void add_month(int n);
            void add_year(int n);

        private:
            int y;
            Month m;
            int d;

    };

    bool is_date(int y, Month m, int d);

    bool is_leap_year(int y);

    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    std::ostream& operator<<(std::ostream& os, const Date& d);
    std::istream& operator>>(std::istream& is, Date& dd);

    Day day_of_week(const Date& d);
    Date next_Sunday(const Date d); 
    Date next_weekday(const Date& d); // next weekday after d.
}