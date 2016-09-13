//
//  admin.cpp
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/12/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

// Last editor: zak35

#include "admin.h"
#include "database.h"

void writeToStorage() {
  updateUser();
  updateUserCart();
  updateCartItem();
  updateItem();
  updateInventory();
}

void readFromStorage() {
  getUser();
  getUserCart();
  getCartItem();
  getItem();
  getInventory();
 }