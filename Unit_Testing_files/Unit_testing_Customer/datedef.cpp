#include"date.h"


Date :: Date()
{
     dd=0;
     mm=0;
     yy=0;
}

Date :: Date(int dd,int mm,int yy)
{
     this->dd=dd;
     this->mm=mm;
     this->yy=yy;
}

void Date :: accept()
{
	int DATE;
	cout<<"\nEnter Date of Birth dd/mm/yy : ";
	char p,q;
	cin>>dd>>p>>(mm)>>q>>(yy);
	DATE = DOB_validation(dd, mm, yy);
	if(DATE == 0)
	{
		accept();
	}
}

void Date :: setDay(int dd)
{
	this->dd = dd;
}

void Date :: setMonth(int mm)
{
	this->mm = mm;
}

void Date :: setYear(int yy)
{
	this->yy = yy;
}

int Date :: getDay()
{
	return dd;
}

int Date :: getMonth()
{
	return mm;
}

int Date :: getYear()
{
	return yy;
}

void Date :: display()
{
     cout<<"\nDate: "<<dd<<mm<<yy;
}

int Date :: DOB_validation(int dd, int mm, int yyyy)
{
	time_t ti = time(NULL);
	struct tm tm = *localtime(&ti);
	int y = tm.tm_year + 1900;
	
	if(yyyy >= (y -100) && (yyyy < y)) 
	{	
		if(mm>=1 && mm<=12) 
		{	
			if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
			{
				return 1;
			}
			else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm== 9 || mm==11))
			{
				
			        return 1;
			
			}
			else if((dd>1 && dd<=28) && (mm==2))
			{
			
				return 1;
				
			}
			else if(dd==29 && mm==2 && (yyyy%4==0 || (yyyy%4==0 && yyyy%100!=0)))
			{
				
				return 1;
				
			}
			else
			{
				return 0;
			}
		}
		else
		{
		
	            	return 0;
		}
	}
	else
	{
		return 0;
	}
	
}

