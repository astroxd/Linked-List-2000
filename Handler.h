#ifndef HANDLER_H
#define HANDLER_H
// #include <windows.h>

template<typename T> void Error(T e){
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout<<"\033[1;31mERROR\t"<<e<<"\033[0m\n";
    // SetConsoleTextAttribute(hConsole, 12);
    // std::cout<<"Error\t"<<e<<std::endl;
    // SetConsoleTextAttribute(hConsole, 7);
}
template<typename T> void Output(T out){
    // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout<<"\033[1;36mOUTPUT\t"<<out<<"\033[0m\n";
    // SetConsoleTextAttribute(hConsole, 11);
    // std::cout<<"OUTPUT\t"<<out<<std::endl;
    // SetConsoleTextAttribute(hConsole, 7);
}

#endif