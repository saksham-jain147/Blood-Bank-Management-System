/*
This file contains all the header files and classes related to Login Module...
*/

//Header files
#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include"admin.h"

//Macros for credential files
#define a "text_files/admin_credential.txt"
#define c "text_files/customer_credential.txt"
#define d "text_files/donor_credential.txt"
#define h "text_files/hospital_credential.txt"

#define ADMIN 1
#define CUSTOMER 2
#define DONOR 3
#define HOSPITAL 4
#define EXIT 0

using namespace std;

//Login Class
class Login
{
	public:
		
		Login();								//Default Constructor
		
		string credential_validation(string id, string password, string x);	//Function to validate credentials
		void accept();								//Function to accept user name and password
		string displayMenu();							//Function to display choice menu
		
		void setId(string id);							//Function to set user id 
		string getId();								//Function to get user id
		
		void setPassword(string password);					//Function to set user password 
		string getPassword();							//Function to get user id
		
		
	private:									//private variables
		string id;
		string password;
};
