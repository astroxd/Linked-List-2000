#include "PrettyTable.h"
#include "Handler.h"
#include <iostream>
#include <iomanip>

using namespace std;
const std::string PrettyTable::_BLACK = "\033[0;30m";
const std::string PrettyTable::_RED = "\033[0;31m";
const std::string PrettyTable::_GREEN = "\033[0;32m";
const std::string PrettyTable::_YELLOW = "\033[0;33m";
const std::string PrettyTable::_BLUE = "\033[0;34m";
const std::string PrettyTable::_MAGENTA = "\033[0;35m";
const std::string PrettyTable::_CYAN = "\033[0;36m";
const std::string PrettyTable::_WHITE = "\033[0;37m";
const std::string PrettyTable::_RESET = "\033[0;0m";

PrettyTable::PrettyTable()
{

    contentColor = _RESET;
    borderColor = _RESET;
};
PrettyTable::~PrettyTable()
{
    fields.clear();
    max_lengths.clear();
    parts.clear();
}

void PrettyTable::AddColumn(string field, int max_length)
{
    if (field.length() > max_length)
    {
        Error("Il nome inserito [" + field + "][" + to_string(field.length()) + "] supera i caratteri massimi per questo campo [" + to_string(max_length) + "]");
        throw "il nome supera i caratteri massimi per questo campo";
    }
    else
    {
        fields.push_back(field);
        max_lengths.push_back(max_length);
    }
}

void PrettyTable::AddRow(string inputString)
{
    size_t pos = 0;
    size_t i = 0;
    string delimiter = ",";
    string token;
    while ((pos = inputString.find(delimiter)) != string::npos)
    {
        token = inputString.substr(0, pos);
        if (token.length() > max_lengths[i])
        {
            Error("Il nome inserito [" + token + "][" + to_string(token.length()) + "] supera i caratteri massimi per questo campo [" + to_string(max_lengths[i]) + "]");
            throw "il nome supera i caratteri massimi per questo campo";
        }
        else
        {
            parts.push_back(token);
            inputString.erase(0, pos + delimiter.length());
            i++;
        }
    }
    if (inputString.length() > max_lengths[i])
    {
        Error("Il nome inserito [" + token + "][" + to_string(token.length()) + "] supera i caratteri massimi per questo campo [" + to_string(max_lengths[i]) + "]");
        throw "il nome supera i caratteri massimi per questo campo";
    }
    else
    {
        parts.push_back(inputString);
    }
}

void PrettyTable::PrintHeaders()
{

    PrettyTable::PrintFooter();
    for (int i = 0; i < max_lengths.size(); ++i)
    {
        if (i == max_lengths.size() - 1)
        {
            cout << borderColor;
            cout << "|";
            cout << contentColor;
            cout << setw(max_lengths[i] + 1) << fields.back() << setw(borderColor.size() + 1);
            cout << borderColor;
            cout << "|" << endl;
        }
        else
        {
            cout << borderColor;
            cout << "|";
            cout << contentColor;
            cout << setw(max_lengths[i] + 1) << fields[i] << setw(borderColor.size() + 1);
        }
    }
}

void PrettyTable::PrintRows()
{
    int y = 0;
    for (int index = 0; index < parts.size(); ++index)
    {
        if (y == 0)
        {
            PrettyTable::PrintFooter();
        }

        if (y == fields.size() - 1)
        {

            cout << borderColor;
            cout << "|";
            cout << contentColor;
            cout << setw(max_lengths[y] + 1) << parts[index] << setw(borderColor.size() + 1);
            cout << borderColor;
            cout << "|" << endl;
            y = 0;
        }
        else
        {

            cout << borderColor;
            cout << "|";
            cout << contentColor;
            cout << setw(max_lengths[y] + 1) << parts[index] << setw(borderColor.size() + 1);
            y++;
        }
    }
}

void PrettyTable::PrintFooter()
{
    cout << borderColor;
    for (int i = 0; i < max_lengths.size(); ++i)
    {
        if (i == max_lengths.size() - 1)
        {
            cout << "+" << setw(max_lengths[i] + 3) << setfill('-') << "+" << endl;
            cout << setfill(' ');
        }
        else
        {
            cout << "+" << setw(max_lengths[i] + 3) << setfill('-');
        }
    }
    cout << _RESET;
}

void PrettyTable::SetContentColor(string colorCode)
{

    contentColor = colorCode;
}

void PrettyTable::SetBorderColor(string colorCode)
{

    borderColor = colorCode;
}

void PrettyTable::PrintTable()
{
    PrettyTable::PrintHeaders();
    PrettyTable::PrintRows();
    PrettyTable::PrintFooter();
}