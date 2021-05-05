#include <iostream>
#include "Client.h"
#include "Handler.h"
#include "Problem.h"

using namespace std;

Client::Client(){};
void Client::CustomConstructor(){
    Client::setSurname();
    Client::setName();
    Client::setPhoneNumber();
    Client::problems = 0;
}
//* Cool but not used
Client::Client(string phone_number, string name, string surname, int problems){
    Client::phone_number = phone_number.length() == 10 ? phone_number : "Unknown Number";
    Client::name = name.length() <= 20 && name.length() > 0 ? name : "Unknown Name";
    Client::surname = surname.length() <= 20 && surname.length() > 0 ? surname : "Unknown Surname";
    Client::problems = problems >= 0 ? problems : 0;
}
void Client::setPhoneNumber(){
    string newPhoneNumber;
    do{
        cout<<"Inserisci le 10 cifre del numero di telefono:\n";
        cin>>newPhoneNumber;
        if(newPhoneNumber.length() < 10){
            Error("Le cifre del numero sono meno di 10");
        }
        else if(newPhoneNumber.length() > 10){
            Error("Le cifre del numero sono maggiori di 10");
        }
        else{
            phone_number = newPhoneNumber;
        }
    }while(newPhoneNumber.length() != 10);
}
void Client::setName(){
    string newName;
    cout<<"Inserisci al massimo i 20 caratteri del nome:\n";
        cin>>newName;
        if(newName.length() > 20){
            Error("I caratteri del nome sono maggiori di 20");
            Client::setName();
        }
        else{
            name = newName;
        }
    // do{
    //     cout<<"Inserisci al massimo i 20 caratteri del nome:\n";
    //     cin>>newName;
    //     if(newName.length() > 20){
    //         Error("I caratteri del nome sono maggiori di 20");
    //     }
    //     else{
    //         name = newName;
    //     }
    // }while(newName.length() > 20);
}
void Client::setSurname(){
    string newSurname;
    do{
        cout<<"Inserisci al massimo i 20 caratteri del cognome:\n";
        cin>>newSurname;
        if(newSurname.length() > 20){
            Error("I caratteri del cognome sono maggiori di 20");
        }
        else{
            surname = newSurname;
        }
    }while(newSurname.length() > 20);
}
void Client::setSurname(string surname){
    Client::surname = surname;
}
Problem Client::addProblem(){
    Problem problem(phone_number);
    problems++;
    return problem;
}
void Client::removeProblem(){
    problems--;
}
string Client::getPhoneNumber(){
    return phone_number;
}
string Client::getName(){
    return name;
}
string Client::getSurname(){
    return surname;
}
int Client::getProblems(){
    return problems;
}

