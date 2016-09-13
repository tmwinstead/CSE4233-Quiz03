//
//  user.cpp
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/11/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#include "user.h"

//  Creates a new user
User::User(string userID) {
    
    username = userID;
    
    //  SQL to add a new user to DB with given username
}

//  Deletes a user object without removing user from the database
User::~User() {
    username = "";
}

//  Checks that provided username is in the DB, if not, creates a new entry
string User::login(string userID) {
    
    //  SQL to check that username is in DB
    //  SQL to add username if not
    //  Check if userID was new or not, return appropriate string
    //  --> return "Logged In"
    //  --> return "User Created and Logged In"
    return "Logged In";
}

//  Creates cart from history after lookup via passed User ID
/*Cart User::getHistory(int num) {
    Cart *cart = new Cart(num);
    return cart;
}

void User::logout() {
    
}*/