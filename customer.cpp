#include <iostream>
#include "User.h"
#include "Customer.h"
#include "book.h"

using namespace std;

customer::customer(){
    customerInfo=user();
    for(int i=0;i<5;i++){
        customerBooks[i]=book();
    }
}
customer::customer(string name) {customerInfo= user(name);}

void customer::borrowBook(book objBook) {
    customerBooks[numBorrowedBooks]=objBook;
    numBorrowedBooks++;
}

void customer::displayCustomerData() {
    cout<<"the customer name/ID is:";
    customerInfo.displayUserInfo();
    cout<<".He borrowed "<<numBorrowedBooks<<" books."<<" ";
    for(int i=0;i<numBorrowedBooks;i++){
        customerBooks[i].BookInfoDisplay();
    }
}
void customer::displayNameID(){
    customerInfo.displayUserInfo();
}
int customer::getNumberOfBorrowedBook() {return numBorrowedBooks;}

book *customer::getArrayOfBooks() {return customerBooks;}

void customer::returnBook(const int& bookID) {
    for (int i = 0; i < 5; i++) {
        if (customerBooks[i].getID() == bookID) {
            for (int j = i; j < 5; j++) {
                customerBooks[j] = customerBooks[j + 1];
            }
            cout << "Book returned from the library!" << endl;
        }
        break;
    }
    numBorrowedBooks--;
}
void customer::operator=(const customer& obj){
    customerInfo=obj.customerInfo;
    for(int i=0;i<5;i++){
        customerBooks[i]=obj.customerBooks[i];
    }
}
int customer::getCustomerID(){return customerInfo.getID();}
