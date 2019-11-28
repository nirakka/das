#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/BriefTestProgressListener.h>

//#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>

int main (int argc, char* argv[])
{
	// informs test-listener about testresults
	CPPUNIT_NS :: TestResult testresult;

	// register listener for collecting the test-results
	CPPUNIT_NS :: TestResultCollector collectedresults;
	testresult.addListener (&collectedresults);

	// register listener for per-test progress output
	CPPUNIT_NS :: BriefTestProgressListener progress;
	testresult.addListener (&progress);

	// insert test-suite at test-runner by registry
	CPPUNIT_NS :: TestRunner testrunner;
	testrunner.addTest (CPPUNIT_NS :: TestFactoryRegistry :: getRegistry ().makeTest ());
	testrunner.run (testresult);

	//CPPUNIT_NS :: CompilerOutputter compileroutputter (&collectedresults, std::cerr);
	//compileroutputter.write ();

	std::ofstream ofs("result.xml");
	CPPUNIT_NS :: XmlOutputter xmloutputter (&collectedresults, ofs, "UTF-8");
	xmloutputter.setStyleSheet("result.xsl");
	xmloutputter.write();
      
	// return 0 if tests were successful
	return collectedresults.wasSuccessful () ? 0 : 1;
}
