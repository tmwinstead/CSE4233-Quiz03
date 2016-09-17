//
//  checkout.h
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/12/16.
//

#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "cart.h"

#include <iostream>
#include <string>

using namespace std;

class Checkout {
private:
    bool updateInventory(Cart cart);
    void addCardNumber();
    void addShippingAddress();
    
public:
    int cardNumber;
    string shippingAddress;
    
    Checkout();
    ~Checkout();
    void submitOrder(Cart cart);
};

#endif