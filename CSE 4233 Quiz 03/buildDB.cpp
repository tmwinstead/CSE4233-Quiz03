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
    
    //Creates empty tables for the database
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

    //Populate the DB with default values
    statement = "INSERT INTO Item VALUES ('0001', 'Finish All in 1 Powerball Mega Pack', 10, 13.56, 'Household Items');\
    INSERT INTO Item VALUES('0002', 'Kleenex Facial Tissue', 10, 14.98, 'Household Items');\
    INSERT INTO Item VALUES('0003', 'Rayovac AA Batteries 20ct', 10, 12.49, 'Household Items');\
    INSERT INTO Item VALUES('0004', 'Lysol Disinfecting Wipes 3-pack', 10, 9.97, 'Household Items');\
    INSERT INTO Item VALUES('0005', 'Bounty Jumbo Paper Towels 12-pack', 10, 18.99, 'Household Items');\
    INSERT INTO Item VALUES('0006', 'The Hunger Games', 10, 12.97, 'Books');\
    INSERT INTO Item VALUES('0007', 'Harry Potter and the Deathly Hallows', 10, 11.11, 'Books');\
    INSERT INTO Item VALUES('0008', 'To Kill a Mockingbird', 10, 8.50, 'Books');\
    INSERT INTO Item VALUES('0009', 'Pride and Prejudice', 10, 7.99, 'Books');\
    INSERT INTO Item VALUES('0010', 'Animal Farm', 10, 5.95, 'Books');\
    INSERT INTO Item VALUES('0011', 'Play-Doh 24-Pack of Colors', 10, 14.99, 'Toys');\
    INSERT INTO Item VALUES('0012', 'Cards Against Humanity', 10, 25.00, 'Toys');\
    INSERT INTO Item VALUES('0013', 'Little Tikes 3ft Trampoline', 10, 37.17, 'Toys');\
    INSERT INTO Item VALUES('0014', 'Uno Card Game', 10, 4.19, 'Toys');\
    INSERT INTO Item VALUES('0015', 'LEGO Mega Builder Set', 10, 27.99, 'Toys');\
    INSERT INTO Item VALUES('0016', 'Amazon Fire TV Stick', 10, 39.99, 'Small Electronics');\
    INSERT INTO Item VALUES('0017', 'Fujifilm INSTAX Mini 8 Instant Camera', 10, 50.99, 'Small Electronics');\
    INSERT INTO Item VALUES('0018', 'Ultra Slim 4-Port USB 3.0 Data Hub', 10, 9.99, 'Small Electronics');\
    INSERT INTO Item VALUES('0019', 'High-Speed HDMI Cable', 10, 5.49, 'Small Electronics');\
    INSERT INTO Item VALUES('0020', 'SanDisk 64GB microSDXC Card', 10, 19.35, 'Small Electronics');\
    INSERT INTO Inventory VALUES('0001', 10);\
    INSERT INTO Inventory VALUES('0002', 10);\
    INSERT INTO Inventory VALUES('0003', 10);\
    INSERT INTO Inventory VALUES('0004', 10);\
    INSERT INTO Inventory VALUES('0005', 10);\
    INSERT INTO Inventory VALUES('0006', 10);\
    INSERT INTO Inventory VALUES('0007', 10);\
    INSERT INTO Inventory VALUES('0008', 10);\
    INSERT INTO Inventory VALUES('0009', 10);\
    INSERT INTO Inventory VALUES('0010', 10);\
    INSERT INTO Inventory VALUES('0011', 10);\
    INSERT INTO Inventory VALUES('0012', 10);\
    INSERT INTO Inventory VALUES('0013', 10);\
    INSERT INTO Inventory VALUES('0014', 10);\
    INSERT INTO Inventory VALUES('0015', 10);\
    INSERT INTO Inventory VALUES('0016', 10);\
    INSERT INTO Inventory VALUES('0017', 10);\
    INSERT INTO Inventory VALUES('0018', 10);\
    INSERT INTO Inventory VALUES('0019', 10);\
    INSERT INTO Inventory VALUES('0020', 10);\
    INSERT INTO Users VALUES('defaultUser'); ";

    strcpy(cStatement, statement.c_str());
    sql = cStatement;
    sqlite3_exec(db, sql, callback, 0, errmsg);

    sqlite3_close(db);
}

int main() {
    buildDB();
    return 0;
}