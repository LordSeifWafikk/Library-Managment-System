#include <iostream>
#include <string>
#include "admin.h"
#include "user.h"
using namespace std;

string admin::getUsername(){return username;}
string admin::getPassword(){return password;}
void admin::displayNameID() {
    userInfo.displayUserInfo();
}
void admin::operator=(const admin &obj) {
    userInfo= obj.userInfo;
    username=obj.username;
    password=obj.password;
}
int admin::getAdminID() {return userInfo.getID();}