/*
This file contains all the definition functions which are declared in class Stock...
*/
#include"stock.h"

//default constructor of class stock
Stock :: Stock()
{
     BloodGroup="\0";
     quantity=0;
}

//parametrized constructor of class stock
Stock :: Stock(string bg,int quantity)
{
     this->BloodGroup=bg;
     this->quantity=quantity;
}

//function to setblood group
void Stock :: setBloodGroup(string bg)
{
     this->BloodGroup=bg;
}

//function to  set quantity
void Stock :: setQuantity(int quantity)
{
     this->quantity=quantity;
}

//function to getbloodgroup
string Stock :: getBloodGroup()
{
     return BloodGroup;
}

//function to updatequantity
int Stock :: getQuantity()
{
     return quantity;
}

//function to search particular bloodgroup 
void Stock :: searchBloodgroup(Stock *eptr,ifstream& fin,string bg)
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
             
             if(bg==str)
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
           eptr->printdetailsofbg(record);
       }
       else
       {
           cout<<"\nwrong details";
       }
       
}

void Stock :: writeFile(ofstream& fout)
{
     fout<<BloodGroup<<","<<quantity<<"\n";
}


int Stock :: Available_Quantity(list<list<string>> record,string bg,int quantity)
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
                     return quan;
               }
               count++;
            }
       }
       //c->printNestedList(record);
       return 0;
}

//function to print details of particular bg
void Stock :: printdetailsofbg(list<list<string> > record) 
{ 
    list<list<string> >::iterator record_itr; 
    cout<<"\nQuantity available is::   ";
    // Print the nested_list 
    for (record_itr = record.begin();record_itr != record.end();++record_itr)
    { 
        
        int count=0;
        list<string>::iterator rec_itr; 
        list<string>& rec_pointer = *record_itr; 
        for (rec_itr = rec_pointer.begin();rec_itr != rec_pointer.end();rec_itr++)
        { 
            if(count==0)
            {
                cout << "\n\tBloodGroup::  " << *rec_itr << " "; 
            }
            if(count==1)
            {
                cout << "\n\tQuantity::  " << *rec_itr << " ";
            }
            count++;
            
        } 

       cout<<endl;

    } 
}

bool Stock :: check_quantity(list<list<string>> record,string bg,int quantity)
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
                         return true;
                     }
               }
               count++;
            }
       }
       //c->printNestedList(record);
       return false;
}
