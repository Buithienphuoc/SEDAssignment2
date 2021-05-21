//
// Created by phuoc on 11/05/2021.
//


#include <sstream>

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
        theString = toUpperCase(theString);
        cout << "genre type:" << theString << endl;
        if (theString == "ACTION"){
            return ACTION;
        } else if (theString == "HORROR"){
            return HORROR;
        } else if (theString == "DRAMA"){
            return DRAMA;
        } else if (theString == "COMEDY"){
            return COMEDY;
        } else {
            cout << "Wrong genre type input, use default" << endl;
            return COMEDY;
        }
    }

    AccountType convertStringToAccountType(string theString){
        theString = toUpperCase(theString);
        cout << "Role in function:" << theString << endl;
        if (theString == "GUEST"){
            return GUEST;
        } else if (theString == "REGULAR"){
            return REGULAR;
        } else if (theString == "VIP"){
            return VIP;
        } else {
            cout << "Wrong customer type input, use default" << endl;
            return GUEST;
        }
    }

    LinkedList<string> splitString(const string& str)
    {
        LinkedList<string> wordList;
        stringstream ss(str);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            wordList.add(substr);
        }
        return wordList;
    }

    const char* ws = " \t\n\r\f\v";

// trim from end of string (right)
    inline std::string rtrim(string s, const char* t = ws){
        s.erase(s.find_last_not_of(t) + 1);
        return s;
    }

// trim from beginning of string (left)
    inline string ltrim(string s, const char* t = ws){
        s.erase(0, s.find_first_not_of(t));
        return s;
    }

// trim from both ends of string (right then left)
    inline std::string trim(std::string s, const char* t = ws){
        return ltrim(rtrim(s, t), t);
    }
}



