//
//  admin.cpp
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
#include "admin.h"

using namespace std;
//adds the admin item to the beginning of the linked list for the invtory read in from the CSV
void admin::Push(inventory*& head_item) {
    inventory* newNode = new inventory;            //Create a new node to add to the front of the list
    
    //Set the members of the new node Data
    newNode->fiveDigitCode = fiveDigitCode;
    newNode->itemNumber = itemNumber;
    newNode->cost = cost;
    newNode->qty = qty;                      //Store the data inside the new node
    newNode->next = head_item->next;                        //Set the new node next equal to the orginal head
    
    head_item = newNode;                                //Set the orginal head to point to the new node.
    
}
//delete a product
void admin::deleteProduct(inventory * head_item){
    
    int count = 0;
    struct inventory* current = head_item;
    struct inventory* prev = head_item;
    
    if (itemNumber < 0 || itemNumber > length(head_item))
    {
        cout << "Invalid index!" << endl;
        return;
    }
    else if (itemNumber == 0)
    {
        current = current->next;
        delete prev;
        head_item = current;
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
int admin::length(inventory* head_item) {
    //Create a temporary node to keep track of the current node
    inventory* current = head_item;
    int count = 0;
    //Loop through the list until we find the end
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

//function to update the quantity for the admin
inventory* admin::updateQty(inventory* head_item){
    inventory* current = head_item->next;
    
    while (current != NULL)
    {
        if(current->fiveDigitCode == fiveDigitCode)
        {
            current->qty = qty;
            break;
        }
        
        current = current->next;
        
    }
    return current;
}

//function to update the quantity for the admin
inventory * admin::updateCost(inventory* head_item){
    inventory* current = head_item->next;
    
    while (current != NULL)
    {
        if(current->fiveDigitCode == fiveDigitCode)
        {
            current->cost = cost;
            break;
        }
        
        current = current->next;
        
    }
    return current;
}

//validate input for the username and password
//validate for username
bool admin::validateUser(string username){
    if(username_ == username){
        return true;
    }
    else{
        return false;
    }
}

bool admin::validatePass(string password){
    if(password_ == password){
        return true;
    }
    else{
        return false;
    }
}
