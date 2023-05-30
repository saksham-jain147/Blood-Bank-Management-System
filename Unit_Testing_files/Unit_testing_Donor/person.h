/*
This file contains all the header files and classes related to Person Module...
*/

#include<iostream>
#include<string>
#include<string.h>
#include<list>
#include<iterator>
#include"date.h"
#include<istream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

//Person Class
class Person
{
     public:
          Person();										//Default Constructor
          Person(string, string, string, long, long, string, int, int, int, string, string);	//Parameterized Constructor
         
         	//Setter Function Declarations
          void setFirstname(string);
          void setLastname(string);
          void setBloodgroup(string);
          void setAadhaar(long);
          void setPhonenumber(long);
          void setGender(string);
          void setAddress(string);
          void setPassword(string);
          
          	//Getter Function Declarations
          string getFirstname();
          string getLastname();
          string getBloodgroup();
          long getAadhaar();
          long getPhonenumber();
          string getGender();
          string getAddress();
          string getPassword();
          
          void accept();				//Function to accept Person Details 
          void display();				//Function to display Person Details
          
          	//Validation Funciton Declarations
          string firstname_validation();
          string lastname_validation();
          string bloodgroup_validation();
          long aadhaar_validation();
          long phonenumber_validation();
          string gender_validation();
          string address_validation();
          string password_validation();
          
          	//Function to generate ID(s)
          string get_Latest_Customer_Id();
          string get_Latest_Donor_Id();
          
          	//Function to append Person details in file
          void append_Customer_Details();
          void append_Donor_Details();
         
      private:
      
      		//Person attributes
      	 string id;
         string firstname;
	 	 string lastname;  
         string bloodgroup;
         long aadhaar;
         long phonenumber;
         string gender;
         Date bdate;
         string address;
         string password;
};



