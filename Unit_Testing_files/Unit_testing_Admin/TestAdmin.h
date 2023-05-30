#ifndef TEST_H
#define TEST_H

#include<cppunit/TestCase.h>
#include<cppunit/extensions/HelperMacros.h>
#include"admin.h"
//#include "person.h"

/* class for testing Admin Module */
class AdminTestCase : public CppUnit::TestCase // inheriting base class TestCase 
{
		CPPUNIT_TEST_SUITE(AdminTestCase); // to start the test suite definition
			CPPUNIT_TEST(testConstructor); // to define a test case
			CPPUNIT_TEST(testConstructor1);
			CPPUNIT_TEST(testlogin);
			 
			CPPUNIT_TEST(testName1);
			CPPUNIT_TEST(testName2);
			CPPUNIT_TEST(testName3);
			CPPUNIT_TEST(testName4);
			CPPUNIT_TEST(testName5);
			
			CPPUNIT_TEST(testbloodgroup1);
			CPPUNIT_TEST(testbloodgroup2);
			CPPUNIT_TEST(testbloodgroup3);
			
			CPPUNIT_TEST(testaadhaar1);
			CPPUNIT_TEST(testaadhaar2);
			CPPUNIT_TEST(testaadhaar3);
			
			CPPUNIT_TEST(testPhoneNumber1);
			CPPUNIT_TEST(testPhoneNumber2);
			CPPUNIT_TEST(testPhoneNumber3);
			
			CPPUNIT_TEST(testGender1);
			CPPUNIT_TEST(testGender2);
			CPPUNIT_TEST(testGender3);
			CPPUNIT_TEST(testGender4);
			
			CPPUNIT_TEST(testAddress1);
			CPPUNIT_TEST(testAddress2);
			CPPUNIT_TEST(testAddress3);
			CPPUNIT_TEST(testAddress4);
			
			CPPUNIT_TEST(testPassword1);
			CPPUNIT_TEST(testPassword2);
			CPPUNIT_TEST(testPassword3);
			CPPUNIT_TEST(testPassword4);
			CPPUNIT_TEST(testPassword5);
			CPPUNIT_TEST(testPassword6);
			CPPUNIT_TEST(testPassword7);
			CPPUNIT_TEST(testPassword8);
			CPPUNIT_TEST(testPassword9);
			
		CPPUNIT_TEST_SUITE_END(); // to end test suite definition	
	
    
	public:
		void testConstructor(); // testing constructor of Admin class
		void testConstructor1();
		
		void testlogin();
		
		void testName1();
		void testName2();
		void testName3();
		void testName4();
		void testName5();
		
		void testbloodgroup1();
		void testbloodgroup2();
		void testbloodgroup3();
		
		void testaadhaar1();
		void testaadhaar2();
		void testaadhaar3();
		
		void testPhoneNumber1();
		void testPhoneNumber2();
		void testPhoneNumber3();
		
		void testGender1();
		void testGender2();
		void testGender3();
		void testGender4();
		
		void testAddress1();
		void testAddress2();
		void testAddress3();
		void testAddress4();
		
		void testPassword1();
		void testPassword2();
		void testPassword3();
		void testPassword4();
		void testPassword5();
		void testPassword6();
		void testPassword7();
		void testPassword8();
		void testPassword9();
		
		
		string firstname_validation(string firstname);
		string bloodgroup_validation(string bloodgroup);
		long aadhaar_validation(long int aadhaarnumber);
		long phonenumber_validation(long int phonenumber);
		string gender_validation(string gender);
		string address_validation(string address);
		string password_validation(string password);
};
#endif

