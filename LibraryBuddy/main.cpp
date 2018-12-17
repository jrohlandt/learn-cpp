#include "Book.h"
#include<iostream>

using namespace LibraryBuddy;
using namespace std;

int main()
{
    string title = "A Walk in the Woods";
    string author = "Bill Bryson";
    Chrono::Date date{2017, Chrono::Month::jul, 10};

    Book book = Book();

    book.set_title("A Walk in the Woods");
    book.set_author("Bill Bryson");
    book.set_date(Chrono::Date(2017, Chrono::Month::jul, 10));

    std::cout << book.getTitle() 
                << " | " << book.getAuthor() 
                << " | " << book.getDate() << '\n';

    
}