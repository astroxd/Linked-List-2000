#include <iostream>
#include "ClientList.h"
#include "ProblemList.h"
#include "Handler.h"
using namespace std;

void printName(){
    string rows[6] = {
        R"(    __    _       __            __   __    _      __     ___   ____  ____  ____)",
        R"(   / /   (_)___  / /_____  ____/ /  / /   (_)____/ /_   |__ \ / __ \/ __ \/ __ \)",
        R"(  / /   / / __ \/ //_/ _ \/ __  /  / /   / / ___/ __/   __/ // / / / / / / / / /)",
        R"( / /___/ / / / / ,< /  __/ /_/ /  / /___/ (__  ) /_    / __// /_/ / /_/ / /_/ /)",
        R"(/_____/_/_/ /_/_/|_|\___/\__,_/  /_____/_/____/\__/   /____/\____/\____/\____/)"
    };

    for (int i = 0; i<6; i++){
        cout<<"\033[1;3"<<i+1<<"m"<<rows[i]<<endl;
    }
    cout<<"\033[0;0m";
}


int main()
{

    system("Color");
    printName();
    ClientList clients;
    ProblemList problems;
    const char *text =
        R"(1. Aggiungi un nuovo cliente
2. Elimina cliente
3. Stampa lista clienti
4. Ordina lista clienti (A->Z)
5. Ordina lista clienti (Z->A)
6. Aggiung problema al cliente
7. Risolvi problema al cliente (ex Rimuovi problema al cliente)
8. Trova posizione di un cliente
9. Stampa i problemi di un cliente
10. Stampa i problemi di tutti i clienti
12. Esci
)";

const char *test_feature = "\033[1;36m11. Test Feature(works only with at least 1 client)\033[0;0m";
    int scelta;
    string phone_number;
    char newProblemChoice;
    string problem_phone_number;
    Client* cacca;
    do
    {
        cout << text;
        cout<<test_feature<<endl;
        cout << "Scelta: ";
        cin >> scelta;
        if(!cin.good()){
            cin.clear();
            cin.ignore(INTMAX_MAX, '\n');
            scelta = 12;
        }
        switch (scelta)
        {
        case 1:
            //* Done
            clients.AddNode();
            break;
        case 2:
            //* Done
            phone_number = clients.DeleteNode();
            if (phone_number != "0")
            {
                problems.DeleteAllOccurences(phone_number);
            };
            break;
        case 3:
            //* Done
            clients.PrintList();
            break;
        case 4:
            //* Done
            clients.SetReorder(1);
            clients.Reorder();
            clients.PrintList();
            break;
        case 5:
            //* Done
            clients.SetReorder(-1);
            clients.Reorder();
            clients.PrintList();
            break;
        case 6:
            //* Done
            problems.AddNode(clients.AddClientProblem());
            break;
        case 7:
            //* Done
            // problems.DeleteNode(clients.RemoveClientProblem());
            problem_phone_number = problems.SolveClientProblem(clients.RemoveClientProblem());
            if(problem_phone_number != "0"){
                clients.RemoveClientProblem(problem_phone_number);
            };
            break;
        case 8:
            //* Done
            clients.Find();
            break;
        case 9:
            //* Done
            cout << "Ecco la lista di tutti i clienti\n";
            clients.PrintList();
            problems.PrintClientProblems();
            break;
        case 10:
            //* Done
            problems.PrintList();
            break;
        case 11:
            cacca =  clients.test();
            cout<<cacca->getName();
            cout<<cacca->getProblems();
            cacca->addProblem();
            cout<<cacca->getProblems();

            break;
        case 12:
            Output("Arrivederci");
            break;
        default:
            Error("Hai inserito un numero non valido");
            break;
        }
    } while (scelta != 12);
    // system("pause");
    getchar();
    return 0;
}