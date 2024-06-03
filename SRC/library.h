#ifndef LIBRARY_REALSOURCE_H
#define LIBRARY_REALSOURCE_H
#include <iostream>
#include <string>
#include "book.h"
using namespace std;

class library{
private :
    const int max_books = 50;
    book* allbooks;
    int num_books=0; //index

public:
    library();
    void add_book(string , string , string);
    void remove_book( int );
    void display_allbooks();
    book find_book_ID(const int&,int x);
    book* find_book_author(const  string&,int&);
    book* find_book_category(const string&,int&);
    book* find_book_title(const string&,int&);
    void display_borrowed();
    void display_nonborrowed();
    bool ismatching(const string& , const string&); // it helps in find by name function
    string tosmall(const string &);
    int getNumBooks();
};
#endif
