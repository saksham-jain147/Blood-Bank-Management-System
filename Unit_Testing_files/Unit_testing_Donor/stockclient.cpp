#include"stock.h"

int main()
{
    string bg;
    Stock s("A+",30);
    cout<<"\nEnter quantity::  ";
    cin>>bg;
    ifstream in;
    in.open("credential_files/stock.txt");
    if(!in.is_open())
    { 
          cout<<"\n invalid text file";
          exit(0);
    }
    s.searchBloodgroup(&s,in,bg);
}
