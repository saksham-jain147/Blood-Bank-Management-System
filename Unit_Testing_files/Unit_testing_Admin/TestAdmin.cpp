#include "TestAdmin.h"

CPPUNIT_TEST_SUITE_REGISTRATION(AdminTestCase);


//function to test constructor
void AdminTestCase::testConstructor()
{
	Admin ad("A101005006","Avinash","Reddy","AB+",1111222233333,9884565522,"Male",3,3,1999,"asdf","Avinash@0323");
	//Admin ad;
	string Admin_id = ad.getId();
	CPPUNIT_ASSERT_MESSAGE("WRONG ID !",Admin_id == "A101005006");
	
	string first_name = ad.getFirstname();
	CPPUNIT_ASSERT_MESSAGE("WRONG FIRSTNAME !",first_name == "Avinash");
	
	string last_name = ad.getLastname();
	CPPUNIT_ASSERT_MESSAGE("WRONG LASTNAME !",last_name == "Reddy");
	
	string bg = ad.getBloodgroup();
	CPPUNIT_ASSERT_MESSAGE("WRONG BLOODGROUP !",bg == "AB+");
	
	long phno = ad.getPhonenumber();
	CPPUNIT_ASSERT_MESSAGE("WRONG PHONENUMBER !",phno == 9884565522);
	
	long aadhaar = ad.getAadhaar();
	CPPUNIT_ASSERT_MESSAGE("WRONG AADHAAR !",aadhaar == 1111222233333);
	
	string gender = ad.getGender();
	CPPUNIT_ASSERT_MESSAGE("WRONG GENDER !",gender == "Male");
	
	string address = ad.getAddress();
	CPPUNIT_ASSERT_MESSAGE("WRONG address !",address == "asdf");
}

void AdminTestCase::testlogin()
{
      Admin *e=new Admin();
      e->credential_validation("A601005001","Avinash@143");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Avinash@143" == e->getPassword()) && ("A601005001" == e->getId()));
}

void AdminTestCase::testName1()
{
      AdminTestCase *a = new AdminTestCase();
      string name = a->firstname_validation("Avinash");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Avinash" == name));
     
}


void AdminTestCase::testName2()
{
      AdminTestCase *a = new AdminTestCase();
      string name = a->firstname_validation("dev");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("dev" == name));
     
}

void AdminTestCase::testName3()
{
      AdminTestCase *a = new AdminTestCase();
      string name = a->firstname_validation("SAKSHAM");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("SAKSHAM" == name));
     
}

void AdminTestCase::testName4()
{
      AdminTestCase *a = new AdminTestCase();
      string name = a->firstname_validation("Jahnavi159");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Jahnavi159" == name));
     
}

void AdminTestCase::testName5()
{
      AdminTestCase *a = new AdminTestCase();
      string name = a->firstname_validation("Jithendra@Kumar");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Jithendra@Kumar" == name));
     
}

/*
Test cases for blood Group
*/
void AdminTestCase::testbloodgroup1()
{
      AdminTestCase *a = new AdminTestCase();
      string name = a->bloodgroup_validation("A+");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("A+" == name));
     
}


void AdminTestCase::testbloodgroup2()
{
      AdminTestCase *a = new AdminTestCase();
      string name = a->bloodgroup_validation("A123");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("A123" == name));
}

void AdminTestCase::testbloodgroup3()
{
      AdminTestCase *a = new AdminTestCase();
      string name = a->bloodgroup_validation("B");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("B" == name));
}


/*
TEST CASES FOR AADHAAR NUMBER
*/
void AdminTestCase::testaadhaar1()
{
      AdminTestCase *a = new AdminTestCase();
      long aadhaar = a->aadhaar_validation(521591255636);
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",(521591255636 == aadhaar));
}

void AdminTestCase::testaadhaar2()
{
      AdminTestCase *a = new AdminTestCase();
      long aadhaar = a->aadhaar_validation(52159);
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",(52159 == aadhaar));
}

void AdminTestCase::testaadhaar3()
{
      AdminTestCase *a = new AdminTestCase();
      long aadhaar = a->aadhaar_validation(521591255636456456);
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",(521591255636456456 == aadhaar));
}


/*
TEST CASES FOR PHONE NUMBER
*/
void AdminTestCase::testPhoneNumber1()
{
      AdminTestCase *a = new AdminTestCase();
      long PhoneNumber = a->phonenumber_validation(9411456489);
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",(9411456489 == PhoneNumber));
}

void AdminTestCase::testPhoneNumber2()
{
      AdminTestCase *a = new AdminTestCase();
      long PhoneNumber = a->phonenumber_validation(9411456489123564);
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",(9411456489123564 == PhoneNumber));
}

void AdminTestCase::testPhoneNumber3()
{
      AdminTestCase *a = new AdminTestCase();
      long PhoneNumber = a->phonenumber_validation(9411);
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",(9411 == PhoneNumber));
}

/*
TEST CASE FOR GENDER
*/
void AdminTestCase::testGender1()
{
      AdminTestCase *a = new AdminTestCase();
      string gender = a->gender_validation("Male");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Male" == gender));
}

void AdminTestCase::testGender2()
{
      AdminTestCase *a = new AdminTestCase();
      string gender = a->gender_validation("Male123");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Male123" == gender));
}

void AdminTestCase::testGender3()
{
      AdminTestCase *a = new AdminTestCase();
      string gender = a->gender_validation("Male#");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Male#" == gender));
}

void AdminTestCase::testGender4()
{
      AdminTestCase *a = new AdminTestCase();
      string gender = a->gender_validation("Female");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Female" == gender));
}

/*
TEST CASE FOR ADDRESS
*/
void AdminTestCase::testAddress1()
{
      AdminTestCase *a = new AdminTestCase();
      string address = a->address_validation("Capgemini Mumbai-531163");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Capgemini Mumbai-531163" == address));
}

void AdminTestCase::testAddress2()
{
      AdminTestCase *a = new AdminTestCase();
      string address = a->address_validation("Capgemini Private Limited Mumbai India-531163");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Capgemini Private Limited Mumbai India-531163" == address));
}

void AdminTestCase::testAddress3()
{
      AdminTestCase *a = new AdminTestCase();
      string address = a->address_validation("Mumbai");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Mumbai" == address));
}

void AdminTestCase::testAddress4()
{
      AdminTestCase *a = new AdminTestCase();
      string address = a->address_validation("Capgemini Mumbai,531163");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Capgemini Mumbai,531163" == address));
}

/*
TEST CASE FOR PASSWORD
*/
void AdminTestCase::testPassword1()
{
      AdminTestCase *a = new AdminTestCase();
      string password = a->password_validation("Dev@153PA");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Dev@153PA" == password));
}

void AdminTestCase::testPassword2()
{
      AdminTestCase *a = new AdminTestCase();
      string password = a->password_validation("dev@153pa");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("dev@153pa" == password));
}

void AdminTestCase::testPassword3()
{
      AdminTestCase *a = new AdminTestCase();
      string password = a->password_validation("SAKSHAM#123");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("SAKSHAM#123" == password));
}

void AdminTestCase::testPassword4()
{
      AdminTestCase *a = new AdminTestCase();
      string password = a->password_validation("1234567890");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("1234567890" == password));
}

void AdminTestCase::testPassword5()
{
      AdminTestCase *a = new AdminTestCase();
      string password = a->password_validation("SAKSHAM123");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("SAKSHAM123" == password));
}

void AdminTestCase::testPassword6()
{
      AdminTestCase *a = new AdminTestCase();
      string password = a->password_validation("JithendraKumar@13245679jithendra");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("JithendraKumar@13245679jithendra" == password));
}

void AdminTestCase::testPassword7()
{
      AdminTestCase *a = new AdminTestCase();
      string password = a->password_validation("Dp");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Dp" == password));
}

void AdminTestCase::testPassword8()
{
      AdminTestCase *a = new AdminTestCase();
      string password = a->password_validation("Janhavi[^&*]");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Janhavi[^&*]" == password));
}

void AdminTestCase::testPassword9()
{
      AdminTestCase *a = new AdminTestCase();
      string password = a->password_validation("Janhavi[^&*]123");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Janhavi[^&*]123" == password));
}
















void AdminTestCase::testConstructor1()
{
	Admin ad("A101005006","Avinash","Reddy","AB+",1111222233333,9884565522,"Male",3,3,1999,"asdf","Avinash@0323");
	//Admin ad;
	string Admin_id = ad.getId();
	//char c="C";
	CPPUNIT_ASSERT_MESSAGE("WRONG ID !",(Admin_id == "A101005006" && Admin_id.substr(0,1)=="A"));
	
	string first_name = ad.getFirstname();
	CPPUNIT_ASSERT_MESSAGE("WRONG FIRSTNAME !",first_name == "Avinash");
	
	string last_name = ad.getLastname();
	CPPUNIT_ASSERT_MESSAGE("WRONG LASTNAME !",last_name == "Reddy");
	
	string bg = ad.getBloodgroup();
	CPPUNIT_ASSERT_MESSAGE("WRONG BLOODGROUP !",bg == "AB+");
	
	long phno = ad.getPhonenumber();
	CPPUNIT_ASSERT_MESSAGE("WRONG PHONENUMBER !",phno == 9884565522);
	
	long aadhaar = ad.getAadhaar();
	CPPUNIT_ASSERT_MESSAGE("WRONG AADHAAR !",aadhaar == 1111222233333);
	
	string gender = ad.getGender();
	CPPUNIT_ASSERT_MESSAGE("WRONG GENDER !",gender == "Male");
	
	string address = ad.getAddress();
	CPPUNIT_ASSERT_MESSAGE("WRONG address !",address == "asdf");
}


/* 
Funciton definition to validate first name
Check whether it contains characters only
It's return type is string and it does not take any parameter
*/
string AdminTestCase :: firstname_validation(string firstname)
{
	int count = 0;
		 
	if(firstname == "q")
	{
		cout<<"Entered to Main Menu"<<endl;
		exit(0);		//Baad mai change kar denge according to program
	}
     	else
     	{
     		for(int i=0;i<firstname.length();i++)
		{
			if( (firstname[i]>='a' &&  firstname[i]<='z') || (firstname[i]>='A' && firstname[i]<='Z') || firstname[i]==' '  )
				continue;
			else
			{
				return "Invalid";
			}
		}
		
		count = firstname.length();
		
		if(count > 20)
		{
			return "Invalid";
		}
		else if(count <= 2)
		{
			return "Invalid";
		}
		else
		{
			return firstname;  
		}
	}    
}




/* 
Funciton definition to validate blood group
Check whether it contains existing blood groups only
It's return type is string and it does not take any parameter
*/
string AdminTestCase :: bloodgroup_validation(string bloodgroup)
{
	if(bloodgroup == "q")
	{
		cout<<"Entered to Main Menu"<<endl;
		exit(0);		//Baad mai change kar denge according to program
	}
	else
	{
		if(bloodgroup == "O-" || bloodgroup == "O+" || bloodgroup == "A-" || bloodgroup == "A+" || bloodgroup == "B-" || bloodgroup == "B+" || bloodgroup == "AB-" || bloodgroup == "AB+")
		{
			return bloodgroup;
		}
		else
		{
			return "Invalid Blood Group";
		}
		return bloodgroup;
	}
}



/* 
Funciton definition to validate aadhaar
Check whether it contains 12 digits number
It's return type is long and it does not take any parameter
*/
long AdminTestCase :: aadhaar_validation(long int aadhaarnumber)
{
	long int an;
	int digit = 0;
	
	an = aadhaarnumber;
	
	
	if(aadhaarnumber == 0)
	{
		return -1;
	}
	else
	{
		while(an != 0)
		{
			digit++;
			an = an/10;
		}
		
		if(digit == 12)
		{
			return aadhaarnumber;
		}
		else
		{
			return -1;
		}
		return aadhaarnumber;
	}
}


/* 
Funciton definition to validate phone number
Check whether it contains 10 digits number
It's return type is long and it does not take any parameter
*/
long AdminTestCase :: phonenumber_validation(long int phonenumber)
{
	long int ph;
	int digit = 0;

	ph = phonenumber;
	
	if(phonenumber == 0)
	{
		return -1;
	}
	else
	{
		while(ph != 0)
		{
			digit++;
			ph = ph/10;
		}
		
		if(digit == 10)
		{
			return phonenumber;
		}
		else
		{
			return -1;
		}
		return phonenumber;
	}
}


/* 
Funciton definition to validate gender
It's return type is string and it does not take any parameter
*/
string AdminTestCase :: gender_validation(string gender)
{
	if(gender == "q")
	{
		return "Invalid";
	}
	else if(gender == "Male" || gender=="male" || gender=="Female" || gender=="female" || gender == "m" || gender == "f" || gender == "M" || gender == "F" )
	{
		return gender;
	}
	else
	{
		return "Invalid";
	}
	return gender;
}


/* 
Funciton definition to validate address
Check whether it contains characters ('a to z' || 'A to Z' || (- and /))
It's return type is string and it does not take any parameter
*/
string AdminTestCase :: address_validation(string address)
{
	int count=0;

	if(address == "q")
	{
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
			return "Invalid";
		}
	}
	
	count = address.length();
	
	if(count > 30)
	{
		return "Invalid";
	}
	else if(count <= 8)
	{
		return "Invalid";
	}
	
	return address;
}


/* 
Funciton definition to validate password
Check whether it contains alphanumeric ('a to z' || 'A to Z' || (1 to 9))
Special Characters allowed are : (@ # $ % * & _)
It's return type is string and it does not take any parameter
*/
string AdminTestCase :: password_validation(string password)
{
	int scount=0,dcount=0,lcount=0,ucount=0,count=0;

	if(password == "q")
	{
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
			return "Invalid";
		}
	}
	count = password.length();
	if((count>=8 && count<=15) && dcount>0 && lcount>0 && ucount>0 && scount>0)
	{
		return password;
	}
	else if(count>15)
	{
		return "Invalid";
	}
	else if(count<8)
	{
		return "Invalid";
	}
	else
	{
		return "Invalid";
	}
	
	return password;
}
