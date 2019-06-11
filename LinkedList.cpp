//
//  LinkedList.cpp
//  Ecommerce System Phase 4
//
//  Created by Sebastian Moreno on 5/6/19.
//  Copyright © 2019 Sebastian Moreno. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "inventory.h"
#include "LinkedList.h"
using namespace std;
LinkedList::LinkedList(){
    
}

LinkedList::LinkedList(inventory * head_item){
        head = head_item;
    }
    

    
    void LinkedList::addNode(inventory * searchPtr, inventory * shopping_cart,int quantity){
        inventory * customerCart = shopping_cart;
        inventory * current = nullptr;
        inventory * newNode = new inventory;
        
        //Set the members of the new node Data
        newNode->fiveDigitCode = searchPtr->fiveDigitCode;
        newNode->itemNumber = searchPtr->itemNumber;
        newNode->cost = searchPtr->cost;
        newNode->qty = quantity;
        //total cost is the amount the user entered plus the cost of the item
        newNode->totalCost = quantity * searchPtr->cost;
        newNode->next = NULL;
        
        //Check to see if linked list is empty
        if (!customerCart) {
            //If it is append the new node onto the empty list
            customerCart = newNode;
        }
        else {
            //Set the current node to the head node
            current =  customerCart;
            //Traverse the linked list until you reach the end
            while (current->next) {
                current = current->next;
            }
            //At the end set the current to point to the new node.
            current->next = newNode;
            
        }
        //Return the new linked list to the calling function
        shopping_cart = customerCart;
    }
    
    
    

