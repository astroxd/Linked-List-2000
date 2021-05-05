#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>

class Date{
    std::string day;
    std::string month;
    std::string year;
    public:
    Date();
    Date(std::string gg, std::string mm, std::string aaaa);
    std::string getDay();
    std::string getMonth();
    std::string getYear();
    std::string getStringDate();
};

#endif
