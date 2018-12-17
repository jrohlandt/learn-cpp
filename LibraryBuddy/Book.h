#include<string>
#include "../Chrono/Chrono.h"

namespace LibraryBuddy {

    class Book {

        public:
            class Invalid {};

            Book(){};
            Book(std::string title, std::string author, Chrono::Date date);

            std::string getTitle() const { return title; }
            std::string getAuthor() const { return author; }
            Chrono::Date getDate() const { return copyright_date; }

            void set_title(std::string t) { title = t; }
            void set_author(std::string a) { author = a; }
            void set_date(Chrono::Date d) { copyright_date = d; }
            void set_isbn(std::string n) { isbn = n; }

        private:
            std::string title;
            std::string author;
            Chrono::Date copyright_date;
            std::string isbn;
            bool is_checked_out;
    };
}