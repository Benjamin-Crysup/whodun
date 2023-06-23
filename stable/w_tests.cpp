#include "whodun_tests.h"

#include <math.h>
#include <string.h>

using namespace whodun;

UnitTestResult::UnitTestResult(){}
UnitTestResult::~UnitTestResult(){}

UnitTestSet::UnitTestSet(){}
UnitTestSet::~UnitTestSet(){}
uintptr_t UnitTestSet::size(){
	return tests.size();
}
uintptr_t UnitTestSet::run(UnitTestResult* fillRes){
	uintptr_t numFail = 0;
	for(uintptr_t i = 0; i<tests.size(); i++){
		UnitTest* curRun = &(tests[i]);
		UnitTestResult* curFill = fillRes ? (fillRes + i) : (UnitTestResult*)0;
		if(curFill){
			curFill->theTest = curRun;
			curFill->failed = 0;
			curFill->excepted = 0;
		}
		clock_t startTime = clock();
		try{
			const char* runRes = curRun->code();
			if(runRes && strlen(runRes)){
				numFail++;
				if(curFill){
					curFill->failed = 1;
					curFill->hotExcept = WhodunError(WHODUN_ERROR_LEVEL_WARNING, WHODUN_ERROR_SDESC_ASSERT, curRun->srcFile, curRun->srcLine, runRes, 0, 0);
				}
			}
		}
		catch(WhodunError& errW){
			numFail++;
			if(curFill){
				curFill->failed = 1;
				curFill->excepted = 1;
				curFill->hotExcept = errW;
			}
		}
		catch(std::exception& errE){
			numFail++;
			if(curFill){
				curFill->failed = 1;
				curFill->excepted = 1;
				curFill->hotExcept = WhodunError(errE, curRun->srcFile, curRun->srcLine);
			}
		}
		if(curFill){
			curFill->takenTime = (clock() - startTime);
		}
	}
	return numFail;
}

RunUnitTestRunProgram::RunUnitTestRunProgram(){
	name = "unit";
	summary = "Run a set of unit tests.";
	version = "whodun unit 0.0\nCopyright (C) 2022 Benjamin Crysup\nLicense LGPLv3: GNU LGPL version 3\nThis is free software: you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\n";
	usage = "unit";
}
RunUnitTestRunProgram::~RunUnitTestRunProgram(){}
void RunUnitTestRunProgram::baseRun(){
	char asciiBuff[8*sizeof(uintmax_t)+16];
	uintptr_t numFail = 0;
	uintptr_t numRan = 0;
	std::vector<UnitTestResult> hotRes;
	for(uintptr_t i = 0; i<allSets.size(); i++){
		//run the set
			UnitTestSet* curSet = allSets[i];
			uintptr_t curSetS = curSet->size();
			hotRes.resize(std::max((uintptr_t)(hotRes.size()), (uintptr_t)(curSetS + 1)));
			curSet->run(&(hotRes[0]));
			numRan += curSetS;
		//dump the results
			for(uintptr_t j = 0; j<curSetS; j++){
				UnitTestResult* curR = &(hotRes[j]);
				UnitTest* curT = curR->theTest;
				//print the test
				{
					sprintf(asciiBuff, "in %es", (double)(curR->takenTime / (double)CLOCKS_PER_SEC));
					const char* passArr[] = {curSet->name, curT->name, asciiBuff};
					useErr->logError(WHODUN_ERROR_LEVEL_DEBUG, WHODUN_ERROR_SDESC_UPDATE, curT->srcFile, curT->srcLine, "Ran Test", 3, passArr);
				}
				//print any failure
				if(curR->failed){
					numFail++;
					const char* passArr[] = {curSet->name, curT->name, curR->hotExcept.what()};
					useErr->logError(WHODUN_ERROR_LEVEL_WARNING, WHODUN_ERROR_SDESC_ASSERT, curT->srcFile, curT->srcLine, "FAIL", 3, passArr);
				}
				//if any exceptions, print
				if(curR->excepted){
					useErr->logError(curR->hotExcept);
				}
			}
	}
	//print out total number of tests
	{
		sprintf(asciiBuff, "%d", (int)numRan);
		const char* passArr[] = {asciiBuff};
		useErr->logError(WHODUN_ERROR_LEVEL_DEBUG, WHODUN_ERROR_SDESC_UPDATE, __FILE__, __LINE__, "Ran All Tests", 1, passArr);
	}
	//print out number of failures
	if(numFail){
		sprintf(asciiBuff, "%d", (int)numFail);
		const char* passArr[] = {asciiBuff};
		useErr->logError(WHODUN_ERROR_LEVEL_WARNING, WHODUN_ERROR_SDESC_ASSERT, __FILE__, __LINE__, "FAILURES", 1, passArr);
	}
}

int whodun::floatClose(double ta, double tb, double tol){
	return fabs(ta - tb) < tol;
}



