#include <iostream>
#include <string>
#include "library.h"
#include "book.h"
#include "user.h"
#include "admin.h"
#include "customer.h"

using namespace std;

bool login(const int& num_admins, admin* admins) {
    string enteredUsername, enteredPassword;

    while (true) {
        cout << "Login: " << endl;
        cout << "Username: ";
        getline(cin, enteredUsername);
        cout << "Password: ";
        getline(cin, enteredPassword);
        cout << endl;

        bool loggedIn = false;

        for (int i = 0; i < num_admins; i++) {
            if (enteredPassword == admins[i].getPassword() && enteredUsername == admins[i].getUsername()) {
                loggedIn = true;
                break;
            }
        }

        if (loggedIn) {
            cout << "Login successful!" << endl;
            return true;
        } else {
            cout << "Wrong username or password! Try again." << endl;
        }
    }
}
void displayMenu(){
    cout<<"Menu"<<endl;
    cout<<"1. Create a new user"<<endl;
    cout<<"2. Display existing user info"<<endl;
    cout<<"3. Remove customer by ID"<<endl;
    cout<<"4. Add book to library"<<endl;
    cout<<"5. Remove a book from the library by ID"<<endl;
    cout<<"6. Allow a customer to borrow a book" <<endl;
    cout<<"7. Allow a customer to return a book" << endl;
    cout<<"8. Display all books" <<endl;
    cout<<"9. Display book info by title" << endl;
    cout<<"10. Display books of a certain category" << endl;
    cout<<"11. Display books of a certain author"<<endl;
    cout<<"12. Exit" <<endl;
    cout<<endl;
}
admin createAdmin(const int z=0){
    admin objAdmin;
    string name,username,password;
    cout<<"Please enter the admin's data:"<<endl;
    cout<<" Full Name:";
    if(z!=0)
       cin.ignore();
    getline(cin,name);
    cout<<" Username:";
    getline(cin,username);
    cout<<" Password:";
    getline(cin,password);
    cout<<endl;
    objAdmin=admin(name,username,password);
    return objAdmin;
}

customer createCustomer(){
    customer objCustomer;
    string name;
    cout<<"please enter the customer name:";
    cin.ignore();
    getline(cin,name);
    cout<<endl;
    objCustomer=customer(name);
    return objCustomer;
}
void displayCustomers(customer* arrCustomers,const int& numCustomers){
    cout<<"the customers data:"<<endl;
    cout<<"ID:\t\tname:"<<endl;
    for(int i=0;i<numCustomers;i++){
        arrCustomers[i].displayNameID();
    }
    cout<<endl;
}
void displayAdmins(admin* arrAdmins,const int& numAdmins){
    cout<<"the admins data:"<<endl;
    cout<<"ID:\t\tname:"<<endl;
    for(int i=0;i<numAdmins;i++){
        arrAdmins[i].displayNameID();
        cout<<endl;
    }
    cout<<endl;
}
int findCustomer(customer* arrCustomers, int numOfCustomers,int theID){
    int index = 0;
    for(int i=0;i<numOfCustomers;i++){
        if(arrCustomers[i].getCustomerID()==theID) {
            index = i;
            break;
        }
    }
    return index;
}











int main(){
    const int max_admins=10;
    int num_admins=0,num_customers=0;
    const int max_customers=40;
    library l1;

    customer *customers=new customer[max_customers];
    admin *admins = new admin[max_admins];
    admins[num_admins]=createAdmin();
    num_admins++;

    int choice;
    if (login(num_admins, admins)){
    do{
        
        displayMenu();
        cout<< "Enter your choice: ";
        
        cin >> choice;
        switch(choice) {
            case 1: {
                string usertype;
                cout << "Enter the type of the user...(admin / customer):" << endl;
                cin >> usertype;
                cout << endl;
                if (usertype == "admin") {
                    admins[num_admins] = createAdmin(1);
                    num_admins++;
                    cout<<"Admin created."<<endl;
                } else if (usertype == "customer") {
                    customers[num_customers]=createCustomer();
                    num_customers++;
                    cout << "Customer created."<<endl;
                }else{
                    cout<<"error! (user type does not exist!!)"<<endl;
                }
                break;
            }
            case 2: {
                displayAdmins(admins,num_admins);
                displayCustomers(customers,num_customers);
                break;
            }
            case 3:{
                displayCustomers(customers,num_customers);
                int IDtoDelete ;
                cout<<"enter the ID of the customer you want to remove:";
                cin>>IDtoDelete;
                for(int i=findCustomer(customers,num_customers,IDtoDelete);
                    i<num_customers;i++){
                    customers[i]=customers[i+1];
                }
                num_customers--;
                cout<<"the customer has been removed"<<endl;
                break;
            }
            case 4: {
                string bookTitle, bookAuthor, bookCategory;
                cout << "Enter the book name: "<<endl;
                cin.ignore();
                getline(cin,bookTitle);

                cout << "Enter the author: "<<endl;
                getline(cin,bookAuthor);

                cout << "Enter the category: "<<endl;
                getline(cin, bookCategory);
                cout << endl;

                if (bookTitle.empty() || bookAuthor.empty() || bookCategory.empty()) {
                    cout << "Error: Empty fields. Please enter all the details." << endl;
                    break;
                }
                l1.add_book(bookTitle, bookAuthor, bookCategory);
                break;
            }
            case 5:{
                l1.display_allbooks();
                int id;
                cout<<"Enter the book id: "<<endl;
                cin>>id;
                l1.remove_book(id);
                break;
            }
            case 6: {
                int customerID, bookID, index;
                displayCustomers(customers,num_customers);
                cout <<"Enter the customer's ID:";
                cin>>customerID;
                index= findCustomer(customers, num_customers, customerID);
                if (customers[index].getNumberOfBorrowedBook() == 5) {
                    cout << "Customer has borrowed 5 books; Can not borrow any more." << endl;
                    break;
                } else {
                    l1.display_nonborrowed();
                    cout << "Enter the book's ID:";
                    cin>>bookID;
                    customers[index].borrowBook(l1.find_book_ID(bookID,1));
                    cout<<"The book is borrowed."<<endl;
                    break;
                }
            }
            case 7:{
                l1.display_borrowed();
                int customer_ID,book_ID,index_;
                displayCustomers(customers,num_customers);
                cout<<"Enter the customer's ID:";
                cin>>customer_ID;
                index_= findCustomer(customers,num_customers,customer_ID);
                l1.display_borrowed();
                cout<<"Enter the book's ID:";
                cin>>book_ID;
                l1.find_book_ID(book_ID,0);
                customers[index_].returnBook(book_ID);
                cout<<"The book is returned."<<endl;
                break;
            }
            case 8:{
                l1.display_borrowed();
                l1.display_nonborrowed();
                break;
            }
            case 9:{
                string title;
                book *found;
                int numfound;
                cout<<"Enter Book Title: "<<endl;
                cin.ignore();
                getline(cin,title);

                found=l1.find_book_title(title,numfound);

                for(int i=0 ; i<numfound;i++){
                    found[i].BookInfoDisplay();
                }

                break;
            }
            case 10:{
                string category;
                book* found;
                int numfound;
                cout<<"Enter the book's category: "<<endl;
                cin.ignore();
                getline(cin,category);

                found=l1.find_book_category(category,numfound);

                for(int i=0 ; i<numfound;i++){
                    found[i].BookInfoDisplay();
                }

                break;
            }

            case 11:{
                string author;
                book* found;
                int numfound;
                cout<<"Enter Author Name: "<<endl;
                cin.ignore();
                getline(cin,author);

                found=l1.find_book_author(author,numfound);

                for(int i=0 ; i<numfound;i++){
                    found[i].BookInfoDisplay();
                }

                break;
            }
            case 12:{
                return false;
            }
            default:{
                cout<<"Invalid Choice!"<<endl;
                break;
            }
        }
    } while (choice!=12);
    }
    delete customers;
    delete admins;
    return 0;
}