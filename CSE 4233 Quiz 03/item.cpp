//
//  item.cpp
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/12/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#include "item.h"

//  Creates a blank item object
Item::Item() {
    itemID = 0;
    stockQuantity = 0;
    cost = 0.0;
    itemName = "";
    category = "";
}

//  Creates an item object based on itemID
Item::Item(int itemNum) {
    itemID = itemNum;
    //  SQL to lookup item details based on itemID
    //  --> stockQuantity
    //  --> cost
    //  --> itemName
    //  --> category
    //  Database db = new Database;
    //  Item item = db.getItem(itemNum);
    //  stockQuantity = item.stockQuantity;
    //  itemName = item.itemName;
    //  category = item.category;
}

//  Resets an item object's variables
Item::~Item() {
    itemID = 0;
    stockQuantity = 0;
    cost = 0.0;
    itemName = "";
    category = "";
}

//  Checks item availability in inventory
bool Item::inInventory() {
    return stockQuantity > 0;
}