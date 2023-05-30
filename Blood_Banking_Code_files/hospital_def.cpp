/*
This file contains all the definition functions which are declared in class Hospital..
*/
#include"hospital.h"


/*default constructor of class Hospital
It has no return type and does not take any parameter*/
Hospital :: Hospital()
{
    hospital_id="\0";
    name="\0";
    address="\0";
    phone_number=0;
}

/*Parameterized Constructor for Hospital Class
It has no return type and it takes parameter as: 
string id,string name, string address,long phone_number
*/
Hospital :: Hospital(string hid,string name,string address,long phone_number, string password)
{
    hospital_id=hid;
    this->name=name;
    this->address=address;
    this->phone_number=phone_number;
    this->password = password;
}

/* 
Funciton definition to set user hospital_id
It's void return type and it takes string as a parameter
*/
void Hospital :: setHospitalid(string id)
{
    hospital_id=id;
}

/* 
Funciton definition to get user hospital_id
It's return type is string and it takes no parameters
*/
string Hospital :: getHospitalid()
{
    return hospital_id;
}

/* 
Funciton definition to display hospital details
It's void return type and does not take any parameter
*/
void Hospital :: display()
{
    cout<<"\nHospital ID::\t  "<<hospital_id;
    cout<<"\nName ::\t\t  "<<name;
    cout<<"\nAddress ::\t  "<<address;
    cout<<"\nPhone No. ::\t  "<<phone_number;
}

/*function definition to display options given to hospital
its void return type and takes no parameters
*/
void Display :: display_H_menu()
{
	cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    cout<<"\n\t\tSELECT AN OPTION TO PROCEED\n\n\t\t\t1. Display Hospital Details\n\t\t\t2. Make Orders\n\t\t\t3. Search for a Blood Group\n\t\t\t4. Edit Hospital Details\n\t\t\t5. View Past Orders History\n\t\t\t99. Logout\n";
   	 cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
}


/*function  definition to display hospital details
its return type is void and takes nested list as parameter
*/
void Hospital :: printNestedList(list<list<string> > record) 
{ 
    
     string x[record.size()][4];
     list<list<string> >::iterator record_itr; 
    //print the nested_list 
    int i=0,j=0;
     for (record_itr = record.begin();record_itr != record.end();++record_itr)
     { 
        
        int count=0;
        list<string>::iterator rec_itr; 
        list<string>& rec_pointer = *record_itr; 
        for (rec_itr = rec_pointer.begin();rec_itr != rec_pointer.end();rec_itr++) 
        {
              x[i][j]=*rec_itr;
              j++;
        }
        i++;
       }
     for(int i=0;i<record.size();i++)
     {
       cout << "\n\tHospital Id::\t  " << x[i][0]; //record[i][0]
       cout << "\n\tName::\t\t  " << x[i][1]; /// name 
       cout << "\n\tAddress::\t  " << x[i][2];
       cout << "\n\tPhone Number::\t  " << x[i][3];   
       
     }
}

/*function definition to read data from the file
its return type is void and takes Hospital object,input stream,and string as parameters
*/
void Hospital::readData(Hospital *eptr,ifstream& fin,string id)
{
       list<list<string> > record;
       list<string> rec;
       string str,temp;
       int i=0;
       do
       {
            rec.clear();
            getline(fin,temp);
            if(fin.eof())
                  break;
           
             stringstream data(temp);
             getline(data,str,',');
             
             if(id==str)
             {
                 rec.push_back(str);    
                 while(getline(data,str,','))
                 {
                    rec.push_back(str);
                 }
                 record.push_back(rec);
             }     
             
       }while(!fin.eof());
       
       if(!record.empty())
       {
           eptr->printNestedList(record);
       }
       else
       {
           cout<<"\nWrong Details";
       }
       
}

/*function definition to load data in file to database
its return type is nestedlist
*/
list<list<string>> Hospital :: Load_data_into_list(ifstream& fin)
{
       list<list<string> > record;
       list<string> rec;
       string str,temp;
       int i=0;
       do
       {
            rec.clear();
            getline(fin,temp);
            if(fin.eof())
                  break;
           
            stringstream data(temp);    
            while(getline(data,str,','))
            {
               rec.push_back(str);
            }
            record.push_back(rec);
          
       }while(!fin.eof()); 
       
       return record;  
}


/*function to see if required blood group is there in database
its return type is bool,and it takes nested list and string as parameters
*/
bool Hospital::IsBloodgroupValid(list<list<string> > record,string bg)
{
       list<list<string> >::iterator record_itr; 
       for (record_itr = record.begin();record_itr != record.end();++record_itr)
       { 
        
           int count=0;
           list<string>::iterator rec_itr; 
           list<string>& rec_pointer = *record_itr; 
           for (rec_itr = rec_pointer.begin();rec_itr != rec_pointer.end();rec_itr++) 
           { 
           
               if(count==0)
               {
                     if(*rec_itr==bg)
                     {
                          return true;
                     }
               }
            }
       }
       
       return false;
}


/*function to update list containing stock details
its return type is nestedlist and it takes nestedlist,string and int as parameters
*/
list<list<string>> Hospital :: Update_list(list<list<string>> record,string bg,int quantity)
{
       
       list<list<string> >::iterator record_itr; 
       for (record_itr = record.begin();record_itr != record.end();++record_itr)
       { 
        
           int count=0;
           int yes=0;
           list<string>::iterator rec_itr; 
           list<string>& rec_pointer = *record_itr; 
           for (rec_itr = rec_pointer.begin();rec_itr != rec_pointer.end();rec_itr++) 
           { 
           
               if(count==0)
               {
                     if(*rec_itr==bg)
                     {
                          yes=1;
                     }
               }
               if(count==1 and yes==1)
               {
                     int quan;
                     quan=stoi(*rec_itr);
                     if(quan>=quantity)
                     {
                         int updatedquantity;
                         updatedquantity=quan-quantity;
                         *rec_itr=to_string(updatedquantity);
                         return record;
                     }
               }
               count++;
            }
       }
   
       return record;
}


/*function to update name of the Hospital
its return type is void and it takes nestedlist,ofstream,string,string as parameters
*/
void Update_Name(Hospital *h,list<list<string>> record,ofstream &out,string id,string name)
{
     list<list<string> >::iterator record_itr; 
     for (record_itr = record.begin();record_itr != record.end();++record_itr)
     { 
        
        int count=0;
        int yes=0;
        string bg;
        int quan;
        list<string>::iterator rec_itr; 
        list<string>& rec_pointer = *record_itr; 
        for (rec_itr = rec_pointer.begin();rec_itr != rec_pointer.end();rec_itr++) 
        { 
            if(count==0)
            {
                
                if(id==*rec_itr)
                {
                   yes=1;
                }
            }
            if(count==1)
            {
                if(yes==1)
                {
                   *rec_itr=name;
                }
            }
            count++;
        }
     }
        h->writeFile(record,out);
        cout<<"\n****************Hospital Name updated successfully****************\n";
}


/*function to update address of the Hospital
its return type is void and it takes nestedlist,ofstream,string,string as parameters
*/
void Update_Address(Hospital *h,list<list<string>> record,ofstream &out,string id,string address)
{
     list<list<string> >::iterator record_itr; 
     for (record_itr = record.begin();record_itr != record.end();++record_itr)
     { 
        int count=0;
        int yes=0;
        string bg;
        int quan;
        list<string>::iterator rec_itr; 
        list<string>& rec_pointer = *record_itr; 
        for (rec_itr = rec_pointer.begin();rec_itr != rec_pointer.end();rec_itr++) 
        { 
            if(count==0)
            {
                
                if(id==*rec_itr)
                {
                   yes=1;
                }
            }
            
            if(count==2)
            {
                if(yes==1)
                {
                   *rec_itr=address;
                }
            }
            count++;
            
        }    
     }
        h->writeFile(record,out);
        cout<<"\n******************Address updated successfully******************\n";
}


/*function to update phonenumber of the Hospital
its return type is void and it takes nestedlist,ofstream,string,long as parameters
*/
void Update_phonenumber(Hospital *h,list<list<string>> record,ofstream &out,string id,long phonenumber)
{
     list<list<string> >::iterator record_itr; 
     for (record_itr = record.begin();record_itr != record.end();++record_itr)
     { 
        
        int count=0;
        int yes=0;
        string bg;
        int quan;
        list<string>::iterator rec_itr; 
        list<string>& rec_pointer = *record_itr; 
        for (rec_itr = rec_pointer.begin();rec_itr != rec_pointer.end();rec_itr++) 
        { 
            if(count==0)
            {
                
                if(id==*rec_itr)
                {
                   yes=1;
                }
            }
           
            if(count==3)
            {
                if(yes==1)
                {
                   
                   *rec_itr=to_string(phonenumber);
                }
            }
           
            count++;
            
        } 
      }
        h->writeFile(record,out);
        cout<<"\n****************Phone Number Updated Successfully****************\n";
}


/*function to write data into the file
its return type void. it takes nestedlist,ofstream as parameters
*/
void Hospital :: writeData(list<list<string>> record,ofstream& out)
{
       list<list<string> >::iterator record_itr; 
       for (record_itr = record.begin();record_itr != record.end();++record_itr)
       { 
        
           int count=0;
           string bg;
           int quan;
           list<string>::iterator rec_itr; 
           list<string>& rec_pointer = *record_itr; 
           for (rec_itr = rec_pointer.begin();rec_itr != rec_pointer.end();rec_itr++) 
           { 
                if(count==0)
                {
                    bg=*rec_itr;
                } 
                if(count==1)
                {
                    quan=stoi(*rec_itr);
                }
                count++;
           }
           out<<bg<<","<<quan<<"\n";
        }
}

void Hospital :: writeFile(list<list<string>> record,ofstream &out)
{
     list<list<string> >::iterator record_itr; 
     for (record_itr = record.begin();record_itr != record.end();++record_itr)
     { 
        
        int count=0;
        int yes=0;
        string bg;
        int quan;
        list<string>::iterator rec_itr; 
        list<string>& rec_pointer = *record_itr; 
        for (rec_itr = rec_pointer.begin();rec_itr != rec_pointer.end();rec_itr++) 
        { 
            if(count!=3)
            {
              out<<*rec_itr<<",";
            }
            if(count==3)
            {
                out<<*rec_itr;
            }
            count++;
        }   
        out<<"\n";
      }
}

/*function to call writedata
its return type is void.it takes nestedlist,hospital object and ofstream as parameters
*/
void Hospital :: update_stock(list<list<string>> record,Hospital *h,ofstream& fout)
{    
     h->writeData(record,fout);
}

/*function to update order history
its return type is void.it takes ifstream,string,string,int as parameters
*/
void Hospital :: update_orderhistory(Order *o,ifstream &in,string id,string bg,int quantity)
{
    list<list<string>> record;
    int order_id;
    int bag_id;
    order_id=o->get_order_id(in);
    in.close();
    in.open("text_files/orderhistory.txt",ios::app);
    bag_id=o->get_packet_id(in);
    in.close();
    tm *dt;
    time_t now=time(0); 
    dt=localtime(&now); 
    ofstream out;
    out.open("text_files/orderhistory.txt",ios::app);
    out<<order_id<<","<<bag_id<<","<<id<<","<<bg<<","<<quantity<<","<<dt->tm_mday<<"/"<< (dt->tm_mon)+1<<"/"<< (dt->tm_year)+1900<<"\n";
    
}


//funtion to place order 
list<list<string>> Hospital :: Placeorder(list<list<string>> record,Hospital *h,Stock *s,Order *o,ofstream& out,string bg,int quantity,string id)
{
      list<list<string>> updatedrecord;
      if(s->check_quantity(record,bg,quantity))
      {
           updatedrecord=h->Update_list(record,bg,quantity);
           h->update_stock(updatedrecord,h,out);
           //out.close();
           cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
           cout<<"\n\t\tYOUR ORDER HAS BEEN SUCCESSFULLY PLACED...\n";
           cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
           ifstream in;
           in.open("text_files/orderhistory.txt");
           h->update_orderhistory(o,in,id,bg,quantity);
           in.close();
           return updatedrecord;
      }
      else
      {
           int quan=s->Available_Quantity(record,bg,quantity);
           if(quan!=0)
           {
            cout<<"\nOnly "<<quan<<" packets are available.Do you wish to place order\n(1-placeorder/0-go back to main menu)";
            cout<<"\nEnter your choice :: ";
            int choice;
            cin>>choice;
		    if(choice==1)
		    {
		       updatedrecord=h->Update_list(record,bg,quan);
		       h->update_stock(updatedrecord,h,out);
		       	cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
          		cout<<"\n\t\tYOUR ORDER HAS BEEN SUCCESSFULLY PLACED...\n";
         		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		       ifstream in;
		       in.open("text_files/orderhistory.txt");
		       h->update_orderhistory(o,in,id,bg,quan);
		       in.close();
		       return updatedrecord;
		   }
		   else
		   {
		        h->update_stock(record,h,out);
		        cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
           		cout<<"\n\t\tYOUR ORDER CANNOT BE PLACED DUE TO STOCK INSUFFICIENCY!!!\n";
           		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
		        
		        return record;
		   }
           
           }
           else
           {
                h->update_stock(record,h,out);
                cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
           	cout<<"\n\t\tYOUR ORDER CANNOT BE PLACED DUE TO STOCK INSUFFICIENCY!!!\n";
           	cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
               
                return record;
           }
      }
      
}

/* 
Funciton definition to accept details of hospital to regiter for first time
It's void return type and does not take any parameter
*/
string Hospital :: hospital_accept()
{	
	//Calling functions for validation
	
	name = get_H :: name_validation();
	if(name == "Invalid")
	{
		return "Invalid";
	}
	
	phone_number = get_H :: phonenumber_validation();
	if(phone_number == -1)
	{
		return "Invalid";
	}
	
	address = get_H :: address_validation();
	if(address == "Invalid")
	{
		return "Invalid";
	}
	
	//Displaying Password Criteria
	cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout<<"\tPassword Criteria :: ";
	cout<<"\n\n-----------------------------------------------------------------------------------------------------------------\n";
	cout<<"\nPassword should contain\n\n--> Atleast one numeric value.\n--> Alteast one lower case and one upper case alphabet.\n--> Atleast one special character.\n--> Only special characters (@,#,$,_,&,*) are allowed.\n--> Password should be atleast 8 characters and maximum of 15 characters long.\n";
	cout<<"\n\n-----------------------------------------------------------------------------------------------------------------\n";
	
	password = password_validation();
	if(password == "Invalid")
	{
		return "Invalid";
	}
	
	return "Valid";
}


/* 
Funciton definition to validate hospital name
Check whether it contains characters only
It's return type is string and it does not take any parameter
*/
string get_H:: name_validation()
{
	string name;
	int count = 0;
		 
	cout<<"\nEnter Hospital Name: ";
	getline(cin >> ws, name);
	
	if(name == "q")
	{
		cout<<endl<<"-------------------------------------------------"<<endl;
		cout<<"\n\tEntered to Previous Menu"<<endl;
		cout<<endl<<"-------------------------------------------------"<<endl;
		
		return "Invalid";
	}
     	else
     	{
     		for(int i=0;i<name.length();i++)
		{
			if( (name[i]>='a' &&  name[i]<='z') || (name[i]>='A' && name[i]<='Z') || name[i]==' '  )
				continue;
			else
			{
				cout<<endl<<"-------------------------------------------------"<<endl;
				cout<<endl<<"\t\tInvalid Name...!! Re-Enter"<<endl;
				cout<<endl<<"\nPress q to Enter Main Menu"<<endl;
				cout<<endl<<"-------------------------------------------------"<<endl;
				
				name = name_validation();
			}
		}
		
		count = name.length();
		
		if(count > 20)
		{
			cout<<endl<<"-------------------------------------------------"<<endl;
			cout<<endl<<"\tFirst Name is too Long !!!\n\t";
			cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
			cout<<endl<<"-------------------------------------------------"<<endl;
			
			name = name_validation();
		}
		else if(count <= 2)
		{
			cout<<endl<<"-------------------------------------------------"<<endl;
			cout<<endl<<"\tFirst Name is too short !!!\n\t";
			cout<<endl<<"\nPress q to Enter Main Menu...."<<endl;
			cout<<endl<<"-------------------------------------------------"<<endl;
			
			name = name_validation();
		}
		
     		return name;    	
	}    
}


/* 
Funciton definition to validate phone number
Check whether it contains 10 digits number
It's return type is long and it does not take any parameter
*/
long get_H :: phonenumber_validation()
{
	long phonenumber, ph;
	int digit = 0;
	string ph_no;
	
	cout<<"\nEnter Phone Number: ";
	cin>>ph_no;
	
	if(ph_no == "q")
	{
		cout<<endl<<"-------------------------------------------------"<<endl;
		cout<<"\n\tEntered to Previous Menu"<<endl;
		cout<<endl<<"-------------------------------------------------"<<endl;
		
		return -1;
	}
	else
	{
		phonenumber = stol(ph_no);
		ph = phonenumber;
		
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
			cout<<endl<<"\nPress q to Enter Previous Menu...."<<endl;
			cout<<endl<<"-------------------------------------------------"<<endl;
			
			phonenumber = phonenumber_validation();
		}
		return phonenumber;
	}
}


/* 
Funciton definition to validate address
Check whether it contains characters ('a to z' || 'A to Z' || (- and /))
It's return type is string and it does not take any parameter
*/
string get_H :: address_validation()
{
	string address;
	int count=0;
	
	cout<<"\nEnter Address: ";
	getline(cin >> ws, address);
	
	if(address == "q")
	{
		cout<<endl<<"-------------------------------------------------"<<endl;
		cout<<"\n\tEntered to Previous Menu"<<endl;
		cout<<endl<<"-------------------------------------------------"<<endl;
		
		return "Invalid";
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
Funciton definition to generate Hospital Id
It reads latest id from hospital_details.txt file as a reference
It's return type is string and it does not take any parameter
*/
string Hospital :: get_Latest_Hospital_Id()
{

	int gid;
	string eid,add,ph,hname;
	string str;
	string get_id;
	
	ifstream in("text_files/Hospital_details.txt");			//Creating object for ifstream named in
	
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
		getline(ss, hname, ',');		//Dividing the line into parts(firstname)
		getline(ss, add, ',');			//Dividing the line into parts(address)
		getline(ss, ph, ',');			//Dividing the line into parts(phonenumber)
	
		str = eid.substr(1,9);			//String stripping to get integer part.
	}
	gid = stoi(str);				//Typecasting string to int
	in.seekg(0, ios::beg);				//File Pointing back to start
	in.close();					//Closing file (deallocating file pointer)
	
	gid = gid + 1;					//Incrementing latest id
	get_id = "H" + to_string(gid);			//Concatinating strings and typecasting int to string
	
	return get_id;					//Returning latest id
}



/* 
Funciton definition to append hospital details into hospital_details.txt
It appends hospitals's new id, name, phone number and address
It's return type is void and it does not take any parameter
*/
void Hospital :: append_Hospital_Details()
{
	string get_hospital_id = get_Latest_Hospital_Id();
	
	//------------------------------------------------Appending in Hospital_details.txt file-------------------------------------------------------
	
	ofstream out;					//Creating an object for ofstream
	
	out.open("text_files/Hospital_details.txt", ios::app);	//Opening file to append
	if(!out.is_open())				//Checing for file existance
	{
		cout<<"\n----------------------------------------------------------------\n";
		cout<<"\n\t\tCannot find Text file named : hospital_details.txt"<<endl;
		cout<<"\n----------------------------------------------------------------\n\n";
		
		exit(0);				//Exit
	}
	
	//Writing into the file hospital_details.txt
	out<<get_hospital_id<<","<<this->name<<","<<this->address<<","<<this->phone_number;	
	
	out<<endl;
	
	out.close();					//Closing file(deallocating file pointer)
	
	
	
	
	//------------------------------------------------Appending in hospital_credential.txt file-------------------------------------------------------
	
	ofstream out1;						//Creating an object for ofstream
	
	out1.open("text_files/hospital_credential.txt", ios::app);		//Opening file to append
	if(!out1.is_open())					//Checing for file existance
	{
		cout<<"\n---------------------------------------------------------------------------------------------------------------------\n";
		cout<<"\n\t\tCannot find Text file named : hospital_credential.txt"<<endl;
		cout<<"\n---------------------------------------------------------------------------------------------------------------------\n\n";
		
		exit(0);					//Exit
	}
	
	out1<<get_hospital_id<<","<<this->password;	//writing to file hospital_credential.txt
	
	out1<<endl;
	
	cout<<"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	cout<<"\n\t\t\t\tACCOUNT CREATED SUCCESSFULLY...."<<endl;
	cout<<"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
	
	out1.close();					//Closing file(deallocating file pointer)
}


/* 
Funciton definition to validate password
Check whether it contains alphanumeric ('a to z' || 'A to Z' || (1 to 9))
Special Characters allowed are : (@ # $ % * & _)
It's return type is string and it does not take any parameter
*/
string Hospital :: password_validation()
{
	string password;
	int scount=0,dcount=0,lcount=0,ucount=0,count=0;
	
	cout<<"\nEnter Password: ";
	cin>>password;
	
	if(password == "q")
	{
		cout<<endl<<"-------------------------------------------------"<<endl;
		cout<<"\n\tEntered to Previous Menu"<<endl;
		cout<<endl<<"-------------------------------------------------"<<endl;
		
		return "Invalid";
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
Funciton definition to display hospital details
It's void return type and does not take any parameter
*/
void Hospital :: Hospital_display()
{
    cout<<"\nName ::\t\t  "<<name;
    cout<<"\nAddress ::\t  "<<address;
    cout<<"\nPhone No. ::\t  "<<phone_number;
}

//function to navigate through options
void get_H :: get_H_choice(string id)
{
     int choice;
     Stock *s;
     Hospital *h;
     Order *o;
     do
     {
         Display::display_H_menu();
         cout<<"\nEnter your choice::  ";
         cin>>choice;
         switch(choice)
         {
              case H_DISPLAY:  //to display personal details of hospital
              {	
              		system("clear");
              		
                    ifstream in;
                    in.open("text_files/Hospital_details.txt");
                    if(!in.is_open())
                    { 
                          cout<<"\n invalid text file";
                           exit(0);
                    }
                    
                    cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
                    cout<<"\n\t\tHOSPITAL DETAILS ::\n";
                    h->readData(h,in,id);
                    cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
                    in.close();
                    break;
               }
                    
              case H_MAKEORDER:   // Make order for blood bags
              {
              		system("clear");
              	
                   cout<<"\nEnter blood group to order::  ";
                   string bg;
                   cin>>bg;
                   
                   cout<<"\nEnter Quantity::  ";
                   int quantity;
                   cin>>quantity;
                   
                   ifstream in;
                   in.open("text_files/stock.txt");
                   
                   if(!in.is_open())
                   { 
                       cout<<"\n Invalid text file!!!";
                       exit(0);
                   }
                   
                   //loading data into the list
                   list<list<string> > record;
                   record=h->Load_data_into_list(in);
                   
                   in.close();
                   in.open("text_files/stock.txt");
                   
                   //checking if blood group is valid
                   if(h->IsBloodgroupValid(record,bg))
                   {
                       in.close();
                       ofstream out;
                       out.open("text_files/stock.txt");
                   
                       if(!out.is_open())
                       { 
                           cout<<"\n Invalid text file";
                          exit(0);
                       }
                       //placing order
                       record=h->Placeorder(record,h,s,o,out,bg,quantity,id);
                       out.close();  
                   }  
                   else
                   {
                        cout<<"\n*********Oops!!!Your required Blood group is not in our stock*********\n";
                   }
                   record.clear();
                   break;
              } 
                 
              case H_SEARCH: //searching for required blood group and displaying details
              {   
              		system("clear");
              	
                   cout<<"\nEnter blood group to search::  ";
                   string bg;
                   cin>>bg;
                   ifstream in;
                   in.open("text_files/stock.txt");
                   if(!in.is_open())
                   { 
                       cout<<"\n Invalid text file";
                       exit(0);
                   }
                   s->searchBloodgroup(s,in,bg);
                   in.close();
                   break;
                   
              }
                   
              case H_UPDATE:  //editing personal details
              {
              		system("clear");
              	
                   ifstream in;
                   int ch;
                  
                   list<list<string> > record;
     
                   do
                   {
                       system("clear");
                   	
                       cout<<"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
                       cout<<"\n\t\tSELECT AN OPTION TO PROCEED : \n\n\t\t\t61. Update Hospital Name\n\t\t\t62. Update Address\n\t\t\t63. Update Phone Number\n\t\t\t65. Previous Menu\n";
                       cout<<"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
                       cout<<"\nEnter your choice::  ";
                       cin>>ch;
                       switch(ch)
                       {
                            case H_NAME:  //updating name
                            {
                            		system("clear");
              	
                                 string new_name;
                                 new_name = name_validation();
                                 if(new_name != "Invalid")
                                 {
		                         in.open("text_files/Hospital_details.txt");
		                         record=h->Load_data_into_list(in);
		                         in.close();
		                         ofstream out;
		                         out.open("text_files/Hospital_details.txt");
		                         Update_Name(h,record,out,id,new_name);
		                         out.close();
		                         record.clear();
                                 }
                                 break;
                            }    
                            
                            case H_ADDRESS:  //updating address
                            {
                            		system("clear");
              	
                                 string new_address;
                                 new_address = address_validation();
                                 if(new_address != "Invalid")
                                 {
		                         in.open("text_files/Hospital_details.txt");
		                         record=h->Load_data_into_list(in);
		                         in.close();
		                         ofstream out;
		                         out.open("text_files/Hospital_details.txt");
		                         Update_Address(h,record,out,id,new_address);
		                         out.close();
		                         record.clear();
                                 }
                                 break;
                            }   
                            case H_PHONENUMBER:  //updating phonenumber
                            {
                            		system("clear");
              	
                                 long phno;
                                 phno = phonenumber_validation();
                                 if(phno != -1)
                                 {
		                         in.open("text_files/Hospital_details.txt");
		                         record=h->Load_data_into_list(in);
		                         in.close();
		                         ofstream out;
		                         out.open("text_files/Hospital_details.txt");
		                         Update_phonenumber(h,record,out,id,phno);
		                         record.clear();
                                 }
                                 break;
                            }    
                            case H_BACK:
                                 ch=0;
                                 break;
                             
                            default:
                                 cout<<"Invalid choice";
                                 break;
                       }   
                   }while(ch!=0);
                   
                   break;
              }  
              case H_ORDERHISTORY:
              {
              		system("clear");
              	
                   list<list<string> > record;
                   ifstream in;
                   in.open("text_files/orderhistory.txt");
                   record=h->Load_data_into_list(in);
                   in.close();
                   
                   cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
                   cout<<"\n\t\tYOUR ORDER HISTORY\n";
                   o->display_orderhistory(record,id);
                   cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
                   break;
                   
              }  
              case H_LOGOUT:
              {
              	   system("clear");
              	   
              	   cout<<endl<<"\n-------------------------------------------------------------------------------\n\n";
                   cout<<"\nYou are been LOGGED OUT....";
                   cout<<endl<<"\n-------------------------------------------------------------------------------\n\n";
                   sleep(1);
                   choice=0;
                   break;
              }
                   
              default:
              		system("clear");
              		
                   cout<<"\nInvalid choice";
                   break;
                        
         }
     }while(choice!=0);
     
     cout<<"\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
     cout<<"\n\t\t\tTHANK YOU!!";
     cout<<"\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
     sleep(1);
    
     return;
}


