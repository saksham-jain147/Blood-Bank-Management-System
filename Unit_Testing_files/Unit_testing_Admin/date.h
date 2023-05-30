#include<iostream>
#include<time.h>

using namespace std;

class Date
{
     public:
          Date();
          Date(int,int,int);
          void display();
          void accept();
          
          void setDay(int dd);
          void setMonth(int mm);
          void setYear(int yy);
          
          int getDay();
          int getMonth();
          int getYear();
          
          int DOB_validation(int dd, int mm, int yy);
          
    private:
          int dd;
          int mm;
          int yy;
};

