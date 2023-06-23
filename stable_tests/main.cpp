#include "tests.h"

int main(int argc, char** argv){
	whodun::RunUnitTestRunProgram runProg;
	runProg.allSets.push_back(getStringTests());
	runProg.allSets.push_back(getContainerTests());
	runProg.allSets.push_back(getCompressTests());
	runProg.allSets.push_back(getSortTests());
	runProg.parseArguments(argc - 1, argv + 1);
	runProg.run();
	return runProg.wasError;
}

