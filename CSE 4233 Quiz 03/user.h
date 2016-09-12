//
//  user.h
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/11/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User {
public:
    string username;
    string login(string username);
    
    User(string userID);
    ~User();
    void logout();
    
};

#endif