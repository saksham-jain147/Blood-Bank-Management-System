#include<cppunit/ui/text/TestRunner.h>
#include<cppunit/extensions/TestFactoryRegistry.h>

#include "TestAdmin.h"

int main(int argc, char* argv[])
{
	CppUnit::TextUi::TestRunner runner;
	runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest() );
    runner.run();
	
	return 0;
}
