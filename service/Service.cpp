//
// Created by phuoc on 14/05/2021.
//

#include "Service.h"

/*
 * ITEM LIST FUNCTIONS:
 */

void Service::add(Item item) {
    itemDao.addNewItem(item);
}

void Service::showAllItem() {
    itemDao.showAllItem();
}

void Service::showItemById(string id) {
    Item theItem = itemDao.findItemById(id);
    cout << "Item with id:" << id << endl;
    cout << theItem;
}

void Service::updateItemById(string id, Item newInformation) {
    itemDao.updateItemById(id, newInformation);
}

void Service::deleteItemById(string id) {
    itemDao.deleteItemById(id);
}

void Service::receiveNewItemStock(string id, int numberOfNewCopies) {
    itemDao.receiveNewItemStock(id, numberOfNewCopies);
}

void Service::decreaseNumberOfCopies(string id, int numberOfCopies) {
    itemDao.decreaseNumberOfCopies(id, numberOfCopies);
}

void Service::changeStatusOfItem(string id, RentalStatusType newStatus) {
    itemDao.changeStatusOfItem(id, newStatus);
}

void Service::showOutOfStockItem() {
    // There are maybe more than out-of-stock items ==> This is a list of items
    itemDao.findOutOfStockItem().print();
}

void Service::sortItemById() {
    itemDao.sortById();
}

void Service::sortItemByTitle() {
    itemDao.sortByTitle();
}

/*
 * CUSTOMER LIST FUNCTIONS:
 */

void Service::add(Customer customer) {
    customerDao.addNewCustomer(customer);
}

void Service::showAllCustomer() {
    customerDao.showAllCustomer();
}

void Service::showCustomerById(string id) {
    Customer targetCustomer = customerDao.findCustomerById(id);
    cout << targetCustomer << endl;
    cout << "with all rentals:" << endl;
    targetCustomer.showAllRentals();
}

void Service::updateCustomerById(string id, Customer newInformation) {
    customerDao.updateCustomerById(id, newInformation);
}

void Service::deleteCustomerById(string id) {
    customerDao.deleteCustomerById(id);
}

void Service::showCustomersByName(string name) {
    // The list may have more than 1 customer have the same name ==> This is a list of customer with the same name
    customerDao.findCustomerByName(name).print();
}

void Service::showCustomersByGroup(AccountType accountType) {
    // Group of customer ==> List
    customerDao.findCustomersByGroup(accountType).print();
}

void Service::promoteCustomer(string id, AccountType newType) {
    customerDao.promoteCustomer(id, newType);
}

void Service::addItemForCustomer(string customerId, Item item) {
    customerDao.addItemForCustomer(customerId, item);
}

void Service::removeItemForCustomer(string customerId, Item item) {
    customerDao.removeItemForCustomer(customerId, item);
}

void Service::sortCustomerById() {
    customerDao.sortById();
}

void Service::sortCustomerByName() {
    customerDao.sortByName();
}


/*
 * OTHER FUNCTIONS
 */

void Service::customerRentAnItem(string customerId, string itemId) {
    itemId = toUpperCase(itemId);
    /*
     * This function is created by decreasing stock number from item list and then add it to the customer.
     * While the item is rented, some of information inside the rented item Object is not used
     * so another developer can understand the code
     */
    Item rentedItem = itemDao.findItemById(itemId); // ==> find the item to rent
    if (rentedItem.getNumberOfCopies() >= 1){
        cout << "Rent successfully!" << endl;
        itemDao.decreaseNumberOfCopies(itemId, 1); // ==> rent 1, decrease by 1
        if (rentedItem.getNumberOfCopies() == 0){ // ==> check after change
            itemDao.changeStatusOfItem(itemId, BORROWED);// ==> Not Available to rent
        }
        customerDao.addItemForCustomer(customerId, rentedItem);
    }
    else { // ==> if the number of copy is 0
        cout << "There is not any copy of item with id = " << itemId << " to rent, please wait for more stock or someone return" << endl;
    }
}

