#include "test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(DonorTestCase);


//function to test constructor
void DonorTestCase::testConstructor()
{
	Donor d("D801005006","jithendra","kumar","B+",621627476958,9121828687,"male",3,8,2001,"guntur","Jithendra@123");
	//Donor d;
	string Donor_id=d.getDonorid();
	CPPUNIT_ASSERT_MESSAGE("WRONG ID !",Donor_id == "D801005006");
	string first_name=d.getFirstname();
	CPPUNIT_ASSERT_MESSAGE("WRONG FIRSTNAME !",first_name == "jithendra");
	string last_name=d.getLastname();
	CPPUNIT_ASSERT_MESSAGE("WRONG LASTNAME !",last_name == "kumar");
	string bg=d.getBloodgroup();
	CPPUNIT_ASSERT_MESSAGE("WRONG BLOODGROUP !",bg == "B+");
	long phno=d.getPhonenumber();
	CPPUNIT_ASSERT_MESSAGE("WRONG PHONENUMBER !",(phno == 9121828687 && to_string(phno).size()==10));
	long aadhaar=d.getAadhaar();
	CPPUNIT_ASSERT_MESSAGE("WRONG AADHAAR !",(aadhaar == 621627476958 && to_string(aadhaar).size()==12));
	string gender=d.getGender();
	CPPUNIT_ASSERT_MESSAGE("WRONG GENDER !",gender == "male");
	string address=d.getAddress();
	CPPUNIT_ASSERT_MESSAGE("WRONG address !",address == "guntur");
}

void DonorTestCase::testConstructorcase2()
{
	Donor d("D801005006","jithendra","kumar","B+",621627476958,912182868,"male",3,8,2001,"guntur","Jithendra@123");
	//Donor d;
	string Donor_id=d.getDonorid();
	CPPUNIT_ASSERT_MESSAGE("WRONG ID !",Donor_id == "D801005006");
	string first_name=d.getFirstname();
	CPPUNIT_ASSERT_MESSAGE("WRONG FIRSTNAME !",first_name == "jithendra");
	string last_name=d.getLastname();
	CPPUNIT_ASSERT_MESSAGE("WRONG LASTNAME !",last_name == "kumar");
	string bg=d.getBloodgroup();
	CPPUNIT_ASSERT_MESSAGE("WRONG BLOODGROUP !",bg == "B+");
	long phno=d.getPhonenumber();
	CPPUNIT_ASSERT_MESSAGE("WRONG PHONENUMBER !",(phno == 912182868 && to_string(phno).size()==10));
	long aadhaar=d.getAadhaar();
	CPPUNIT_ASSERT_MESSAGE("WRONG AADHAAR !",(aadhaar == 621627476958 && to_string(aadhaar).size()==12));
	string gender=d.getGender();
	CPPUNIT_ASSERT_MESSAGE("WRONG GENDER !",gender == "male");
	string address=d.getAddress();
	CPPUNIT_ASSERT_MESSAGE("WRONG address !",address == "guntur");
}

void DonorTestCase::testlogin()
{
      Donor *e=new Donor();
      e->credential_validation("D801005001","Avinash@133");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Avinash@133" == e->getPassword() && "D801005001" == e->getDonorid()));
      delete e;
      Donor *d=new Donor();
      d->credential_validation("D801005002","Janhavi#133");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Janhavi#133" == d->getPassword() && "D801005002" == d->getDonorid()));
      delete d;

}

void DonorTestCase::testlogincase1()
{
      Donor *e=new Donor();
      e->credential_validation("H701005002","Janhavi#133");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Janhavi#133" == e->getPassword() && "H701005002" == e->getDonorid()));
      delete e;

}

void DonorTestCase::testConstructorcase1()
{
	Donor d("H701005006","jithendra","kumar","B+",621627476958,9121828687,"male",3,8,2001,"guntur","Jithendra@123");
	//Donor c;
	string Donor_id=d.getDonorid();
	//char c="D";
	CPPUNIT_ASSERT_MESSAGE("WRONG ID !",(Donor_id == "H701005006" && Donor_id.substr(0,1)=="D"));
	string first_name=d.getFirstname();
	CPPUNIT_ASSERT_MESSAGE("WRONG FIRSTNAME !",first_name == "jithendra");
	string last_name=d.getLastname();
	CPPUNIT_ASSERT_MESSAGE("WRONG LASTNAME !",last_name == "kumar");
	string bg=d.getBloodgroup();
	CPPUNIT_ASSERT_MESSAGE("WRONG BLOODGROUP !",bg == "B+");
	long phno=d.getPhonenumber();
	CPPUNIT_ASSERT_MESSAGE("WRONG PHONENUMBER !",(phno == 9121828687 && to_string(phno).size()==10));
	long aadhaar=d.getAadhaar();
	CPPUNIT_ASSERT_MESSAGE("WRONG AADHAAR !",(aadhaar == 621627476958 && to_string(aadhaar).size()==12));
	string gender=d.getGender();
	CPPUNIT_ASSERT_MESSAGE("WRONG GENDER !",gender == "male");
	string address=d.getAddress();
	CPPUNIT_ASSERT_MESSAGE("WRONG address !",address == "guntur");
}

void DonorTestCase::testsetterId()
{
       Donor *d=new Donor();
       d->setDonorid("D801005006");
       CPPUNIT_ASSERT_MESSAGE("WRONG ID !",(d->getDonorid() == "D801005006" && d->getDonorid().substr(0,1)=="D"));
       delete d;
}

void DonorTestCase::testsetterIdcase1()
{
       Donor *d=new Donor();
       d->setDonorid("H701005006");
       CPPUNIT_ASSERT_MESSAGE("WRONG ID !",(d->getDonorid() == "H701005006" && d->getDonorid().substr(0,1)=="D"));
       delete d;
}

void DonorTestCase::testDate()
{
      Date *d=new Date();
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(2,3,2000));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(29,2,2012));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(30,9,2001));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(31,8,2000));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(2,12,2010));
      delete d;
}

void DonorTestCase::testDatecase1()
{
      Date *d=new Date();
      CPPUNIT_ASSERT_MESSAGE("WRONG month !",1 ==d->DOB_validation(2,13,2000));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(30,2,2012));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(29,2,2001));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(31,8,1000));
      CPPUNIT_ASSERT_MESSAGE("WRONG date !",1 ==d->DOB_validation(33,12,2010));
      delete d;
}

void DonorTestCase::testStockconstructor()
{
     Stock s("B+",12);
     CPPUNIT_ASSERT_MESSAGE("Wrong bloodgroup !!",(s.getBloodGroup()=="B+" || s.getBloodGroup()=="B+" || s.getBloodGroup()=="AB+" || s.getBloodGroup()=="A-" || s.getBloodGroup()=="B-" || s.getBloodGroup()=="AB-" || s.getBloodGroup()=="O+" || s.getBloodGroup()=="O-"));
     CPPUNIT_ASSERT_MESSAGE("Invalid quantity !!",(s.getQuantity()>0));
}

void DonorTestCase::testStockconstructorcase1()
{
     Stock s("H+",12);
     CPPUNIT_ASSERT_MESSAGE("Wrong bloodgroup !!",(s.getBloodGroup()=="B+" || s.getBloodGroup()=="B+" || s.getBloodGroup()=="AB+" || s.getBloodGroup()=="A-" || s.getBloodGroup()=="B-" || s.getBloodGroup()=="AB-" || s.getBloodGroup()=="O+" || s.getBloodGroup()=="O-"));
     CPPUNIT_ASSERT_MESSAGE("Invalid quantity !!",(s.getQuantity()>0));
}

void DonorTestCase::testStockconstructorcase2()
{
     Stock s("B+",0);
     CPPUNIT_ASSERT_MESSAGE("Wrong bloodgroup !!",(s.getBloodGroup()=="B+" || s.getBloodGroup()=="B+" || s.getBloodGroup()=="AB+" || s.getBloodGroup()=="A-" || s.getBloodGroup()=="B-" || s.getBloodGroup()=="AB-" || s.getBloodGroup()=="O+" || s.getBloodGroup()=="O-"));
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
