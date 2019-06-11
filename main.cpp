//project 4,
//  main.cpp
//  Ecommerce System Phase 4
//Sebastian Moreno, the username is UTD and password is Password
//  Created by Sebastian Moreno on 4/30/19.
//  Copyright © 2019 Sebastian Moreno. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

#include "LinkedList.h"
#include "inventory.h"
#include "customer.h"
#include "admin.h"
using namespace std;



//function protoytpes
inventory* searchFunction(inventory* , int);
bool searchDuplicate( inventory* , int);
inventory * updateQtyCartDuplicate(inventory*, int , int);
inventory * updateQtyforProducts(inventory* ,int, int);
void updateFile(string inputFileName, inventory* head_item);
void invoice(inventory* , int , string , string , string, string, string);


int main() {
    
    // **variable/object declarations**
    //the inventory pointer for head
    inventory * head_item = new inventory;
    head_item->next = nullptr;
    LinkedList store_inventory(head_item);
    customer user;
    //invetory pointer for shopping cart
    inventory * shopping_cart = new inventory;
    shopping_cart->next = nullptr;
    
    LinkedList cart(shopping_cart);
    inventory * searchPtr = nullptr;
    
    //create object for the admin
    admin administrator;

    int fiveDigitCode = 1;
    string userInput;
    string interfaceChoice;
    int adminChoice;
    int totProd = 0;
    int quantity = 0;
    int adminFiveDigit = 0;
    int adminItemNum = 0;
    double adminCost = 0.0;
    int adminQty = 0;
    int adminDelete = 0;
    int cartDelete = 0;
   
    // read in contents of file
    fstream myFile;
    
    myFile.open("ProductData.csv", ios::in);
    
    //read in the data from the csv file
    bool firstNode = true;
    inventory * prev = nullptr;
    while(myFile){
        inventory * node = new inventory;
        if(firstNode){
            store_inventory.head->next = node; // point the head node's next to the first actual node
            firstNode = false;
        }
        else{
            prev->next = node;
        }
        
        myFile.seekg(0L, ios::cur);
        myFile >> node->fiveDigitCode;
        myFile.seekg(8L, ios::cur);
        myFile >> node->itemNumber;
        myFile.seekg(1L, ios::cur);
        myFile >> node->cost;
        myFile.seekg(1L, ios::cur);
        myFile >> node->qty;
        prev = node;
        
    }
    prev->next = NULL;
    myFile.close();
    

    
    
    cout << "Please enter whether you want to enter the admin interface or the customer interface." << endl;
    cout << "Enter \"A\" or \"Admin\" to the admin interface, if admin is selected, then you will be prompted ";
    cout << " a valid username and password." << endl;
    cout << "Otherwise enter \"C\" or \"Customer\" to enter the customer interface of the program." << endl;
    cout << "To exit the admin function please enter \"E\" or \"Exit\" for the username." << endl;
    
    cin >> interfaceChoice;
    while (interfaceChoice == "A" || interfaceChoice == "a" || interfaceChoice == "admin" || interfaceChoice == "Admin") {

        
        cout << "Please enter a valid username." << endl;
        string username, password;
        bool user_correct = false;
        
      
         //username is UTD
        cin >> username;
        if(username == "E" || username == "e" || username == "Exit" || username == "exit")
            break;
        
        //call the admin object to test the username
      user_correct = administrator.validateUser(username);
        
        //if the username does not match UTD, then enter the loop and keep prompting the user
        while(user_correct == false){
            cout << "The username you entered is not valid, please enter a valid username." << endl;
            cin >> username;
            user_correct = administrator.validateUser(username);

        }
        //if the username is valid, then ask for the password
        if (user_correct == true) {
            cout << "Please enter a password." << endl;
            bool pass_correct = false;
            
            //password is Password
            cin >> password;
            
            //call the admin object to test the password
           pass_correct =  administrator.validatePass(password);
            
            //if the password does not match Password, then entre the loop and keep prompting the user
            while (pass_correct == false) {
                cout << "The password you entered is not valid, please enter a valid password." << endl;
                cin >> password;
                pass_correct =  administrator.validatePass(password);

            }
            if (pass_correct == true) {
                cout << "You have succesfully logged into the admin capabilites" << endl;
                cout << "Welcome to admin mode. Please select an option from the menu:" << endl;
                cout << "1 - Add a new product." << endl;
                cout << "2 - Delete an existing product." << endl;
                cout << "3 - Update the quantity of an existing product." << endl;
                cout << "4 - Update the cost of an existing product." << endl;

                cout << " " << endl;
                cin >> adminChoice;
                //code the admin functions with with the correct classes
                //code this after the adnin classes have been made
                    switch (adminChoice){
                        case 1:
                            cout << "Please enter the five digit code you would like";
                            cout << " to assign for this product: " << endl;
                            cin >> adminFiveDigit;
                            administrator.getFiveDigitCode(adminFiveDigit);
                            
                            cout << "Please enter the product number you would like";
                            cout << " to assign for this product: " << endl;
                            cin >> adminItemNum;
                            administrator.getItemNumber(adminItemNum);

                            cout << "Please enter the cost you would like";
                            cout << " to assign for this product: " << endl;
                            cin >> adminCost;
                            administrator.getCost(adminCost);

                            cout << "Please enter the quantity you would like";
                            cout << " to assign for this product: " << endl;
                            cin >> adminQty;
                            administrator.getQty(adminQty);
                            
                            //call to add all the information to the inventory function
                            administrator.Push(head_item);

                            break;
                        case 2:
                            cout << "Please enter the Product item Number (not the five digit code)";
                            cout << " of the product you want to delete." << endl;
                            cin >> adminDelete;
                            
                            administrator.deleteItem(adminDelete);
                            
                            administrator.deleteProduct(head_item);

                            break;
                        case 3:
                            cout << "Please enter the five digit code of the product";
                            cout << " you want to modify the quantity for." << endl;
                            cin >> adminFiveDigit;

                            cout << "Please enter the new amount of quantity you want this product to contain.";
                            cout << "This will replace the current amount of quantity." << endl;
                            cin >> adminQty;
                            
                            administrator.setQty(adminFiveDigit, adminQty);
                            administrator.updateQty(head_item);
                            
                            break;
                        case 4:
                            cout << "Please enter the five digit code of the product you want";
                            cout << " you want to modify the cost for." << endl;
                            cin >> adminFiveDigit;
                            
                            cout << "Please enter the new amount of cost you want this product to contain.";
                            cout << "This will replace the current cost of quantity." << endl;
                            cin >> adminCost;
                            
                            administrator.setCost(adminFiveDigit, adminCost);
                            administrator.updateCost(head_item);

                            
                            break;
                            default:
                            break;
                                }
            }
            
        }
        }
       
    
     if(interfaceChoice == "C" || interfaceChoice == "c" || interfaceChoice == "Customer" || interfaceChoice == "customer"){
        
        //prompt user with instructions of adding items to the cart, viewing the cart, or deleting items from the cart
        cout << "Please enter the product's 5 digit identifier that you would like to purchase." << endl;
        cout << "Once done, press 0 to exit." << endl;
        cout << "After an item has been successfully entered, the ability to view your shopping" << endl;
        cout << "cart will be unlocked, to view your shopping cart please enter the word \"Cart\"" << endl;
        cout << "If you wish to delete an item from the shopping cart, please enter the keyword \"Delete\" or \"D\"" << endl;
        
        while(fiveDigitCode != 0){
            bool duplicate = false;
            cout << "Please enter the product's 5 digit identifier that you would like to purchase." << endl;
            cout << "Once done, press 0 to exit." << endl;
            cin >> userInput;
            //if the user has entered the cart, then display the cart
            if (userInput == "Cart" || userInput == "cart") {
                user.displayCart(shopping_cart, totProd);
            }
            else if (userInput == "Delete" || userInput == "delete" || userInput == "D" || userInput == "d") {
                //input the call to delete
                cout << "Please enter the number that you wish to delete from you cart, in the order that you entered";
                cout << " it to your cart. Regardless of what the product name is, what is important is the numerical order." << endl;
                cout << "For example, to delete the first item you added to your cart, enter 1." << endl;
                cin >> cartDelete;
                
                user.getCartCode(++cartDelete);
                
                user.deleteFromCart(shopping_cart);
                --totProd;
            }
            else{
                fiveDigitCode = stoi(userInput);
                //test to see if the five digit code was zero and break out of the for loop
                if(fiveDigitCode == 0){
                    break;
                }
                //search the linked list to see find the five digit code
                searchPtr = searchFunction(head_item, fiveDigitCode);
            
                //if the five digit code isnt found in the inventroy linked list, prompt the user to enter another five digit code
                while(searchPtr == nullptr & fiveDigitCode != 0){
                    cout << "invalid number, please enter another valid 5 digit of code" << endl;

                    cin >> fiveDigitCode;

                    searchPtr = searchFunction(head_item, fiveDigitCode);

                }
                
                //if the five digit code is not 0, prompt user for quantity, if the five digit code is 0, do not ask for the quantity.
                if(fiveDigitCode != 0){
                    cout << "Please enter the quantity of the amount that you want to purchase." << endl;
                    cin >> quantity;
                    
                    //while the quantity is false or the quantity is less than
                    while(quantity > searchPtr->qty || quantity <= 0){
                        //if 0 items are attempted to be entered into the cart
                        if(quantity == 0){
                            cout << "0 items of a product cannot be added to the cart, please enter a valid quantity." << endl;
                            cin >> quantity;
                        }
                        cout << "Product " << searchPtr->itemNumber << " only has " << searchPtr->qty << " in stock.";
                        cout << " Please enter another quantity that is valid." << endl;
                        cin >> quantity;
                        
                    }
                    //once the five digit code and the quantity are both valid,
                    //check to see if there is a duplicate item in the current shopping cart
                    duplicate = searchDuplicate(shopping_cart, fiveDigitCode);
                    if(duplicate == true){
                        //function to update the quantity and total cost in the linked list
                        updateQtyCartDuplicate(shopping_cart, fiveDigitCode, quantity);
                        continue;
                    }
                    totProd++;
                }
                // sending in that pointer to become a node in the cart head linked list first
                //update the quanity of the first linked list with the new quantity
                updateQtyforProducts(head_item, fiveDigitCode, quantity);
                
                //send in the shopping cart head and a pointer with the item that the user selected
                cart.addNode(searchPtr, shopping_cart, quantity);
            }
            
            
        }
        
 
    
 
    }
    string firstName;
    string lastName;
    string address;
    string cityStateZip;
    string inputFileName;
    //gather information from the user
    cin.ignore(100, '\n');
    cout << "Enter your first name." << endl;
    getline(cin, firstName);
    cout << "Enter your last name." << endl;
    getline(cin, lastName);
    cout << "Enter your street address." << endl;
    getline(cin, address);
    cout << "Enter your city, state, and zip code." << endl;
    getline(cin, cityStateZip);
    
    inputFileName = user.invoiceFile(lastName);
    //code for invoice.txt
    invoice(shopping_cart, totProd , inputFileName ,firstName, lastName, address , cityStateZip);
    
    //outputting the information from the purchase to the console
    
    cout << "Customer Name: " << firstName << " " << lastName << endl;
    cout << "Customer Address: " << address << endl;
    cout << right << setw(18 + (int)cityStateZip.length()) << cityStateZip << endl;
    cout << " " << endl;
    user.displayCart(shopping_cart, totProd);
    updateFile("ProductData.csv", head_item);
    
    //delete memory, c++11
    delete head_item;
    delete shopping_cart;

    return 0;
}

//test to see if the five digit code entered by the user is valid
inventory * searchFunction(inventory * head_item, int fiveDigitCode){
    struct inventory* current = head_item;
    
    while (current != NULL)
    {
        if(current->fiveDigitCode == fiveDigitCode)
        {
            break;
        }
        
        current = current->next;
        
    }
    return current;
}

//function to test if there is a duplicate in the shopping cart
bool searchDuplicate(inventory* shopping_cart , int fiveDigitCode){
    struct inventory* current = shopping_cart;
    
    while (current != NULL)
    {
        if(current->fiveDigitCode == fiveDigitCode)
        {
            return true;
        }
        
        current = current->next;
        
    }
    return false;
}


//function to update the quantities for the first linked list
inventory * updateQtyCartDuplicate(inventory* shopping_cart, int fiveDigitCode, int quantity){
    struct inventory* current = shopping_cart;
    
    while (current != NULL)
    {
        if(current->fiveDigitCode == fiveDigitCode)
        {
            current->qty += quantity;
            current->totalCost = current->cost * current->qty;
            break;
        }
        
        current = current->next;
        
    }
    return current;
    
}

//function to update the quantities for the first linked list **After** an item has been purchased
inventory* updateQtyforProducts(struct inventory* head_item, int fiveDigitCode, int quantity){
    struct inventory* current = head_item;
    
    while (current != NULL)
    {
        if(current->fiveDigitCode == fiveDigitCode)
        {
            current->qty = current->qty - quantity;
            break;
        }
        
        current = current->next;
        
    }
    return current;
}


void updateFile(string myFileName, inventory* head_item){
    fstream myFile;
    myFile.open(myFileName, ios::in | ios::out | ios::trunc);
    inventory* current = head_item->next;
    
    
    while (current != nullptr) {
        if(current->qty != 0){
            myFile << current->fiveDigitCode << ", Product " << current->itemNumber << "," << setprecision(2) << fixed << current->cost << "," << current->qty << endl;
        }
        current = current->next;
    }
    myFile.close();
}

//function to make the invoice txt
void invoice(inventory* shopping_cart,  int totProd, string invoiceFileName,string firstName, string lastName, string address, string cityStateZip){
    
    ofstream outputFile;
    outputFile.open(invoiceFileName, ios::out);
    
    //Create a temporary node to keep track of the current node
    inventory* current = shopping_cart->next;
    double total = 0;
    
    //outputting the information from the purchase to the  file "Invoice.txt"
    outputFile << "Customer Name: " << firstName << " " << lastName << endl;
    outputFile << "Customer Address: " << address << endl;
    outputFile << right << setw(18 + (int)cityStateZip.length()) << cityStateZip << endl;
    outputFile << " " << endl;
    outputFile << "Item Number " << setw(19) <<  "Item Name" << setw(15) << "Qty" << setw(19) << "Unit Cost" << setw(15) << "Total" << endl;
    outputFile << "-----------------------------------------------------------------------------------" << endl;
    
    for(int i = 0; i < totProd; i++){
        outputFile << fixed << setprecision(0);
        outputFile << "Item Number " << current->fiveDigitCode  << setw(18) << " Product Name " << left << setw(3) << current->itemNumber << right << setw(8) << current->qty << fixed << setprecision(2) << setw(15) << current->cost << setw(20) << current->totalCost << endl;
        
        total += current->totalCost;
        current = current->next;
    }
    outputFile << "-----------------------------------------------------------------------------------" << endl;
    outputFile << setw(74) << fixed << setprecision(2) << "Total: $"  << total;
}
