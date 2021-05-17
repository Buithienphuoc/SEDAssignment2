//
// Created by phuoc on 13/05/2021.
//

#ifndef TESTPROJECT_VIEW_H
#define TESTPROJECT_VIEW_H


#include "iostream"
#include "../service/Service.cpp"

class View {
private:
    Service service;
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
};


#endif //TESTPROJECT_VIEW_H
