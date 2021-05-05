#include <iostream>
#include "Date.h"

using namespace std;
Date::Date(){}

Date::Date(string gg, string mm, string aaaa){
    day = gg;
    month = mm;
    year = aaaa;
}
string Date::getDay(){
    return day;
}
string Date::getMonth(){
    return month;
}
string Date::getYear(){
    return year;
}
string Date::getStringDate(){
    return day+"/"+month+"/"+year;
}
