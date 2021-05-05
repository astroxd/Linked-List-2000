#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include <string>
#include "Date.h"
class Problem{
    private:
    std::string phone_number;
    Date date;
    char solved;
    public:
    Problem();
    Problem(std::string phone_number);
    Problem(std::string phone_number, Date date, char solved);

    void setPhoneNumber();
    void setDate();
    int scanner(std::string newDate);
    void setSolved(bool isSolved);
    
    std::string getPhoneNumber();
    std::string getDate();
    char getSolved();
};


#endif