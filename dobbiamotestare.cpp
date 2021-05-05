// #include <iostream>
// #include <map>
// using namespace std;
// template<typename T> void Error(T e){
//     std::cout<<"\033[1;31mERROR\t"<<e<<"\033[0m\n";
// }
// template<typename T> void Output(T out){
//     std::cout<<"\033[1;36mOUTPUT\t"<<out<<"\033[0m\n";
// }

// class Date{
//     int day;
//     int month;
//     int year;
//     public:
//     Date();
//     Date(int gg, int mm, int aaaa);
//     int getDay();
//     int getMonth();
//     int getYear();
// };
// Date::Date(){}

// Date::Date(int gg, int mm, int aaaa){
//     day = gg;
//     month = mm;
//     year = aaaa;
// }
// int Date::getDay(){
//     return day;
// }
// int Date::getMonth(){
//     return month;
// }
// int Date::getYear(){
//     return year;
// }


// class DateParser{
//     std::string date;
//     std::string delimiter = "/";
//     int parts[3];
//     public:
//     DateParser(std::string d);
//     void parse();
//     int getDay();
//     int getMonth();
//     int getYear();
// };
// DateParser::DateParser(string d){
//     date = d;
//     DateParser::parse();
// }
// void DateParser::parse(){

//     size_t pos = 0;
//     size_t i = 0;
//     string token;
//     while ((pos = date.find(delimiter)) != string::npos) {
//         token = date.substr(0, pos);
//         parts[i] = stoi(token);
//         date.erase(0, pos + delimiter.length());
//         i++;
//     }
//     parts[i] = stoi(date);
// }

// int DateParser::getDay(){
//     return parts[0];
// }
// int DateParser::getMonth(){
//     return parts[1];
// }
// int DateParser::getYear(){
//     return parts[2];
// }

// class Problem{
//     private:
//     std::string phone_number;
//     Date date;
//     char solved;
//     public:
//     Problem();
//     Problem(std::string phone_number, Date date, char solved);
//     void setTelefono();
//     void setDate();
//     int scanner(std::string newDate);
//     void setSolved(bool isSolved);
//     std::string getPhoneNumber();
//     Date getDate();
//     char getSolved();
// };



// Problem::Problem() {}
// Problem::Problem(string phone_number, Date date, char solved){
//         Problem::phone_number = phone_number;
//         Problem::date = date;
//         Problem::solved = solved;
// }
// void Problem::setTelefono(){
//     string newTelefono;
//         do{
//             cout<<"Inserisci le 10 cifre del numero di telefono:\n";
//             cin>>newTelefono;
//             if(newTelefono.length() < 10){
//                 Error("Le cifre del numero sono meno di 10");
//             }
//             else if(newTelefono.length()>10){
//                 Error("Le cifre del numero sono più di 10");
//             }
//             else{
//                 phone_number = newTelefono;
//             }
//         }while(newTelefono.length() != 10);
        
// }
// void Problem::setDate(){
//     string newDate;
//     bool isDateValid = false;
//     while(isDateValid == false){
//         cout<<"Inserisci la data in questo formato:\t(gg/mm/aaaa)\n";
//         cin>>newDate;
//         if(scanner(newDate)){
//             DateParser parser(newDate);
//             date = Date(parser.getDay(), parser.getMonth(), parser.getYear());
//             isDateValid = true;
//         }
//         else{
//             Error("Formato sbagliato");
//         }
//     }
// }
// int Problem::scanner(string newDate){
//     if(newDate.length() != 10){
//         return 0;
//     };
    
//     map<string, int> months  = {
//             {"01", 31},
//             {"02", 28},
//             {"03", 31},
//             {"04", 30},
//             {"05", 31},
//             {"06", 30},
//             {"07", 31},
//             {"08", 31},
//             {"09", 30},
//             {"10", 31},
//             {"11", 30},
//             {"12", 31}
//     };
//     string day = "";
//     string month = "";
//     string year = "";
//     string firstDigit;
//     string secondDigit;

//     //MONTH
//     firstDigit = newDate[3];
//     secondDigit = newDate[4];
//     month = firstDigit.append(secondDigit);
//     //check if month is valid
//     if(months.find(month) == months.end()){
//         Error("Il mese non va bene");
//         return 0;
//     }
//     //YEAR
//     for(int i = 6; i<10; i++){
//         firstDigit = newDate[i];
//         year.append(firstDigit);
//     }
//     try
//     {   
//         cout<<"cacca\n";
//         stoi(year);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//         Error("Anno inserito ["+year+"] non valido");
//         return 0;
//     }
    
//     //check if is a leap year
//     if(month == "02"){
//         ((stoi(year) % 4 == 0) && (stoi(year) % 100 != 0) || (stoi(year) % 400 == 0)) ? months["02"] = 29 : NULL;
//     }

//     //DAY
//     firstDigit = newDate[0];
//     secondDigit = newDate[1];
//     day = firstDigit.append(secondDigit);
//     //check if day is contained in month
//     try
//     {
//         cout<<"test\n";
//         stoi(day);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//         Error("Giorno inserito ["+day+"] non valido");
//         return 0;
//     }
    
//     for(int i = 1; i<31; i++){
//         if(stoi(day) == i){
//             break;
//         }
//         else if(i>31){
//             Error("Giorno inserito ["+day+"] non valido");
//             return 0;
//         }
//     }

//     try
//     {
//         stoi(day);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//         cout<<"qual è il problema?\n";
//     }
    
//     if(stoi(day) > months[month]){
//         Error("I giorni inseriti ["+day+"] superano il numero massimo di giorni nel mese ["+month+"]");
//         return 0;
//     }

//     return 1;
// }
// void Problem::setSolved(bool isSolved){
//     isSolved ? solved = 'S' : solved = 'N';
// }
// string Problem::getPhoneNumber(){
//     return phone_number;
// }
// Date Problem::getDate(){
//     return date;
// }
// char Problem::getSolved(){
//     return solved;
// }

// int main(){
//     Problem problema;
//     problema.setDate();
//     // DateParser parser("12/12/2000");
    
// }