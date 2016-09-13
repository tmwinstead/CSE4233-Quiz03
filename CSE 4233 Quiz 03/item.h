//
//  item.h
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/12/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    int itemID;
    int stockQuantity;
    int cost;
    string itemName;
    string category;
    
    Item();
    ~Item();
    bool inInventory();
};

#endif