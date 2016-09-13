//
//  cart.h
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/11/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#ifndef CART_H
#define CART_H

#include "item.h"
#include "user.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cart {
public:
    string username;
    int uniqueID;
    vector<Item> itemList;
    vector<int> itemQuantities;
    int numItems;
    
    Cart(User user);
    Cart(User user, int cartID);
    ~Cart();
    void addToCart(int itemID, int quantity);
    void removeFromCart(Item item, int quantity);
    void goToCheckout(User user, Cart cart);
    float getTotal(Cart cart);
};

#endif