//
//  checkout.cpp
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/12/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#include "checkout.h"

Checkout::Checkout() {
    cardNumber = 0;
    shippingAddress = "";
}

Checkout::~Checkout() {
    cardNumber = 0;
    shippingAddress = "";
}

void Checkout::addCardNumber() {
    cout << "\n\nEnter your card number: ";
    cin >> cardNumber;
}

void Checkout::addShippingAddress() {
    cout << "\n\nEnter your shipping address: ";
    cin >> shippingAddress;
}

void Checkout::updateInventory() {
    
}