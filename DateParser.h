#ifndef DATEPARSER_H
#define DATEPARSER_H
#include <iostream>
#include <string>

class DateParser{
    std::string date;
    std::string delimiter = "/";
    std::string parts[3];
    public:
    DateParser(std::string d);
    void parse();
    std::string getDay();
    std::string getMonth();
    std::string getYear();
};

#endif

