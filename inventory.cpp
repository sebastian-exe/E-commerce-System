//
//  inventory.cpp
//  Ecommerce System Phase 4
//
//  Created by Sebastian Moreno on 5/6/19.
//  Copyright © 2019 Sebastian Moreno. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "inventory.h"
using namespace std;



//default
inventory::inventory(){};

//accessors
void inventory::getFiveDigitCode(int adminFiveDigit){
    fiveDigitCode = adminFiveDigit;
}

void inventory::getItemNumber(int adminItemNum){
    itemNumber = adminItemNum;
}

void inventory::getCost(double adminCost){
    cost = adminCost;
}

void inventory::getQty(int adminQty){
    qty = adminQty;
}

void inventory::getCartCode(int cartDelete){
    itemNumber = cartDelete;
}


//mutators
void inventory::setQty(int adminFiveDigitCode, int adminQty){
    fiveDigitCode = adminFiveDigitCode;
    qty = adminQty;
    
}
void inventory::setCost(int adminFiveDigitCode, double adminCost){
    fiveDigitCode = adminFiveDigitCode;
    cost = adminCost;
}


//deleteitem
void inventory::deleteItem(int adminDelete){
    itemNumber = adminDelete;
}
