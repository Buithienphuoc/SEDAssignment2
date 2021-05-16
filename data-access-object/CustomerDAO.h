//
// Created by phuoc on 10/05/2021.
//

#ifndef TESTPROJECT_CUSTOMERDAO_H
#define TESTPROJECT_CUSTOMERDAO_H

#include "../model/Customer.h"
#include "../linkedlist/LinkedList.h"

class CustomerDAO {
private:
    LinkedList<Customer> customerList;
public:
    CustomerDAO();
    void addNewCustomer(Customer customer);
    void showAllCustomer();
    Customer findCustomerById(string id);
    LinkedList<Customer> findCustomerByName(string name);
    LinkedList<Customer> findCustomersByGroup(AccountType accountType);
    void updateCustomerById(string id, Customer newInformation);
    void deleteCustomerById(string id);
    void promoteCustomer(string id, AccountType newType);
    void addItemForCustomer(string customerId, Item item);
    void returnItemForCustomer(string customerId, Item item);
    void swap(Customer customer1, Customer customer2);
    void sortById();
    void sortByName();
};


#endif //TESTPROJECT_CUSTOMERDAO_H
