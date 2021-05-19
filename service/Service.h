//
// Created by phuoc on 14/05/2021.
//

#ifndef TESTPROJECT_CONTROLLER_H
#define TESTPROJECT_CONTROLLER_H

#include "../data-access-object/CustomerDAO.cpp"
#include "../data-access-object/ItemDAO.cpp"

/*
 * This is a class with void functions.
 * Is used to get a request from a user and response with DAO (Data Access Object)
 */

class Service {
private:
    CustomerDAO customerDao;
    ItemDAO itemDao;
public:
    /*
    * ITEM LIST FUNCTIONS:
    */
    void add(Item item); // ==> Function overload
    void showAllItem();
    void showItemById(string id);
    void updateItemById(string id, Item newInformation);
    void deleteItemById(string id);
    void receiveNewItemStock(string id, int numberOfNewCopies);
    void decreaseNumberOfCopies(string id, int numberOfCopies);
    void changeStatusOfItem(string id, RentalStatusType newStatus);
    void showOutOfStockItem();
    void sortItemById();
    void sortItemByTitle();

    /*
    * CUSTOMER LIST FUNCTIONS:
    */
    void add(Customer customer); // ==> Function overload
    void showAllCustomer();
    void showCustomerById(string id);
    void updateCustomerById(string id, Customer newInformation);
    void deleteCustomerById(string id);
    void showCustomersByName(string name);
    void showCustomersByGroup(AccountType accountType);
    void promoteCustomer(string id, AccountType newType);
    void addItemForCustomer(string customerId, Item item);
    void removeItemForCustomer(string customerId, string itemId);
    void sortCustomerById();
    void sortCustomerByName();

    // Other functions:

    void customerRentAnItem(string customerId, string itemId);
    void rentWithAuthentication(string customerId, string itemId);
    void customerReturnAnItem(string customerId, string itemId);
};


#endif //TESTPROJECT_CONTROLLER_H
