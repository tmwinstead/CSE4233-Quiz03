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
vector<int> getOldCarts(string username, int start);
void detailHistoryMenu(int cartID);

User user;
Cart cart;

vector<Item> getItems(string type, int start){
    vector<int> itemIDs;
    // SQL code to get a list of max of 7 itemIDs WHERE type is type starting after the n-th instance
    vector<Item> items;
    for (int i = 0; i<itemIDs.size(); i++){
        Item* newItem = new Item(itemIDs.at(i));
        items.push_back(*newItem);
    }
    return items;
}

vector<int> getOldCarts(string username, int start){
    vector<int> fullHistory = user.getHistory();
    vector<int> history;
    for (int i = start; i<fullHistory.size() || i+start<start+7 ; i++){
        history.push_back(fullHistory.at(i));
    }
    return history;
}

void inventoryMenu(string name, int page){
    
    cout << "" << endl;
    cout << name << endl;
    cout << "Page " << page+1 << endl;
    cout << "Type in the number then the quantity to add to your cart.";
    cout << "  0. Back" << endl;
    cout << "  1. Next Page" << endl;
    
    int numItems = cart.numItems;
    float totalPrice = cart.getTotal();
    cout << "  2. View Cart (" << numItems << ") $";
    cout << fixed << setprecision(2) << totalPrice << endl;
    
    vector<Item> items = getItems(name, page*7);
    
    for (int i=0; i<7 || i<items.size(); i++){
        cout << "  " << i+3 << ". " << items.at(i).itemName << " ($" << items.at(i).cost << ")" << endl;
    };
    
    bool loop = true;
    int choice;
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
            if (choice > items.size()+3){
                cout << "Not a valid choice. Try again." << endl;
                cout << "" << endl;
                cartMenu(page);
                break;
            }
            bool thisLoop = true;
            int quantity = 0;
            while (thisLoop){
                cout << "Input qunatity: ";
                cin >> quantity;
                if (int(quantity) == quantity)
                    thisLoop = false;
            };
            cart.addToCart(items.at(choice-3).itemID, quantity);
            break;
    }

}

void cartMenu(int page){
    vector<Item> items = cart.itemList;
    cout << "" << endl;
    cout << "Cart #" << cart.uniqueID <<endl;
    cout << "Number of items: " << items.size();
    cout << "Total cost: $" << fixed << setprecision(2) << cart.getTotal() << endl;
    cout << "Page " << page+1 << endl;
    cout << "Type in the number then you can remove from or add more to add to your cart.";
    cout << "  0. Back" << endl;
    cout << "  1. Next Page" << endl;
    
    cout << "  2. Checkout" << endl;
    
    for (int i=0; i<7 || i<items.size()-page*7; i++){
        cout << "  " << i+3 << ". " << items.at(i+page*7).itemName;
        cout << " (" << cart.itemQuantities.at(i+page*7) << ") @ $";
        cout << fixed << setprecision(2) << items.at(i+page*7).cost << " each = ";
        cout << fixed << setprecision(2) << items.at(i+page*7).cost*cart.itemQuantities.at(i+page*7) << endl;
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
            if (choice+page*7 > items.size()){
                cout << "Not a valid choice. Try again." << endl;
                cout << "" << endl;
                cartMenu(page);
                break;
            }
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
                        if ((thisChoice == 2) && (cart.itemQuantities.at(choice-3+page*7) < quantity)){
                            cout << "Cannot remove more than " << cart.itemQuantities.at(choice-3+page*7) << " items. Try again." << endl;
                        }
                        if (int(quantity)== quantity)
                            loop2 = false;
                    }
                }
            };
            
            if (thisChoice==1)
                cart.addToCart(items.at(choice-3+page*7).itemID, quantity);
            else if(thisChoice==2)
                cart.removeFromCart(items.at(choice-3+page*7), quantity);
            cout << endl;
            cout << endl;
            cartMenu(page);
            break;
            
    }
}

void historyMenu(int page){
    vector<int> historyCarts = getOldCarts(user.username, page*8);
    cout << "" << endl;
    cout << "Cart History" << endl;
    cout << "Page " << page+1 << endl;
    cout << "Type in the number then you can remove from or add more to add to your cart.";
    cout << "  0. Back" << endl;
    cout << "  1. Next Page" << endl;
    
    for (int i=0; i<8 || i<historyCarts.size(); i++){
        cout << "  " << i+2 << ". Cart #" << historyCarts.at(i) << endl;
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
            
        default:
            if (choice > historyCarts.size()+2){
                cout << "Not a valid choice. Try again." << endl;
                cout << "" << endl;
                historyMenu(page);
                break;
            }
            cout << "" << endl;
            detailHistoryMenu(historyCarts.at(choice-2));
            historyMenu(page);
            break;
    }
}

void detailHistoryMenu(int cartID){
    Cart historyCart = Cart(user, cartID);
    cout << "Cart Hisotory" << endl;
    cout << "Cart #" << cartID << endl;
    cout << "  Number of items: " << historyCart.numItems << endl;
    cout << "  Total cost: $" << fixed << setprecision(2) << historyCart.getTotal() << endl;
    for (int i=0; i<historyCart.itemList.size(); i++){
        cout << "    " << historyCart.itemList.at(i).itemName;
        cout << " (" << historyCart.itemQuantities.at(i) << ") @ $";
        cout << fixed << setprecision(2) << historyCart.itemList.at(i).cost << " each = ";
        cout << fixed << setprecision(2) << historyCart.itemList.at(i).cost*historyCart.itemQuantities.at(i) << endl;
    }
    
    int nothing;
    cout << "Press Enter to return to cart history. ";
    cin >> nothing;
    cout << endl;
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
    int choice;
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
    
    user = User(argv[1]);
    cart = Cart(user);
    
    bool keepGoing = true;
    while(keepGoing){
        keepGoing = mainMenu();
    }
    return 0;
}
