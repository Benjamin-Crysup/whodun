#ifndef WHODUN_TESTS_H
#define WHODUN_TESTS_H 1

/**
 * @file
 * @brief Structure for unit tests.
 */

#include <time.h>
#include <vector>

#include "whodun_args.h"
#include "whodun_ermac.h"
#include "whodun_string.h"

namespace whodun {

/**A unit test to run.*/
typedef struct{
	/**The name of the test.*/
	const char* name;
	/**The code to run for the test. Return null or empty string on success.*/
	const char* (*code)();
	/**The file this test is from.*/
	const char* srcFile;
	/**The line it starts at.*/
	int srcLine;
} UnitTest;

/**The result from running a unit test.*/
class UnitTestResult{
public:
	/**Set up an empty result.*/
	UnitTestResult();
	/**Clean up.*/
	~UnitTestResult();
	
	/**The test that ran.*/
	UnitTest* theTest;
	/**Whether the test failed.*/
	int failed;
	/**Whether the test threw an exception.*/
	int excepted;
	/**The exception it threw.*/
	WhodunError hotExcept;
	/**The time it took to run.*/
	clock_t takenTime;
};

/**A collection of unit tests.*/
class UnitTestSet{
public:
	/**Set up an empty set.*/
	UnitTestSet();
	/**Clean up*/
	~UnitTestSet();
	
	/**
	 * Get the number of tests.
	 * @return The number of tests.
	 */
	uintptr_t size();
	/**
	 * Run the unit tests.
	 * @param fillRes The place to put the results: null to not save.
	 * @return The number of failing tests.
	 */
	uintptr_t run(UnitTestResult* fillRes);
	
	/**The name of this set.*/
	const char* name;
	/**The tests in this set.*/
	std::vector<UnitTest> tests;
};

/**Run some unit tests.*/
class RunUnitTestRunProgram : public StandardProgram{
public:
	/**Set up*/
	RunUnitTestRunProgram();
	/**Tear down*/
	~RunUnitTestRunProgram();
	void baseRun();
	
	/**All the sets to run.*/
	std::vector<UnitTestSet*> allSets;
};

/**
 * Test whether floats are approximately equal.
 * @param ta The first value.
 * @param tb The second value.
 * @param tol The tolerance (absolute).
 * @return Whether the floats are approximately equal.
 */
int floatClose(double ta, double tb, double tol);

};

#endif

