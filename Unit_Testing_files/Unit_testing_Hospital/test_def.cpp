#include "test.h"

CPPUNIT_TEST_SUITE_REGISTRATION(HospitalTestCase);


//function to test constructor
void HospitalTestCase::testConstructor()
{
	Hospital h("H901005006","Ruby Hall Clinic","40-Sasoon Road Sangamvadi Pune-411001",9696965222,"Ruby#123");

	string hospital_id=h.getHospitalid();
	CPPUNIT_ASSERT_MESSAGE("WRONG ID !",hospital_id == "H901005006");
	string name=h.getName();
	CPPUNIT_ASSERT_MESSAGE("WRONG NAME !",name == "Ruby Hall Clinic");
	string address=h.getAddress();
	CPPUNIT_ASSERT_MESSAGE("WRONG address !",address == "40-Sasoon Road Sangamvadi Pune-411001");
	long phone_number=h.getPhonenumber();
	CPPUNIT_ASSERT_MESSAGE("WRONG PHONENUMBER !",phone_number == 9696965222);
		
}

void HospitalTestCase::testConstructorcase1()
{
	Hospital h("H901005006","Ruby Hall Clinic","40-Sasoon Road Sangamvadi Pune-411001",9696965222,"Ruby#123");

	string hospital_id=h.getHospitalid();
	CPPUNIT_ASSERT_MESSAGE("WRONG ID !",hospital_id == "H901005006");
	string name=h.getName();
	CPPUNIT_ASSERT_MESSAGE("WRONG NAME !",name == "Ruby Hall Clinic");
	string address=h.getAddress();
	CPPUNIT_ASSERT_MESSAGE("WRONG address !",address == "40-Sasoon Road Sangamvadi Pune-411001");
	long phone_number=h.getPhonenumber();
	CPPUNIT_ASSERT_MESSAGE("WRONG PHONENUMBER !",phone_number == 9696965222);
		
}

void HospitalTestCase::testConstructorcase2()
{
	Hospital h("C901005006","Ruby Hall Clinic","40-Sasoon Road Sangamvadi Pune-411001",9696965222,"Ruby#123");

	string hospital_id=h.getHospitalid();
	//char h="H"
	CPPUNIT_ASSERT_MESSAGE("WRONG ID !",hospital_id == "C901005006");
	string name=h.getName();
	CPPUNIT_ASSERT_MESSAGE("WRONG NAME !",name == "Ruby Hall Clinic");
	string address=h.getAddress();
	CPPUNIT_ASSERT_MESSAGE("WRONG address !",address == "40-Sasoon Road Sangamvadi Pune-411001");
	long phone_number=h.getPhonenumber();
	CPPUNIT_ASSERT_MESSAGE("WRONG PHONENUMBER !",phone_number == 9696965222);
		
}

void HospitalTestCase::testlogin()
{
      Hospital *e=new Hospital();
      e->credential_validation("H901005004","Artemis@123");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ","Artemis@123" == e->getPassword());
      delete e;
      Hospital *h=new Hospital();
      h->credential_validation("H901005001","Apollo@123");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ","Apollo@123" == h->getPassword());
      delete h;
}

void HospitalTestCase::testlogincase1()
{
      Hospital *e=new Hospital();
      e->credential_validation("C901005002","Fortis@123");
      CPPUNIT_ASSERT_MESSAGE("Test Case Fail! Login Failed.. ",("Fortis@123" == e->getPassword() && "C901005002" == e->getHospitalid()));
      delete e;

}









void HospitalTestCase::testsetterId()
{
       Hospital *c=new Hospital();
       c->setHospitalid("H901005006");
       CPPUNIT_ASSERT_MESSAGE("WRONG ID !",(c->getHospitalid() == "H901005006" && c->getHospitalid().substr(0,1)=="C"));
       delete c;
}

void HospitalTestCase::testsetterIdcase1()
{
       Hospital *c=new Hospital();
       c->setHospitalid("C901005006");
       CPPUNIT_ASSERT_MESSAGE("WRONG ID !",(c->getHospitalid() == "C901005006" && c->getHospitalid().substr(0,1)=="H"));
       delete c;
}


void HospitalTestCase::testStockconstructor()
{
     Stock s("A+",12);
     CPPUNIT_ASSERT_MESSAGE("Wrong bloodgroup !!",(s.getBloodGroup()=="A+" || s.getBloodGroup()=="B+" || s.getBloodGroup()=="AB+" || s.getBloodGroup()=="A-" || s.getBloodGroup()=="B-" || s.getBloodGroup()=="AB-" || s.getBloodGroup()=="O+" || s.getBloodGroup()=="O-"));
     CPPUNIT_ASSERT_MESSAGE("Invalid quantity !!",(s.getQuantity()>0));
}

void HospitalTestCase::testStockconstructorcase1()
{
     Stock s("H+",12);
     CPPUNIT_ASSERT_MESSAGE("Wrong bloodgroup !!",(s.getBloodGroup()=="A+" || s.getBloodGroup()=="B+" || s.getBloodGroup()=="AB+" || s.getBloodGroup()=="A-" || s.getBloodGroup()=="B-" || s.getBloodGroup()=="AB-" || s.getBloodGroup()=="O+" || s.getBloodGroup()=="O-"));
     CPPUNIT_ASSERT_MESSAGE("Invalid quantity !!",(s.getQuantity()>0));
}

void HospitalTestCase::testStockconstructorcase2()
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


