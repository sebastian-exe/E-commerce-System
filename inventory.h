//
//  inventory.h
//  Ecommerce System Phase 4
//
//  Created by Sebastian Moreno on 5/6/19.
//  Copyright © 2019 Sebastian Moreno. All rights reserved.
//

#ifndef inventory_h
#define inventory_h

class inventory{
    //private:
    
public:
    
    int fiveDigitCode = 0;
    int itemNumber = 0;
    double cost = 0;
    int qty = 0;
    double totalCost = 0;
    inventory * next;
    
    //default
    inventory();
    
    //accessors
    void getFiveDigitCode(int);
    
    void getItemNumber(int);
    
    void getCost(double);
    
    void getQty(int);
    
    void getCartCode(int);
    
    
    //mutators
    void setQty(int, int);
    
    void setCost(int, double);
    
    //deleteitem
    void deleteItem(int);
    
};

#endif /* inventory_h */
