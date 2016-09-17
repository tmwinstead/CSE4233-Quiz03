//
//  cart.h
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/11/16.
//

#ifndef CART_H
#define CART_H

#include "item.h"
#include "user.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cart {
public:
    string username;
    int uniqueID;
    vector<Item> itemList;
    vector<int> itemQuantities;
    int numItems;
    
    Cart();
    Cart(User user);
    Cart(User user, int cartID);
    ~Cart();
    void addToCart(int itemID, int quantity);
    void removeFromCart(Item item, int quantity);
    void goToCheckout();
    float getTotal();
};

#endif