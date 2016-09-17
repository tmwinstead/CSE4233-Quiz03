//
//  item.h
//  CSE 4233 Quiz 03
//
//  Created by Tyler Winstead on 09/12/16.
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
    float cost;
    string itemName;
    string category;
    
    Item();
    Item(int itemNum);
    ~Item();
    bool inInventory();
};

#endif