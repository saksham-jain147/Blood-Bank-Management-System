#ifndef TEST_H
#define TEST_H

#include<cppunit/TestCase.h>
#include<cppunit/extensions/HelperMacros.h>
#include"customer.h"

/* class for testing Customer Module */
class CustomerTestCase : public CppUnit::TestCase // inheriting base class TestCase 
{
		CPPUNIT_TEST_SUITE(CustomerTestCase); // to start the test suite definition
			CPPUNIT_TEST(testConstructor); // to define a test case
			CPPUNIT_TEST(testConstructorcase1);
			CPPUNIT_TEST(testConstructorcase2);
			CPPUNIT_TEST(testlogin); 
			CPPUNIT_TEST(testlogincase1);
			CPPUNIT_TEST(testsetterId);
			CPPUNIT_TEST(testsetterIdcase1);
			CPPUNIT_TEST(testDate);	
			CPPUNIT_TEST(testDatecase1);
			CPPUNIT_TEST(testStockconstructor);
			CPPUNIT_TEST(testStockconstructorcase1);
			CPPUNIT_TEST(testStockconstructorcase2);	
		CPPUNIT_TEST_SUITE_END(); // to end test suite definition	
    
	public:
		void testConstructor(); // testing constructor of Customer class for positive testcase
		void testConstructorcase1(); // testing constructor of Customer class for negative testcase
		void testConstructorcase2();
		void testlogin();
		void testlogincase1();
		void testsetterId();
		void testsetterIdcase1();
		void testDate();
		void testDatecase1();
		void testStockconstructor();
		void testStockconstructorcase1();
		void testStockconstructorcase2();
};
#endif
