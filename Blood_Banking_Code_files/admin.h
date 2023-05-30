/*
This file contains all the header files and classes related to Admin Module...
*/
#include"donor.h"

#define ADD_CUSTOMER 11
#define ADD_DONOR 12
#define ADD_HOSPITAL 13
#define DELETE_CUSTOMER 14
#define DELETE_DONOR 15
#define DELETE_HOSPITAL 16
#define LOGOUT 99
#define EXIT 0

using namespace std;

class Admin : public Person
{
	public:
		Admin();
		
		void get_A_Choice();
		void displayMenu();
		void delete_Customer(string id);
		void delete_Donor(string id);
		void delete_Hospital(string id);
		
	private:
		string id;
};
