#include<string>
#include "../Chrono/Chrono.h"

namespace LibraryBuddy {

    class Book {

        public:
            class Invalid {};

            Book(std::string title, std::string author, Chrono::Date date);

            std::string getTitle() const { return title; }
            std::string getAuthor() const { return author; }
            Chrono::Date getDate() const { return copyright_date; }

        private:
            std::string title;
            std::string author;
            Chrono::Date copyright_date;
            std::string ISBN;
            bool is_checked_out;
    };
}