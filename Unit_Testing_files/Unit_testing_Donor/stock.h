#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<string>
#include<list>
#include<iterator>
using namespace std;

class Stock
{
    public:
          Stock();
          Stock(string,int);
          void setBloodGroup(string); 
          string getBloodGroup();
          void setQuantity(int);
          int getQuantity();
          
          void searchBloodgroup(Stock*,ifstream&,string);
          void printdetailsofbg(list<list<string> >);
          void writeFile(ofstream&);
          bool check_quantity(list<list<string>>,string,int);
          
    private:
          string BloodGroup;
          int quantity;
};
