#include <iostream>
#include <string>
#include "book.h"
using namespace std;


book::book(string title_ , string author_ , string category_) :ID(generateBookID()), Title(title_),Author(author_),Category(category_),Borrowed(false){}
int book::generateBookID(){
    srand((unsigned) time(NULL));
    int id= 10000 +(rand()%100001);
    return id;
}
void book::BookInfoDisplay() {
    cout<<"here's the book's information:"<<endl;
    cout<<"the book's title is:"<<Title<<endl;
    cout<<"the book's author is:"<<Author<<endl;
    cout<<"the book's ID is:"<<ID<<endl;
    cout<<"the book's category is:"<<Category<<endl;
    if(Borrowed==false){
        cout<<"the book is not borrowed."<<endl;
    }else{
        cout<<"the book is borrowed."<<endl;
    }
}
int book::getID() {return ID;}

string book::getTitle() {return Title;}

string book::getAuthor() {return Author;}

string book::getCategory() {return Category;}

bool book::getBorrowed() {return Borrowed;}

void book::operator=(const book &obj) {
    ID=obj.ID;
    Category=obj.Category;
    Author=obj.Author;
    Title=obj.Title;
    Borrowed=obj.Borrowed;
}

void book::borrowBook() {
    Borrowed= true;
}

void book::returnBook() {
    Borrowed= false;
}