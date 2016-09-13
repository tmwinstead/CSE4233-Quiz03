//
//  database.h
//  CSE 4233 Quiz 03
//
//  Created by Zach Kendall on 09/12/16.
//  Copyright © 2016 Zach Kendall. All rights reserved.
//

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>

using namespace std;

class Database {
public:
  static int callback(void *NotUsed, int argc, char **argv, char **azColName);
  void getUser(string username);
  void getItem(string itemName);
  void getItem(int userID);
  void getCart(string username);
  void updateUser();
  void updateUserCart();
  void updateCartItem();
  void updateItem();
  void updateInventory();
};

#endif