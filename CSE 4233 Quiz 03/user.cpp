//
//  user.cpp
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/11/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#include "user.h"
#include "cart.cpp"

// Creates cart from history after lookup via passed User ID
Cart User::getHistory(int num) {
    Cart *cart = new Cart(num);
    return cart;
}

void User::logout() {
    
}