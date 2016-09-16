//
//  database.cpp
//  CSE 4233 Quiz 03
//
//  Created by Zach Kendall on 09/12/16.
//  Copyright © 2016 Zach Kendall. All rights reserved.
//

#include "database.h"
#include "sqlite3.h"

#include <cstring>
#include <sstream>

using namespace std;

Database::Database() {
  sqlite3 *db;
  //db = "quiz3.db";
  
  //This will create a database if it doesn't exist.
  sqlite3_open("quiz3.db", &db);
  //Check to see if connection was successful
  if (!SQLITE_OK) {
    printf("Connection failed. \n");
  }
  sqlite3_close(db);
}


//Taken from www.sqlite.org/quickstart.html, as it is needed for sqlite_exec().
int Database::callback(void *NotUsed, int argc, char **argv, char **azColName) {
  int i;
  for (i = 0; i<argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

Item Database::getItem(int itemID) {
  sqlite3 *db;

  //This converts itemID into a string to concatenate onto the sql statement.
  string itemUID;
  ostringstream convert;
  convert << itemID;
  itemUID = convert.str();
  //********************//

  char *cItemUID;
  char **errmsg;

  Item itemInfo;
  itemInfo.itemID = itemID;
  const char *sql;

  sqlite3_open("quiz3.db", &db);
  
    /*
     int sqlite3_exec(
     sqlite3*,                                  // An open database
    const char *sql,                           // SQL to be evaluated
    int (*callback)(void*,int,char**,char**),  // Callback function
    void *,                                    // 1st argument to callback
    char **errmsg                              // Error msg written here
    );*/

    //Iterate through each column of the table and place the data in a vector to return to the Item class.
  for (int i = 0; i < 4; i++) {
    switch (i) {
    case 0:
      itemUID = "SELECT stockQuantity FROM item WHERE item.itemID = " + itemUID;
      strcpy(cItemUID, itemUID.c_str());
      sql = cItemUID;
      itemInfo.stockQuantity = sqlite3_exec(db, sql, callback, 0, errmsg);
      break;
    case 1:
      itemUID = "SELECT cost FROM item WHERE item.itemID = " + itemUID;
      strcpy(cItemUID, itemUID.c_str());
      sql = cItemUID;
      itemInfo.cost = sqlite3_exec(db, sql, callback, 0, errmsg);
      break;
    case 2:
      itemUID = "SELECT itemName FROM item WHERE item.itemID = " + itemUID;
      strcpy(cItemUID, itemUID.c_str());
      sql = cItemUID;
      itemInfo.itemName = sqlite3_exec(db, sql, callback, 0, errmsg);
      break;
    case 3:
      itemUID = "SELECT category FROM item WHERE item.itemID = " + itemUID;
      strcpy(cItemUID, itemUID.c_str());
      sql = cItemUID;
      itemInfo.category = sqlite3_exec(db, sql, callback, 0, errmsg);
      break;

    default:
      sqlite3_close(db);
      break;
    }
  }

  sqlite3_close(db);

  return itemInfo;
}

int Database::getNextCart(string username) {
  sqlite3 *db;
  int cartNum;
  string statement;
  bool isPurchased;

  char *cStatement;
  char **errmsg;

  const char *sql;

  statement = "SELECT MAX(uniqueID) FROM UserCart WHERE UserCart.username = " + username;
  strcpy(cStatement, statement.c_str());
  sql = cStatement;

  sqlite3_open("quiz3.db", &db);

  //Gets latest cartNum, add one to the cartNum, then creates an empty cart.
  cartNum = sqlite3_exec(db, sql, callback, 0, errmsg);

  //This converts cartNum into a string to concatenate onto the sql statement.
  string strCartNum;
  ostringstream convert;
  convert << cartNum;
  strCartNum = convert.str();
  //********************//

  statement = "SELECT isPurchased FROM UserCart WHERE UserCart.uniqueID = " + strCartNum;
  strcpy(cStatement, statement.c_str());
  sql = cStatement;
  isPurchased = sqlite3_exec(db, sql, callback, 0, errmsg);

  if (!isPurchased) {
    sqlite3_close(db);

    return cartNum;
  }
  else {
    cartNum += 1;

    //This converts cartNum into a string to concatenate onto the sql statement.
    string strCartNum;
    ostringstream convert;
    convert << cartNum;
    strCartNum = convert.str();
    //********************//

    statement = "INSERT INTO UserCart VALUES (" + strCartNum + "," + username + ",FALSE)";
    strcpy(cStatement, statement.c_str());
    sql = cStatement;

    sqlite3_exec(db, sql, callback, 0, errmsg);
    //*****************************************//

    sqlite3_close(db);

    return cartNum;
  }
}

bool Database::isPurchased(int uniqueID) {
  sqlite3 *db;
 
  string statement;
  bool purchased;

  char *cStatement;
  char **errmsg;

  const char *sql;

  //This converts cartNum into a string to concatenate onto the sql statement.
  string strCartNum;
  ostringstream convert;
  convert << uniqueID;
  strCartNum = convert.str();
  //********************//

  statement = "SELECT isPurchased FROM UserCart WHERE UserCart.uniqueID = " + strCartNum;
  strcpy(cStatement, statement.c_str());
  sql = cStatement;

  sqlite3_open("quiz3.db", &db);

  purchased = sqlite3_exec(db, sql, callback, 0, errmsg);

  sqlite3_close(db);

  return purchased;
}

string Database::updateUser(string username) {
  sqlite3 *db;

  char *cStatement;
  char **errmsg;

  string statement;
  const char *sql;
  bool exists;
  string login = "Logged in.";

  //SQL statement to check if the user exists; if no, then make it
  statement = "SELECT * FROM User WHERE User.username = " + username;
  strcpy(cStatement, statement.c_str());
  sql = cStatement;

  sqlite3_open("quiz3.db", &db);

  exists = sqlite3_exec(db, sql, callback, 0, errmsg);
  if (!exists) {
    statement = "INSERT INTO User VALUES (" + username + ")";
    strcpy(cStatement, statement.c_str());
    sql = cStatement;
    sqlite3_exec(db, sql, callback, 0, errmsg);
    login = "User created and logged in.";
  }
  
  sqlite3_close(db);

  return login;
}

bool Database::updateInventory(Cart cart) {
  sqlite3 *db;

  char *cStatement;
  char **errmsg;

  string statement;
  const char *sql;
  string newQuantity;
  string strItemID;
  string strCartNum;
  ostringstream convert;
  bool success;

  sqlite3_open("quiz3.db", &db);

  for (int i = 0; i < cart.itemList.size(); i++) {
    //This converts itemID into a string to concatenate onto the sql statement.
    convert << cart.itemList.at(i).itemID;
    strItemID = convert.str();
    //********************//

    statement = "UPDATE Inventory SET quantity = " + newQuantity + " WHERE Inventory.itemID = " + strItemID;
    strcpy(cStatement, statement.c_str());
    sql = cStatement;

    cout << cart.itemList.at(i).stockQuantity; //Old q
    cart.itemList.at(i).stockQuantity -= cart.itemQuantities.at(i);
    cout << cart.itemList.at(i).stockQuantity; //New q

    //This converts the item quantity into a string to concatenate onto the sql statement.
    convert << cart.itemList.at(i).stockQuantity;
    newQuantity = convert.str();
    //********************//

    sqlite3_exec(db, sql, callback, 0, errmsg);
    if (SQLITE_OK) {
      success = true;
    }
  }

  //This converts cartNum into a string to concatenate onto the sql statement.
  convert << cart.uniqueID;
  strCartNum = convert.str();
  //********************//
  statement = "UPDATE UserCart SET isPurchased = TRUE WHERE UserCart.uniqueID = " + strCartNum;
  strcpy(cStatement, statement.c_str());
  sql = cStatement;
  sqlite3_exec(db, sql, callback, 0, errmsg);

  sqlite3_close(db);

  if (success) { return success; }
  else { return false; }
}

Cart Database::rebuildCart(string username, int uniqueID) {
  sqlite3 *db;
  Cart cart;

  int iterations;
  int itemID;
  int quantity;
  string statement;
  char *cStatement;
  char **errmsg;

  //This converts cartNum into a string to concatenate onto the sql statement.
  string strCartNum;
  ostringstream convert;
  convert << uniqueID;
  strCartNum = convert.str();
  //********************//
  string strItemNum; //for later use


  const char *sql;
  sqlite3_open("quiz3.db", &db);

  //Get number of items in cart to determine how many iterations the loop runs
  statement = "SELECT MAX(itemNum) FROM CartItem WHERE CartItem.uniqueID = " + strCartNum + " AND CartItem.username = " + username;
  strcpy(cStatement, statement.c_str());
  sql = cStatement;
  iterations = sqlite3_exec(db, sql, callback, 0, errmsg);

  for (int i = 0; i <= iterations; i++) {
    //This converts iterations into a string to concatenate onto the sql statement.
    convert << i;
    strItemNum = convert.str();
    //********************//

    //Get itemID
    statement = "SELECT itemID FROM CartItem WHERE CartItem.uniqueID = " + strCartNum + " AND CartItem.username = " + username + " AND CartItem.itemNum = " + strItemNum;
    strcpy(cStatement, statement.c_str());
    sql = cStatement;
    itemID = sqlite3_exec(db, sql, callback, 0, errmsg);
    //Get quantity
    statement = "SELECT quantity FROM CartItem WHERE CartItem.uniqueID = " + strCartNum + " AND CartItem.username = " + username + " AND CartItem.itemNum = " + strItemNum;
    strcpy(cStatement, statement.c_str());
    sql = cStatement;
    quantity = sqlite3_exec(db, sql, callback, 0, errmsg);
    //Add to cart
    cart.addToCart(itemID, quantity);
  }
  
  sqlite3_close(db);

  return cart;
}

vector<Item> Database::categoryLookup(string category) {
  sqlite3 *db;
  Cart cart;

  string strItemNum;
  vector<Item> items;
  string statement;
  char *cStatement;
  char **errmsg;

  const char *sql;
  sqlite3_open("quiz3.db", &db);

  //Get number of items in category to determine how many iterations the loop runs
  statement = "SELECT COUNT(*) FROM Item WHERE Item.category= " + category;
  strcpy(cStatement, statement.c_str());
  sql = cStatement;
  iterations = sqlite3_exec(db, sql, callback, 0, errmsg);

  for (int i = 0; i < iterations; i++) {
    //This converts iterations into a string to concatenate onto the sql statement.
    convert << i;
    strItemNum = convert.str();
    //********************//

    Item item = new Item;
    item.category = category;

    statement = "SELECT itemID FROM Item WHERE Item.category = " + category + " AND Item.itemNum = " + strItemNum;
    strcpy(cStatement, statement.c_str());
    sql = cStatement;
    item.itemID = sqlite3_exec(db, sql, callback, 0, errmsg);

    statement = "SELECT cost FROM Item WHERE Item.category = " + category + " AND Item.itemNum = " + strItemNum;
    strcpy(cStatement, statement.c_str());
    sql = cStatement;
    item.cost = sqlite3_exec(db, sql, callback, 0, errmsg);

    statement = "SELECT quantity FROM Item WHERE Item.category = " + category + " AND Item.itemNum = " + strItemNum;
    strcpy(cStatement, statement.c_str());
    sql = cStatement;
    item.stockQuantity = sqlite3_exec(db, sql, callback, 0, errmsg);

    items.push_back() = item;
  }

  sqlite3_close(db);

  return items;
}