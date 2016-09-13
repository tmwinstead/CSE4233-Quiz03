//
//  cart.cpp
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/11/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#include "cart.h"
#include "checkout.h"

//  Builds an empty cart with variables initialized
Cart::Cart() {
    username = "";
    uniqueID = 0;
    numItems = 0;
}

//  Builds a new cart with no items
Cart::Cart(User user) {
    username = user.username;
    
    // SQL here to pull next unique ID
    // uniqueID = ***returned uniqueID+1 ***
    
    numItems = 0;
    
}

//  Builds a cart with existing history
Cart::Cart(User user, int cartID) {
    username = user.username;
    uniqueID = cartID;
    
    //  SQL code to populate items/quantities/prices
    //  --> itemList[]
    //  --> itemQuantities[]
    //  --> itemPrices[]
    //  --> numItems (a count of number of different items)
}

//  Resets a cart object but does not remove from DB
Cart::~Cart() {
    username = "";
    uniqueID = 0;
    numItems = 0;
    itemList.clear();
    itemQuantities.clear();
}

//  Adds an item to the cart
void Cart::addToCart(int itemID, int quantity) {
    Item *item = new Item;
    item->itemID = itemID;
    
    //  SQL to lookup item and populate item object data fields
    //  --> item.stockQuantity
    //  --> item.cost
    //  --> item.itemName
    //  --> item.category
    
    int exists = 0;
    for (int i=0; i < itemList.size(); i++) {
        if (item->itemID == itemList.at(i).itemID) {
            exists = 1;
            if (item->stockQuantity < itemList.at(i).stockQuantity+quantity) {
                itemQuantities.at(i) = item->stockQuantity;
            }
            else {
                itemQuantities.at(i) += quantity;
            }
            break;
        }
    }
    if (!exists) {
        numItems++;
        itemList.push_back(*item);
        if (item->stockQuantity < quantity) {
            itemQuantities.push_back(item->stockQuantity);
        }
        else itemQuantities.push_back(quantity);
    }
}

//  Removes an item from the cart
void Cart::removeFromCart(Item item, int quantity) {
    for (int i=0; i < itemList.size(); i++) {
        if (item.itemID == itemList.at(i).itemID) {
            if (itemQuantities.at(i)-quantity < 0) {
                itemQuantities.at(i) = 0;
            }
            else itemQuantities.at(i)-=1;
            break;
        }
    }
}

//  Creates a checkout object and starts the checkout process
void Cart::goToCheckout() {
    Checkout *checkout = new Checkout();
    checkout->addCardNumber();
    checkout->addShippingAddress();
}


























