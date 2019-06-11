//
//  LinkedList.h
//  Ecommerce System Phase 4
//
//  Created by Sebastian Moreno on 5/6/19.
//  Copyright © 2019 Sebastian Moreno. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
using namespace std;
#include "inventory.h"
class LinkedList:public inventory{
public:
    inventory * head;
    inventory * cartHead;
    bool firstNode = true;
    LinkedList();
    
    LinkedList(inventory *);
        
    
    void addNode(inventory *, inventory * ,int );
    
    
};


#endif /* LinkedList_h */
