//
//  checkout.cpp
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/12/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#include "checkout.h"

//  Creates a checkout object with initialized variables
Checkout::Checkout() {
    cardNumber = 0;
    shippingAddress = "";
}

//  Resets the checkout object's variables
Checkout::~Checkout() {
    cardNumber = 0;
    shippingAddress = "";
}

//  Private method that prompts user for a card number
void Checkout::addCardNumber() {
    cout << "\n\nEnter your card number: ";
    cin >> cardNumber;
}

//  Private method that prompts user for shipping address
void Checkout::addShippingAddress() {
    cout << "\n\nEnter your shipping address: ";
    cin >> shippingAddress;
}

//  Updates the inventory at the end of checkout
string Checkout::updateInventory() {
    
    //  SQL to update the inventory
    //  If inventory update is successful, return purchase successful
    //  If inventory update fails, return purchase unsuccessful
    
    return "Purchase successful";
}

//  Calls the private methods for completing a checkout
void Checkout::submitOrder(string username, int uniqueID) {
    addCardNumber();
    addShippingAddress();
    updateInventory();
}