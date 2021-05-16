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
}



