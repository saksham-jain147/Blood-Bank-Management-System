#include"order.h"

Order :: Order()
{
     order_id=0;
     packet_id=0;
     customer_id="\0";
     bloodgroup="\0";
     quantity=0;
}

Order :: Order(int o_id,int p_id,string c_id,string bg,int quan)
{
     time_t now=time(0); 
     order_id=o_id;
     packet_id=p_id;
     customer_id=c_id;
     bloodgroup=bg;
     quantity=quan;
     dt=localtime(&now); 
}

void Order :: display()
{
     cout<<"Date:: "<<dt->tm_mday<<"/"<< (dt->tm_mon)+1<<"/"<< (dt->tm_year)+1900<<endl;
}

int Order :: get_order_id(ifstream &in)
{
       string bg,o_id,b_id,c_id,quan,date;
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
            getline(data,date,',');     
       }
       
       return stoi(o_id)+1;
}

int Order :: get_packet_id(ifstream &in)
{
       string o_id,b_id,c_id,quan,date;
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
            getline(data,date,',');   
       }
     
       return stoi(b_id)+1;
}

void Order :: display_orderhistory(list<list<string> >record,string id)
{
    list<list<string> >::iterator record_itr; 
    
    // Print the nested_list 
    string order_id,packet_id;
    int yes=0;
    for (record_itr = record.begin();record_itr != record.end();++record_itr)
    { 
        
        int count=0;
        yes=0;
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
                  cout << "\n\tOrder Id \t::  " << order_id << " ";
                  cout << "\n\tBag Id \t\t::  " << packet_id << " ";
                  cout << "\n\tId \t\t::  " << *rec_itr << " ";
                }
            }
            if(count==3 and yes==1)
            {
                cout << "\n\tBlood Group \t::  " << *rec_itr << " ";   
            }
             
            if(count==4 and yes==1)
            {
                cout << "\n\tQuantity \t::  " << *rec_itr << " ";
            }
            if(count==5 and yes==1)
            {
                cout << "\n\tDate \t\t::  " << *rec_itr << " ";
                cout<<endl;
            }
            count++;
            
        } 

    }
    if(yes!=1)
    {
    	 cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
         cout<<"\n\t\t\tNO ORDERS PLACED IN PAST!!!\n";
         cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
    } 
}
   

