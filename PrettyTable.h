#ifndef PRETTY_TABLE_H
#define PRETTY_TABLE_H
#include <iostream>
#include <vector>
#include <map>
#include <string>

// const std::string PRETTYTABLE_BLACK = "\033[0;30m";
// const std::string PRETTYTABLE_RED = "\033[0;31m";
// const std::string PRETTYTABLE_GREEN = "\033[0;32m";
// const std::string PRETTYTABLE_YELLOW = "\033[0;33m";
// const std::string PRETTYTABLE_BLUE = "\033[0;34m";
// const std::string PRETTYTABLE_MAGENTA = "\033[0;35m";
// const std::string PRETTYTABLE_CYAN = "\033[0;36m";
// const std::string PRETTYTABLE_WHITE = "\033[0;37m";
// const std::string PRETTYTABLE_RESET = "\033[0;0m";

class PrettyTable
{
private:
    std::vector<std::string> fields;
    std::vector<int> max_lengths;
    std::vector<std::string> parts;
    std::string contentColor;
    std::string borderColor;
    std::map<std::string, std::string> validColors{
        {"BLACK", "\033[0;30m"},
        {"RED", "\033[0;31m"},
        {"GREEN", "\033[0;32m"},
        {"YELLOW", "\033[0;33m"},
        {"BLUE", "\033[0;34m"},
        {"MAGENTA", "\033[0;35m"},
        {"CYAN", "\033[0;36m"},
        {"WHITE", "\033[0;37m"},
        {"RESET", "\033[0;0m"},
    };

public:
    static const std::string _BLACK;
    static const std::string _RED;
    static const std::string _GREEN;
    static const std::string _YELLOW;
    static const std::string _BLUE;
    static const std::string _MAGENTA;
    static const std::string _CYAN;
    static const std::string _WHITE;
    static const std::string _RESET;

    PrettyTable();
    ~PrettyTable();

    void AddColumn(std::string field, int max_length);
    void AddRow(std::string inputString);

    void SetContentColor(std::string colorCode);
    void SetBorderColor(std::string colorCode);

    void PrintHeaders();
    void PrintRows();
    void PrintFooter();

    void PrintTable();
};
#endif