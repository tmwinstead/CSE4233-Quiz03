//
//  cart.cpp
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/11/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#include "cart.h"
#include "checkout.h"
#include "database.h"

//  Builds an empty cart with variables initialized
Cart::Cart() {
    username = "";
    uniqueID = 0;
    numItems = 0;
}

//  Builds a new cart for a user
Cart::Cart(User user) {
    username = user.username;
    Database db;
    uniqueID = db.getNextCart(username);
    bool purchased = db.isPurchased(uniqueID);
    if (!purchased) {
        Cart(user, uniqueID);
    }
}

//  Builds a cart with existing history
Cart::Cart(User user, int cartID) {
    
    Database db;
    Cart cart = db.rebuildCart(user.username, cartID);
    username = cart.username;
    uniqueID = cart.uniqueID;
    numItems = cart.numItems;
}

//  Resets a cart object's variables but does not remove from DB
Cart::~Cart() {
    username = "";
    uniqueID = 0;
    if (numItems > 0) {
        itemList.erase(itemList.begin()+numItems-1);
        itemQuantities.erase(itemQuantities.begin()+numItems-1);
        numItems = 0;
    }
}

//  Adds an item to the cart
void Cart::addToCart(int itemID, int quantity) {
    Database db;
    Item item = db.getItem(itemID);
    
    int exists = 0;
    for (int i=0; i < itemList.size(); i++) {
        if (item.itemID == itemList.at(i).itemID) {
            exists = 1;
            if (item.stockQuantity < itemList.at(i).stockQuantity+quantity) {
                itemQuantities.at(i) = item.stockQuantity;
            }
            else {
                itemQuantities.at(i) += quantity;
            }
            break;
        }
    }
    if (!exists) {
        numItems++;
        itemList.push_back(item);
        if (item.stockQuantity < quantity) {
            itemQuantities.push_back(item.stockQuantity);
        }
        else itemQuantities.push_back(quantity);
    }
}

//  Removes an item from the cart
void Cart::removeFromCart(Item item, int quantity) {
    for (int i=0; i < itemList.size(); i++) {
        if (item.itemID == itemList.at(i).itemID) {
            if (itemQuantities.at(i)-quantity < 0) {
                itemList.erase(itemList.begin()+i);
                itemQuantities.erase(itemQuantities.begin()+i);
            }
            else itemQuantities.at(i) -= quantity;
            break;
        }
    }
}

//  Creates a checkout object and starts the checkout process
void Cart::goToCheckout() {
    Checkout *checkout = new Checkout();
    checkout->submitOrder(*this);
}

//  Returns the current value of a cart
float Cart::getTotal() {
    float total=0;
    for (int i=0; i < itemList.size(); i++) {
        total += itemList.at(i).cost*itemQuantities.at(i);
    }
    return total;
}