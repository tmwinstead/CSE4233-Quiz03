//
//  user.cpp
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/11/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#include "user.h"

//  Creates an empty user and initializes variables
User::User() {
    username = "";
}

//  Creates a new user
User::User(string userID) {
    
    username = userID;
    
    //  SQL to add a new user to DB with given username
}

//  Resets a user object without removing from DB
User::~User() {
    username = "";
}

//  Creates cart from history after lookup via passed User ID
vector<int> User::getHistory() {
    vector<int> prevCarts;
    
    //  SQL to query DB for all cart uniqueIDs tied to username
    //  For each previous cart, prevCarts.push_back(cart#)
    
    return prevCarts;
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

void User::logout() {
    
}