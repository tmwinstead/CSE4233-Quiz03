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
    printf("Connection established.\n");
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

string Database::getUser(string username) {
  sqlite3 *db;

  sqlite3_open("quiz3.db", &db);

  
  
  sqlite3_close(db);

  return username;
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
  
  //Iterate through each column of the table and place the data in a vector to return to the Item class.
    
    /*
     int sqlite3_exec(
     sqlite3*,                                  // An open database
    const char *sql,                           // SQL to be evaluated
    int (*callback)(void*,int,char**,char**),  // Callback function
    void *,                                    // 1st argument to callback
    char **errmsg                              // Error msg written here
    );*/
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

vector<int> Database::getCart(string username) {
  sqlite3 *db;

  sqlite3_open("quiz3.db", &db);
  vector<int> cartNums;

  while (!SQLITE_OK) {
    //add stuff here
  }

  sqlite3_close(db);

  return cartNums;
}

void Database::updateUser(string username) {
  sqlite3 *db;

  sqlite3_open("quiz3.db", &db);

  sqlite3_close(db);
}

void Database::updateItem(string itemName) {
  sqlite3 *db;

  sqlite3_open("quiz3.db", &db);

  sqlite3_close(db);
}

void Database::updateItem(int itemID) {
  sqlite3 *db;

  sqlite3_open("quiz3.db", &db);

  sqlite3_close(db);
}

void Database::updateInventory() {
  sqlite3 *db;

  sqlite3_open("quiz3.db", &db);

  sqlite3_close(db);
}