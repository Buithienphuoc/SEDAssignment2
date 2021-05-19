//
// Created by phuoc on 13/05/2021.
//

#ifndef TESTPROJECT_VIEW_H
#define TESTPROJECT_VIEW_H


#include "iostream"
#include "../service/Service.cpp"

class Controller {
private:
    Service service;

protected:
    void loadDatabase();
    void addItem();
    void addCustomer();
    void updateItem();
    void updateCustomer();
    void deleteItem();
    void deleteCustomer();
    Item getItemInput();
    Customer getCustomerInput();
    void searchItemById();
    void searchCustomerById();
    void searchItemByTitle();
    void searchCustomerByName();

public:
    void showMenu();
    void workWithChoice();
    void addUpdateDeleteItem();
    void addUpdateDeleteCustomer();
    void promoteAnExistingCustomer();
    void rentItem();
    void returnItem();
    void displayAllItem();
    void displayOutOfStockItem();
    void displayAllCustomer();
    void displayGroupOfCustomer();
    void searchItemOrCustomer();
    void saveAndExit();
    void runProgram();
};


#endif //TESTPROJECT_CONTROLLER_H
