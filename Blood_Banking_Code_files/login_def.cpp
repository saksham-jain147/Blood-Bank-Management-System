/*
This file contains all the definition functions which are declared in class Login...
*/
#include"login.h"

/*
Default Construct Function 
*/
Login::Login()
{
	id = '\0';			//id = user ID
	password = '\0';		//password = user Password
}

/* 
Funciton definition to accept user id and password
It's void return type and does not take any parameter
*/
void Login::accept()
{	
	cout<<"\nEnter User Id: ";
	cin>>id;				
	cout<<"\nEnter User Password: ";
	cin>>password;
}

/* 
Funciton definition to set user ID
It takes string ID as a parameter and void return type 
*/
void Login::setId(string id)
{
	this->id = id;
}


/* 
Funciton definition to get user ID 
It  does not takes any parameter and return's string ID type
*/
string Login::getId()
{
	return this->id;
}


/* 
Funciton definition to set user PASSWORD
It takes string PASSWORD as a parameter and void return type 
*/
void Login::setPassword(string password)
{
	this->password = password;
}

/* 
Funciton definition to get user PASSWORD
It does not takes any parameter and return's string PASSWORD type
*/
string Login::getPassword()
{
	return this->password;
}

/* 
Funciton definition to validate credentials
It takes string ID, string PASSWORD and string LOGIN_ACCOUNT_TYPE as a parameter and string return type 
*/
string Login::credential_validation(string lid, string lpassword, string x)
{
	int count = 0;
	int mark = 0;
	
	ifstream in(x);			//Creating object for ifstream named in
	
	if(!in.is_open())		//Checking if file exist or not
	{
		cout<<"\n----------------------------------------------------------------\n\n";
		cout<<"\t\tCannot find Text file"<<endl;
		cout<<"\n\n----------------------------------------------------------------\n\n";	
		
		exit(0);		//Baad mai change kar denge
	}
	
	string line;			//Takes 1 full line from text file as a string
	
	while(getline(in, line))
	{
		stringstream ss(line);				//reading the line from text file
		getline(ss, id, ',');				//Dividing the line into parts(id)
		getline(ss, password, ',');			//Dividing the line into parts(password)
		
		if(id == lid && password == lpassword)		//Checking for both user id and password are valid or not
		{
			mark++;
		}
		else if(id == lid && password != lpassword)	//Checking whether user id is correct or not 
		{
			count++;
		}
	}
	if(mark == 1)
	{
		cout<<"\n----------------------------------------------------------------\n\n";
		cout<<"\t\tYou are Successfully LOGGED IN...\n";
		cout<<"\n----------------------------------------------------------------\n\n";
		
		return id;
	}
	else if(count == 1)
	{
		cout<<"\n----------------------------------------------------------------\n\n";
		cout<<"\t\tInvalid Password!!!\n";
		cout<<"\n----------------------------------------------------------------\n\n";
		
		return "invalid";
	}
	else
	{
		cout<<"\n----------------------------------------------------------------\n\n";
		cout<<"\t\tInvalid Login credentials!!!\n";
		cout<<"\n----------------------------------------------------------------\n\n";
		
		return "invalid";
	}
	in.close();		//Closing the file 
	
	return id;
}


/* 
Funciton definition to display menu choice 
It does not takes any parameter and return's string type
*/
string Login::displayMenu()
{
	//string id, password;
	
	string str, s, id;
	int ch;
	Login l1;	//Object creation
				
	
	do
	{
		system("clear");
		
		cout<<"\n------------------Enter the code to Login----------------------------\n";
		cout<<"\n\t1: ADMIN\n \t2: CUSTOMER\n \t3: DONOR\n \t4: HOSPITAL\n \t0: EXIT\n\n \tENTER CHOICE : ";
		cin>>ch;
		cout<<endl;
		
		switch(ch)
		{
			case ADMIN:	
			{
					system("clear");
					
					Admin ad;
					str = a;		//MACRO replace a with text file path as: credential_files/admin_credential.txt...
					l1.accept();								//accept() Function is called
					id = l1.getId();
					s = l1.credential_validation(l1.getId(), l1.getPassword(), str);	//credential_validation() Function is called
					
					if(s == "invalid")
					{
						break;
					}
					ad.get_A_Choice();	
					break;
			}
			
			case CUSTOMER:	
			{
					system("clear");
					
					str = c;		//MACRO replace c with text file path as: credential_files/customer_credential.txt...
					l1.accept();								//accept() Function is called
					id = l1.getId();
					s = l1.credential_validation(l1.getId(), l1.getPassword(), str);	//credential_validation() Function is called
					
					if(s == "invalid")
					{
						break;
					}
					get_C::get_C_choice(id);
					break;
			}
				
			case DONOR:	
			{	
					system("clear");
					
					str = d;		//MACRO replace d with text file path as: credential_files/donor_credential.txt...
					l1.accept();								//accept() Function is called
					id = l1.getId();
					s = l1.credential_validation(l1.getId(), l1.getPassword(), str);	//credential_validation() Function is called
					
					if(s == "invalid")
					{
						break;
					}
					get_D::get_D_choice(id);
					
					break;
			}
				
			case HOSPITAL:	
			{	
					system("clear");
					
					str = h;		//MACRO replace h with text file path as: credential_files/hospital_credential.txt...
					l1.accept();							//accept() Function is called
					id = l1.getId();
					s = l1.credential_validation(l1.getId(), l1.getPassword(), str);	//credential_validation() Function is called
					
					if(s == "invalid")
					{
						break;
					}
					get_H::get_H_choice(id);
					break;
			}
					
			case EXIT:
			{
					system("clear");
					
					cout<<"\n----------------------------------------------------------------\n\n";
					cout<<"\t\tThank you for using our services !!!\n";
					cout<<"\n----------------------------------------------------------------\n\n";	
					exit(0);
			}
			
			default:
			{
					system("clear");
					
					cout<<"\n----------------------------------------------------------------\n\n";
					cout<<"\t\tINVALID CHOICE!!!\n";
					cout<<"\n----------------------------------------------------------------\n\n";	
					
					break; 	
			}
		}

	}while(ch != 0);
	
	return str;
}

