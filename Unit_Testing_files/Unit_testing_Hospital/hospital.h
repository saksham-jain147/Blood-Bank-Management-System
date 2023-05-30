/*
This file contains all the definition functions which are declared in class Stock...
*/

#include"stock.h"
#include"order.h"
#include<vector>









#define H_DISPLAY 1
#define H_MAKEORDER 2
#define H_SEARCH 3
#define H_NAME 61
#define H_ADDRESS 62
#define H_PHONENUMBER 63
#define H_BACK 65
#define H_UPDATE 4
#define H_ORDERHISTORY 5
#define H_LOGOUT 99

class Hospital
{
     public:
          Hospital();						//default constructor
          Hospital(string , string, string, long, string);	//parameterized constructor
          string getHospitalid();
          string getName();
          string getAddress();
          long getPhonenumber();
          string getPassword();
          void setPassword(string);
          void setHospitalid(string);
          void display();
          void writeFile(ofstream&);
          void printNestedList(list<list<string> >);
          //function to write data into the file using stl list
          void writeData(list<list<string>>,ofstream&);
          //function to read data from the file
          void readData(Hospital*,ifstream&,string);
          //function to valid blood group
          bool IsBloodgroupValid(list<list<string> >,string);
          //function to place order
          list<list<string>> Placeorder(list<list<string>>,Hospital*,Stock*,Order*,ofstream&,string,int,string );
          //funtion to load data in file into list
          list<list<string>> Load_data_into_list(ifstream&);
          //function to update list after accepting order
          list<list<string>> Update_list(list<list<string>>,string,int);
          //void update_orderhistory(string);
          void update_orderhistory(Order*,ifstream&,string,string,int);
          //function to update stock after accepting order
          void update_stock(list<list<string>>,Hospital*,ofstream&);
          void writeFile(list<list<string>>,ofstream&);
          
          //void accept();
	  void hospital_accept();
	  string name_validation();
	  long phonenumber_validation();
	  string address_validation();
	  string get_Latest_Hospital_Id();
	  string password_validation();
	  void append_Hospital_Details();
	  void Hospital_display();
	  bool credential_validation(string,string);
           
     private:
          string hospital_id;
          string name;
          string address;
          long phone_number;
          string password;
};

namespace Display
{
    //function to display options given to customer
    void display_H_menu();
}

namespace get_H
{
     //function to navigate through the options
     void get_H_choice(string);
}


string hname_validation();

string haddress_validation();

long hphonenumber_validation();
