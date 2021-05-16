//
// Created by phuoc on 14/05/2021.
//

#ifndef TESTPROJECT_CONTROLLER_H
#define TESTPROJECT_CONTROLLER_H

#include "../data-access-object/CustomerDAO.cpp"
#include "../data-access-object/ItemDAO.cpp"

class Service {
private:
    CustomerDAO customerDao;
    ItemDAO itemDao;
public:
    // CRUD Item:
    void addItem(Item item){
        itemService.addNewItem(item);
    }

    void getItemById(string id){
        itemService.findItemById(id);
    }
    // CRUD Customer:
    // Other functions:
};


#endif //TESTPROJECT_CONTROLLER_H
