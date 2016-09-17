//
//  database.h
//  CSE 4233 Quiz 03
//
//  Created by Zach Kendall on 09/12/16.
//

#ifndef DATABASE_H
#define DATABASE_H

#include "item.h"
#include "user.h"
#include "cart.h"
#include "checkout.h"

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class Database {
public:
    
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    Item getItem(int userID);
    
    Database();
    //~Database();
    
    string updateUser(string username);
    int getNextCart(string username);
    bool isPurchased(int uniqueID);
    bool updateInventory(Cart cart);
    Cart rebuildCart(string username, int uniqueID);
    vector<Item> categoryLookup(string category);
    void addToUserCart(int uniqueID, string username);
    void addToCartItem(int uniqueID, int itemNum, int quantity, float price, int itemID);
    void removeFromCartItem(int uniqueID, int itemNum, int quantity, float price, int itemID);
};

#endif