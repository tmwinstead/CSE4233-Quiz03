//
//  main.cpp
//  CSE 4233 Quiz 03
//
//  Created by Jimmy Bailey on 9/12/16.
//  Copyright © 2016 Tyler Winstead. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "item.h"
#include "admin.h"
#include "cart.h"
#include "checkout.h"
#include "inventory.h"
#include "user.h"
#include "database.h"


using namespace std;

bool mainMenu();
void cartMenu(int page);
void historyMenu(int page);
vector<int> getHistory(string username, int start);

User user;
Cart cart;

void inventoryMenu(string name, int page){
    cout << "" << endl;
    cout << name << endl;
    cout << "Page " << page+1 << endl;
    cout << "Type in the number then the quantity to add to your cart.";
    cout << "  0. Back" << endl;
    cout << "  1. Next Page" << endl;
    
    int numItems = cart.numItems;
    float totalPrice = cart.calculatedTotal;
    cout << "  2. View Cart (" << numItems << ") $";
    cout << fixed << setprecision(2) << totalPrice << endl;
    
    vector<Item> items = getItems(name, page*7);
    
    for (int i=0; i<7 || i<items.size(); i++){
        cout << "  " << i+3 << ". " << items.at(i).itemName << " ($" << items.at(i).cost << ")" << endl;
    };
    
    bool loop = true;
    int choice = 0;
    while (loop){
        cout << "Input choice: ";
        cin >> choice;
        if (int(choice) == choice)
            loop = false;
    };
    switch (choice) {
        case 0:
            break;
            
        case 1:
            inventoryMenu(name, page+1);
            break;
            
        case 2:
            cartMenu(0);
            break;
            
        default:
            bool thisLoop = true;
            int quantity = 0;
            while (thisLoop){
                cout << "Input qunatity: ";
                cin >> quantity;
                if (int(quantity) == quantity)
                    thisLoop = false;
            };
            cart.addToCart(items.at(choice-3), quantity);
            break;
    }

}

void cartMenu(int page){
    vector<Item> items = cart.itemList;
    
    cout << "" << endl;
    cout << "Cart #" << cart.uniqueID <<endl;
    cout << "Number of items: " << items.size();
    cout << "Total cost: $" << fixed << setprecision(2) << cart.calculatedTotal << endl;
    cout << "Page " << page+1 << endl;
    cout << "Type in the number then you can remove from or add more to add to your cart.";
    cout << "  0. Back" << endl;
    cout << "  1. Next Page" << endl;
    
    cout << "  2. Checkout" << endl;
    
    // SQL to get each item and price
    
    for (int i=0; i<7 || i<items.size()-page*7; i++){
        cout << "  " << i+3 << ". " << items.at(i+page*7).itemName << " (" << cart.itemQuantities.at(i+page*7) << ") ($" << items.at(i+page*7).cost*cart.itemQuantities.at(i+page*7) << ")" <<endl;
    };
    
    bool loop = true;
    int choice = 0;
    while (loop){
        cout << "Input choice: ";
        cin >> choice;
        if (int(choice) == choice)
            loop = false;
    };
    switch (choice) {
        case 0:
            break;
            
        case 1:
            cartMenu(page+1);
            break;
            
        case 2:
            cart.goToCheckout();
            break;
            
        default:
            bool thisLoop = true;
            bool loop2 = true;
            int quantity = 0;
            int thisChoice;
            cout << "" << endl;
            cout << "1. Add quantity" << endl;
            cout << "2. Remove quantity" << endl;
            while (thisLoop){
                cout << "Input choice: ";
                cin >> thisChoice;
                if (int(thisChoice) == thisChoice){
                    thisLoop = false;
                    while(loop2){
                        cout << "Input quantity: ";
                        cin >> quantity;
                    }
                }
            };
            if (thisChoice==1)
                cart.addToCart(items.at(choice-3), quantity);
            else if(thisChoice==2)
                cart.removeFromCart(items.at(choice-3), quantity);
            break;
    }
}


void historyMenu(int page){
    vector<int> historyCarts = getHistory(user.username, page*8)
    cout << "" << endl;
    cout << "Cart History" << endl;
    cout << "Page " << page+1 << endl;
    cout << "Type in the number then you can remove from or add more to add to your cart.";
    cout << "  0. Back" << endl;
    cout << "  1. Next Page" << endl;
    
    cout << "  2. Checkout" << endl;
    
    // SQL to get each item and price
    
    for (int i=0; i<8 || i<items.size()-page*8; i++){
        cout << "  " << i+3 << ". Cart #" << historyCarts.at(i+page*8) << endl;
    };
    
    bool loop = true;
    int choice = 0;
    while (loop){
        cout << "Input choice: ";
        cin >> choice;
        if (int(choice) == choice)
            loop = false;
    };
    switch (choice) {
        case 0:
            break;
            
        case 1:
            cartMenu(page+1);
            break;
            
        case 2:
            cart.goToCheckout();
            break;
            
        default:
            bool thisLoop = true;
            bool loop2 = true;
            int quantity = 0;
            int thisChoice;
            cout << "" << endl;
            cout << "1. Add quantity" << endl;
            cout << "2. Remove quantity" << endl;
            while (thisLoop){
                cout << "Input choice: ";
                cin >> thisChoice;
                if (int(thisChoice) == thisChoice){
                    thisLoop = false;
                    while(loop2){
                        cout << "Input quantity: ";
                        cin >> quantity;
                    }
                }
            };
            if (thisChoice==1)
                cart.addToCart(items.at(choice-3), quantity);
            else if(thisChoice==2)
                cart.removeFromCart(items.at(choice-3), quantity);
            break;
    }
}

vector<int> getHistory(string username, int start){
    vector<int> history;
    
    return history;
}

bool mainMenu(){
    bool keepGoing = true;
    cout << "" << endl;
    cout << "Main Menu" << endl;
    cout << "    1. History" << endl;
    cout << "    2. View Cart" << endl;
    cout << "    3. Quit" << endl;
    cout << "  Categories:" << endl;
    cout << "    4. Household Items" << endl;
    cout << "    5. Books" << endl;
    cout << "    6. Toys" << endl;
    cout << "    7. Small Electronics" << endl;
    bool loop = true;
    int choice = 0;
    while (loop){
        cout << "Input choice: ";
        cin >> choice;
        if (int(choice) == choice)
            loop = false;
    };
    switch (choice) {
        case 1:
            historyMenu(0);
            break;
            
        case 2:
            cartMenu(0);
            break;
            
        case 3:
            keepGoing = false;
            break;
            
        case 4:
            inventoryMenu("Household Items", 0);
            break;
            
        case 5:
            inventoryMenu("Books", 0);
            break;
            
        case 6:
            inventoryMenu("Toys", 0);
            break;
            
        case 7:
            inventoryMenu("Small Electronics", 0);
            break;
    }
    return keepGoing;
}

int main(int argc, const char * argv[])
{
    cout << endl;
    if (argc != 2)
    {
        cout << "usage " << argv[0] << " username\n" << endl;
        return 0;
    }
    
    // SQL get the username here, check if it is valid, then check to see if cart is active
    /*
     sqlLine = "SELECT"
    returnLine = readDatabase(sqlLine)
    writeDatabase(sqLine)
     */
    
    user = User(argv[1]);
    cart = Cart(user);
    
    bool keepGoing = true;
    while(keepGoing){
        keepGoing = mainMenu();
    }
    
    
}
