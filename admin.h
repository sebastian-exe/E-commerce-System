//
//  admin.h
//  Ecommerce System Phase 4
//
//  Created by Sebastian Moreno on 5/6/19.
//  Copyright © 2019 Sebastian Moreno. All rights reserved.
//

#ifndef admin_h
#define admin_h
#include "inventory.h"
#include "LinkedList.h"
#include "customer.h"
//show that the admin inherits the o
class admin:public inventory{
public:
    string username_ = "UTD";
    string password_ = "Password";
    
    
    //adds the admin item to the beginning of the linked list for the invtory read in from the CSV
    void Push(inventory*&);
    
    //delete a product
    void deleteProduct(inventory *);
    
    
    //function to find the length
    int length(inventory*);
    
    //function to update the quantity for the admin
    inventory* updateQty(inventory*);
    //function to update the quantity for the admin
    inventory * updateCost(inventory*);
    
    
    //validate input for the username and password
    //validate for username
    bool validateUser(string);
    
    bool validatePass(string);
    
};
#endif /* admin_h */
