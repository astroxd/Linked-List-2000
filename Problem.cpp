#include <iostream>
#include <map>
#include "Problem.h"
#include "Date.h"
#include "DateParser.h"
#include "Handler.h"

using namespace std;
Problem::Problem(){};
Problem::Problem(string phone_number) {
    Problem::phone_number = phone_number;
    if(phone_number != "0"){
        Problem::setDate();
        Problem::solved = 'N';
    }
    
}
Problem::Problem(string phone_number, Date date, char solved){
    Problem::phone_number = phone_number;
    Problem::date = date;
    Problem::solved = solved;
}

void Problem::setPhoneNumber(){
    string newTelefono;
        do{
            cout<<"Inserisci le 10 cifre del numero di telefono:\n";
            cin>>newTelefono;
            if(newTelefono.length() < 10){
                Error("Le cifre del numero sono meno di 10");
            }
            else if(newTelefono.length()>10){
                Error("Le cifre del numero sono più di 10");
            }
            else{
                phone_number = newTelefono;
            }
        }while(newTelefono.length() != 10);
        
}
void Problem::setDate(){
    string newDate;
    bool isDateValid = false;
    while(isDateValid == false){
        cout<<"Inserisci la data in questo formato:\t(gg/mm/aaaa)\n";
        cin>>newDate;
        if(scanner(newDate)){
            DateParser parser(newDate);
            date = Date(parser.getDay(), parser.getMonth(), parser.getYear());
            isDateValid = true;
        }
        else{
            Error("Formato sbagliato");
        }
    }
}
//* Check if is a valid date
int Problem::scanner(string newDate){
    if(newDate.length() != 10){
        return 0;
    };
    
    map<string, int> months  = {
            {"01", 31},
            {"02", 28},
            {"03", 31},
            {"04", 30},
            {"05", 31},
            {"06", 30},
            {"07", 31},
            {"08", 31},
            {"09", 30},
            {"10", 31},
            {"11", 30},
            {"12", 31}
    };
    string day = "";
    string month = "";
    string year = "";
    string firstDigit;
    string secondDigit;

    //*MONTH
    firstDigit = newDate[3]; 
    secondDigit = newDate[4];
    month = firstDigit.append(secondDigit);
    //*check if month is valid
    if(months.find(month) == months.end()){
        Error("Il mese non va bene");
        return 0;
    }
    //*YEAR
    for(int i = 6; i<10; i++){
        firstDigit = newDate[i];
        year.append(firstDigit);
    }
    //*check if year is a number
    try
    {   
        stoi(year);
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
        Error("Anno inserito ["+year+"] non valido");
        return 0;
    }
    
    //*check if is a leap year
    if(month == "02"){
        if((stoi(year) % 4 == 0) && (stoi(year) % 100 != 0) || (stoi(year) % 400 == 0)){
            months["02"] = 29;
        } 
    }

    //*DAY
    firstDigit = newDate[0];
    secondDigit = newDate[1];
    day = firstDigit.append(secondDigit);
    //*check if day is a number
    try
    {
        stoi(day);
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
        Error("Giorno inserito ["+day+"] non valido");
        return 0;
    }
    
    //*check if day is contained in month
    if(stoi(day) > months[month]){
        Error("I giorni inseriti ["+day+"] superano il numero massimo di giorni nel mese ["+month+"]");
        return 0;
    }

    return 1;
}
void Problem::setSolved(bool isSolved){
    isSolved ? solved = 'S' : solved = 'N';
}
string Problem::getPhoneNumber(){
    return phone_number;
}
string Problem::getDate(){
    string string_date = date.getStringDate();
    return string_date;
}
char Problem::getSolved(){
    return solved;
}