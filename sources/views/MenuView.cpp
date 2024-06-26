//
// Created by HP on 27/05/2024.
//
#include <iostream>
#include <iomanip>
#include "MenuView.h"
#include "Utils.h"
#include "View.h"

using namespace std;

Menu MenuView::getMenu(const string& name) {
    string Name;
    string Description;
    float SellingPrice;
    float SupplierPrice;
    int AmountInStock;
    string CategoryFood;
    bool isAvailable;

    Name = Utils::getString("Name");
    Description = Utils::getString("Description");
    CategoryFood = Utils::getString("CategoryFood");
    AmountInStock = Utils::getNumber("AmountInStock");
    SellingPrice = Utils::getFloat("SellingPrice");
    SupplierPrice = Utils::getFloat("SupplierPrice");
    isAvailable = Utils::getBool("Is the product available? (1 - yes, 0 - no)? ");

    Menu menu(Name, Description, CategoryFood, AmountInStock, SupplierPrice, SellingPrice, isAvailable);
    return menu; // Corrected return statement
}

void MenuView::printMenuContainerClient(list<Menu>& menu, const string& listTitle) {
    cout << listTitle << endl;
    cout << setw(PRICESPACING) << "SellingPrice";
    cout << " Name";

    cout << endl;
    for (auto it = menu.begin(); it != menu.end(); ++it) {
        cout << setw(PRICESPACING) << it->getSellingPrice();
        cout << " " << it->getName() << endl;
    }
}

void MenuView::printMenuClient(Menu& menu) {
    cout << "Name          : " << menu.getName() << endl;
    cout << "Description   : " << menu.getDescription() << endl;
    cout << "Price         : " << menu.getSellingPrice() << endl;
    cout << "AmountInStock : " << menu.getAmountInStock() << endl;
    cout << "CategoryFood  : " << menu.getCategoryFood() << endl;
}

void MenuView::printMenuContainerDono(list<Menu>& menu, const string& listTitle) {
    cout << listTitle << endl;
    cout << setw(PRICESPACING) << "Price";
    cout << setw(QUANTITYSPACING) << "Qty";
    cout << setw(PRICESPACING + 7) << "Supplier Price";
    cout << setw(NAMESPACING) << "Availability";
    cout << " Name";

    cout << endl;
    for (auto it = menu.begin(); it != menu.end(); ++it) {
        cout << setw(NAMESPACING) << it->getName();
        cout << setw(PRICESPACING) << it->getSellingPrice();
        cout << setw(PRICESPACING + 7) << it->getSupplierPrice();
        cout << setw(QUANTITYSPACING) << it->getAmountInStock();
        cout << setw(NAMESPACING) << ((it->getAvailable()) ? "Available" : "Unavailable");
        cout << " " << it->getName() << endl;
    }
}

string MenuView::getName() {
    string name;
    bool flag;
    do {
        name = Utils::getString("Insert Menu Name");
        flag = false;
        if (!Utils::stringAmountInStock(name)) { // Assuming this is a utility function for validation
            flag = true;
            MenuUnavailable();
        }
    } while (flag);
    return name;
}

void MenuView::MenuUnavailable() {
    cout << "Menu is not available" << endl;
}
