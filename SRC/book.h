
#ifndef REAL_SOURCE_CODE_BOOKS_H
#define REAL_SOURCE_CODE_BOOKS_H
#include <iostream>
#include <string>
using namespace std;
class book{
private:
    int ID;
    string Title;
    string Author;
    string Category;
    bool Borrowed;
public:
    int generateBookID();
    book() : ID(0), Title(""), Author(""), Category(""), Borrowed(false) {};   //Default Constructor
    book(string , string , string);    //Constructor with arguments!
    void BookInfoDisplay();
    int getID();
    string getTitle();
    string getAuthor();
    string getCategory();
    bool getBorrowed();
    void borrowBook();
    void returnBook();// borrowed true
                        // borrowed false 
    void operator=(const book&);

};

#endif //REAL_SOURCE_CODE_BOOKS_H
