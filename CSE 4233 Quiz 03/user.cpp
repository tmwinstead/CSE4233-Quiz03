//
//  user.cpp
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/11/16.
//

#include "user.h"
#include "database.h"

//  Creates a new user and initializes username
User::User() {
    username = "";
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
    username = userID;
    
    Database db;
    string login = db.updateUser(userID);
    
    return login;
}

void User::logout() {
    this->~User();
}