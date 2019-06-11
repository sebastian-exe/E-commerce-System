//
//  customer.cpp
//  Ecommerce System Phase 4
//
//  Created by Sebastian Moreno on 5/6/19.
//  Copyright © 2019 Sebastian Moreno. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "inventory.h"
#include "LinkedList.h"
#include "customer.h"
using namespace std;
//lets just work on getting the shopping cart ot display currently 
void customer::displayCart(inventory * shopping_cart, int totProd){
    inventory* current = shopping_cart->next;
    cout << "Item Number " << setw(19) <<  "Item Name" << setw(15) << "Qty" << setw(19) << "Unit Cost" << setw(15) << "Total" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    //Loop through the list until we find the end
    for(int i = 0; i < totProd; i ++) {
        cout <<  fixed << setprecision(0);
        cout << "Item Number " << current->fiveDigitCode  << setw(18) << " Product Name " << left << setw(3) << current->itemNumber << right << setw(8) << current->qty << fixed << setprecision(2) << setw(15) << current->cost << setw(20) << current->totalCost << endl;
        totalCostCart += current->totalCost;
        current = current->next;
    }
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << setw(30) << fixed << setprecision(2) << "Total: $"  << totalCostCart << endl;
    
}
//delete an item from the shopping cart linked list
//test to see if the five digit code entered by the user is valid
void customer::deleteFromCart(inventory * shopping_cart){
    int count = 0;
    struct inventory* current = shopping_cart;
    struct inventory* prev = shopping_cart;
    
    if (itemNumber < 0 || itemNumber > length(shopping_cart))
    {
        cout << "Invalid index!" << endl;
        return;
    }
    else if (itemNumber == 0)
    {
        current = current->next;
        delete prev;
        shopping_cart = current;
        return;
    }
    else
    {
        while (current != NULL)
        {
            if (count == itemNumber)
            {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
            count++;
        }
    }
    
}

//function to find the length
int customer::length(inventory* shopping_cart) {
    //Create a temporary node to keep track of the current node
    inventory* current = shopping_cart;
    int count = 0;
    //Loop through the list until we find the end
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

string customer::invoiceFile(string lastName){
    invoiceFileName =  lastName + ".txt";
    
    return invoiceFileName;
    }
