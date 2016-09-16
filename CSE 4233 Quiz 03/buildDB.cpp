//
//  buildDB.cpp
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/16/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

//  Builds DB
void buildDB() {
    
    string statement;
    const char *sql;
    char *cStatement = (char *) malloc(sizeof(char)*200);
    char **errmsg;
    
    sqlite3 *db;
    sqlite3_open("quiz3.db", &db);
    
    statement = "CREATE TABLE Users(username varchar(50) PRIMARY KEY NOT NULL);";
    strcpy(cStatement, statement.c_str());
    sql = cStatement;
    sqlite3_exec(db, sql, callback, 0, errmsg);
    
    statement = "CREATE TABLE Item(itemID varchar(50) PRIMARY KEY NOT NULL, itemName varchar(100), stockQuantity int, cost float, category varchar(50));";
    strcpy(cStatement, statement.c_str());
    sql = cStatement;
    sqlite3_exec(db, sql, callback, 0, errmsg);
    
    statement = "CREATE TABLE Inventory(quantity int, itemID int);";
    strcpy(cStatement, statement.c_str());
    sql = cStatement;
    sqlite3_exec(db, sql, callback, 0, errmsg);
    
    statement = "CREATE TABLE UserCart(isPurchased boolean, uniqueID int, username varchar(50));";
    strcpy(cStatement, statement.c_str());
    sql = cStatement;
    sqlite3_exec(db, sql, callback, 0, errmsg);
    
    statement = "CREATE TABLE CartItem(uniqueID int PRIMARY KEY NOT NULL, itemNum int, quantity int, price float, itemID int);";
    strcpy(cStatement, statement.c_str());
    sql = cStatement;
    sqlite3_exec(db, sql, callback, 0, errmsg);
    
    sqlite3_close(db);
}

int main() {
    buildDB();
    return 0;
}