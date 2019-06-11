//
//  customer.h
//  Ecommerce System Phase 4
//
//  Created by Sebastian Moreno on 5/6/19.
//  Copyright © 2019 Sebastian Moreno. All rights reserved.
//

#ifndef customer_h
#define customer_h
#include "inventory.h"
#include "LinkedList.h"
class customer:public inventory{
public:
    string firstName;
    string lastName;
    string address;
    string cityStateZip;
    string invoiceFileName;
    double totalCostCart;
    //lets just work on getting the shopping cart ot display currently 
    void displayCart(inventory * , int );
    
    //delete an item from the shopping cart linked list
    //test to see if the five digit code entered by the user is valid
void deleteFromCart(inventory *);
    
    //function to find the length
    int length(inventory*);
    
    
    string invoiceFile(string);
    
    
};


#endif /* customer_h */
