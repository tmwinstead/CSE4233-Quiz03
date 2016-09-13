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
private:
    string updateInventory();
    void addCardNumber();
    void addShippingAddress();
    
public:
    int cardNumber;
    string shippingAddress;
    
    Checkout();
    ~Checkout();
    void submitOrder(string username, int uniqueID);
};

#endif