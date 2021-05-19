//
// Created by phuoc on 11/05/2021.
//


using namespace std;

namespace string_conversion {
    string toLowerCase(string myString){
        for(int index = 0; index < myString.length(); index++){
            myString[index] = tolower(myString[index]);
        }
        return myString;
    }
    string toUpperCase(string myString){
        for(int index = 0; index < myString.length(); index++){
            myString[index] = toupper(myString[index]);
        }
        return myString;
    }
    RentalType convertStringToRentalType(string theString) {
        if (toLowerCase(theString) == "record"){
            return RECORD;
        } else if (toLowerCase(theString) == "dvd"){
            return DVD;
        } else if (toLowerCase(theString) == "game"){
            return GAME;
        } else {
            cout << "Wrong rental type input, use default" << endl;
            return RECORD;
        }
    }

    LoanType convertStringToLoanType(string theString) {
        if (theString == toLowerCase("2-day")){
            return TWODAYLOAN;
        } else if (theString == toLowerCase("1-week")){
            return ONEWEEKLOAN;
        } else {
            cout << "Wrong loan type input, use default" << endl;
            return TWODAYLOAN;
        }
    }

    GenreType convertStringToGenreType(string theString){
        if (toUpperCase(theString) == "ACTION"){
            return ACTION;
        } else if (toUpperCase(theString) == "HORROR"){
            return HORROR;
        } else if (toUpperCase(theString) == "DRAMA"){
            return DRAMA;
        } else if (toUpperCase(theString) == "COMEDY"){
            return COMEDY;
        } else {
            cout << "Wrong genre type input, use default" << endl;
            return COMEDY;
        }
    }

    AccountType convertStringToAccountType(string theString){
        return GUEST;
    }
}



