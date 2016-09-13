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
#include <vector>
#include <tuple>
#include <sstream>

using namespace std;

Database::Database() {
  sqlite3 *db;
  db = "quiz3.db";
  
  //This will create a database if it doesn't exist.
  sqlite_open(db);
  //Check to see if connection was successful
  if (!SQLITE_OK) {
    printf("Connection established.\n");
  }
  sqlite_close(db);
}


//Taken from www.sqlite.org/quickstart.html, as it is needed for sqlite_exec().
static int Database::callback(void *NotUsed, int argc, char **argv, char **azColName) {
  int i;
  for (i = 0; i<argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

Database::getUser(string username) {
  sqlite3 *db;

  sqlite3_open(db, );

  
  
  sqlite3_close(db);

  return username;
}

Database::getItem(int itemID) {
  sqlite3 *db;

  //This converts itemID into a string to concatenate onto the sql statement.
  string itemUID;
  ostringstream convert;
  convert << itemID;
  itemUID = convert.str();
  //********************//

  int sqlCmdNum;
  tuple<int, float, string, string> itemInfo;
  string sql;

  sqlite3_open(db, &db);
  
  //Iterate through each column of the table and place the data in a vector to return to the Item class.
  for (int i = 0; i < 4; i++) {
    sqlCmdNum = i;
    switch sqlCmdNum{
    case 0:
      sql = "SELECT stockQuantity FROM item WHERE item.itemID = " + itemUID;
      get<i>(itemInfo) = sqlite3_exec(db, sql, callback, 0, "");
      break;
    case 1:
      sql = "SELECT cost FROM item WHERE item.itemID = " + itemUID;
      get<i>(itemInfo) = sqlite3_exec(db, sql, callback, 0, "");
      break;
    case 2:
      sql = "SELECT itemName FROM item WHERE item.itemID = " + itemUID;
      get<i>(itemInfo) = sqlite3_exec(db, sql, callback, 0, "");
      break;
    case 3:
      sql = "SELECT category FROM item WHERE item.itemID = " + itemUID;
      get<i>(itemInfo) = sqlite3_exec(db, sql, callback, 0, "");
      break;

    default:
      sql_close(db);
      break;
    }
  }

  sqlite3_close(db);

  return itemInfo;
}

Database::getCart(string username) {
  sqlite3 *db;

  sqlite3_open(db);

  while (!SQLITE_OK) {
    //add stuff here
  }

  sqlite3_close(db);

  return //array of cart nums
}

Database::getInventory() {
  sqlite3 *db;

  sqlite3_open();

  sqlite3_close(db);
}

Database::updateUser(string username) {
  sqlite3 *db;

  sqlite3_open();

  sqlite3_close(db);
}

Database::updateItem(string itemName) {
  sqlite3 *db;

  sqlite3_open();

  sqlite3_close(db);
}

Database::updateItem(int itemID) {
  sqlite3 *db;

  sqlite3_open();

  sqlite3_close(db);
}

Database::updateInventory() {
  sqlite3 *db;

  sqlite3_open();

  sqlite3_close(db);
}