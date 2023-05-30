/*
This file contains all the definition functions which are declared in class Person and Stock...
*/
#include<unistd.h>
#include"person.h"
#include"hospital.h"

#define C_DISPLAY 1
#define C_REQUEST 2
#define C_SEARCH 3
#define C_F_NAME 41
#define C_L_NAME 42
#define C_ADDRESS 43
#define C_PHONENUMBER 44
#define C_BACK 45
#define C_UPDATE 4
#define C_ORDERHISTORY 5
#define C_LOGOUT 0

class Customer:public Person
{
     public:
          Customer();
          Customer(string , string, string, string, long, long, string, int, int, int, string, string);
          string getCustomerid();
          void setCustomerid(string);
          void display();
          void writeFile(ofstream&);
          void printNestedList(list<list<string> >);
          
          //function to write data into the file using stl list
          void writeData(list<list<string>>,ofstream&);
          
          //function to read data from the file
          void readData(Customer*,ifstream&,string);
          
          //function to valid blood group
          bool IsBloodgroupValid(list<list<string> >,string);
          
          //function to place order
          list<list<string>> Placeorder(list<list<string>>,Customer*,Stock*,Order*,ofstream&,string,int,string);
          
          //funtion to load data in file into list
          list<list<string>> Load_data_into_list(ifstream&);
          
          //function to update list after acceptio=ng order
          list<list<string>> Update_list(list<list<string>>,string,int);
          
          //void update_orderhistory(string);
          void update_orderhistory(Order*,ifstream&,string,string,int);
          
          //function to update stock after accepting order
          void update_stock(list<list<string>>,Customer*,ofstream&);
          
          void writeFile(list<list<string>>,ofstream&);
           
     private:
          string customer_id;
          list<list<string>> arr;
};

namespace Display
{
    //function to display options given to customer
    void display_C_menu();
}

namespace get_C
{
     //function to navigate through the options
     void get_C_choice(string);
}

