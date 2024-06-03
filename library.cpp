#include <iostream>
#include <string>
#include "book.h"
#include "library.h"
//THE OLD book     //the old book
using namespace std;

library::library(){ allbooks= new book[max_books];}
string library:: tosmall(const string &s){
    string small_s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            small_s += s[i] + 32;
        }
        else {
            small_s += s[i];
        }
    }
    return small_s;
}

bool library::ismatching(const string &s,const string &t){ // it helps in find by name function
    int size1 = s.size();                    // for searching about part of the name
    int size2 = t.size();
    if(size1>size2){
        return false;
    }
    for(int i = 0;i<size2-size1+1;i++){
        if(t[i] == s[0]){
            bool matching = true;
            for(int k = i,j = 0;j<size1;j++,k++){
                if(t[k]!=s[j]){
                    matching= false;
                    break;
                }
            }
            if(matching){
                return true;
            }
        }
    }
    return false;
}

void library::add_book(string title, string author, string category){
        if (num_books >= max_books) {
            cout << "Library is full!" << endl;
            return;
        }
        allbooks[num_books++]=book(title ,author ,category);
        
        cout<<"Book added to the library!"<<endl;
}

void library::remove_book(int bookID){
    for (int i=0;i<num_books;i++){
        if (allbooks[i].getID() == bookID){
            for (int j=i;j<num_books-1;j++){
                allbooks[j]=allbooks[j+1];
            }
        num_books--;
        cout<<"Book removed from the library!"<< endl;
        return;
        }
    cout<<"The Book ID you entered is not found in the library" << endl;
    }        
}

void library::display_allbooks(){
    if (num_books==0){
        cout << "Library is empty!" <<endl;
        return;
    }

    for (int i =0; i<num_books;i++){
        allbooks[i].BookInfoDisplay();
        cout<<endl;
    }
}

void library::display_borrowed(){
    cout<<"Borrowed books:"<<endl;
    for(int i=0;i<num_books;i++){
        if(allbooks[i].getBorrowed()){
            allbooks[i].BookInfoDisplay();
            cout<<endl;
        }
    }
}
void library::display_nonborrowed(){
    cout<<"Non Borrowed books:"<<endl;
    for(int i=0;i<num_books;i++){
        if(!allbooks[i].getBorrowed()){
            allbooks[i].BookInfoDisplay();
            cout<<endl;
        }
    }
}
//do not forget in-sensitive cases ym3alemm
book* library::find_book_category(const string &category, int &found){
    book* matching_books= new book[num_books];
    int count=0;
    for(int i=0;i<num_books;i++){
        if(tosmall(allbooks[i].getCategory())==tosmall(category)){
            matching_books[count++]=allbooks[i];
        }
    }
    if (count==0){ // there is no book with the entered category
        cout<<"No books found by this category"<<endl;
        delete[] matching_books;
        return nullptr;
    }
    found=count;
    return matching_books;
}

book* library::find_book_author(const string &author_name, int& found){
    book* matching_books= new book[num_books];
    int count=0;
    for(int i=0;i<num_books;i++){
        if(ismatching(tosmall(author_name),tosmall(allbooks[i].getAuthor()))){
            matching_books[count]=allbooks[i];
            count++;
        }
    }
    if (count==0){ // there is no book with the entered name
        cout<<"No books found by this author"<<endl;
        delete[] matching_books;
        return nullptr;
    }
    found=count;
    return matching_books;
}
book* library::find_book_title(const string &title, int &found){
    book* matching_books= new book[num_books];
    int count=0;
    for(int i=0;i<num_books;i++){
        if(tosmall(allbooks[i].getTitle())==tosmall(title)){
            matching_books[count]=allbooks[i];
            count++;
        }
    }
    if (count==0){ // there is no book with the entered name
        cout<<"No books found by this title"<<endl;
        delete[] matching_books;
        return nullptr;
    }
    found=count;
    return matching_books;
}

book library::find_book_ID(const int &ID,int x) {
    book matching_book;
    for(int i=0;i<num_books;i++) {
        if (allbooks[i].getID()== ID) {
            if(x=1){
                allbooks[i].borrowBook();
            }else{
                allbooks[i].returnBook();
            }
            return matching_book;
        }
    }
}
int library::getNumBooks(){return num_books;}