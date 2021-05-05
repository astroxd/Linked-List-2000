#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "Problem.h"
class Client{
    std::string phone_number;
    std::string name;
    std::string surname;
    size_t problems;
    public:
    Client();
    void CustomConstructor();
    Client(std::string phone_number, std::string name, std::string surname, int problems);

    void setPhoneNumber();
    void setName();
    void setSurname();
    void setSurname(std::string surname);

    Problem addProblem();
    void removeProblem();
    
    std::string getPhoneNumber();
    std::string getName();
    std::string getSurname();
    int getProblems();


};

#endif