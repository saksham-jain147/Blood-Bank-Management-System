/*
This file contains all the definition functions which are declared in class Donor..
*/
#include"donor.h"


/*default constructor of class donor
It has no return type and does not take any parameter*/
Donor :: Donor()
{
    donor_id="\0";
}

/*Parameterized Constructor for donor Class
It has no return type and it takes parameter as: 
sstring id,tring firstname, string lastname, string bg,long aadhaar,long phno, string gender,int d,int m,int y, string address, string password
This contains date class and person class
*/
Donor :: Donor(string did,string f_name,string l_name,string bg,long aadhaar,long phno,string gender,int d,int m,int y,string address,string password):Person(f_name,l_name,bg,aadhaar,phno,gender,d,m,y,address,password)
{
    donor_id=did;
}

/* 
Funciton definition to set user donor_id
It's void return type and it takes string as a parameter
*/
void Donor :: setDonorid(string did)
{
    donor_id=did;
}

/* 
Funciton definition to get user Donor_id
It's return type is string and it takes no parameters
*/
string Donor :: getDonorid()
{
    return donor_id;
}

/*
/* 
Funciton definition to set user Donor_id
It's void return type and it takes string as a parameter
*/
void Donor :: setPassword(string password)
{
    this->password=password;
}

/* 
Funciton definition to get user Donor_id
It's return type is string and it takes no parameters
*/
string Donor :: getPassword()
{
    return this->password;
}

/*

 
Funciton definition to display donor details
It's void return type and does not take any parameter
and it calls display function of person class
*/
void Donor :: display()
{
    cout<<"\ndonorid::  "<<donor_id;
    Person :: display();
}

/*function definition to display options given to donor
its void return type and takes no parameters
*/
void Display::displaymenu()
{
    cout<<"\n*********************Select an  Option to Proceed*********************\n\n\t\t\t1. Display Donor Details\n\t\t\t2. Make Donation\n\t\t\t3. Edit personal Details\n\t\t\t4. view donation history\n\t\t\t0. logout\n";
}


/*function  definition to display donor details
its return type is void and takes nested list as parameter
*/
void Donor :: printNestedList(list<list<string> > record) 
{ 
    list<list<string> >::iterator record_itr; 
    // Print the nested_list 
    for (record_itr = record.begin();record_itr != record.end();++record_itr)
    { 
        
        int count=0;
        list<string>::iterator rec_itr; 
        list<string>& rec_pointer = *record_itr; 
        for (rec_itr = rec_pointer.begin();rec_itr != rec_pointer.end();rec_itr++) { 
            if(count==0)
            {
                cout << "\n\tid::  " << *rec_itr << " "; 
            }
            if(count==1)
            {
                cout << "\n\tfirst name::  " << *rec_itr << " ";
            }
            if(count==2)
            {
                cout << "\n\tlast name::  " << *rec_itr << " ";
            }
            if(count==3)
            {
                cout << "\n\tbloodgroup::  " << *rec_itr << " ";   
            }
             
            if(count==4)
            {
                cout << "\n\taadhaar::  " << *rec_itr << " ";
            }
            
            if(count==5)
            {
                cout << "\n\tPhonenumber::  " << *rec_itr << " ";
            }
           
            if(count==6)
            {
                cout << "\n\tgender::  " << *rec_itr << " ";
            }
            if(count==7)
            {
                cout << "\n\tDOB ::  " << *rec_itr << " ";
            }
            if(count==8)
            {
                cout << "\n\taddress::  " << *rec_itr << " ";
            }
            count++;
            
        } 

       cout<<endl;

    } 
}

/*function definition to read data from the file
its return type is void and takes donor object,input stream,and string as parameters
*/
void Donor::readData(Donor *eptr,ifstream& fin,string id)
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
           cout<<"\nwrong details";
       }
       
}

/*function definition to load data in file to database
its return type is nestedlist
*/
list<list<string>> Donor :: load_Data_into_list(ifstream& fin)
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


//function to update list containing stock details
list<list<string>> Donor :: Update_list(list<list<string>> record,string bg,int quantity)
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
                         int updated_quantity;
                         updated_quantity=quan+quantity;
                         *rec_itr=to_string(updated_quantity);
                         return record;
                     }
               }
               count++;
            }
       }
   
       return record;
}


//function to update name
void Update_Name(Donor *d,list<list<string>> record,ofstream &out,string id,string name)
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
        d->writeFile(record,out);
        cout<<"\n****************your first name is updated successfully****************\n";
}

void Update_last_Name(Donor *d,list<list<string>> record,ofstream &out,string id,string name)
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
                   *rec_itr=name;
                }  
            }
            count++;
            
        }  
        }
        d->writeFile(record,out);
        cout<<"\n*****************your lastname is updated successfully*****************\n";
}



//function to update address
void Update_Address(Donor *d,list<list<string>> record,ofstream &out,string id,string address)
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
            if(count==8)
            {
                if(yes==1)
                {
                   *rec_itr=address;
                }
            }
            count++;
            
        }  
        }
        d->writeFile(record,out);
        cout<<"\n******************your address is updated successfully******************\n";
}


//function to update the phonenumber
void Update_phonenumber(Donor *d,list<list<string>> record,ofstream &out,string id,long phonenumber)
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
            if(count==5)
            {
                if(yes==1)
                {
                   
                   *rec_itr=to_string(phonenumber);
                }
            }
            count++;
            
        }  
        }
        d->writeFile(record,out);
        cout<<"\n****************your phonenumber is updated successfully****************\n";
}


//function to write data into the file
void Donor :: writeData(list<list<string>> record,ofstream& out)
{
       //eptr->writeFile(out);
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


//function to call writedata
void Donor::update_stock(list<list<string>> record,Donor *s,ofstream& fout)
{    
     s->writeData(record,fout);
}


int donation::get_donation_id(ifstream &in)
{
       string bg,o_id,b_id,c_id,quan;
       int latest_o_id;
       string temp;
       while(getline(in,temp))
       {
            stringstream data(temp);
            getline(data,o_id,',');
            getline(data,b_id,',');
            getline(data,c_id,',');
            getline(data,bg,',');
            getline(data,quan,',');   
       }
     //  latest_o_id=stoi(o_id)+1;
       
       return stoi(o_id)+1;
}

int packet::get_packet_id(ifstream &in)
{
       string o_id,b_id,c_id,quan;
       string bg;
       string temp;
       int latest_o_id;
       while(getline(in,temp))
       {
            stringstream data(temp);
            getline(data,o_id,',');
            getline(data,b_id,',');
            getline(data,c_id,',');
            getline(data,bg,',');
            getline(data,quan,',');   
       }
       return stoi(b_id)+1;
}


void Donor :: writeFile(list<list<string>> record,ofstream &out)
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
            if(count!=8)
            {
              out<<*rec_itr<<",";
            }
            if(count==8)
            {
                out<<*rec_itr;
            }
            count++;
        }   
        out<<"\n";
      }
}


void Donor :: update_donation_history(ifstream &in,string id,string bg,int quantity)
{
    list<list<string>> record;
    int donation_id;
    int bag_id;
    donation_id=donation::get_donation_id(in);
    in.close();
    in.open("credential_files/donationhistory.txt",ios::app);
    bag_id=packet::get_packet_id(in);
    in.close();
    tm *dt;
    time_t now=time(0); 
    dt=localtime(&now); 
    ofstream out;
    if(quantity>0)
    {
		out.open("credential_files/donationhistory.txt",ios::app);
		out<<donation_id<<","<<bag_id<<","<<id<<","<<bg<<","<<quantity<<","<<dt->tm_mday<<"/"<< (dt->tm_mon)+1<<"/"<< (dt->tm_year)+1900<<"\n";
    }
    out.close();
}
//funtion to Make donation 
list<list<string>> Donor :: Makedonation(list<list<string>> record,Donor *s,ofstream& out,string bg,int quantity,string id)
{
      list<list<string>> updated_record;
      updated_record=s->Update_list(record,bg,quantity);
      s->update_stock(updated_record,s,out);
      //out.close();
      if(quantity>0)
      {
      	cout<<"\n*************************Your Donation is received*************************\n";
      	return updated_record;
      }
      else
      {
      	cout<<"\n*************************Your Donation is Not valid*************************\n";
      	return record;
      }  
}


string Donor :: get_Blood_group(Donor *d,list<list<string>> record,ofstream &out,string id)
{

     string bg;
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
                
                if(id==*rec_itr)
                {
                   yes=1;
                }
            }
            if(count==3)
            {
                if(yes==1)
                {
                   
                   bg=*rec_itr;
                }
            }
            count++;
            
        }  
        }
        d->writeFile(record,out);
        return bg;
}


void display_donation_history(list<list<string> >record,string id)
{
    list<list<string> >::iterator record_itr; 
    // Print the nested_list 
    string donation_id,packet_id;
    for (record_itr = record.begin();record_itr != record.end();++record_itr)
    { 
        
        int count=0;
        int yes=0;
        list<string>::iterator rec_itr; 
        list<string>& rec_pointer = *record_itr; 
        for (rec_itr = rec_pointer.begin();rec_itr != rec_pointer.end();rec_itr++) { 
            if(count==0)
            {
                donation_id=*rec_itr; 
            }
            if(count==1)
            {
                packet_id=*rec_itr; 
            }
            if(count==2)
            {
                if(*rec_itr==id)
                {
                  yes=1;
                  cout << "\n\tdonation_id::  " << donation_id << " ";
                  cout << "\n\tpacket_id::  " << packet_id << " ";
                  cout << "\n\tdonor_id::  " << *rec_itr << " ";
                }
            }
            if(count==3 and yes==1)
            {
                cout << "\n\tbloodgroup::  " << *rec_itr << " ";   
            }
             
            if(count==4 and yes==1)
            {
                cout << "\n\tquantity::  " << *rec_itr << " ";
                cout<<endl;
            }
            if(count==5 and yes==1)
            {
                cout << "\tDate::  " << *rec_itr << " ";
                cout<<endl;
            }	
            
            count++;
            
        } 

    } 
}

void get::getchoice()
{
     int choice;
     string id;
     cout<<"\nEnter id::  ";
     cin>>id;
     Stock *s;
     Donor *d;
     do
     {
         Display::displaymenu();
         cout<<"\nEnter your choice::  ";
         cin>>choice;
         switch(choice)
         {
              case DISPLAY:  //to display personal details of Donor
              {
                    ifstream in;
                    in.open("credential_files/donor_details.txt");
                    if(!in.is_open())
                    { 
                          cout<<"\n invalid text file";
                           exit(0);
                    }
                    
                    cout<<"\ndonor details::  \n";
                    d->readData(d,in,id);
                    in.close();
                    break;
               }
                    
              case DONATION:   // Make donation
              {
                   string bg;
                   list<list<string> > record;
                   ifstream in;
				   in.open("credential_files/donor_details.txt");
				   record=d->load_Data_into_list(in);
				   in.close();
                   ofstream out;
                   out.open("credential_files/donor_details.txt");
                   bg=d->get_Blood_group(d,record,out,id);
                   record.clear();
                   out.close();
                   cout<<"\nEnter quantity in packets (1 packet = 250ml)::  ";
                   int quantity;
                   cin>>quantity;
                   
                   
                   in.open("credential_files/stock.txt");
                   
                   if(!in.is_open())
                   { 
                       cout<<"\n invalid text file";
                       exit(0);
                   }
                   
                   //loading data into the list
                   //list<list<string> > record;
                   record=d->load_Data_into_list(in);
                   
                   in.close();
                  // ofstream out;
                   out.open("credential_files/stock.txt");
                   if(!out.is_open())
                   { 
                        cout<<"\n invalid text file";
                        exit(0);
                   }
                   //making donation
                   record=d->Makedonation(record,d,out,bg,quantity,id);
                   out.close();
                   //ifstream in;
                   in.open("credential_files/donationhistory.txt");
                   d->update_donation_history(in,id,bg,quantity);
                   record.clear();
                   break;
              } 
                   
              case UPDATE:  //editing personal details
              {
                   ifstream in;
                   int ch;
                   //in.open("credential_files/Donor_details.txt");
                   list<list<string> > record;
     
                   do
                   {
                       cout<<"\n*********************Select an  Option to Proceed*********************\n\n\t\t\t31. Update first name\n\t\t\t32. Update last name\n\t\t\t33. Update address\n\t\t\t34. update Phone number\n\t\t\t35. previous menu\n";
                       cout<<"\nEnter your choice::  ";
                       cin>>ch;
                       switch(ch)
                       {
                            case F_NAME:  //updating first name
                            {
                                 string updated_name;
                                 updated_name=d->Person :: firstname_validation();
                                 if(updated_name!="NULL")
                                 {
                                 in.open("credential_files/donor_details.txt");
                                 record=d->load_Data_into_list(in);
                                 in.close();
                                 ofstream out;
                                 out.open("credential_files/donor_details.txt");
                                 Update_Name(d,record,out,id,updated_name);
                                 out.close();
                                 record.clear();
                                 }
                                 break;
                            }    
                            
                            case L_NAME:  //updating last name
                            {
                                 string updated_name;
                                 updated_name=d->Person :: lastname_validation();
                                 if(updated_name!="NULL")
                                 {
                                 in.open("credential_files/donor_details.txt");
                                 record=d->load_Data_into_list(in);
                                 in.close();
                                 ofstream out;
                                 out.open("credential_files/donor_details.txt");
                                 Update_last_Name(d,record,out,id,updated_name);
                                 out.close();
                                 record.clear();
                                 }
                                 break;
                            }    
                            
                            case ADDRESS:  //updating address
                            {
                                 string updated_address;
                                 updated_address=d->Person :: address_validation();
                                 if(updated_address!="NULL")
                                 {
                                 in.open("credential_files/donor_details.txt");
                                 record=d->load_Data_into_list(in);
                                 in.close();
                                 ofstream out;
                                 out.open("credential_files/donor_details.txt");
                                 Update_Address(d,record,out,id,updated_address);
                                 out.close();
                                 record.clear();
                                 }
                                 break;
                            }   
                            case PHONENUMBER:  //updating phonenumber
                            {
                                 long updated_phno;
                                 updated_phno=d->Person::phonenumber_validation();
                                 if(updated_phno!=0)
                                 {
                                 in.open("credential_files/donor_details.txt");
                                 record=d->load_Data_into_list(in);
                                 in.close();
                                 ofstream out;
                                 out.open("credential_files/donor_details.txt");
                                 Update_phonenumber(d,record,out,id,updated_phno);
                                 record.clear();
                                 }
                                 break;
                            }    
                            case BACK:
                                 ch=0;
                                 break;
                             
                            default:
                                 cout<<"Invalid choice";
                                 break;
                       }   
                   }while(ch!=0);
                   
                   break;
              }  
              case DONATIONHISTORY:
              {
                   list<list<string> > record;
                   ifstream in;
                   in.open("credential_files/donationhistory.txt");
                   record=d->load_Data_into_list(in);
                   in.close();
                   cout<<"\n*************************Donation history*************************\n";
                   display_donation_history(record,id);
                   break;
              }  
              case LOGOUT:
                   exit(0);
                   
              default:
                   cout<<"\nInvalid choice";
                   break;
                        
         }
     }while(choice!=0);
     delete[] s;
     delete[] d;
}

bool Donor::credential_validation(string id,string pwd)
{
	int i;
	bool flg = false;
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	ifstream in;
	in.open("donor_credential.txt");
	if(!in.is_open())
	{
		cout<<"\nCannot open file...!!\n";
		exit(0);
	}
	while(getline(in,temp))
	{
		word.clear();
		stringstream data(temp);
		while(getline(data,con,','))
			word.push_back(con);
		lines.push_back(word);
	}
	in.close();
	for(i=0;i<(int)lines.size();i++)
	{
		if(id==lines[i][0] && pwd==lines[i][1])
		{
			flg = true;
			break;
		}
	}
	if(flg)
	{
		setDonorid(id);
		setPassword(pwd);
	}
	
	return flg;
}










