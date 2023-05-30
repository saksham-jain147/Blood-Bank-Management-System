/*
This file contains all the definition functions which are declared in class Customer..
*/
#include"customer.h"


/*default constructor of class customer
It has no return type and does not take any parameter
*/
Customer :: Customer()
{
    customer_id="\0";
}

/*Parameterized Constructor for Customer Class
It has no return type and it takes parameter as: 
sstring id,tring firstname, string lastname, string bg,long aadhaar,long phno, string gender,int d,int m,int y, string address, string password
This contains date class and person class
*/
Customer :: Customer(string cid,string f_name,string l_name,string bg,long aadhaar,long phno,string gender,int d,int m,int y,string address,string password):Person(f_name,l_name,bg,aadhaar,phno,gender,d,m,y,address,password)
{
    customer_id=cid;
}


/*Funciton definition to set user customer_id
It's void return type and it takes string as a parameter
*/
void Customer :: setCustomerid(string id)
{
    this->customer_id=id;
}

/* 
Funciton definition to get user customer_id
It's return type is string and it takes no parameters
*/
string Customer :: getCustomerid()
{
    return this->customer_id;
}

/* 
Funciton definition to set user customer_id
It's void return type and it takes string as a parameter
*/
void Customer :: setPassword(string password)
{
    this->password=password;
}

/* 
Funciton definition to get user customer_id
It's return type is string and it takes no parameters
*/
string Customer :: getPassword()
{
    return this->password;
}

/* 

/* 
Funciton definition to display customer details
It's void return type and does not take any parameter
and it calls display function of person class
*/
void Customer :: display()
{
    cout<<"\ncustomerid::  "<<customer_id;
    Person :: display();
}



/*function definition to display options given to customer
its void return type and takes no parameters
*/
void Display :: displaymenu()
{
    cout<<"\n*********************Select an  Option to Proceed*********************\n\n\t\t\t1. Display Customer Details\n\t\t\t2. Request for blood\n\t\t\t3. Search for a blood group\n\t\t\t4. Edit personal Details\n\t\t\t5. view order history\n\t\t\t0. logout\n";
}


/*function  definition to display customer details
its return type is void and takes nested list as parameter
*/

/*void Customer :: printNestedList(list<list<string> > record) 
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
                cout << "\n\tid::  " << *rec_itr << " "; //record[i][0]
            }
            if(count==1)
            {
                cout << "\n\tfirst name::  " << *rec_itr << " "; ///firstname:: name 
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
}*/

void Customer :: printNestedList(list<list<string> > record) 
{
      string x[record.size()][9];
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
       cout << "\n\tid::  " << x[i][0]; //record[i][0]
       cout << "\n\tfirst name::  " << x[i][1]; ///firstname:: name 
       cout << "\n\tlast name::  " << x[i][2];
       cout << "\n\tbloodgroup::  " << x[i][3];   
       cout << "\n\taadhaar::  " << x[i][4];
       cout << "\n\tPhonenumber::  " <<x[i][5];
       cout << "\n\tgender::  " << x[i][6];
       cout << "\n\tDOB ::  " << x[i][7];
       cout << "\n\taddress::  " << x[i][8];
     }

}


/*function definition to read data from the file
its return type is void and takes customer object,input stream,and string as parameters
*/
void Customer::readData(Customer *eptr,ifstream& fin,string id)
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
             getline(data,str,',');  ///[[1][2][3]]
             
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
list<list<string>> Customer :: Load_data_into_list(ifstream& fin)
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
bool Customer::IsBloodgroupValid(list<list<string> > record,string bg)
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
list<list<string>> Customer :: Update_list(list<list<string>> record,string bg,int quantity)
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


/*function to update name of the customer
its return type is void and it takes nestedlist,ofstream,string,string as parameters
*/
void Update_Name(Customer *c,list<list<string>> record,ofstream &out,string id,string name)
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
            if(count==0)   //[[1,2,3,4,5][2,3,4,5]]
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
                    cout<<name;
                   *rec_itr=name;
                }
            }    
            count++;   
        }   
      }
      
        c->writeFile(record,out);
        cout<<"\n****************your first name is updated successfully****************\n";
        //delete[] c;
}

/*function to update last name of the customer
its return type is void and it takes nestedlist,ofstream,string,string as parameters
*/
void Update_last_Name(Customer *c,list<list<string>> record,ofstream &out,string id,string name)
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
        c->writeFile(record,out);
        cout<<"\n*****************your lastname is updated successfully*****************\n";
        //delete[] c;
}

/*function to update address of the customer
its return type is void and it takes nestedlist,ofstream,string,string as parameters
*/
void Update_Address(Customer *c,list<list<string>> record,ofstream &out,string id,string address)
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
               // out <<*rec_itr <<","; 
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
        c->writeFile(record,out);
        cout<<"\n******************your address is updated successfully******************\n";
}

/*function to update phonenumber of the customer
its return type is void and it takes nestedlist,ofstream,string,long as parameters
*/
void Update_phonenumber(Customer *c,list<list<string>> record,ofstream &out,string id,long phonenumber)
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
        c->writeFile(record,out);
        cout<<"\n****************your phonenumber is updated successfully****************\n";
}


/*function to write data into the file
its return type void. it takes nestedlist,ofstream as parameters
*/
void Customer :: writeData(list<list<string>> record,ofstream& out)
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

void Customer :: writeFile(list<list<string>> record,ofstream &out)
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

/*function to call writedata
its return type is void.it takes nestedlist,customer object and ofstream as parameters
*/
void Customer :: update_stock(list<list<string>> record,Customer *s,ofstream& fout)
{    
     s->writeData(record,fout);
}


/*function to update order history
its return type is void.it takes ifstream,string,string,int as parameters
*/
void Customer :: update_orderhistory(Order *o,ifstream &in,string id,string bg,int quantity)
{
    list<list<string>> record;
    int order_id;
    int bag_id;
    order_id=o->get_order_id(in);
    in.close();
    in.open("credential_files/orderhistory.txt",ios::app);
    bag_id=o->get_packet_id(in);
    in.close();
    tm *dt;
    time_t now=time(0); 
    dt=localtime(&now); 
    ofstream out;
    out.open("credential_files/orderhistory.txt",ios::app);
    out<<order_id<<","<<bag_id<<","<<id<<","<<bg<<","<<quantity<<","<<dt->tm_mday<<"/"<< (dt->tm_mon)+1<<"/"<< (dt->tm_year)+1900<<"\n";
    
}

//funtion to place order 
list<list<string>> Customer :: Placeorder(list<list<string>> record,Customer *s,Stock *c,Order *o,ofstream& out,string bg,int quantity,string id)
{
      list<list<string>> updatedrecord;
      if(c->check_quantity(record,bg,quantity))
      {
           updatedrecord=s->Update_list(record,bg,quantity);
           s->update_stock(updatedrecord,s,out);
           //out.close();
           cout<<"\n*************************Your Order is placed*************************\n";
           ifstream in;
           in.open("credential_files/orderhistory.txt");
           s->update_orderhistory(o,in,id,bg,quantity);
           in.close();
           return updatedrecord;
      }
      else
      {
           int quan=c->Available_Quantity(record,bg,quantity);
           if(quan!=0)
           {
            cout<<"\nOnly "<<quan<<" packets are available.Do you wish to place order\n(1-placeorder/0-go back to main menu)";
            cout<<"\nEnter your choice :: ";
            int choice;
            cin>>choice;
            if(choice==1)
            {
               updatedrecord=s->Update_list(record,bg,quan);
               s->update_stock(updatedrecord,s,out);
               cout<<"\n*************************Your Order is placed*************************\n";
               ifstream in;
               in.open("credential_files/orderhistory.txt");
               s->update_orderhistory(o,in,id,bg,quan);
               in.close();
               return updatedrecord;
           }
           else
           {
                s->update_stock(record,s,out);
                cout<<"\n**********Your Order cant be placed due to insufficient stock**********\n";
                return record;
           }
           
           }
           else
           {
                s->update_stock(record,s,out);
                cout<<"\n**********Your Order cant be placed due to insufficient stock**********\n";
                return record;
           }
      }
      
}

/*function to display order history
its return type is void.it takes nestedlist,string as parameters
*/
void display_orderhistory(list<list<string> >record,string id)
{
    list<list<string> >::iterator record_itr; 
    // Print the nested_list 
    string order_id,packet_id;
    for (record_itr = record.begin();record_itr != record.end();++record_itr)
    { 
        
        int count=0;
        int yes=0;
        list<string>::iterator rec_itr; 
        list<string>& rec_pointer = *record_itr; 
        for (rec_itr = rec_pointer.begin();rec_itr != rec_pointer.end();rec_itr++) { 
            if(count==0)
            {
                order_id=*rec_itr; 
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
                  cout << "\n\torder_id::  " << order_id << " ";
                  cout << "\n\tpacket_id::  " << packet_id << " ";
                  cout << "\n\tcustomer_id::  " << *rec_itr << " ";
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
            
            count++;
            
        } 

    } 
}
   



//function to navigate through options
void get :: getchoice()
{
     int choice;
     string id;
     cout<<"\nEnter id::  ";
     cin>>id;
     Stock *s;
     Customer *c;
     Order *o;
     do
     {
         Display::displaymenu();
         cout<<"\nEnter your choice::  ";
         cin>>choice;
         switch(choice)
         {
              case DISPLAY:  //to display personal details of customer
              {
                    ifstream in;
                    in.open("credential_files/customer_details.txt");
                    if(!in.is_open())
                    { 
                          cout<<"\n invalid text file";
                           exit(0);
                    }
                    
                    cout<<"\ncustomer details::  \n";
                    c->readData(c,in,id);
                    in.close();
                    break;
               }
                    
              case REQUEST:   // request for blood
              {
                   cout<<"\nEnter blood group to order::  ";
                   string bg;
                   cin>>bg;
                   
                   cout<<"\nEnter quantity::  ";
                   int quantity;
                   cin>>quantity;
                   
                   ifstream in;
                   in.open("credential_files/stock.txt");
                   
                   if(!in.is_open())
                   { 
                       cout<<"\n invalid text file";
                       exit(0);
                   }
                   
                   if(quantity>0)
                   {
                   //loading data into the list
                   list<list<string> > record;
                   record=c->Load_data_into_list(in);
                   
                   in.close();
                   in.open("credential_files/stock.txt");
                   
                   //checking if blood group is valid
                   if(c->IsBloodgroupValid(record,bg))
                   {
                       in.close();
                       ofstream out;
                       out.open("credential_files/stock.txt");
                   
                       if(!out.is_open())
                       { 
                           cout<<"\n invalid text file";
                          exit(0);
                       }
                       //placing order
                       record=c->Placeorder(record,c,s,o,out,bg,quantity,id);
                       out.close();
                       /*ifstream in;
                       in.open("credential_files/orderhistory.txt");
                       c->update_orderhistory(o,in,id,bg,quantity);*/
                         
                   }  
                   else
                   {
                        cout<<"\n*********Oops!!!Your required Blood group is not in our stock*********\n";
                   }
                   record.clear();
                   }
                   else
                   {
                       cout<<"\n**************************enter valid Quantity**************************\n";
                   }
                   break;
              } 
                 
              case SEARCH: //searching for required blood group and displaying details
              {   
                   cout<<"\nEnter blood group to search::  ";
                   string bg;
                   cin>>bg;
                   ifstream in;
                   in.open("credential_files/stock.txt");
                   if(!in.is_open())
                   { 
                       cout<<"\n invalid text file";
                       exit(0);
                   }
                   s->searchBloodgroup(s,in,bg);
                   in.close();
                   break;
                   
              }
                   
              case UPDATE:  //editing personal details
              {
                   ifstream in;
                   int ch;
                   //in.open("credential_files/customer_details.txt");
                   list<list<string> > record;
     
                   do
                   {
                       cout<<"\n*********************Select an  Option to Proceed*********************\n\n\t\t\t41. Update first name\n\t\t\t42. Update last name\n\t\t\t43. Update address\n\t\t\t44. update Phone number\n\t\t\t45. previous menu\n";
                       cout<<"\nEnter your choice::  ";
                       cin>>ch;
                       switch(ch)
                       {
                            case F_NAME: //updating first name
                            {
                                 string new_name;
                                 new_name=c->Person :: firstname_validation();
                                 if(new_name!="NULL")
                                 {
                                 in.open("credential_files/customer_details.txt");
                                 record=c->Load_data_into_list(in);
                                 in.close();
                                 ofstream out;
                                 out.open("credential_files/customer_details.txt");
                                 Update_Name(c,record,out,id,new_name);
                                 out.close();
                                 record.clear();
                                 }
                                 break;
                            }    
                            
                            case L_NAME:  //updating last name
                            {
                                 string last_name;
                                 last_name=c->Person :: lastname_validation();
                                 if(last_name!="NULL")
                                 {
                                 in.open("credential_files/customer_details.txt");
                                 record=c->Load_data_into_list(in);
                                 in.close();
                                 ofstream out;
                                 out.open("credential_files/customer_details.txt");
                                 Update_last_Name(c,record,out,id,last_name);
                                 out.close();
                                 record.clear();
                                 }
                                 break;
                            }    
                            
                            case ADDRESS:  //updating address
                            {
                                 string name;
                                 name=c->Person :: address_validation();
                                 if(name!="NULL")
                                 {
                                 in.open("credential_files/customer_details.txt");
                                 record=c->Load_data_into_list(in);
                                 in.close();
                                 ofstream out;
                                 out.open("credential_files/customer_details.txt");
                                 Update_Address(c,record,out,id,name);
                                 out.close();
                                 record.clear();
                                 }
                                 break;
                            }   
                            case PHONENUMBER:  //updating phonenumber
                            {
                                 long phno;
                                 phno=c->Person::phonenumber_validation();
                                 if(phno!=0)
                                 {
                                 in.open("credential_files/customer_details.txt");
                                 record=c->Load_data_into_list(in);
                                 in.close();
                                 ofstream out;
                                 out.open("credential_files/customer_details.txt");
                                 Update_phonenumber(c,record,out,id,phno);
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
              case ORDERHISTORY:
              {
                   list<list<string> > record;
                   ifstream in;
                   in.open("credential_files/orderhistory.txt");
                   record=c->Load_data_into_list(in);
                   in.close();
                   //c->printNestedList(record);
                   cout<<"\n*************************order history*************************\n";
                   o->display_orderhistory(record,id);
                   break; 
              } 
               
              case LOGOUT:
              {
                   cout<<"\n***************Thankyou for using our services****************\n\n";
                   exit(0);
              }     
              default:
                   cout<<"\nInvalid choice";
                   break;
                        
         }
     }while(choice!=0);
}

//defining function to validate admin
bool Customer::credential_validation(string id,string pwd)
{
	int i;
	bool flg = false;
	vector<vector<string>> lines;
	vector<string> word;
	string con,temp;
	ifstream in;
	in.open("customer_credential.txt");
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
		setCustomerid(id);
		setPassword(pwd);
	}
	
	return flg;
}









