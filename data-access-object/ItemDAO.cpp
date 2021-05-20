//
// Created by phuoc on 08/05/2021.
//
#include "ItemDAO.h"

ItemDAO::ItemDAO() {
}

void ItemDAO::addNewItem(Item item) {
    itemList.add(item);
}

void ItemDAO::showAllItem(){
    itemList.print();
}

Item ItemDAO::findItemById(string id) {
    id = toUpperCase(id);
    cout << "find item id:" << id << endl;
    for (int itemPosition = 1; itemPosition <= itemList.size(); itemPosition++){
        Item targetItem = itemList.getIndex(itemPosition);
        string targetString = toUpperCase(targetItem.getId());
        if (targetString == id) {
            return targetItem;
        }
    }
    cout << "Find Fail" << endl;
    return Item();
}

Item ItemDAO::findItemByTitle(string title) {
    for (int itemPosition = 1; itemPosition <= itemList.size(); itemPosition++){
        Item targetItem = itemList.getIndex(itemPosition);
        string targetString = toUpperCase(targetItem.getTitle());
        if (targetString == title) {
            return targetItem;
        }
    }
    cout << "There is not item with title " << title << endl;
    return Item();
}

void ItemDAO::deleteItemById(string id) {
    Item item = findItemById(id);
    itemList.deleteItem(item);
}

void ItemDAO::updateItemById(string id, Item newInformation) {
    Item oldInformation = findItemById(id);
    itemList.update(oldInformation, newInformation);
}

void ItemDAO::receiveNewItemStock(string id, int numberOfNewCopies) {
    Item targetItem = findItemById(id);
    targetItem.setNumberOfCopies(targetItem.getNumberOfCopies() + numberOfNewCopies);
    updateItemById(id,targetItem);
}
/*
 * You may ask:" Why did I want to put the number of copy for this function as the param ? "
 * Answer: "In the future someone wants to develop functions with: borrow more than 2 copy"
 */
void ItemDAO::decreaseNumberOfCopies(string id, int numberOfCopies) {
    Item targetItem = findItemById(id);
    if (numberOfCopies <= targetItem.getNumberOfCopies()){
        targetItem.setNumberOfCopies(targetItem.getNumberOfCopies() - numberOfCopies );
        updateItemById(id,targetItem);
    }
    else {
        cout << "You cannot get more than " << targetItem.getNumberOfCopies() << " coppies !!" << endl;
    }

    if (targetItem.getNumberOfCopies() == 0){
        changeStatusOfItem(id, BORROWED);
    }
}

void ItemDAO::changeStatusOfItem(string id, RentalStatusType newStatus) {
    Item targetItem = findItemById(id);
    if (targetItem.getRentalStatus() != newStatus){
        targetItem.setRentalStatus(newStatus);
    }
}

LinkedList<Item> ItemDAO::findOutOfStockItem() {
    LinkedList<Item> resultList;
    if (itemList.size() == 0) {
        cout << "There is not any item" << endl;
    } else {
        for (int itemPosition = 1; itemPosition <= itemList.size(); itemPosition++) {
            Item currentItem = itemList.getIndex(itemPosition);
            if (currentItem.getNumberOfCopies() == 0) {
                resultList.add(currentItem);
            }
        }
        cout << "List of out of stock Item:" << endl;
        resultList.print();
    }
    return resultList;
}

void ItemDAO::swap(Item item1, Item item2) {
    itemList.swap(item1, item2);
}

// Bubble sort
void ItemDAO::sortById() {
    int i, j;
    int itemListSize = itemList.size();
    for (i = 1; i < itemListSize; i++){
        // Last i elements are already in place
        for (j = 1; j < itemListSize-i+1; j++)
            if (itemList.getIndex(j).getId() > itemList.getIndex(j+1).getId()){
                swap(itemList.getIndex(j), itemList.getIndex(j+1));
            }
    }
}

void ItemDAO::sortByTitle() {
    int i, j;
    int itemListSize = itemList.size();
    for (i = 1; i < itemListSize; i++){
        // Last i elements are already in place
        for (j = 1; j < itemListSize-i+1; j++)
            if (itemList.getIndex(j).getTitle() > itemList.getIndex(j+1).getTitle()){
                swap(itemList.getIndex(j), itemList.getIndex(j+1));
            }
    }
}