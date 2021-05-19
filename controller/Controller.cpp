//
// Created by phuoc on 13/05/2021.
//

#include "Controller.h"

// Load database
void Controller::loadDatabase() {

}

// Main menu:
void Controller::showMenu() {
    cout << " Welcome to Genie’s video store \n"
            "Enter an option below. \n"
            "1. Add a new item, update or delete an existing item \n"
            "2. Add new customer or update an existing customer \n"
            "3. Promote an existing customer\n"
            "4. Rent an item\n"
            "5. Return an item \n"
            "6. Display all items \n"
            "7. Display out-of-stock items \n"
            "8. Display all customers \n"
            "9. Display group of customers \n"
            "10. Search items or customers\n"
            "Exit. " << endl;
}

// Get user choices:
void Controller::workWithChoice() {
    bool programRun = true;
    string userChoice = "0";
    while (programRun) {
        showMenu();
        cout << "Your choice:";
        cin >> userChoice;
        cout << endl;
        if (userChoice == "1") { // 1. Add a new item, update or delete an existing item
            addUpdateDeleteItem();
        } else if (userChoice == "2") { // 2. Add new customer or update an existing customer
            addUpdateDeleteCustomer();
        } else if (userChoice == "3") { // 3. Promote an existing customer
            promoteAnExistingCustomer();
        } else if (userChoice == "4") { // 4. Rent an item
            rentItem();
        } else if (userChoice == "5") { // 5. Return an item
            returnItem();
        } else if (userChoice == "6") { // 6. Display all items
            displayAllItem();
        } else if (userChoice == "7") { // 7. Display out-of-stock items
            displayOutOfStockItem();
        } else if (userChoice == "8") { // 8. Display all customers
            displayAllCustomer();
        } else if (userChoice == "9") { // 9. Display group of customers
            displayGroupOfCustomer();
        } else if (userChoice == "10") { // 10. Search items or customers
            searchItemOrCustomer();
        } else if (toLowerCase(userChoice) == "exit") { // Exit: Save changes and exit
            programRun = false;
        } else {
            cout << "Please type again..." << endl;
        }
    }

}

// 1. Add a new item, update or delete an existing item
void Controller::addUpdateDeleteItem() {
    bool isRunning = true;
    string userChoice = "0";
    while (isRunning) {
        cout << " 1.Add item \n"
                " 2.Update item \n"
                " 3.Delete item \n"
                " Type 'return' or 'back' to return to main menu " << endl;
        cout << "Your choice:";
        cin >> userChoice;
        cout << endl;
        if (userChoice == "1") { // Add customer
            addItem();
        } else if (userChoice == "2") { // Update customer
            updateItem();
        } else if (userChoice == "3") { // Delete customer
            deleteItem();
        } else if (toLowerCase(userChoice) == "return" or toLowerCase(userChoice) == "back") {
            isRunning = false;
        } else {
            cout << "Please type again..." << endl;
        }
    }
}

// 2. Add new customer or update an existing customer
void Controller::addUpdateDeleteCustomer() {
    bool isRunning = true;
    string userChoice = "0";
    while (isRunning) {
        cout << " 1.Add customer \n"
                " 2.Update customer \n"
                " 3.Delete customer \n"
                " Type 'return' or 'back' to return to main menu " << endl;
        cout << "Your choice:";
        cin >> userChoice;
        cout << endl;
        if (userChoice == "1") { // Add customer
            addCustomer();
        } else if (userChoice == "2") { // Update customer
            updateCustomer();
        } else if (userChoice == "3") { // Delete customer
            deleteCustomer();
        } else if (toLowerCase(userChoice) == "return" or toLowerCase(userChoice) == "back") {
            isRunning = false;
        } else {
            cout << "Please type again..." << endl;
        }
    }
}

// 3. Promote an existing customer
void Controller::promoteAnExistingCustomer() {
    string customerId;
    string inputAccountString;
    AccountType newAccountType;
    cout << "Type the customer id to promote:";
    cin >> customerId;
    cout << endl;
    cout << "Which role do you want to promote?";
    cin >> inputAccountString;
    cout << endl;
    customerId = toUpperCase(customerId);
    inputAccountString = toLowerCase(inputAccountString);
    if (inputAccountString == "regular") {
        newAccountType = REGULAR;
    } else {
        newAccountType = VIP;
    }
    service.promoteCustomer(customerId, newAccountType);
}

// 4. Rent an item
void Controller::rentItem() {
    cout << "Rent item !" << endl;
    string customerId;
    string itemId;
    cout << "ID of renter:";
    cin >> customerId;
    cout << endl;
    cout << "ID of rental:";
    cin >> itemId;
    cout << endl;
    service.rentWithAuthentication(customerId, itemId);
}

// 5. Return an item
void Controller::returnItem(){
    cout << "Return item !" << endl;
    string customerId;
    string itemId;
    cout << "ID of renter:";
    cin >> customerId;
    cout << endl;
    cout << "ID of rental:";
    cin >> itemId;
    cout << endl;
    service.customerReturnAnItem(customerId, itemId);
}

// 6. Display all items
void Controller::displayAllItem() {
    service.showAllItem();
}

// 7. Display out-of-stock items
void Controller::displayOutOfStockItem() {
    service.showOutOfStockItem();
}


// 8. Display all customers
void Controller::displayAllCustomer() {
    service.showAllCustomer();
}

// 9. Display group of customers
void Controller::displayGroupOfCustomer(){
    string stringAccountType;
    AccountType inputAccountType = convertStringToAccountType(stringAccountType);
    service.showCustomersByGroup(inputAccountType);
}

// 10. Search items or customers
void Controller::searchItemOrCustomer() {

}

// 11. Save changes and exit:
void Controller::saveAndExit() {
    cout << "Saving data...";
}

// Main program:
void Controller::runProgram() {
    loadDatabase();
    workWithChoice();
}

// Protected Functions:

Customer Controller::getCustomerInput() {
    string inputId;
    string inputName;
    string inputAddress;
    string inputPhone;
    string stringAccountType;
    cout << "Type customer id:";
    cin >> inputId;
    cout << endl;
    cout << "Type customer name:";
    cin >> inputName;
    cout << endl;
    cout << "Type customer address:";
    cin >> inputAddress;
    cout << endl;
    cout << "Type customer phone:";
    cin >> inputPhone;
    cout << endl;
    cout << "Type customer account type ( guess, regular, vip, default = guess):";
    cin >> stringAccountType;
    cout << endl;

    AccountType inputAccountType = convertStringToAccountType(stringAccountType);
    return Customer(inputId, inputName, inputAddress, inputPhone, inputAccountType);
}

Item Controller::getItemInput() {
    // Normal field :
    string inputId;
    string inputTitle;
    int inputNumberOfCopies = 0;
    int inputRentalFee = 0;
    // Enum field :
    RentalType inputRentalType;
    string stringRentalType;
    LoanType inputLoanType;
    string stringLoanType;

    cout << "Type new Id:";
    cin >> inputId;
    cout << endl;
    cout << "Type new Title:";
    cin >> inputTitle;
    cout << endl;
    cout << "Type new Number Of Copies:";
    cin >> inputNumberOfCopies;
    cout << endl;
    cout << "Type new Rental Fee:";
    cin >> inputRentalFee;
    cout << endl;
    cout << "Type new Loan Type ( 2-day, 1-week , default = 2-day):";
    cin >> stringLoanType;
    cout << endl;
    cout << "Type new Rental Type ( record, dvd, game , default = record ):";
    cin >> stringRentalType;
    cout << endl;

    // check loan type
    inputLoanType = convertStringToLoanType(stringLoanType);
    // check rental type:
    inputRentalType = convertStringToRentalType(stringRentalType);

    if (inputRentalType == GAME) {
        return Item(inputId, inputTitle, inputRentalType, inputLoanType, inputNumberOfCopies, inputRentalFee);
    } else {
        GenreType inputGenreType;
        string stringGenreType;
        cout << "Type new Genre Type ( action, horror, drama, comedy - default = action):";
        cin >> stringGenreType;
        cout << endl;
        // Check genre
        inputGenreType = convertStringToGenreType(stringGenreType);
        return Item(inputId, inputTitle, inputRentalType, inputLoanType, inputNumberOfCopies, inputRentalFee,
                    inputGenreType);
    }
}

void Controller::addItem() {
    Item newItem = getItemInput();
    service.add(newItem);
}

void Controller::addCustomer() {
    Customer newCustomer = getCustomerInput();
    service.add(newCustomer);
}

void Controller::updateItem() {
    string itemId;
    cout << "Type the item ID to update:";
    cin >> itemId;
    cout << endl;
    cout << "Please type new information of this item, you may change the ID, too" << endl;
    Item newInformation = getItemInput();
    service.updateItemById(itemId, newInformation);
}

void Controller::updateCustomer() {
    string customerId;
    cout << "Type the item ID to update:";
    cin >> customerId;
    cout << endl;
    cout << "Please type new information of this customer, you may change the ID, too" << endl;
    Item newInformation = getItemInput();
    service.updateItemById(customerId, newInformation);
}

void Controller::deleteItem() {
    string id;
    cout << "Type the item id to delete:";
    cin >> id;
    cout << endl;
    service.deleteItemById(id);
}

void Controller::deleteCustomer() {
    string id;
    cout << "Type the customer id to delete:";
    cin >> id;
    cout << endl;
    service.deleteCustomerById(id);
}
