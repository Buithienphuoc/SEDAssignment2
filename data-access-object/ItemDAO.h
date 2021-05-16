//
// Created by phuoc on 08/05/2021.
//

#ifndef TESTPROJECT_ITEMDAO_H
#define TESTPROJECT_ITEMDAO_H


// 1. Add a new item, update or delete an existing item
#include "iostream"
#include "../linkedlist/LinkedList.h"
#include "../model/Item.h"

using namespace std;
class ItemDAO {
private:
    LinkedList<Item> itemList;
public:
    ItemDAO();
    void addNewItem(Item item);
    void showAllItem();
    Item findItemById(string id);
    Item findItemByTitle(string title);
    void updateItemById(string id, Item newInformation);
    void deleteItemById(string id);
    void receiveNewItemStock(string id, int numberOfNewCopies);
    void decreaseNumberOfCopies(string id, int numberOfCopies);
    void changeStatusOfItem(string id, RentalStatusType newStatus);
    LinkedList<Item> findOutOfStockItem();
    void swap(Item item1, Item item2);
    void sortById();
    void sortByTitle();
};


#endif //TESTPROJECT_ITEMDAO_H
