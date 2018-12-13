#include "Book.h"

namespace LibraryBuddy {

    Book::Book(std::string t, std::string a, Chrono::Date date)
        : title{t}, author{a}, copyright_date{date}
        {
        }
}