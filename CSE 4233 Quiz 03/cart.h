//
//  cart.h
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/11/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#ifndef cart_hpp
#define cart_hpp

#include "item.h"
#include "user.h"

#include <iostream>
using namespace std;

class Cart {
public:
    int numItems;
    int itemList[0];
    int itemQuantities[0];
    int itemPrices;
    int calculatedTotal;
    int uniqueID;
    User user;
    
    void addToCart(Item item, int quantity);
    void removeFromCart(Item item, int quantity);
    void goToCheckout(Cart cart);
};

#endif
