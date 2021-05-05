#ifndef CLIENTLIST_H
#define CLIENTLIST_H
#include "Client.h"
#include "Problem.h"
class ClientList{
    private:
    struct node
    {
        Client client;
        node* next;
    };
    typedef struct node* nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;
    int order;//* Used for sort cryteria
    public:
    ClientList();

    void AddNode();
    std::string DeleteNode();

    void PrintList();

    Problem AddClientProblem();
    std::string RemoveClientProblem();
    void RemoveClientProblem(std::string phone_number);

    void SetReorder(int i);
    void Reorder();
    
    void Find();

    Client* test();
};

#endif
