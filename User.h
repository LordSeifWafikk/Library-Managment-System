#include <iostream>
#include <string>

using namespace std;
#ifndef REAL_SOURCE_CODE_USER_H
#define REAL_SOURCE_CODE_USER_H
class user
{
private:
    int userID;
    string name;
public:
    user():userID(0),name(""){};
    user(string name_):userID(generateUserID()),name(name_){};
    int generateUserID();
    void displayUserInfo();
    int getID();
    string getName();
    void operator=(const user&);
};
#endif //REAL_SOURCE_CODE_USER_H
