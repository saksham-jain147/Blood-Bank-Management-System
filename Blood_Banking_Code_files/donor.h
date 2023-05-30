/*
This file contains all the definition functions which are declared in class Person and Stock...
*/
#include"customer.h"

#define D_DISPLAY 1
#define D_DONATION 2
#define D_F_NAME 31
#define D_L_NAME 32
#define D_ADDRESS 33
#define D_PHONENUMBER 34
#define D_BACK 35
#define D_UPDATE 3
#define D_DONATIONHISTORY 4
#define D_LOGOUT 0

class Donor:public Person
{
     public:
          Donor();
          Donor(string , string, string, string, long, long, string, int, int, int, string, string);
          string getDonorid();
          void setDonorid(string);
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
           
     private:
          string donor_id;
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
    void display_D_menu();
}

namespace get_D
{
     //function to navigate through the options
     void get_D_choice(string);
}
