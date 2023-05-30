/*
This file contains all the definition functions which are declared in class Person and Stock...
*/
#include"person.h"
#include"stock.h"

#define DISPLAY 1
#define DONATION 2
#define F_NAME 31
#define L_NAME 32
#define ADDRESS 33
#define PHONENUMBER 34
#define BACK 35
#define UPDATE 3
#define DONATIONHISTORY 4
#define LOGOUT 0

class Donor:public Person
{
     public:
          Donor();
          Donor(string , string, string, string, long, long, string, int, int, int, string, string);
          string getDonorid();
          void setDonorid(string);
          string getPassword();
          void setPassword(string);
          void display();
          void writeFile(ofstream&);
          void printNestedList(list<list<string> >);
          //function to write data into the file using stl list
          void writeData(list<list<string>>,ofstream&);
          //function to read data from the file
          void readData(Donor*,ifstream&,string);
          //function to valid blood group
          bool IsBloodgroupValid(list<list<string> >,string);
          //function to place order
          list<list<string>> Makedonation(list<list<string>>,Donor*,ofstream&,string,int,string );
          //funtion to load data in file into list
          list<list<string>> load_Data_into_list(ifstream&);
          //function to update list after donation order
          list<list<string>> Update_list(list<list<string>>,string,int);
          //void update_donationhistory(string);
          void update_donation_history(ifstream&,string,string,int);
          //function to update stock after accepting order
          void update_stock(list<list<string>>,Donor*,ofstream&);
          void writeFile(list<list<string>>,ofstream&);
          string get_Blood_group(Donor*,list<list<string>>,ofstream&,string);
          bool credential_validation(string,string);
          
          
           
     private:
          string donor_id;
          string password;
          list<list<string>> arr;
};

namespace donation
{
	//function to get donation id
	int get_donation_id(ifstream&);
}
namespace packet
{
	//function to get packet id
	int get_packet_id(ifstream&);
}

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

//void Update_Name(Customer*,list<list<string>> ,ofstream&,string,string);
