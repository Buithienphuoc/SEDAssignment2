//
// Created by phuoc on 13/05/2021.
//

#ifndef TESTPROJECT_VIEW_H
#define TESTPROJECT_VIEW_H

#include "../service/CustomerService.h"
#include "../service/ItemService.h"
#include "iostream"


class View {
private:
    CustomerService customerService;
    ItemService itemService;
public:
    void showMenu();
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
};


#endif //TESTPROJECT_VIEW_H
