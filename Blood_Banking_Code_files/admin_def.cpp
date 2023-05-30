/*
This file contains function definition for the function declared in Admin Class
*/
#include"admin.h"

/* 
Default Constructor for Admin Class
It has no return type and does not take any parameter
*/

Admin::Admin()
{
	id = '\0';
}

/*
Function definition to display ADMIN MENU.
It's return type is void and it takes no parameter
*/
void Admin :: displayMenu()
{
	cout<<endl<<"\n--------------------------------------------------------------------------------------------------------------------------\n"<<endl;
	cout<<"\t\t\t\t\tSELECT AN OPTION TO PROCEED : "<<endl<<endl;
	cout<<"\t11: \tADD Customer\n";
	cout<<"\t12: \tADD Donor\n";
	cout<<"\t13: \tADD Hospital\n";
	cout<<"\t14: \tDELETE Customer\n";
	cout<<"\t15: \tDELETE Donor\n";
	cout<<"\t16: \tDELETE Hospital\n";
	cout<<"\t99: \tLOGOUT\n";
	cout<<endl<<"\n--------------------------------------------------------------------------------------------------------------------------"<<endl;
}


/*
Funciton definition to delete Customer details from customer_details.txt, customer_credentails.txt and rewriting the file: customer_details.txt and customer_credentials.txt
Updating the file after deleting unnecessary data in the file
It's return type is void and it takes string as a parameter
*/
void Admin :: delete_Customer(string id)
{
	list<string> l1_customer;
	list<string> l2_customer;
	
	int count = 0;
	int gid;
	
	string eid,aad,ph,fname,lname,bgroup,gdr,dt,adr,pwd;
	string str;
	string get_id;
	string lastelement;
	
	
	//---------------------------------------------------------------------Customer Details Part---------------------------------------------------------------------------------
	
	
	ifstream in("text_files/customer_details.txt");	//Creating object for ifstream named in
	
	if(!in.is_open())			//Checking if file exist or not
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCannot find Text file"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		
		exit(0);		
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
		
		if(id == eid)
		{
			count++;
			continue;
		}
		
		
		l2_customer.push_back(line);
	}
	
	in.seekg(0, ios::beg);				//File Pointing back to start
	in.close();					//Closing file (deallocating file pointer)
	
	//Writing into the file customer_details.txt
	lastelement  = l2_customer.back();
	
	ofstream out;					//Creating an object for ofstream
	
	out.open("text_files/customer_details.txt");		//Opening file to write
	if(!out.is_open())				//Checing for file existance
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCannot find Text file named : customer_details.txt"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		
		exit(0);				//Exit
	}
	
	//Writing data from list to file...
	for(auto x : l2_customer)
	{
		if(x == lastelement)
			out<<x;
		else
			out<<x<<endl;
	}
	out<<endl;
	
	out.close();	//Closing the file
	
	
	//---------------------------------------------------------------------Customer Credentials Part---------------------------------------------------------------------------------
	
	
	ifstream in1("text_files/customer_credential.txt");	//Creating object for ifstream named in
	
	if(!in1.is_open())				//Checking if file exist or not
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCannot find Text file"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		
		exit(0);				
	}
	
	/*string myString;
	string line;					//Takes 1 full line from text file as a string*/
	
	while(getline(in1, line))
	{
		
		stringstream ss(line);			//reading the line from text file
		
		getline(ss, eid, ',');			//Dividing the line into parts(id)
		getline(ss, pwd, ',');			//Dividing the line into parts(password)
		
		if(id == eid)
		{
			count++;
			continue;
		}
		l1_customer.push_back(line);
	}
	
	in1.seekg(0, ios::beg);				//File Pointing back to start
	in1.close();					//Closing file (deallocating file pointer)
	
	//Writing into the file customer_details.txt
	lastelement  = l1_customer.back();
	
	ofstream out1;					//Creating an object for ofstream
	
	out1.open("text_files/customer_credential.txt");		//Opening file to write
	if(!out1.is_open())				//Checing for file existance
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCannot find Text file named : customer_credentials.txt"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		
		exit(0);				//Exit
	}
	
	//Writing data from list to file...
	for(auto x : l1_customer)
	{
		if(x == lastelement)
			out1<<x;
		else
			out1<<x<<endl;
	}
	out1<<endl;
	
	out1.close();					//Closing the file
	
	if(count == 0)
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCustomer ID does not exist"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
	}
	else
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCUSTOMER ACCOUNT DELETED SUCCESSFULLY...."<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
	}
}


/*
Funciton definition to delete Donor details from donor_details.txt, donor_credentials.txt and rewriting the file: donor_details.txt and donor_credentials.txt
Updating the file after deleting unnecessary data in the file
It's return type is void and it takes string as a parameter
*/
void Admin :: delete_Donor(string id)
{
	list<string> l1_donor;
	list<string> l2_donor;
	
	int count = 0;
	int gid;
	
	string eid,aad,ph,fname,lname,bgroup,gdr,dt,adr,pwd;
	string str;
	string get_id;
	string lastelement;
	
	
	//---------------------------------------------------------------------Donor Details Part---------------------------------------------------------------------------------
	
	
	ifstream in("text_files/donor_details.txt");		//Creating object for ifstream named in
	
	if(!in.is_open())				//Checking if file exist or not
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCannot find Text file"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		
		exit(0);				
	}
	
	string myString;
	string line;					//Takes 1 full line from text file as a string
	
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
		
		if(id == eid)
		{
			count++;
			continue;
		}
		
		l2_donor.push_back(line);
	}
	
	in.seekg(0, ios::beg);				//File Pointing back to start
	in.close();					//Closing file (deallocating file pointer)
	
	//Writing into the file donor_details.txt
	lastelement  = l2_donor.back();
	
	ofstream out;					//Creating an object for ofstream
	
	out.open("text_files/donor_details.txt");			//Opening file to write
	if(!out.is_open())				//Checing for file existance
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCannot find Text file named : donor_details.txt"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		
		exit(0);				//Exit
	}
	
	//Writing data from list to file...
	for(auto x : l2_donor)
	{
		if(x == lastelement)
			out<<x;
		else
			out<<x<<endl;
	}
	out<<endl;
	
	out.close();					//Closing the file
	
	
	//---------------------------------------------------------------------Donor Credentials Part------------------------------------------------------------------
	
	
	ifstream in1("text_files/donor_credential.txt");		//Creating object for ifstream named in
	
	if(!in1.is_open())				//Checking if file exist or not
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCannot find Text file"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		
		exit(0);				
	}
	
	/*string myString;
	string line;					//Takes 1 full line from text file as a string*/
	
	while(getline(in1, line))
	{
		
		stringstream ss(line);			//reading the line from text file
		
		getline(ss, eid, ',');			//Dividing the line into parts(id)
		getline(ss, pwd, ',');			//Dividing the line into parts(password)
		
		if(id == eid)
		{
			count++;
			continue;
		}
		
		l1_donor.push_back(line);
	}
	
	in1.seekg(0, ios::beg);				//File Pointing back to start
	in1.close();					//Closing file (deallocating file pointer)
	
	//Writing into the file donor_details.txt
	lastelement = l1_donor.back();
	
	ofstream out1;					//Creating an object for ofstream
	
	out1.open("text_files/donor_credential.txt");		//Opening file to write
	if(!out1.is_open())				//Checing for file existance
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCannot find Text file named : donor_credentials.txt"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		
		exit(0);				//Exit
	}
	
	//Writing data from list to file...
	for(auto x : l1_donor)
	{
		if(x == lastelement)
			out1<<x;
		else
			out1<<x<<endl;
	}
	out1<<endl;
	
	out1.close();					//Closing the file
	
	if(count == 0)
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tDonor ID does not exist"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
	}
	else
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tDONOR ACCOUNT DELETED SUCCESSFULLY...."<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
	}
}

/*
Funciton definition to delete Hospital details from hospital_details.txt, Hospital_credentials.txt and rewriting the file: Hospital_details.txt and hospital_credentials.txt
Updating the file after deleting unnecessary data in the file
It's return type is void and it takes string as a parameter
*/
void Admin :: delete_Hospital(string id)
{
	list<string> l1_hospital;
	list<string> l2_hospital;
	
	int count = 0;
	int gid;
	
	string eid,hname,ph,adr,pwd;
	string str;
	string get_id;
	string lastelement;
	
	
	//---------------------------------------------------------------------Hospital Details Part---------------------------------------------------------------------------------
	
	
	ifstream in("text_files/Hospital_details.txt");		//Creating object for ifstream named in
	
	if(!in.is_open())				//Checking if file exist or not
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCannot find Text file"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		
		exit(0);				
	}
	
	string myString;
	string line;					//Takes 1 full line from text file as a string
	
	while(getline(in, line))
	{
		
		stringstream ss(line);			//reading the line from text file
		
		getline(ss, eid, ',');			//Dividing the line into parts(id)
		getline(ss, hname, ',');		//Dividing the line into parts(firstname)
		getline(ss, ph, ',');			//Dividing the line into parts(phonenumber)
		getline(ss, adr, ',');			//Dividing the line into parts(address)
		
		if(id == eid)
		{
			count++;
			continue;
		}
		
		l2_hospital.push_back(line);
	}
	
	in.seekg(0, ios::beg);				//File Pointing back to start
	in.close();					//Closing file (deallocating file pointer)
	
	//Writing into the file Hospital_details.txt
	lastelement  = l2_hospital.back();
	
	ofstream out;					//Creating an object for ofstream
	
	out.open("text_files/Hospital_details.txt");			//Opening file to write
	if(!out.is_open())				//Checing for file existance
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCannot find Text file named : Hospital_details.txt"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		
		exit(0);				//Exit
	}
	
	//Writing data from list to file...
	for(auto x : l2_hospital)
	{
		if(x == lastelement)
			out<<x;
		else
			out<<x<<endl;
	}
	out<<endl;
	
	out.close();					//Closing the file
	
	
	//---------------------------------------------------------------------Hospital Credentials Part------------------------------------------------------------------
	
	
	ifstream in1("text_files/hospital_credential.txt");		//Creating object for ifstream named in
	
	if(!in1.is_open())				//Checking if file exist or not
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCannot find Text file"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		
		exit(0);				
	}
	
	/*string myString;
	string line;					//Takes 1 full line from text file as a string*/
	
	while(getline(in1, line))
	{
		
		stringstream ss(line);			//reading the line from text file
		
		getline(ss, eid, ',');			//Dividing the line into parts(id)
		getline(ss, pwd, ',');			//Dividing the line into parts(password)
		
		if(id == eid)
		{
			count++;
			continue;
		}
		
		l1_hospital.push_back(line);
	}
	
	in1.seekg(0, ios::beg);				//File Pointing back to start
	in1.close();					//Closing file (deallocating file pointer)
	
	//Writing into the file Hospital_details.txt
	lastelement = l1_hospital.back();
	
	ofstream out1;					//Creating an object for ofstream
	
	out1.open("text_files/hospital_credential.txt");		//Opening file to write
	if(!out1.is_open())				//Checing for file existance
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tCannot find Text file named : hospital_credentials.txt"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		
		exit(0);				//Exit
	}
	
	//Writing data from list to file...
	for(auto x : l1_hospital)
	{
		if(x == lastelement)
			out1<<x;
		else
			out1<<x<<endl;
	}
	out1<<endl;
	
	out1.close();					//Closing the file
	
	if(count == 0)
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tHospital ID does not exist"<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
	}
	else
	{
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		cout<<"\n\t\tHospital ACCOUNT DELETED SUCCESSFULLY...."<<endl;
		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
	}
}

/*
Function definition to work with ADMIN OPTIONS by calling required functions.
It's return type is void and it does not take any parameter
*/
void Admin :: get_A_Choice()
{
	string id, accept;
	int ch,gid;
	string eid,str,get_id;
	Hospital h;
	do
	{
		displayMenu();
		cout<<"Enter Choice :: ";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case ADD_CUSTOMER :
			{
							system("clear");
							
							accept = Person::accept();
							if(accept == "Invalid")
							{
								break;
							}
							
							Person::append_Customer_Details();
							cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
							cout<<"\t\t\t\tCUSTOMER DETAILS : "<<endl<<endl;
							eid = Person::get_Latest_Customer_Id();
							str = eid.substr(1,9);
							gid = stoi(str) - 1;
							get_id = "C" + to_string(gid);	
							cout<<"Customer ID\t:: "<<get_id;
							Person::display();
							cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
							
							break;
			}
			case ADD_DONOR :
			{
							system("clear");
							
							accept = Person::accept();
							if(accept == "Invalid")
							{
								break;
							}
							
							Person::append_Donor_Details();
							cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
							cout<<"\t\t\t\tDONOR DETAILS : "<<endl<<endl;
							eid = Person::get_Latest_Donor_Id();
							str = eid.substr(1,9);
							gid = stoi(str) - 1;
							get_id = "D" + to_string(gid);
							cout<<"Donor ID\t:: "<<get_id;
							Person::display();
							cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
							
							break;
			}
							
			case ADD_HOSPITAL : 
			{				
							system("clear");
							
							accept = h.hospital_accept();
							if(accept == "Invalid")
							{
								break;
							}
							
							h.append_Hospital_Details();
							cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
							cout<<"\t\t\t\tHOSPITAL DETAILS : "<<endl<<endl;
							
							eid = h.get_Latest_Hospital_Id();
							str = eid.substr(1,9);
							gid = stoi(str) - 1;
							get_id = "H" + to_string(gid);
							cout<<"Hospital ID ::\t  "<<get_id;
							
							//Hospital :: display();
							h.Hospital_display();
							cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
							
							break;
			}
			
			
			case DELETE_CUSTOMER :	
			{			
							system("clear");
							
							cout<<"Enter Customer Id : ";
							cin>>id;
							delete_Customer(id);
							
							break;
			}	
			
			case DELETE_DONOR :	
			{	
							system("clear");
							
							cout<<"Enter Donor Id : ";
							cin>>id;
							delete_Donor(id);
							
							break;
			}
			
			
			case DELETE_HOSPITAL :	
			{
							system("clear");
							
							cout<<"Enter Hospital Id : ";
							cin>>id;
							Admin :: delete_Hospital(id);
							
							break;
			}
			
			case LOGOUT :	
			{
							system("clear");
							
							cout<<endl<<"\n-------------------------------------------------------------------------------\n\n";
							cout<<"You are been LOGGED OUT....\n";
							cout<<"\n-------------------------------------------------------------------------------\n"<<endl;
							sleep(1);
							ch = 0;
							
							break;
			}
	
			default : 
			{
							cout<<endl<<"\n-------------------------------------------------------------------------------\n\n";
							cout<<"\t\tInvalid Choice\n";
							cout<<"\n-------------------------------------------------------------------------------\n"<<endl;
							
							break;
			}
		}
	}while(ch != 0);
	
	cout<<"\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
     	cout<<"\n\t\t\tTHANK YOU!!";
     	cout<<"\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
     	sleep(1);
     	
     	return;
}

