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

void Service::showItemByTitle(string title) {
    Item theItem = itemDao.findItemByTitle(title);
    cout << "Item with title:" << title << endl;
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

void Service::addItemForCustomer(string customerId, string itemId){
    Item item = itemDao.findItemById(itemId);
    customerDao.addItemForCustomer(customerId, item);
}

void Service::removeItemForCustomer(string customerId, string itemId) {
    customerDao.removeItemForCustomer(customerId, itemId);
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

void Service::rentWithAuthentication(string customerId, string itemId) {
    Customer customer = customerDao.findCustomerById(customerId);
    Item item = itemDao.findItemById(itemId);
    if (customer.getAccountType() == GUEST and customer.getNumberOfRentals() == 2){
        cout << "Customer with id:" << customerId << " is the GUEST, please ask to promote to rent more item";
    }
    else if (customer.getAccountType() == REGULAR and customer.getNumberOfRentals() == 3){
        cout << "Customer with id:" << customerId << " is the REGULAR, please ask to promote to rent more item";
    }
    else if (customer.getAccountType() == GUEST and item.getLoanType() == TWODAYLOAN){
        cout << "Customer with id:" << customerId << " is the guest, please ask to promote to rent 2-days loan item";
    }
    else {
        customerRentAnItem(customerId,itemId);
    }
}

void Service::customerReturnAnItem(string customerId, string itemId){
    customerDao.removeItemForCustomer(customerId, itemId);
    itemDao.receiveNewItemStock(itemId,1);
}

void Service::loadDatabase() {
    loadItemFile();
    loadCustomerFile();
}

void Service::loadItemFile() {
    // Create a text string, which is used to output the text file
    LinkedList<string> myItemList;
    // Declare item:
    string id;
    string title;
    RentalType rentalType;
    LoanType loan;
    GenreType genre;
    int numberOfCopies;
    float rentalFee;
    fstream itemFile("database/items.txt");
    string line;
    if (itemFile.is_open()){
        while (getline(itemFile, line)){
            line = line+ "\n";
            myItemList.add(line);
        }
        itemFile.close();

        for (int i = 1; i <= myItemList.size(); i++){
            string itemObjectString = myItemList.getIndex(i);
            LinkedList<string> itemInfoList;
            itemInfoList = splitString(itemObjectString);
            cout << "Add item " << i << ":" << endl;
            cout << "item info size =" << itemInfoList.size()<<endl;
            if (itemInfoList.size() == 6){
                cout << "id=" << itemInfoList.getIndex(1) << endl;
                id = itemInfoList.getIndex(1);
                cout << "title=" << itemInfoList.getIndex(2) << endl;
                title = itemInfoList.getIndex(2);
                cout << "rental type=" << itemInfoList.getIndex(3) << endl;
                rentalType = convertStringToRentalType(itemInfoList.getIndex(3));
                cout << "loan type=" << itemInfoList.getIndex(4) << endl;
                loan = convertStringToLoanType(itemInfoList.getIndex(4));
                cout << "no.copies=" << itemInfoList.getIndex(5) << endl;
                numberOfCopies = stoi(itemInfoList.getIndex(5));
                cout << "price=" << itemInfoList.getIndex(6) << endl;
                rentalFee = stof(itemInfoList.getIndex(6));
                Item item(id,title,rentalType,loan,numberOfCopies,rentalFee);
                add(item);
                cout << endl;
            }
            else if (itemInfoList.size() == 7){
                cout << "id=" << itemInfoList.getIndex(1) << endl;
                id = itemInfoList.getIndex(1);
                cout << "title=" << itemInfoList.getIndex(2) << endl;
                title = itemInfoList.getIndex(2);
                cout << "type=" << itemInfoList.getIndex(3) << endl;
                rentalType = convertStringToRentalType(itemInfoList.getIndex(3));
                cout << "loan=" << itemInfoList.getIndex(4) << endl;
                loan = convertStringToLoanType(itemInfoList.getIndex(4));
                cout << "no.copies=" << itemInfoList.getIndex(5) << endl;
                numberOfCopies = stoi(itemInfoList.getIndex(5));
                cout << "price=" << itemInfoList.getIndex(6) << endl;
                rentalFee = stof(itemInfoList.getIndex(6));
                cout << "genre=" << itemInfoList.getIndex(7);
                genre = convertStringToGenreType(itemInfoList.getIndex(7));
                Item item(id,title,rentalType,loan,numberOfCopies,rentalFee,genre);
                add(item);
                cout << endl;
            }
            cout << endl;
        }
    }
}

void Service::loadCustomerFile() {
    LinkedList<string> myCustomerList;
    fstream customerFile("database/customers.txt");
    string line;
    string customerId;
    string customerName;
    string customerAddress;
    string customerPhone;
    int numberOfRentals;
    AccountType accountType;
    if (customerFile.is_open()){
        while (getline(customerFile, line)){
            line = line + "\n";
            myCustomerList.add(line);
        }
        customerFile.close();
        for (int i = 1; i <= myCustomerList.size(); i++){
            string customerObjectString = myCustomerList.getIndex(i);
            if (customerObjectString[0] == 'I'){
                cout << "Add item " << customerObjectString << endl;
                cout << "for customer with id=" << customerId << endl;
                addItemForCustomer(customerId,customerObjectString);
                cout << endl;
                customerDao.findCustomerById(customerId).getListOfRentals().print();
            }
            else if (customerObjectString[0] == 'C'){
                LinkedList<string> customerInfoList;
                customerInfoList = splitString(customerObjectString);
                cout << "Add customer of line " << i << ":" << endl;
                cout << "Customer ID:" << customerInfoList.getIndex(1) << endl;
                customerId = customerInfoList.getIndex(1);
                cout << "Customer name:" << customerInfoList.getIndex(2) << endl;
                customerName = customerInfoList.getIndex(2);
                cout << "Customer address:" << customerInfoList.getIndex(3) << endl;
                customerAddress = customerInfoList.getIndex(3);
                cout << "Customer phone:" << customerInfoList.getIndex(4) << endl;
                customerPhone = customerInfoList.getIndex(4);
                cout << "Number of rentals:" << customerInfoList.getIndex(5) << endl;
                numberOfRentals = stoi(customerInfoList.getIndex(5));
                cout << "Customer account type:" << customerInfoList.getIndex(6) << endl;
                accountType = convertStringToAccountType(customerInfoList.getIndex(6));
                Customer customer(customerId,customerName,customerAddress,customerPhone,numberOfRentals,accountType);
                add(customer);
                cout << endl;
            }
        }
    }
}