//
// Created by phuoc on 21/04/2021.
//

#ifndef TESTPROJECT_CUSTOMER_H
#define TESTPROJECT_CUSTOMER_H

#define VIP_POINTS 0

#include <iostream>
#include "../linkedlist/LinkedList.h"
#include "Item.h"

using namespace std;

class Customer : public Model {
private:
    string id_;
    string name_;
    string address_;
    string phone_;
    int numberOfRentals;
    AccountType accountType_;
    LinkedList<Item> listOfRentals_;

protected:
    int vipPoint = VIP_POINTS;

public:
    Customer() = default;

    Customer(const string &id, const string &name, const string &address, const string &phone, AccountType accountType)
            : id_(id), name_(name), address_(address), phone_(phone), accountType_(accountType) {}

    Customer(const string &id, const string &name, const string &address, const string &phone, int numberOfRentals,
             AccountType accountType) : id_(id), name_(name), address_(address), phone_(phone),
                                        numberOfRentals(numberOfRentals), accountType_(accountType) {}


    // GETTERS:
    const string &getId() const {
        return id_;
    }

    const string &getName() const {
        return name_;
    }

    const string &getAddress() const {
        return address_;
    }

    const string &getPhone() const {
        return phone_;
    }

    AccountType getAccountType() const {
        return accountType_;
    }

    LinkedList<Item> getListOfRentals() {
        return listOfRentals_;
    }

    int getVipPoint() const {
        return vipPoint;
    }

    // SETTERS:
    void setId(const string &id) {
        id_ = id;
    }

    void setName(const string &name) {
        name_ = name;
    }

    void setAddress(const string &address) {
        address_ = address;
    }

    void setPhone(const string &phone) {
        phone_ = phone;
    }

    void setAccountType(AccountType type) {
        Customer::accountType_ = type;
    }

    void setListOfRentals(const LinkedList<Item> &listOfRentals) {
        listOfRentals_ = listOfRentals;
    }

    void setVipPoint(int point) {
        Customer::vipPoint = point;
    }
    // Compare operators:

    bool operator==(const Customer &rhs) const {
        return id_ == rhs.id_ &&
               name_ == rhs.name_ &&
               address_ == rhs.address_ &&
               phone_ == rhs.phone_;
    }

    bool operator!=(const Customer &rhs) const {
        return !(rhs == *this);
    }

    // Put into the list of rentals:

    void addItem(Item item) {
        if (accountType_ == VIP){
            rewardVIPPoint();
        }
        listOfRentals_.add(move(item));
    }

    void removeItem(Item item){
        listOfRentals_.deleteItem(item);
    }

    // VIP member functions:

    void rewardVIPPoint(){
        vipPoint += 10;
        cout << "Your current point is " << vipPoint << endl;
        cout << "You have more 10 points for VIP account" << endl;
        cout << "If you reach 100 points, you can rent 1 more for free" << endl;
    }

    void resetVIPPoint(){
        vipPoint = 0;
    }

    void rentFreeForVIP(Item item){
        listOfRentals_.add(item);
        resetVIPPoint();
    }

    // Show all rentals:
    void showAllRentals() {
        cout << "Customer " << Customer::getName() << " with ID:" << Customer::getId() << " rents: ";
        listOfRentals_.print();
    }

    // Number of rentals:
    int getNumberOfRentals(){
        this->numberOfRentals = listOfRentals_.size();
        return listOfRentals_.size();
    }

    // To String

    string printAccountType() const{
        switch(accountType_){
            case GUEST:
                return "Guest";
            case REGULAR:
                return "Regular";
            case VIP:
                return "VIP";
        }
        return nullptr;
    }

    friend ostream &operator<<(ostream &os, const Customer &customer) {
        os << "id_: " << customer.id_ << " name_: " << customer.name_ << " address_: " << customer.address_
           << " phone_: " << customer.phone_ << " numberOfRentals: " << customer.numberOfRentals << " accountType_:" << customer.printAccountType();
        return os;
    }
};

#endif //TESTPROJECT_CUSTOMER_H
