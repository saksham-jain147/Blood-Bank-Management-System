#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<string>
#include<list>
#include<iterator>
#include<ctime>
using namespace std;

class Order
{
      public:
           Order();
           Order(int,int,string,string,int);
           void display_orderhistory(list<list<string> >,string);
           int get_order_id(ifstream&);
           int get_packet_id(ifstream&);
           void display();
           
      private:
           int order_id;
           int packet_id;
           string customer_id;
           string bloodgroup;
           int quantity;
           tm *dt;
};
