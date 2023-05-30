/*
This file contains all the definition functions which are declared in class Person and Stock...
*/
#include"person.h"
#include"stock.h"
#include"order.h"

#define DISPLAY 1
#define REQUEST 2
#define SEARCH 3
#define F_NAME 41
#define L_NAME 42
#define ADDRESS 43
#define PHONENUMBER 44
#define BACK 45
#define UPDATE 4
#define ORDERHISTORY 5
#define LOGOUT 0

class Customer:public Person
{
     public:
          Customer();
          Customer(string , string, string, string, long, long, string, int, int, int, string, string);
          string getCustomerid();
          void setCustomerid(string);
          string getPassword();
          void setPassword(string);
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
          list<list<string>> Placeorder(list<list<string>>,Customer*,Stock*,Order*,ofstream&,string,int,string );
          //funtion to load data in file into list
          list<list<string>> Load_data_into_list(ifstream&);
          //function to update list after acceptio=ng order
          list<list<string>> Update_list(list<list<string>>,string,int);
          //void update_orderhistory(string);
          void update_orderhistory(Order*,ifstream&,string,string,int);
          //function to update stock after accepting order
          void update_stock(list<list<string>>,Customer*,ofstream&);
          void writeFile(list<list<string>>,ofstream&);
          string getName(list<list<string>>,string);
          bool credential_validation(string,string);
          
          
           
     private:
          string customer_id;
          string password;
          list<list<string>> arr;
};

namespace Display
{
    //function to display options given to customer
    void displaymenu();
}

namespace get
{
     //function to navigate through the options
     void getchoice();
}

void Update_Name(Customer*,list<list<string>> ,ofstream&,string,string);

