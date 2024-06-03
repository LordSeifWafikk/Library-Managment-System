#ifndef REAL_SOURCE_CODE_CUSTOMER_H
#define REAL_SOURCE_CODE_CUSTOMER_H
#include <iostream>
#include <string>
#include "User.h"
#include "book.h"

using namespace std;

class customer:public user{
private:
    user customerInfo;
    book customerBooks[5];
    int numBorrowedBooks=0;
public:
    customer();
    customer(string);
    void borrowBook(book);
    void returnBook(const int&);
    int getNumberOfBorrowedBook();
    book* getArrayOfBooks();
    void displayNameID();
    void displayCustomerData();
    void operator=(const customer&);
    int getCustomerID();
};
#endif //REAL_SOURCE_CODE_CUSTOMER_H
