//
// Created by phuoc on 21/05/2021.
//

#ifndef TESTPROJECT_MODEL_H
#define TESTPROJECT_MODEL_H

#include "../utils/StringType.cpp"

using namespace std;
using namespace string_conversion;
class Model{

private:
    string _id;

public:
    virtual const string &getId() const{
        return this->_id;
    };

    virtual void setId(const string &id){};
};
#endif //TESTPROJECT_MODEL_H


