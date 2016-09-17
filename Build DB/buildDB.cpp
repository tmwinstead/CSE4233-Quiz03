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
    string statement2;
    string statement3;
    string statement4;
    string statement5;
    string statement6;
    string statement7;
    string statement8;
    
    const char *sql;
    const char *sql2;
    const char *sql3;
    const char *sql4;
    const char *sql5;
    const char *sql6;
    const char *sql7;
    const char *sql8;
    
    char *cStatement = (char *) malloc(sizeof(char)*1000);
    char *cStatement2 = (char *) malloc(sizeof(char)*1000);
    char *cStatement3 = (char *) malloc(sizeof(char)*1000);
    char *cStatement4 = (char *) malloc(sizeof(char)*1000);
    char *cStatement5 = (char *) malloc(sizeof(char)*1000);
    char *cStatement6 = (char *) malloc(sizeof(char)*1000);
    char *cStatement7 = (char *) malloc(sizeof(char)*1000);
    char *cStatement8 = (char *) malloc(sizeof(char)*1000);
    
    char **errmsg;
    
    sqlite3 *db;
    sqlite3_open("quiz3.db", &db);
    
    //Creates empty tables for the database
    statement = "CREATE TABLE Users(username varchar(50) PRIMARY KEY NOT NULL);";
    strcpy(cStatement, statement.c_str());
    sql = cStatement;
    sqlite3_exec(db, sql, callback, 0, errmsg);
    
    statement2 = "CREATE TABLE Item(itemID varchar(50) PRIMARY KEY NOT NULL, itemName varchar(100), cost float, category varchar(50));";
    strcpy(cStatement2, statement2.c_str());
    sql2 = cStatement2;
    sqlite3_exec(db, sql2, callback, 0, errmsg);
    
    statement3 = "CREATE TABLE Inventory(itemID int PRIMARY KEY NOT NULL, quantity int);";
    strcpy(cStatement3, statement3.c_str());
    sql3 = cStatement3;
    sqlite3_exec(db, sql3, callback, 0, errmsg);
    
    statement4 = "CREATE TABLE UserCart(uniqueID int PRIMARY KEY NOT NULL, username varchar(50), isPurchased boolean);";
    strcpy(cStatement4, statement4.c_str());
    sql4 = cStatement4;
    sqlite3_exec(db, sql4, callback, 0, errmsg);
    
    statement5 = "CREATE TABLE CartItem(uniqueID int, itemNum int, quantity int, price float, itemID int, CONSTRAINT PK_D PRIMARY KEY (uniqueID, itemNum));";
    strcpy(cStatement5, statement5.c_str());
    sql5 = cStatement5;
    sqlite3_exec(db, sql5, callback, 0, errmsg);
    
    //Populate the DB with default values
    statement6 = "INSERT INTO Item (itemID, itemName, cost, category) VALUES ('0001', 'Finish All in 1 Powerball Mega Pack', 13.56, 'Household Items');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0002', 'Kleenex Facial Tissue', 14.98, 'Household Items');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0003', 'Rayovac AA Batteries 20ct', 12.49, 'Household Items');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0004', 'Lysol Disinfecting Wipes 3-pack', 9.97, 'Household Items');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0005', 'Bounty Jumbo Paper Towels 12-pack', 18.99, 'Household Items');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0006', 'The Hunger Games', 12.97, 'Books');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0007', 'Harry Potter and the Deathly Hallows', 11.11, 'Books');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0008', 'To Kill a Mockingbird', 8.50, 'Books');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0009', 'Pride and Prejudice', 7.99, 'Books');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0010', 'Animal Farm', 5.95, 'Books');";
    strcpy(cStatement6, statement6.c_str());
    sql6 = cStatement6;
    sqlite3_exec(db, sql6, callback, 0, errmsg);
    
    statement7 = "INSERT INTO Item (itemID, itemName, cost, category) VALUES('0011', 'Play-Doh 24-Pack of Colors', 14.99, 'Toys');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0012', 'Cards Against Humanity', 25.00, 'Toys');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0013', 'Little Tikes 3ft Trampoline', 37.17, 'Toys');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0014', 'Uno Card Game', 4.19, 'Toys');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0015', 'LEGO Mega Builder Set', 27.99, 'Toys');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0016', 'Amazon Fire TV Stick', 39.99, 'Small Electronics');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0017', 'Fujifilm INSTAX Mini 8 Instant Camera', 50.99, 'Small Electronics');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0018', 'Ultra Slim 4-Port USB 3.0 Data Hub', 9.99, 'Small Electronics');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0019', 'High-Speed HDMI Cable', 5.49, 'Small Electronics');\
    INSERT INTO Item (itemID, itemName, cost, category) VALUES('0020', 'SanDisk 64GB microSDXC Card', 19.35, 'Small Electronics');";
    
    strcpy(cStatement7, statement7.c_str());
    sql7 = cStatement7;
    sqlite3_exec(db, sql7, callback, 0, errmsg);
    
    statement8 = "INSERT INTO Inventory (itemID, quantity) VALUES('0001', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0002', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0003', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0004', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0005', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0006', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0007', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0008', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0009', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0010', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0011', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0012', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0013', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0014', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0015', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0016', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0017', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0018', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0019', 10);\
    INSERT INTO Inventory (itemID, quantity) VALUES('0020', 10);\
    INSERT INTO Users (username) VALUES('defaultUser');";
    
    strcpy(cStatement8, statement8.c_str());
    sql8 = cStatement8;
    sqlite3_exec(db, sql8, callback, 0, errmsg);
    
    sqlite3_close(db);
}

int main() {
    buildDB();
    return 0;
}