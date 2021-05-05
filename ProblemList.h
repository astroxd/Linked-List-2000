#ifndef PROBLEMLIST_H
#define PROBLEMLIST_H
#include "Problem.h"
class ProblemList{
    private:
    struct node
    {
        Problem problema;
        node* next;
    };
    typedef struct node* nodePtr;
    nodePtr head;
    nodePtr curr;
    nodePtr temp;
    public:
    ProblemList();
    void AddNode();
    void AddNode(Problem problem);
    void DeleteNode(std::string phone_number);
    void DeleteAllOccurences(std::string phone_number);

    std::string SolveClientProblem(std::string phone_number);


    void PrintList();
    void PrintClientProblems();
    void PrintClientProblems(std::string phone_number);
    bool IsDateValid(std::string date);
    

};

#endif
