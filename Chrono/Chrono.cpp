#include "Chrono.h"

namespace Chrono {

    Date::Date(int yy, Month mm, int dd)
        : y{yy}, m{mm}, d{dd}
    {
        if (!is_date(yy,mm,dd)) throw Invalid{};
    }

    const Date& default_date()
    {
        static Date dd {2001, Month::jan, 1};
        return dd;
    }


    Date::Date()
        :y{default_date().year()},
        m{default_date().month()},
        d{default_date().day()}
    { 
    }

    void Date::add_day(int n)
    {
        //
    }

    void Date::add_month(int n)
    {
        //
    }

    void Date::add_year(int n)
    {
        if (m == Month::feb && d == 29 && !is_leap_year(y+n)) {
            // If it is not leap year then the date can't be 29 Feb.
            // It must be March 1.
            // Todo why do the leap year check here?
            // Wouldn't it be better to do it in the constructor before the date 
            // is initialised?
            m = Month::mar;
            d = 1;
        }
        // Add year/s
        y += n;
    }

    bool is_date(int y, Month m, int d)
    {
        // assume year y is valid

        if (d <= 0) return false;
        if (m < Month::jan || m > Month::dec) return false;

        int days_in_month = 31;

        switch (m) {
            case Month::feb:
                days_in_month = (is_leap_year(y)) ? 29 : 28;
                break;
            case Month::apr: 
            case Month::jun:
            case Month::sep:
            case Month::nov:
                days_in_month = 30;
                break;
        }

        if (d > days_in_month) return false;

        return true;
    }

    bool is_leap_year(int y)
    {
        // exercise 10
    }

    bool operator==(const Date& a, const Date& b)
    {
        return a.year() == b.year()
            && a.month() == b.month()
            && a.day() == b.day();
    }

    bool operator!=(const Date& a, const Date& b)
    {
        return !(a == b);
    }

    std::ostream& operator<<(std::ostream& os, const Date& d)
    {
        return os << '(' << d.year() 
                    << ',' 
                    << int(d.month()) 
                    << ',' 
                    << d.day() 
                    << ')';
    }

    Day day_of_week(const Date& d)
    {
        //
    }

    Day next_Sunday(const Date& d)
    {
        //
    }

    Date next_weekday(const Date& d)
    {
        //
    }





}