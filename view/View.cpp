//
// Created by phuoc on 13/05/2021.
//

#include "View.h"

void View::showMenu() {
    cout << " Welcome to Genie’s video store \n"
            "Enter an option below. \n"
            "1. Add a new item, update or delete an existing item \n"
            "2. Add new customer or update an existing customer \n"
            "3. Promote an existing customer\n"
            "4. Rent an item\n"
            "5. Return an item \n"
            "6. Display all items \n"
            "7. Display out-of-stock items \n"
            "8. Display all customers \n"
            "9. Display group of customers \n"
            "10. Search items or customers\n"
            "Exit. " << endl;
}

void View::workWithChoice(){
    bool programRun = true;
    while(programRun){
        string userChoice = "0";
        cout << "Your choice:"; cin >> userChoice; cout << endl;
        if (userChoice == "1"){ // 1. Add a new item, update or delete an existing item

        }
        else if(userChoice == "2"){ // 2. Add new customer or update an existing customer

        }
        else if (userChoice == "3"){ // 3. Promote an existing customer

        }
        else if(userChoice == "4"){ // 4. Rent an item

        }
        else if (userChoice == "5"){ // 5. Return an item

        }
        else if(userChoice == "6"){ // 6. Display all items

        }
        else if (userChoice == "7"){ // 7. Display out-of-stock items

        }
        else if(userChoice == "8"){ // 8. Display all customers

        }
        else if (userChoice == "9"){ // 9. Display group of customers

        }
        else if(userChoice == "10"){ // 10. Search items or customers

        }
        else if (toLowerCase(userChoice) == "exit"){ // Exit
            programRun = false;
        }
    }

}

void View::addUpdateDeleteItem() {


}

void View::addUpdateDeleteCustomer() {

}

void View::promoteAnExistingCustomer() {

}

void View::rentItem() {

}

void View::returnItem() {

}

void View::displayAllItem() {

}

void View::displayOutOfStockItem() {

}

void View::displayAllCustomer() {

}

void View::displayGroupOfCustomer() {

}

void View::searchItemOrCustomer() {

}
