#include <iostream>
#include "ProblemList.h"
#include "Handler.h"
#include "PrettyTable.h"
#include <map>
using namespace std;

ProblemList::ProblemList()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
}

//! Cool but not used
void ProblemList::AddNode()
{
    nodePtr data = new node;
    data->next = NULL;
    data->problema.setPhoneNumber();
    data->problema.setDate();
    data->problema.setSolved(false);

    if (head != NULL)
    {
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = data;
    }
    else
    {
        head = data;
    }
}

void ProblemList::AddNode(Problem problem)
{   
    //* Problem is passed by ClientList::AddClientProblem()
    //* check if is a valid problem
    //* if true create the problem
    //* if false throw
    if (problem.getPhoneNumber() != "0")
    {
        nodePtr data = new node;
        data->next = NULL;
        data->problema = problem;

        if (head != NULL)
        {
            curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = data;
        }
        else
        {
            head = data;
        }

        Output("Problema creato con successo");
    }
    else
    {
        Error("Creazione problema fallita");
    }
}
//* Called by ClientList::DeleteNode() so no need to check phone number
//* Remove all the problem with the given phone number
void ProblemList::DeleteAllOccurences(string phone_number)
{
    nodePtr temp;
    nodePtr prev = nullptr;
    nodePtr next;

    for (temp = head; temp != nullptr; temp = next)
    {
        next = temp->next;

        if (temp->problema.getPhoneNumber() != phone_number)
        {
            prev = temp;
            continue;
        }

        if (prev != nullptr)
        {
            prev->next = next;
        }
        else
        {
            head = next;
        }
        delete temp;
        Output("The value " + phone_number + " was deleted PROBLEMA");
    }
}

//! We don't delete problem
//! We resolve them
void ProblemList::DeleteNode(string phone_number)
{
    //* Check if is a valid phone number
    //* If true delete problem
    //* If false throw 
    if (phone_number != "0")
    {
        string date;

        nodePtr delPtr = nullptr;
        temp = head;
        curr = head;

        do
        {   
            system("clear");
            cout << "Ecco tutti i problemi collegati a questo cliente\n";
            ProblemList::PrintClientProblems(phone_number);
            cout << "Inserisci la data del problema che vuoi eliminare:";
            cin >> date;

        } while (IsDateValid(date) == false);

        while (curr != nullptr && (curr->problema.getPhoneNumber() != phone_number || curr->problema.getDate() != date))
        {
            temp = curr;
            curr = curr->next;
        }
        if (curr == nullptr)
        {
            Error("Il problema ["+date + "] non era nella lista");
            delete delPtr;
        }
        else
        {
            delPtr = curr;
            curr = curr->next;
            temp->next = curr;
            if (delPtr == head)
            {
                head = head->next;
                temp = nullptr;
            }
            delete delPtr;
            Output("Il problema [" + date + "] è stato rimosso con successo");
        }
    }
}

//* phone number is passed by ClientList::RemoveClientProblem()
string ProblemList::SolveClientProblem(string phone_number)
{
    //* Check if is a valid phone number
    //* If true resolve problem
    //* If false return a non-valid phone number
    if (phone_number != "0")
    {
        string date;
        do
        {
            system("clear");
            cout << "Ecco tutti i problemi collegati a questo cliente\n";
            ProblemList::PrintClientProblems(phone_number);
            cout << "Inserisci la data del problema che vuoi eliminare:";
            cin >> date;
        } while (IsDateValid(date) == false);

        curr = head;
        while (curr != nullptr)
        {   
            //* Check if list problem phone number is equal to given phone number 
            //* Check if the dates are the sames
            //* Check if list problem is already solved
            if (curr->problema.getPhoneNumber() == phone_number && curr->problema.getDate() == date && curr->problema.getSolved() == 'N')
            {
                Output("Il problema è stato risolto con successo");
                curr->problema.setSolved(true);
                return phone_number;
            }
            else
            {
                curr = curr->next;
            }
        }
        Error("Nessun problema è stato creato nella data appena inserita ["+date+"]");
        return "0";
    }
    return "0";
}

void ProblemList::PrintList()
{
    system("clear");
    curr = head;
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // SetConsoleTextAttribute(hConsole, 10);
    //* Create new printing table
    PrettyTable pt;
    pt.AddColumn("Phone", 10);
    pt.AddColumn("Date", 10);
    pt.AddColumn("Solved", 6);
    pt.SetContentColor(PrettyTable::_GREEN);
    pt.SetBorderColor(PrettyTable::_YELLOW);
    //* Pass all the list adding each problem to the printing table
    while (curr != nullptr)
    {
        pt.AddRow(curr->problema.getPhoneNumber() + "," + curr->problema.getDate() + "," + curr->problema.getSolved());
        curr = curr->next;
    }
    //* Printing table
    pt.PrintTable();
    // SetConsoleTextAttribute(hConsole, 7);
}

void ProblemList::PrintClientProblems()
{   
    string phone_number;
    cout << "Inserisci il numero di telefono dell'utente di cui vuoi stampare i problemi:\n";
    cin >> phone_number;
    curr = head;
    bool clientExists = false;
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // SetConsoleTextAttribute(hConsole, 10);
    //* Create new printing table
    PrettyTable pt;
    pt.AddColumn("Phone", 10);
    pt.AddColumn("Date", 10);
    pt.AddColumn("Solved", 6);
    pt.SetContentColor(PrettyTable::_GREEN);
    pt.SetBorderColor(PrettyTable::_YELLOW);
    while (curr != nullptr)
    {   
        //* Check if list problem phone number is equal to the given phone number then add it to the printing table
        if (curr->problema.getPhoneNumber() == phone_number)
        {
            clientExists = true;//* If at least enter once print the table
            pt.AddRow(curr->problema.getPhoneNumber() + "," + curr->problema.getDate() + "," + curr->problema.getSolved());
        }
        curr = curr->next;
    }
    //* If at least enter once print the table
    if (clientExists)
    {
        pt.PrintTable();
    }
    //* If there are 0 problems with the given phone number don't print the table
    else
    {
        system("clear");
        Output("Il cliente non esiste o non ha mai avuto problemi");
    }
    // SetConsoleTextAttribute(hConsole, 7);
}

void ProblemList::PrintClientProblems(string phone_number)
{
    system("clear");
    curr = head;
    bool clientExists = false;
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // SetConsoleTextAttribute(hConsole, 10);
    //* Create new printing table
    PrettyTable pt;
    pt.AddColumn("Phone", 10);
    pt.AddColumn("Date", 10);
    pt.AddColumn("Solved", 6);
    pt.SetContentColor(PrettyTable::_GREEN);
    pt.SetBorderColor(PrettyTable::_YELLOW);
    while (curr != nullptr)
    {   
        //* Check if list problem phone number is equal to the given phone number then add it to the printing table
        if (curr->problema.getPhoneNumber() == phone_number)
        {
            clientExists = true;//* If at least enter once print the table
            pt.AddRow(curr->problema.getPhoneNumber() + "," + curr->problema.getDate() + "," + curr->problema.getSolved());
        }
        curr = curr->next;
    }
    //* If at least enter once print the table
    if (clientExists)
    {
        pt.PrintTable();
    }
    //* If there are 0 problems with the given phone number don't print the table
    else
    {
        Output("Il cliente non esiste o non ha mai avuto problemi");
    }
    // SetConsoleTextAttribute(hConsole, 7);
}

//* Check if date is in a valid format 
//* It's equal to Problem::scanner()
bool ProblemList::IsDateValid(string date)
{
    if (date.length() != 10)
    {
        return false;
    };

    map<string, int> months = {
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
        {"12", 31}};
    string day = "";
    string month = "";
    string year = "";
    string firstDigit;
    string secondDigit;

    //*MONTH
    firstDigit = date[3];
    secondDigit = date[4];
    month = firstDigit.append(secondDigit);
    //*check if month is valid
    if (months.find(month) == months.end())
    {
        Error("Il mese non va bene");
        return false;
    }
    //*YEAR
    for (int i = 6; i < 10; i++)
    {
        firstDigit = date[i];
        year.append(firstDigit);
    }
    //*check if year is a number
    try
    {
        stoi(year);
    }
    catch (const std::exception &e)
    {
        // std::cerr << e.what() << '\n';
        Error("Anno inserito [" + year + "] non valido");
        return false;
    }

    //*check if is a leap year
    if (month == "02")
    {
        if ((stoi(year) % 4 == 0) && (stoi(year) % 100 != 0) || (stoi(year) % 400 == 0))
        {
            months["02"] = 29;
        }
    }

    //*DAY
    firstDigit = date[0];
    secondDigit = date[1];
    day = firstDigit.append(secondDigit);
    //*check if day is a number
    try
    {
        stoi(day);
    }
    catch (const std::exception &e)
    {
        // std::cerr << e.what() << '\n';
        Error("Giorno inserito [" + day + "] non valido");
        return false;
    }

    //*check if day is contained in month
    if (stoi(day) > months[month])
    {
        Error("I giorni inseriti [" + day + "] superano il numero massimo di giorni nel mese [" + month + "]");
        return false;
    }

    return true;
}