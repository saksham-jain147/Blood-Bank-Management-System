/*
This file contains function definition for the function declared in Person Class
*/
#include"person.h"

/* 
Default Constructor for Person Class
It has no return type and does not take any parameter
*/
Person :: Person()
{	
    id = "\0";
    firstname = "\0";
    lastname = "\0";
    bloodgroup ="\0";
    aadhaar = 0;
    phonenumber = 0;
    gender = "\0";
    address = "\0";
    password = "\0";
}

/* 
Parameterized Constructor for Person Class
It has no return type and it takes parameter as: 
string firstname, string lastname, string bg,long aadhaar,long phno, string gender,int d,int m,int y, string address, string password
This contains date class
*/
Person :: Person(string firstname, string lastname, string bg,long aadhaar,long phno, string gender,int d,int m,int y, string address, string password) : bdate(d,m,y)
{	
    this->firstname = firstname;
    this->lastname = lastname;
    this->bloodgroup = bg;
    this->aadhaar = aadhaar;
    this->phonenumber = phno;
    this->gender = gender;
    this->address = address;
    this->password = password;
}

/* 
Funciton definition to accept user id and password
It's void return type and does not take any parameter
*/
void Person :: accept()
{	
	//Calling functions for validation
	
	firstname = firstname_validation();			
	lastname = lastname_validation();
	bloodgroup = bloodgroup_validation();	
	aadhaar = aadhaar_validation();
	phonenumber = phonenumber_validation();
	gender = gender_validation();
	bdate.accept();
	address = address_validation();
	
	//Displaying Password Criteria
	cout<<endl<<"\n--------------------------------------------------------------------------------------------------------------------------\n"<<endl;
	cout<<"\tPassword Criteria :: ";
	cout<<endl<<"\n--------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\nPassword should contain\n\n--> Atleast one numeric value.\n--> Alteast one lower case and one upper case alphabet.\n--> Atleast one special character.\n--> Only special characters (@,#,$,_,&,*) are allowed.\n--> Password should be atleast 8 characters and maximum of 15 characters long.\n";
	cout<<endl<<"--------------------------------------------------------------------------------------------------------------------------"<<endl;
	
	password = password_validation();
}

/* 
Funciton definition to display Person's details
It's void return type and does not take any parameter
*/
void Person :: display()
{
    cout<<"\nFirst name\t:: "<<firstname;
    cout<<"\nLast name\t:: "<<lastname;
    cout<<"\nBlood group\t:: "<<bloodgroup;
    cout<<"\nAadhaar\t\t:: "<<aadhaar;
    cout<<"\nPhone Number\t:: "<<phonenumber;
    cout<<"\nGender\t\t:: "<<gender;
    
    cout<<"\nDate\t\t:: "<<bdate.getDay()<<"/"<<bdate.getMonth()<<"/"<<bdate.getYear();
    
    cout<<"\nAddress\t\t:: "<<address;
} 


/* 
Funciton definition to set user first name
It's void return type and it takes string as a parameter
*/
void Person :: setFirstname(string name)
{
     this->firstname=name;
}

/* 
Funciton definition to set user last name
It's void return type and it takes string as a parameter
*/
void Person :: setLastname(string name)
{
     this->lastname=name;
}

/* 
Funciton definition to set user blood group
It's void return type and it takes string as a parameter
*/
void Person :: setBloodgroup(string bg)
{
     this->bloodgroup=bg;
}

/* 
Funciton definition to set user gender
It's void return type and it takes string as a parameter
*/
void Person :: setGender(string gender)
{
     this->gender=gender;
}

/* 
Funciton definition to set user aadhaar
It's void return type and it takes long as a parameter
*/
void Person :: setAadhaar(long aadhaar)
{
     this->aadhaar=aadhaar;
}

/* 
Funciton definition to set user phonenumber
It's void return type and it takes long as a parameter
*/
void Person :: setPhonenumber(long phno)
{
     this->phonenumber=phno;
}

/* 
Funciton definition to set user address
It's void return type and it takes string as a parameter
*/
void Person :: setAddress(string address)
{
     this->address=address;
}

/* 
Funciton definition to set user password
It's void return type and it takes string as a parameter
*/
void Person :: setPassword(string password)
{
     this->password = password;
}


/* 
Funciton definition to get user first name
It's return type is string and it does not take any parameter
*/
string Person :: getFirstname()
{
     return firstname;
}

/* 
Funciton definition to get user last name
It's return type is string and it does not take any parameter
*/
string Person :: getLastname()
{
     return lastname;
}


/* 
Funciton definition to get user  gender
It's return type is string and it does not take any parameter
*/
string Person :: getGender()
{
     return gender;
}

/* 
Funciton definition to get user blood group
It's return type is string and it does not take any parameter
*/
string Person :: getBloodgroup()
{
     return bloodgroup;
}

/* 
Funciton definition to get user address
It's return type is string and it does not take any parameter
*/
string Person :: getAddress()
{
     return address;
}

/* 
Funciton definition to get user aadhaar
It's return type is long and it does not take any parameter
*/
long Person :: getAadhaar()
{
     return aadhaar;
}

/* 
Funciton definition to get user phonenumber
It's return type is long and it does not take any parameter
*/
long Person :: getPhonenumber()
{
     return phonenumber;
}

/* 
Funciton definition to get user password
It's return type is string and it does not take any parameter
*/
string Person :: getPassword()
{
     return password;
}

/* 
Funciton definition to validate first name
Check whether it contains characters only
It's return type is string and it does not take any parameter
*/
string Person :: firstname_validation()
{
	string firstname;
	int count = 0;
		 
	cout<<"\nEnter First Name: ";
	getline(cin >> ws, firstname);
	
	if(firstname == "q")
	{
		cout<<"Entered to Main Menu"<<endl;
		exit(0);		//Baad mai change kar denge according to program
	}
     	else
     	{
     		for(int i=0;i<firstname.length();i++)
		{
			if( (firstname[i]>='a' &&  firstname[i]<='z') || (firstname[i]>='A' && firstname[i]<='Z') || firstname[i]==' '  )
				continue;
			else
			{
				cout<<endl<<"-------------------------------------------------"<<endl;
				cout<<endl<<"\t\tInvalid Name...!! Re-Enter"<<endl;
				cout<<endl<<"\nPress q to Enter Main Menu"<<endl;
				cout<<endl<<"-------------------------------------------------"<<endl;
				
				firstname = firstname_validation();
			}
		}
		
		count = firstname.length();
		
		if(count > 20)
		{
			cout<<endl<<"-------------------------------------------------"<<endl;
			cout<<endl<<"\tFirst Name is too Long !!!\n\t";
			cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
			cout<<endl<<"-------------------------------------------------"<<endl;
			
			firstname = firstname_validation();
		}
		else if(count <= 2)
		{
			cout<<endl<<"-------------------------------------------------"<<endl;
			cout<<endl<<"\tFirst Name is too short !!!\n\t";
			cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
			cout<<endl<<"-------------------------------------------------"<<endl;
			
			firstname = firstname_validation();
		}
		
     		return firstname;    	
	}    
}

/* 
Funciton definition to validate last name
Check whether it contains characters only
It's return type is string and it does not take any parameter
*/
string Person :: lastname_validation()
{
	string lastname;
	int count = 0;
		 
	cout<<"\nEnter Last Name: ";
	getline(cin >> ws, lastname);
	
	if(lastname == "q")
	{
		cout<<"Entered to Main Menu"<<endl;
		exit(0);		//Baad mai change kar denge according to program
	}
     	else
     	{
     		for(int i=0;i<lastname.length();i++)
		{
			if( (lastname[i]>='a' &&  lastname[i]<='z') || (lastname[i]>='A' && lastname[i]<='Z') || lastname[i]==' ')
				continue;
			else
			{
				cout<<endl<<"-------------------------------------------------"<<endl;
				cout<<endl<<"\t\tInvalid Name...!! Re-Enter"<<endl;
				cout<<endl<<"\nPress q to Enter Main Menu"<<endl;
				cout<<endl<<"--------------------------------------------------"<<endl;
				
				lastname = lastname_validation();
			}
		}
		
		count = lastname.length();
		
		if(count > 20)
		{
			cout<<endl<<"-------------------------------------------------"<<endl;
			cout<<endl<<"\tLast Name is too Long !!!\n\t";
			cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
			cout<<endl<<"-------------------------------------------------"<<endl;
			
			lastname = lastname_validation();
		}
		else if(count <= 2)
		{
			cout<<endl<<"-------------------------------------------------"<<endl;
			cout<<endl<<"\tLast Name is too short !!!\n\t";
			cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
			cout<<endl<<"-------------------------------------------------"<<endl;
			
			lastname = lastname_validation();
		}
     		return lastname;    	
	}    
}


/* 
Funciton definition to validate blood group
Check whether it contains existing blood groups only
It's return type is string and it does not take any parameter
*/
string Person :: bloodgroup_validation()
{
	string bloodgroup;
	
	cout<<"\nEnter Blood Group: ";
	cin>>bloodgroup;
	
	if(bloodgroup == "q")
	{
		cout<<"Entered to Main Menu"<<endl;
		exit(0);		//Baad mai change kar denge according to program
	}
	else
	{
		if(bloodgroup == "O-" || bloodgroup == "O+" || bloodgroup == "A-" || bloodgroup == "A+" || bloodgroup == "B-" || bloodgroup == "B+" || bloodgroup == "AB-" || bloodgroup == "AB+")
		{
			return bloodgroup;
		}
		else
		{
			cout<<endl<<"-------------------------------------------------"<<endl;
			cout<<endl<<"\tInvalid Blood Group...!! Re-Enter\n\t";
			cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
			cout<<endl<<"-------------------------------------------------"<<endl;

			bloodgroup = bloodgroup_validation();
		}
		return bloodgroup;
	}
}

/* 
Funciton definition to validate aadhaar
Check whether it contains 12 digits number
It's return type is long and it does not take any parameter
*/
long Person :: aadhaar_validation()
{
	long int aadhaarnumber, an;
	int digit = 0;
	
	cout<<"\nEnter Aadhaar Number: ";
	cin>>aadhaarnumber;
	
	an = aadhaarnumber;
	
	
	if(aadhaarnumber == 0)
	{
		cout<<"Entered to Main Menu"<<endl;
		exit(0);		//Baad mai change kar denge according to program
	}
	else
	{
		while(an != 0)
		{
			digit++;
			an = an/10;
		}
		
		if(digit == 12)
		{
			//cout<<"Digits are 12"<<endl;
			return aadhaarnumber;
		}
		else
		{
			cout<<endl<<"-------------------------------------------------"<<endl;
			cout<<endl<<"\tInvalid Aadhaar...!! Re-Enter\n\t";
			cout<<endl<<"\nPress 0 to Enter Main Menu...."<<endl;
			cout<<endl<<"-------------------------------------------------"<<endl;
			
			aadhaarnumber = aadhaar_validation();
		}
		return aadhaarnumber;
	}
}

/* 
Funciton definition to validate phone number
Check whether it contains 10 digits number
It's return type is long and it does not take any parameter
*/
long Person :: phonenumber_validation()
{
	long int phonenumber, ph;
	int digit = 0;
	
	cout<<"\nEnter Phone Number: ";
	cin>>phonenumber;
	
	ph = phonenumber;
	
	if(phonenumber == 0)
	{
		cout<<"Entered to Main Menu"<<endl;
		exit(0);	//Baad mai change kar denge according to program
	}
	else
	{
		while(ph != 0)
		{
			digit++;
			ph = ph/10;
		}
		
		if(digit == 10)
		{
			//cout<<"Digits are 10"<<endl;
			return phonenumber;
		}
		else
		{
			cout<<endl<<"-------------------------------------------------"<<endl;
			cout<<endl<<"\tInvalid Phone Number...!! Re-Enter\n\t";
			cout<<endl<<"\nPress 0 to Enter Main Menu...."<<endl;
			cout<<endl<<"-------------------------------------------------"<<endl;
			
			phonenumber = phonenumber_validation();
		}
		return phonenumber;
	}
}

/* 
Funciton definition to validate gender
It's return type is string and it does not take any parameter
*/
string Person :: gender_validation()
{
	string gender;
	cout<<"\nEnter Gender: ";
	cin>>gender;
	
	if(gender == "q")
	{
		cout<<"Entered to Main Menu"<<endl;
		exit(0);				//Baad mai kar denge
	}
	else if(gender == "Male" || gender=="male" || gender=="Female" || gender=="female" || gender == "m" || gender == "f" || gender == "M" || gender == "F" )
	{
		return gender;
	}
	else
	{
		cout<<endl<<"-------------------------------------------------"<<endl;
		cout<<endl<<"\tInvalid Gender...!! Re-Enter\n\t";
		cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
		cout<<endl<<"-------------------------------------------------"<<endl;
		
		gender = gender_validation();
	}
	return gender;
}

/* 
Funciton definition to validate address
Check whether it contains characters ('a to z' || 'A to Z' || (- and /))
It's return type is string and it does not take any parameter
*/
string Person :: address_validation()
{
	string address;
	int count=0;
	
	cout<<"\nEnter Address: ";
	getline(cin >> ws, address);
	
	if(address == "q")
	{
		cout<<"Entered to Main Menu"<<endl;
		exit(0);				//Baad mai change kar denge
	}
	
	for(int i=0;i<=address.length();i++)
	{
		if(isdigit(address[i]) || (address[i]>='a' && address[i]<='z') || (address[i]>='A' && address[i]<='Z') || address[i]=='/' || address[i]=='-' || address[i]==' ' || address[i]=='\0')
		{
			count+=1;
		}
		else
		{
			cout<<endl<<"-------------------------------------------------"<<endl;
			cout<<endl<<"\tOnly Special Characters (/ and -) are allowed\n\t";
			cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
			cout<<endl<<"-------------------------------------------------"<<endl;
			
			address = address_validation();			//Recursive Function
		}
	}
	
	count = address.length();
	
	if(count > 30)
	{
		cout<<endl<<"-------------------------------------------------"<<endl;
		cout<<endl<<"\tAddress is too Long \n\t";
		cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
		cout<<endl<<"-------------------------------------------------"<<endl;
		
		address = address_validation();				//Recursive Function
	}
	else if(count <= 8)
	{
		cout<<endl<<"-------------------------------------------------"<<endl;
		cout<<endl<<"\tAddress is too short !!!\n\t";
		cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
		cout<<endl<<"-------------------------------------------------"<<endl;
		
		address = address_validation();				//Recursive Function
	}
	return address;
}

/* 
Funciton definition to validate password
Check whether it contains alphanumeric ('a to z' || 'A to Z' || (1 to 9))
Special Characters allowed are : (@ # $ % * & _)
It's return type is string and it does not take any parameter
*/
string Person :: password_validation()
{
	string password;
	int scount=0,dcount=0,lcount=0,ucount=0,count=0;
	
	cout<<"\nEnter Password: ";
	cin>>password;
	
	if(password == "q")
	{
		cout<<"Entered to Main Menu"<<endl;
		exit(0);					//Baad mai change kar denge
	}
	
	for(int i=0;i<=password.length();i++)
	{
		if(isdigit(password[i]))
		{
			dcount+=1;
		}
		else if(password[i]>='a' && password[i]<='z')
		{
			lcount+=1;
		}
		else if(password[i]>='A' && password[i]<='Z')
		{
			ucount+=1;
		}
		else if(password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='_' || password[i]=='&' || password[i]=='*')
		{
			scount+=1;
		}
		else if(password[i]=='\0')
		{
			count+=1;
		}
		else
		{
			cout<<endl<<"-------------------------------------------------"<<endl;
			cout<<endl<<"\tPassword Invalid !!!\n--> Only Special Characters (@,#,$,_,&,*) are allowed\n\t";
			cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
			cout<<endl<<"-------------------------------------------------"<<endl;
		
			password = password_validation();		//Recursive Function
		}
	}
	count = password.length();
	if((count>=8 && count<=15) && dcount>0 && lcount>0 && ucount>0 && scount>0)
	{
		return password;
	}
	else if(count>15)
	{
		cout<<endl<<"-------------------------------------------------"<<endl;
		cout<<endl<<"\tPassword is too long !!!\n\t";
		cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
		cout<<endl<<"-------------------------------------------------"<<endl;
		
		password = password_validation();			//Recursive Function
	}
	else if(count<8)
	{
		cout<<endl<<"-------------------------------------------------"<<endl;
		cout<<endl<<"\tPassword is too short !!!\n\t";
		cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
		cout<<endl<<"-------------------------------------------------"<<endl;
		
		password = password_validation();			//Recursive Function
	}
	else
	{
		cout<<endl<<"-------------------------------------------------"<<endl;
		cout<<endl<<"\n\tPassword criteria does not match.\n\nPassword should contain\n\n--> Atleast one numeric value.\n--> Alteast one lower case and one upper case alphabet.\n--> Atleast one special character.\n--> Only special characters (@,#,$,_,&,*) are allowed.\n--> Password should be atleast 8 characters and maximum of 15 characters long.\n\n";
		cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
		cout<<endl<<"-------------------------------------------------"<<endl;
		
		password = password_validation();			//Recursive Function
	}
	
	return password;
}

/* 
Funciton definition to generate Customer Id
It reads latest id from customer_details.txt file as a reference
It's return type is string and it does not take any parameter
*/
string Person :: get_Latest_Customer_Id()
{

	int gid;
	string eid,aad,ph,fname,lname,bgroup,gdr,dt,adr;
	string str;
	string get_id;
	
	ifstream in("text_files/customer_details.txt");			//Creating object for ifstream named in
	
	if(!in.is_open())		//Checking if file exist or not
	{
		cout<<"\n----------------------------------------------------------------\n";
		cout<<"\n\t\tCannot find Text file"<<endl;
		cout<<"\n----------------------------------------------------------------\n\n";	
		
		exit(0);		//Baad mai change kar denge
	}
	
	string myString;
	string line;			//Takes 1 full line from text file as a string
	
	while(getline(in, line))
	{
		
		stringstream ss(line);			//reading the line from text file
		
		getline(ss, eid, ',');			//Dividing the line into parts(id)
		getline(ss, fname, ',');		//Dividing the line into parts(firstname)
		getline(ss, lname, ',');		//Dividing the line into parts(lastname)
		getline(ss, bgroup, ',');		//Dividing the line into parts(bloodgroup)
		getline(ss, aad, ',');			//Dividing the line into parts(aadhaarnumber)
		getline(ss, ph, ',');			//Dividing the line into parts(phonenumber)
		getline(ss, gdr, ',');			//Dividing the line into parts(gender)
		getline(ss, dt, ',');			//Dividing the line into parts(Date)
		getline(ss, adr, ',');			//Dividing the line into parts(address)
	
		str = eid.substr(1,9);			//String stripping to get integer part.
	}
	gid = stoi(str);				//Typecasting string to int
	in.seekg(0, ios::beg);				//File Pointing back to start
	in.close();					//Closing file (deallocating file pointer)
	
	gid = gid + 1;					//Incrementing latest id
	get_id = "C" + to_string(gid);			//Concatinating strings and typecasting int to string
	
	return get_id;					//Returning latest id
}

/* 
Funciton definition to generate Donor Id
It reads latest id from donor_details.txt file as a reference
It's return type is string and it does not take any parameter
*/
string Person :: get_Latest_Donor_Id()
{

	int gid;
	string eid,aad,ph,fname,lname,bgroup,gdr,dt,adr;
	string str;
	string get_id;
	
	ifstream in("text_files/donor_details.txt");	//Creating object for ifstream named in
	
	if(!in.is_open())		//Checking if file exist or not
	{
		cout<<"\n----------------------------------------------------------------\n";
		cout<<"\n\t\tCannot find Text file"<<endl;
		cout<<"\n----------------------------------------------------------------\n\n";	
		
		exit(0);		//Baad mai change kar denge
	}
	
	string myString;
	string line;			//Takes 1 full line from text file as a string
	
	while(getline(in, line))
	{
		
		stringstream ss(line);			//reading the line from text file
		
		getline(ss, eid, ',');			//Dividing the line into parts(id)
		getline(ss, fname, ',');		//Dividing the line into parts(firstname)
		getline(ss, lname, ',');		//Dividing the line into parts(lastname)
		getline(ss, bgroup, ',');		//Dividing the line into parts(bloodgroup)
		getline(ss, aad, ',');			//Dividing the line into parts(aadhaarnumber)
		getline(ss, ph, ',');			//Dividing the line into parts(phonenumber)
		getline(ss, gdr, ',');			//Dividing the line into parts(gender)
		getline(ss, dt, ',');			//Dividing the line into parts(Date)
		getline(ss, adr, ',');			//Dividing the line into parts(address)
	
		str = eid.substr(1,9);			//String stripping to get integer part.
	}
	gid = stoi(str);				//Typecasting string to int
	
	in.seekg(0, ios::beg);				//File Pointing back to start
	in.close();					//Closing file (deallocating file pointer)
	
	gid = gid + 1;					//Incrementing latest id
	get_id = "D" + to_string(gid);			//Concatinating strings and typecasting int to string
	
	return get_id;					//Returning latest id
}

/* 
Funciton definition to append Customer details into customer_details.txt
It appends customer's new id, first name, last name, blood group, aadhaar number, phone number, gender, date of birth and address
It's return type is void and it does not take any parameter
*/
void Person :: append_Customer_Details()
{
	string get_customer_id = get_Latest_Customer_Id();
	
	//------------------------------------------------Appending in customer_details.txt file-------------------------------------------------------
	
	ofstream out;					//Creating an object for ofstream
	
	out.open("text_files/customer_details.txt", ios::app);	//Opening file to append
	if(!out.is_open())				//Checing for file existance
	{
		cout<<"\n----------------------------------------------------------------\n";
		cout<<"\n\t\tCannot find Text file named : customer_details.txt"<<endl;
		cout<<"\n----------------------------------------------------------------\n\n";
		
		exit(0);				//Exit
	}
	
	//Writing into the file customer_details.txt
	out<<get_customer_id<<","<<this->firstname<<","<<this->lastname<<","<<this->bloodgroup<<","<<this->aadhaar<<","<<this->phonenumber<<","<<this->gender<<","<<bdate.getDay()<<"/"<<bdate.getMonth()<<"/"<<bdate.getYear()<<","<<this->address;	
	
	out<<endl;
	
	out.close();					//Closing file(deallocating file pointer)
	
	
	
	
	//------------------------------------------------Appending in customer_credential.txt file-------------------------------------------------------
	
	ofstream out1;						//Creating an object for ofstream
	
	out1.open("text_files/customer_credential.txt", ios::app);		//Opening file to append
	if(!out1.is_open())					//Checing for file existance
	{
		cout<<"\n---------------------------------------------------------------------------------------------------------------------\n";
		cout<<"\n\t\tCannot find Text file named : customer_credential.txt"<<endl;
		cout<<"\n---------------------------------------------------------------------------------------------------------------------\n\n";
		
		exit(0);					//Exit
	}
	
	out1<<get_customer_id<<","<<this->password;	//writing to file customer_credential.txt
	
	out1<<endl;
	
	cout<<"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout<<"\n\t\t\t\tACCOUNT CREATED SUCCESSFULLY...."<<endl;
	cout<<"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	
	out1.close();					//Closing file(deallocating file pointer)
}

/* 
Funciton definition to append Customer details into donor_details.txt
It appends donor's new id, first name, last name, blood group, aadhaar number, phone number, gender, date of birth and address
It's return type is void and it does not take any parameter
*/
void Person :: append_Donor_Details()
{
	string get_donor_id = get_Latest_Donor_Id();
	//------------------------------------------------Appending in donor_details.txt file-------------------------------------------------------	
	
	ofstream out;					//Creating an object for ofstream
	
	out.open("text_files/donor_details.txt", ios::app);	//Opening file to append
	if(!out.is_open())				//Checing for file existance
	{
		cout<<"\n---------------------------------------------------------------------------------------------------------------------\n";
		cout<<"\n\t\tCannot find Text file named : donor_details.txt"<<endl;
		cout<<"\n---------------------------------------------------------------------------------------------------------------------\n\n";
		
		exit(0);				//Exit
	}
	
	//Writing into the file donor_details.txt
	out<<get_donor_id<<","<<this->firstname<<","<<this->lastname<<","<<this->bloodgroup<<","<<this->aadhaar<<","<<this->phonenumber<<","<<this->gender<<","<<bdate.getDay()<<"/"<<bdate.getMonth()<<"/"<<bdate.getYear()<<","<<this->address;	//writing to file
	
	out<<endl;
	
	out.close();					//Closing the file
	
	//------------------------------------------------Appending in donor_credential.txt file-------------------------------------------------------
	
	ofstream out1;					//Creating an object for ofstream
	
	out1.open("text_files/donor_credential.txt", ios::app);	//Opening file to append
	if(!out1.is_open())				//Checing for file existance
	{
		cout<<"\n---------------------------------------------------------------------------------------------------------------------\n";
		cout<<"\n\t\tCannot find Text file named : donor_credential.txt"<<endl;
		cout<<"\n---------------------------------------------------------------------------------------------------------------------\n\n";
		
		exit(0);
	}
	
	//Writing to file donor_credential.txt
	out1<<get_donor_id<<","<<this->password;	
	
	out1<<endl;
	
	cout<<"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout<<"\n\t\t\t\tACCOUNT CREATED SUCCESSFULLY...."<<endl;
	cout<<"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	
	out1.close();					//Closing the file	
}

