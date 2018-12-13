#include "Book.h"
#include<iostream>

using namespace LibraryBuddy;

int main()
{
    Book book = Book("Test Book Title", "Test Author", Chrono::Date(2017, Chrono::Month::jul, 10));

    std::cout << book.getTitle() << " | " << book.getAuthor() << book.getDate() << '\n';
}