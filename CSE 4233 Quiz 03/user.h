//
//  user.h
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/11/16.
//

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
public:
    string username;
    
    User();
    User(string userID);
    ~User();
    vector<int> getHistory();
    string login(string userID);
    void logout();
    
};

#endif