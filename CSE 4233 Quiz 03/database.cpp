//
//  database.cpp
//  CSE 4233 Quiz 03
//
//  Created by Zach Kendall on 09/12/16.
//  Copyright © 2016 Zach Kendall. All rights reserved.
//

#include "database.h"
#include "sqlite3.h"
#include <string>
#include <iostream>

using namespace std;

void getUser(string username) {
  sqlite3 *db;

  sqlite3_open();
  //WIP for all these methods, gotta figure out the tutorial
  sqlite3_close(db);
}

void getItem(string itemName) {
  sqlite3 *db;

  sqlite3_open();

  sqlite3_close(db);
}

void getItem(int itemID) {
  sqlite3 *db;

  sqlite3_open();

  sqlite3_close(db);

}

void getCart(string username) {
  sqlite3 *db;

  sqlite3_open();

  sqlite3_close(db);

  return //array of cart nums
}

void getInventory() {
  sqlite3 *db;

  sqlite3_open();

  sqlite3_close(db);
}

void updateUser(string username) {
  sqlite3 *db;

  sqlite3_open();

  sqlite3_close(db);
}

void updateItem(string itemName) {
  sqlite3 *db;

  sqlite3_open();

  sqlite3_close(db);
}

void updateItem(int itemID) {
  sqlite3 *db;

  sqlite3_open();

  sqlite3_close(db);
}

void updateInventory() {
  sqlite3 *db;

  sqlite3_open();

  sqlite3_close(db);
}