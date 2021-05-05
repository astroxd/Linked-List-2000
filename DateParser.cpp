#include <iostream>
#include "DateParser.h"
#include <string>
using namespace std;

DateParser::DateParser(string d){
    date = d;
    DateParser::parse();
}
void DateParser::parse(){

    size_t pos = 0;
    size_t i = 0;
    string token;
    while ((pos = date.find(delimiter)) != string::npos){
        token = date.substr(0, pos);
        parts[i] = token;
        date.erase(0, pos + delimiter.length());
        i++;
    }
    parts[i] = date;
}

string DateParser::getDay(){
    return parts[0];
}
string DateParser::getMonth(){
    return parts[1];
}
string DateParser::getYear(){
    return parts[2];
}