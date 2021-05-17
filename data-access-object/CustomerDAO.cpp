//
// Created by phuoc on 10/05/2021.
//

#include "CustomerDAO.h"

CustomerDAO::CustomerDAO() {}

void CustomerDAO::addNewCustomer(Customer customer) {
    customerList.add(customer);
}

void CustomerDAO::showAllCustomer() {
    if (customerList.size() == 0) {
        cout << "There is not any customer" << endl;
    } else {
        customerList.print();
    }
}

Customer CustomerDAO::findCustomerById(string id) {
    if (customerList.size() == 0) {
        cout << "There is not any customer" << endl;
    } else {
        for (int customerPosition = 1; customerPosition <= customerList.size(); customerPosition++) {
            Customer targetCustomer = customerList.getIndex(customerPosition);
            string targetString = toUpperCase(targetCustomer.getId());
            if (targetString == id) {
                return targetCustomer;
            }
        }
        cout << "There is not customer with id " << id << endl;
    }
    return Customer();
}

LinkedList<Customer> CustomerDAO::findCustomerByName(string name) {
    // There may be more than 2 customers have the same name
    LinkedList<Customer> resultList;
    if (customerList.size() == 0) {
        cout << "There is not any customer" << endl;
    } else {
        for (int customerPosition = 1; customerPosition <= customerList.size(); customerPosition++) {
            Customer currentCustomer = customerList.getIndex(customerPosition);
            if (toLowerCase(currentCustomer.getName()) == toLowerCase(name)) {
                resultList.add(currentCustomer);
            }
        }
    }
    return resultList;
}

void CustomerDAO::deleteCustomerById(string id) {
    if (customerList.size() == 0) {
        cout << "There is not any customer" << endl;
    }
    else {
        Customer customer = findCustomerById(id);
        customerList.deleteItem(customer);
    }
}

void CustomerDAO::updateCustomerById(string id, Customer newInformation) {
    if (customerList.size() == 0) {
        cout << "There is not any customer" << endl;
    }
    else {
        Customer oldInformation = findCustomerById(id);
        customerList.update(oldInformation, newInformation);
    }
}

LinkedList<Customer> CustomerDAO::findCustomersByGroup(AccountType accountType) {
    LinkedList<Customer> resultList;
    if (customerList.size() == 0) {
        cout << "There is not any customer" << endl;
    } else {
        for (int customerPosition = 1; customerPosition <= customerList.size(); customerPosition++) {
            Customer currentCustomer = customerList.getIndex(customerPosition);
            if (currentCustomer.getAccountType() == accountType) {
                resultList.add(currentCustomer);
            }
        }
    }
    return resultList;
}

void CustomerDAO::promoteCustomer(string id, AccountType newType) {
    Customer targetCustomer = findCustomerById(id);
    if (targetCustomer.getAccountType() == VIP && newType <= VIP){
        cout << "This customer is already a VIP customer" << endl;
    }
    else {
        if (newType == targetCustomer.getAccountType()){
            cout << "Cannot promote the same Type, please try again" << endl;
        }
        else {
            cout << "Promote successfully customer "<< id << " from " << targetCustomer.printAccountType() << " to:";
            targetCustomer.setAccountType(newType);
            cout << targetCustomer.printAccountType() << endl;
            updateCustomerById(id, targetCustomer);
        }
    }
}

void CustomerDAO::addItemForCustomer(string customerId, Item item) {
    if(customerList.size() == 0){
        cout << "There is not any customer:" << customerId << endl;
    }
    else {
        Customer targetCustomer = findCustomerById(customerId);
        targetCustomer.addItem(item);
        updateCustomerById(customerId, targetCustomer);
    }
}

void CustomerDAO::removeItemForCustomer(string customerId, Item item) {
    if(customerList.size() == 0){
        cout << "This customer has not rent any item:"<< customerId << endl;
    }
    else {
        Customer targetCustomer = findCustomerById(customerId);

        if (targetCustomer.getListOfRentals().has(item)) {
            targetCustomer.removeItem(item);
            updateCustomerById(customerId, targetCustomer);
            cout << "Item with id = "<< item.getId() << " is returned" << endl;
        } else {
            cout << "You don't have this item id = " << item.getId() <<" to return" << endl;
        }
    }
}

void CustomerDAO::swap(Customer customer1, Customer customer2) {
    customerList.swap(customer1,customer2);
}

void CustomerDAO::sortById() {
    int i, j;
    int customerListSize = customerList.size();
    for (i = 1; i < customerListSize; i++){
        // Last i elements are already in place
        for (j = 1; j < customerListSize-i+1; j++)
            if (customerList.getIndex(j).getId() > customerList.getIndex(j+1).getId()){
                swap(customerList.getIndex(j), customerList.getIndex(j+1));
            }
    }
}

void CustomerDAO::sortByName() {
    int i, j;
    int customerListSize = customerList.size();
    for (i = 1; i < customerListSize; i++){
        // Last i elements are already in place
        for (j = 1; j < customerListSize-i+1; j++)
            if (customerList.getIndex(j).getName() > customerList.getIndex(j+1).getName()){
                swap(customerList.getIndex(j), customerList.getIndex(j+1));
            }
    }
}

int CustomerDAO::getNumberOfRentals(string customerId) {
    Customer targetCustomer = findCustomerById(customerId);
    int numberOfRentals = targetCustomer.getNumberOfRentals();
    return numberOfRentals;
}

