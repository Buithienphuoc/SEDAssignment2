//
// Created by phuoc on 30/04/2021.
//

#ifndef TESTPROJECT_ITEM_H
#define TESTPROJECT_ITEM_H

#include "iostream"
#include "../enumerations/RentalType.cpp"
#include "../enumerations/LoanType.cpp"
#include "../enumerations/RentalStatusType.cpp"
#include "../enumerations/GenreType.cpp"
#include "../enumerations/AccountType.cpp"
#include "../utils/StringType.cpp"


using namespace std;
using namespace string_conversion;

class Item {
private:
    string id_;
    string title_;
    RentalType rentalType_;
    LoanType loanType_;
    int numberOfCopies_;
    int rentalFee_;
    GenreType genreType_;
    RentalStatusType rentalStatus_;

public:
    // Constructors:
    Item() = default;

    // Constructor for games:
    Item(const string &id, const string &title, RentalType rentalType, LoanType loanType, int numberOfCopies,
         int rentalFee) : id_(id), title_(title), rentalType_(rentalType), loanType_(loanType),
                          numberOfCopies_(numberOfCopies), rentalFee_(rentalFee) {
        if(numberOfCopies != 0){
            rentalStatus_ = AVAILABLE;
        }
        else {
            rentalStatus_ = BORROWED;
        }
    }

    // Constructor for DVD and Records
    Item(const string &id, const string &title, RentalType rentalType, LoanType loanType, int numberOfCopies,
         int rentalFee, GenreType genreType) : id_(id), title_(title), rentalType_(rentalType), loanType_(loanType),
                                               numberOfCopies_(numberOfCopies), rentalFee_(rentalFee),
                                               genreType_(genreType) {
        if(numberOfCopies != 0){
            rentalStatus_ = AVAILABLE;
        }
        else {
            rentalStatus_ = BORROWED;
        }
    }

    // GETTERS:

    const string &getId() const {
        return id_;
    }

    const string &getTitle() const {
        return title_;
    }

    RentalType getRentalType() const {
        return rentalType_;
    }

    LoanType getLoanType() const {
        return loanType_;
    }

    int getNumberOfCopies() const {
        return numberOfCopies_;
    }

    int getRentalFee() const {
        return rentalFee_;
    }

    RentalStatusType getRentalStatus() const {
        return rentalStatus_;
    }

    GenreType getGenreType() const {
        return genreType_;
    }

    // SETTERS:

    void setId(const string &id) {
        id_ = id;
    }

    void setTitle(const string &title) {
        title_ = title;
    }

    void setRentalType(RentalType rentalType) {
        rentalType_ = rentalType;
    }

    void setLoanType(LoanType loanType) {
        loanType_ = loanType;
    }

    void setNumberOfCopies(int numberOfCopies) {
        numberOfCopies_ = numberOfCopies;
    }

    void setRentalFee(int fee) {
        Item::rentalFee_ = fee;
    }

    void setRentalStatus(RentalStatusType status) {
        Item::rentalStatus_ = status;
    }

    void setGenreType(GenreType genreType) {
        genreType_ = genreType;
    }

    // COMPARE OPERATORS:

    bool operator==(const Item &rhs) const {
        return id_ == rhs.id_ &&
               title_ == rhs.title_ &&
               rentalType_ == rhs.rentalType_ &&
               loanType_ == rhs.loanType_ &&
               numberOfCopies_ == rhs.numberOfCopies_ &&
               rentalFee_ == rhs.rentalFee_ &&
               rentalStatus_ == rhs.rentalStatus_;
    }

    bool operator!=(const Item &rhs) const {
        return !(rhs == *this);
    }

    // TO STRING:

    string printLoanType() const {
        switch (loanType_) {
            case TWODAYLOAN:
                return "2-day";
            case ONEWEEKLOAN:
                return "1-week";
        }
        return nullptr;
    }

    string printRentalStatus() const {
        switch (rentalStatus_) {
            case BORROWED:
                return "record";
            case AVAILABLE:
                return "available";
        }
        return nullptr;
    }

    string printRentalType() const {
        switch (rentalType_) {
            case RECORD:
                return "Record";
            case DVD:
                return "DVD";
            case GAME:
                return "Game";
        }
        return nullptr;
    }

    string printGenreType() const{
        switch (genreType_) {
            case COMEDY:
                return "Comedy";
            case DRAMA:
                return "Drama";
            case HORROR:
                return "Horror";
            case ACTION:
                return "Action";
        }
        return "Wrong genre type";
    }


    friend ostream &operator<<(ostream &os, const Item &item) {
        if (item.getRentalType() == GAME){
            os << "id_: " << item.id_ << ", title_: " << item.title_ << ", rentalType_: " << item.printRentalType()
               << ", loanType_: " << item.printLoanType() << ", numberOfCopies_: " << item.numberOfCopies_
               << ", rentalFee_: " << item.rentalFee_ << ", status_:" << item.printRentalStatus();
        }
        else
        {
            os << "id_: " << item.id_ << ", title_: " << item.title_ << ", rentalType_: " << item.printRentalType()
               << ", loanType_: " << item.printLoanType() << ", numberOfCopies_: " << item.numberOfCopies_
               << ", rentalFee_: "
               << item.rentalFee_ << ", status_:" << item.printRentalStatus() << ", genreType_: " << item.printGenreType();
        }
        return os;
    }
};

#endif //TESTPROJECT_ITEM_H
