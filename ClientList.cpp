#include <iostream>
#include <iomanip>
#include "ClientList.h"
#include "Handler.h"
#include "PrettyTable.h"
// #include "windows.h"

using namespace std;
ClientList::ClientList(){
    head = nullptr;
    curr = nullptr;
    temp = nullptr;
    order = 1;

}
void ClientList::AddNode(){
    system("clear");
    nodePtr data = new node;
    data->next = nullptr;
    //* Create new client
    data->client.CustomConstructor();
    curr = head;
    //* If new client's phone number is already in the list or all the list's items were passed break
    while(curr != nullptr && curr->client.getPhoneNumber() != data->client.getPhoneNumber()){
        curr = curr->next;
    }
    //* If passed all the list then add new client at the end
    if(curr == nullptr){
        if(head != nullptr){
            curr = head;
            while(curr->next != nullptr){
                curr = curr->next;
            }
            curr->next = data;
        }
        else{
            head = data;
        }
        system("clear");
        Output("Client: "+data->client.getSurname()+" "+data->client.getName()+" "+data->client.getPhoneNumber()+" was created");
        ClientList::Reorder();
    }
    //* new client's phone number is already in the list
    else{
        system("clear");
        Error("Il numero di telefono inserito ["+data->client.getPhoneNumber()+"] è già presente nella lista");
    }
    
}

string ClientList::DeleteNode(){
    system("clear");
    string phone_number;
    cout<<"Eccoti la lista di tutti gli utenti e i loro relativi numeri di telefono\n";
    ClientList::PrintList();
    cout<<"Inserisci il numero di telefono dell'utente che vuoi eliminare:\n";
    cin>>phone_number;

    nodePtr delPtr = nullptr;
    temp = head;
    curr = head;

    //* If inserted phone number is already in the list or all the list was passed then break
    while(curr != nullptr && curr->client.getPhoneNumber() != phone_number){
        temp = curr;
        curr = curr->next;
    }
    //* If passed all the list
    if(curr == nullptr){
        Error("Il cliente ["+phone_number+"] non era nella lista");
        delete delPtr;
        return "0";
    }
    //* If inserted phone number was in the list
    else{
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        if(delPtr == head){
            head = head->next;
            temp = nullptr;
        }
        delete delPtr;
        Output("Il cliente ["+phone_number+"] è stato rimosso con successo");
        return phone_number;
    }
}

void ClientList::PrintList(){
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // SetConsoleTextAttribute(hConsole, 13);
    system("clear");
    curr = head;
    //* Create new printing table
    PrettyTable pt;
    pt.AddColumn("Surname", 20);
    pt.AddColumn("Name", 20);
    pt.AddColumn("Phone", 10);
    pt.AddColumn("#Problems", 9);
    pt.SetContentColor(PrettyTable::_CYAN);
    pt.SetBorderColor(PrettyTable::_MAGENTA);

    //* Pass all the list adding each client to the printing table
    while(curr != nullptr){
        pt.AddRow(curr->client.getSurname()+","
        +curr->client.getName()+","
        +curr->client.getPhoneNumber()+","
        +to_string(curr->client.getProblems()));
        curr = curr->next;
    }
    //* Printing table
    pt.PrintTable();
    // SetConsoleTextAttribute(hConsole, 7);
}


Problem ClientList::AddClientProblem(){
    system("clear");
    string phone_number;
    cout<<"Eccoti la lista di tutti gli utenti e i loro relativi numeri di telefono\n";
    ClientList::PrintList();
    cout<<"Inserisci il numero di telefono dell'utente a cui vuoi aggiungere un problema:\n";
    cin>>phone_number;
    curr = head;
    
    //* If inserted phone number is already in the list or all the list was passed then break
    while(curr != nullptr && curr->client.getPhoneNumber() != phone_number){
        curr = curr->next;
    }
    //* If passed all the list return a non-valid problem
    if(curr == nullptr){
        Error("Il cliente ["+phone_number+"] non era nella lista");
        Problem problem("0");
        return problem;
    }
    //* If inserted phone number was in the list then return a problem with the same phone number and increment client problems counter
    else{
        Problem problem = curr->client.addProblem();
        return problem;
    }
    
}

string ClientList::RemoveClientProblem(){
    system("clear");
    string phone_number;
    cout<<"Eccoti la lista di tutti gli utenti e i loro relativi numeri di telefono\n";
    ClientList::PrintList();
    cout<<"Inserisci il numero di telefono dell'utente a cui vuoi rimuovere un problema:\n";
    cin>>phone_number;
    curr = head;
    
    //* If inserted phone number is already in the list or all the list was passed then break
    while(curr != nullptr && curr->client.getPhoneNumber() != phone_number){
        curr = curr->next;
    }
    //* If passed all the list return a non-valid phone number
    if(curr == nullptr){
        Error("Il cliente ["+phone_number+"] non era nella lista");
        return "0";
    }
    else{
        //* If client has more than 0 problems then return its phone number
        if(curr->client.getProblems() > 0){
            return curr->client.getPhoneNumber();
        }
        //* If client has 0 problem return a non-valid phone number
        else{
            Output("Il cliente: "+curr->client.getSurname()+" "+curr->client.getName()+" "+curr->client.getPhoneNumber()+" non ha problemi all'attivo");
            return "0";
        }
        
    }

}

void ClientList::RemoveClientProblem(string phone_number){
    curr = head;
    //* Since this phone number comes from a real client we don't need checks
    while(curr != nullptr){
        if(curr->client.getPhoneNumber() == phone_number){
            curr->client.removeProblem();//* Decrement client problems counter
            break;
        }
    }
}

//* Change reoder cryteria
void ClientList::SetReorder(int i){
    order = i;
}

//* order = 1 A->Z
//* order = -1 Z->A
void ClientList::Reorder(){
    Client data;
    temp = head;
    curr = head;
    
    while(curr != nullptr){
        temp = curr->next;

        while(temp != nullptr){
            if(order == 1){
                if(curr->client.getSurname() > temp->client.getSurname()){
                    data = curr->client;
                    curr->client = temp->client;
                    temp->client = data;
                }
                temp = temp->next;
            }
            else if(order == -1){
                if(curr->client.getSurname() < temp->client.getSurname()){
                    data = curr->client;
                    curr->client = temp->client;
                    temp->client = data;
                }
                temp = temp->next;
            }
            
        }
        curr = curr->next;
    }
}
void ClientList::Find(){
    system("clear");
    string phone_number;
    int i = 0;    
    curr = head;
    cout<<"Eccoti la lista di tutti gli utenti e i loro relativi numeri di telefono\n";
    ClientList::PrintList();
    cout<<"Inserisci il numero di telefono dell'utente che vuoi trovare:\n";
    cin>>phone_number;
    //* If inserted phone number is already in the list or all the list was passed then break
    while(curr != nullptr && curr->client.getPhoneNumber() != phone_number){
        i++;
        curr = curr->next;
    }
    //* If passed all the list
    if(curr == nullptr){
        Error("Il numero inserito ["+phone_number+"] non era nella lista");
    }
    //* If inserted phone number was in the list display its position
    else{
        Output("Il cliente con numero di telefono ["+phone_number+"] si trova nella posizione ["+to_string(i)+"] della lista");
    }

}

Client* ClientList::test(){
    curr = head;
    return &curr->client;
}

