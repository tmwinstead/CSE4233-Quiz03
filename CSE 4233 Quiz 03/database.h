//
//  database.h
//  CSE 4233 Quiz 03
//
//  Created by Zach Kendall on 09/12/16.
//  Copyright © 2016 Zach Kendall. All rights reserved.
//

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class Database {
public:
    
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    tuple<int, float, string, string> getItem(int userID);
    
    Database();
    ~Database();
    
    string getUser(string username);
    void updateUser(string username);
    
    void getItem(string itemName);
    void updateItem(string itemName);
    void updateItem(int itemID);
    vector<int> getCart(string username);
    void updateInventory();
};

#endif