//
//  quiz3.cpp
//  CSE 4233 Quiz 03
//
//  Created by Jimmy Bailey on 9/12/16.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "item.cpp"
#include "cart.cpp"
#include "checkout.cpp"
#include "user.cpp"
#include "database.cpp"

using namespace std;

bool mainMenu(Cart cart, User user);
void cartMenu(int page, Cart cart, User user);
void historyMenu(int page, Cart cart, User user);
vector<int> getOldCarts(string username, int start, Cart cart, User user);
void detailHistoryMenu(int cartID, Cart cart, User user);

vector<int> getOldCarts(string username, int start, Cart cart, User user){
    vector<int> fullHistory = user.getHistory();
    vector<int> history;
    for (int i = start; i<fullHistory.size() || i+start<start+7 ; i++){
        history.push_back(fullHistory.at(i));
    }
    return history;
}

void inventoryMenu(string name, int page, Cart cart, User user){
    
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
    
    Database db;
    vector<Item> items = db.categoryLookup(name);
    
    for (int i=0; i<7 || i+page*7<items.size(); i++){
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
            inventoryMenu(name, page+1, cart, user);
            break;
            
        case 2:
            cartMenu(0, cart, user);
            break;
            
        default:
            if (choice > items.size()+3){
                cout << "Not a valid choice. Try again." << endl;
                cout << "" << endl;
                cartMenu(page, cart, user);
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

void cartMenu(int page, Cart cart, User user){
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
            cartMenu(page+1, cart, user);
            break;
            
        case 2:
            cart.goToCheckout();
            break;
            
        default:
            if (choice+page*7 > items.size()){
                cout << "Not a valid choice. Try again." << endl;
                cout << "" << endl;
                cartMenu(page, cart, user);
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
            cartMenu(page, cart, user);
            break;
            
    }
}

void historyMenu(int page, Cart cart, User user){
    vector<int> historyCarts = getOldCarts(user.username, page*8, cart, user);
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
            cartMenu(page+1, cart, user);
            break;
            
        default:
            if (choice > historyCarts.size()+2){
                cout << "Not a valid choice. Try again." << endl;
                cout << "" << endl;
                historyMenu(page, cart, user);
                break;
            }
            cout << "" << endl;
            detailHistoryMenu(historyCarts.at(choice-2), cart, user);
            historyMenu(page, cart, user);
            break;
    }
}

void detailHistoryMenu(int cartID, Cart cart, User user){
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

bool mainMenu(Cart cart, User user){
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
            historyMenu(0, cart, user);
            break;
            
        case 2:
            cartMenu(0, cart, user);
            break;
            
        case 3:
            keepGoing = false;
            break;
            
        case 4:
            inventoryMenu("Household Items", 0, cart, user);
            break;
            
        case 5:
            inventoryMenu("Books", 0, cart, user);
            break;
            
        case 6:
            inventoryMenu("Toys", 0, cart, user);
            break;
            
        case 7:
            inventoryMenu("Small Electronics", 0, cart, user);
            break;
    }
    if (keepGoing)
        mainMenu(cart, user);
    
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
    
    string username = argv[1];
    User user =  User();
    user.login(username);

    Cart cart =  Cart(user);
    
    bool keepGoing = true;
    while(keepGoing){
        keepGoing = mainMenu(cart, user);
    }
    
    return 0;
}