#include "User.h"
#include <iostream>
#include <string>
using namespace std;


int user::generateUserID() {
    srand((unsigned) time(NULL));
    int ID= 100000 +(rand()%1000001);
    return ID;
}
void user::displayUserInfo() {
    cout<<userID<<"\t\t"+name<<endl;
}
int user::getID() {return userID;}
string user::getName() {return name;}
void user::operator=(const user &obj) {
    name=obj.name;
    userID=obj.userID;
}