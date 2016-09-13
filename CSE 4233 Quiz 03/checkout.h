//
//  checkout.h
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/12/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "cart.h"

#include <iostream>
#include <string>

using namespace std;

class Checkout {
public:
    int cardNumber;
    string shippingAddress;
    
    void submitOrder(Cart cart);
    void updateInventory();
    void addCardNumber(int cardNumber);
    void addShippingAddress(string shippingAddress);
};

#endif