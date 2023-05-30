#include "test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CustomerTestCase);


//function to test constructor
void CustomerTestCase::testConstructor()
{
	Customer c("C701005006","jahnavi","tamarapalli","A+",966546980470,9177649653,"male",3,8,2001,"bobbili","Janu@0323");
	//Customer c;
	string customer_id=c.getCustomerid();
	CPPUNIT_ASSERT_MESSAGE("WRONG ID !",customer_id == "C701005006");
	string first_name=c.getFirstname();
	CPPUNIT_ASSERT_MESSAGE("WRONG FIRSTNAME !",first_name == "jahnavi");
	string last_name=c.getLastname();
	CPPUNIT_ASSERT_MESSAGE("WRONG LASTNAME !",last_name == "tamarapalli");
	string bg=c.getBloodgroup();
	CPPUNIT_ASSERT_MESSAGE("WRONG BLOODGROUP !",bg == "A+");
	long phno=c.getPhonenumber();
	CPPUNIT_ASSERT_MESSAGE("WRONG PHONENUMBER !",(phno == 9177649653 && to_string(phno).size()==10));
	long aadhaar=c.getAadhaar();
	CPPUNIT_ASSERT_MESSAGE("WRONG AADHAAR !",(aadhaar == 966546980470 && to_string(aadhaar).size()==12));
	string gender=c.getGender();
	CPPUNIT_ASSERT_MESSAGE("WRONG GENDER !",gender == "male");
	string address=c.getAddress();
	CPPUNIT_ASSERT_MESSAGE("WRONG address !",address == "bobbili");
}

void CustomerTestCase::testConstructorcase2()
{
	Customer c("C701005006","jahnavi","tamarapalli","A+",966546980470,917764965,"male",3,8,2001,"bobbili","Janu@0323");
	//Customer c;
	string customer_id=c.getCustomerid();
	CPPUNIT_ASSERT_MESSAGE("WRONG ID !",customer_id == "C701005006");
	string first_name=c.getFirstname();
	CPPUNIT_ASSERT_MESSAGE("WRONG FIRSTNAME !",first_name == "jahnavi");
	string last_name=c.getLastname();
	CPPUNIT_ASSERT_MESSAGE("WRONG LASTNAME !",last_name == "tamarapalli");
	string bg=c.getBloodgroup();
	CPPUNIT_ASSERT_MESSAGE("WRONG BLOODGROUP !",bg == "A+");
	long phno=c.getPhonenumber();
	CPPUNIT_ASSERT_MESSAGE("WRONG PHONENUMBER !",(phno == 917764965 && to_string(phno).size()==10));
	long aadhaar=c.getAadhaar();
	CPPUNIT_ASSERT_MESSAGE("WRONG AADHAAR !",(aadhaar == 966546980470 && to_string(aadhaar).size()==12));
	string gender=c.getGender();
	CPPUNIT_ASSERT_MESSAGE("WRONG GENDER !",gender == "male");
	string address=c.getAddress();
	CPPUNIT_ASSERT_MESSAGE("WRONG address !",address == "bobbili");
}

void CustomerTestCase::testlogin()
{
      Customer *e=new Customer();
      e->credential_validation("C701005001","Avinash@123");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Avinash@123" == e->getPassword() && "C701005001" == e->getCustomerid()));
      delete e;
      Customer *c=new Customer();
      c->credential_validation("C701005002","Janhavi#123");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Janhavi#123" == c->getPassword() && "C701005002" == c->getCustomerid()));
      delete c;

}

void CustomerTestCase::testlogincase1()
{
      Customer *e=new Customer();
      e->credential_validation("H701005002","Janhavi#123");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Janhavi#123" == e->getPassword() && "H701005002" == e->getCustomerid()));
      delete e;

}

void CustomerTestCase::testConstructorcase1()
{
	Customer c("H701005006","jahnavi","tamarapalli","A+",966546980470,9177649653,"male",3,8,2001,"bobbili","Janu@0323");
	//Customer c;
	string customer_id=c.getCustomerid();
	//char c="C";
	CPPUNIT_ASSERT_MESSAGE("WRONG ID !",(customer_id == "H701005006" && customer_id.substr(0,1)=="C"));
	string first_name=c.getFirstname();
	CPPUNIT_ASSERT_MESSAGE("WRONG FIRSTNAME !",first_name == "jahnavi");
	string last_name=c.getLastname();
	CPPUNIT_ASSERT_MESSAGE("WRONG LASTNAME !",last_name == "tamarapalli");
	string bg=c.getBloodgroup();
	CPPUNIT_ASSERT_MESSAGE("WRONG BLOODGROUP !",bg == "A+");
	long phno=c.getPhonenumber();
	CPPUNIT_ASSERT_MESSAGE("WRONG PHONENUMBER !",(phno == 9177649653 && to_string(phno).size()==10));
	long aadhaar=c.getAadhaar();
	CPPUNIT_ASSERT_MESSAGE("WRONG AADHAAR !",(aadhaar == 966546980470 && to_string(aadhaar).size()==12));
	string gender=c.getGender();
	CPPUNIT_ASSERT_MESSAGE("WRONG GENDER !",gender == "male");
	string address=c.getAddress();
	CPPUNIT_ASSERT_MESSAGE("WRONG address !",address == "bobbili");
}

void CustomerTestCase::testsetterId()
{
       Customer *c=new Customer();
       c->setCustomerid("C701005006");
       CPPUNIT_ASSERT_MESSAGE("WRONG ID !",(c->getCustomerid() == "C701005006" && c->getCustomerid().substr(0,1)=="C"));
       delete c;
}

void CustomerTestCase::testsetterIdcase1()
{
       Customer *c=new Customer();
       c->setCustomerid("H701005006");
       CPPUNIT_ASSERT_MESSAGE("WRONG ID !",(c->getCustomerid() == "H701005006" && c->getCustomerid().substr(0,1)=="C"));
       delete c;
}

void CustomerTestCase::testDate()
{
      Date *d=new Date();
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(2,3,2000));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(29,2,2012));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(30,9,2001));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(31,8,2000));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(2,12,2010));
      delete d;
}

void CustomerTestCase::testDatecase1()
{
      Date *d=new Date();
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(2,13,2000));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(30,2,2012));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(29,2,2001));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(31,8,1000));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(33,12,2010));
      delete d;
}

void CustomerTestCase::testStockconstructor()
{
     Stock s("A+",12);
     CPPUNIT_ASSERT_MESSAGE("Wrong bloodgroup !!",(s.getBloodGroup()=="A+" || s.getBloodGroup()=="B+" || s.getBloodGroup()=="AB+" || s.getBloodGroup()=="A-" || s.getBloodGroup()=="B-" || s.getBloodGroup()=="AB-" || s.getBloodGroup()=="O+" || s.getBloodGroup()=="O-"));
     CPPUNIT_ASSERT_MESSAGE("Invalid quantity !!",(s.getQuantity()>0));
}

void CustomerTestCase::testStockconstructorcase1()
{
     Stock s("H+",12);
     CPPUNIT_ASSERT_MESSAGE("Wrong bloodgroup !!",(s.getBloodGroup()=="A+" || s.getBloodGroup()=="B+" || s.getBloodGroup()=="AB+" || s.getBloodGroup()=="A-" || s.getBloodGroup()=="B-" || s.getBloodGroup()=="AB-" || s.getBloodGroup()=="O+" || s.getBloodGroup()=="O-"));
     CPPUNIT_ASSERT_MESSAGE("Invalid quantity !!",(s.getQuantity()>0));
}

void CustomerTestCase::testStockconstructorcase2()
{
     Stock s("A+",0);
     CPPUNIT_ASSERT_MESSAGE("Wrong bloodgroup !!",(s.getBloodGroup()=="A+" || s.getBloodGroup()=="B+" || s.getBloodGroup()=="AB+" || s.getBloodGroup()=="A-" || s.getBloodGroup()=="B-" || s.getBloodGroup()=="AB-" || s.getBloodGroup()=="O+" || s.getBloodGroup()=="O-"));
     CPPUNIT_ASSERT_MESSAGE("Invalid quantity !!",(s.getQuantity()>0));
}


/*

Each time we find an error (for instance, if we detect that the internal data isn’t the same as the external correct data), 
we should raise a concrete exception. You can do this with the CPPUNIT_FAIL(message) helper macro, which raises an exception showing a message parameter.

There is another way to check a condition and raise an exception if it’s false, all in a single step. 
The way to do this is through assertions. Assertions are macros that let us check a condition, and they raise the proper exception if the condition is false, 
with other options. Here are some assertion macros:


1. CPPUNIT_ASSERT(condition): Checks the condition and throws an exception if it’s false.
2. CPPUNIT_ASSERT_MESSAGE(message, condition): Checks the condition and throws an exception and showing specified message if it is false.
3. CPPUNIT_ASSERT_EQUAL(expected,current): Checks whether the expected condition is the same as current, and raises an exception showing the expected and current values.
4. CPPUNIT_ASSERT_EQUAL_MESSAGE(message,expected,current): Checks whether the expected is the same as the actual, 
   and raises an exception showing the expected and current values, and specified message.
5. CPPUNIT_ASSERT_DOUBLES_EQUAL(expected,current,delta): Checks whether the expected and current difference is smaller than delta. If it fails, the expected and current values are shown.

*/


