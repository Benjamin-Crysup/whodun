#include "tests.h"

#include <string>
#include <vector>
#include <string.h>

#include "whodun_string.h"
#include "whodun_container.h"

using namespace whodun;

UnitTestSet allContainerTests;

const char* testContainerStructVector0Func(){
	StructVector<char> testV;
	if(testV.size()){ return "Not empty!"; }
	return 0;
}
UnitTest testContainerStructVector0 = {"StructVector empty",testContainerStructVector0Func,__FILE__,__LINE__};

const char* testContainerStructVector1Func(){
	StructVector<char> testV(5);
	memcpy(testV.at(0), "Hello", 5);
	if(memcmp(testV[0],"Hello",5)){ return "Not getting value correctly!"; }
	return 0;
}
UnitTest testContainerStructVector1 = {"StructVector initial size",testContainerStructVector1Func,__FILE__,__LINE__};

const char* testContainerStructVector2Func(){
	StructVector<char> testV;
	char* addStr = (char*)"Hello";
	testV.insert(0, addStr, addStr+5);
	if(testV.size() != 5){ return "Not resizing properly!"; }
	if(memcmp(testV[0],"Hello",5)){ return "Not inserting correctly!"; }
	return 0;
}
UnitTest testContainerStructVector2 = {"StructVector insert",testContainerStructVector2Func,__FILE__,__LINE__};

const char* testContainerStructVector3Func(){
	char addC = 'H';
	StructVector<char> testV;
	testV.push_back(&addC);
	if(testV.size() != 1){ return "Not pushing properly!"; }
	if(testV[0][0] != 'H'){ return "Not pushing correctly!"; }
	return 0;
}
UnitTest testContainerStructVector3 = {"StructVector push_back",testContainerStructVector3Func,__FILE__,__LINE__};

const char* testContainerStructVector4Func(){
	char addC = 'H';
	StructVector<char> testV;
	testV.push_back(&addC);
	testV.pop_back();
	if(testV.size()){ return "Not popping properly!"; }
	return 0;
}
UnitTest testContainerStructVector4 = {"StructVector pop_back",testContainerStructVector4Func,__FILE__,__LINE__};

const char* testContainerStructVector5Func(){
	StructVector<char> testV;
	char* addStr = (char*)"Hello";
	testV.insert(0, addStr, addStr+5);
	SizePtrString svAS = toSizePtr(&testV);
	SizePtrString cpAS = toSizePtr(addStr);
	if(svAS != cpAS){ return "Not turning into a string correctly."; }
	return 0;
}
UnitTest testContainerStructVector5 = {"StructVector as string",testContainerStructVector5Func,__FILE__,__LINE__};

const char* testContainerStructDeque0Func(){
	StructDeque<char> testV;
	if(testV.size()){ return "Not empty!"; }
	return 0;
}
UnitTest testContainerStructDeque0 = {"StructDeque empty",testContainerStructDeque0Func,__FILE__,__LINE__};

const char* testContainerStructDeque1Func(){
	StructDeque<char> testV;
	char addC = 'H';
	char* addL = testV.pushBack(1);
	*addL = addC;
	if(testV.size() != 1){ return "Not sized right."; }
	if(testV.getItem(0)[0] != 'H'){ return "Not set."; }
	return 0;
}
UnitTest testContainerStructDeque1 = {"StructDeque pushBack",testContainerStructDeque1Func,__FILE__,__LINE__};

const char* testContainerTriple0Func(){
	triple<int,int,int> testV(0,1,2);
	if(testV.first != 0){ return "Not set."; }
	if(testV.second != 1){ return "Not set."; }
	if(testV.third != 2){ return "Not set."; }
	return 0;
}
UnitTest testContainerTriple0 = {"triple constructor",testContainerTriple0Func,__FILE__,__LINE__};

const char* testContainerTriple1Func(){
	triple<int,int,int> testA(0,1,2);
	triple<int,int,int> testB(0,1,3);
	if(!(testA < testB)){ return "Out of order!"; }
	return 0;
}
UnitTest testContainerTriple1 = {"triple (0,1,2) < (0,1,3)",testContainerTriple1Func,__FILE__,__LINE__};

UnitTestSet* getContainerTests(){
	allContainerTests.name = "whodun_container";
	allContainerTests.tests.push_back(testContainerStructVector0);
	allContainerTests.tests.push_back(testContainerStructVector1);
	allContainerTests.tests.push_back(testContainerStructVector2);
	allContainerTests.tests.push_back(testContainerStructVector3);
	allContainerTests.tests.push_back(testContainerStructVector4);
	allContainerTests.tests.push_back(testContainerStructVector5);
	allContainerTests.tests.push_back(testContainerStructDeque0);
	allContainerTests.tests.push_back(testContainerStructDeque1);
	allContainerTests.tests.push_back(testContainerTriple0);
	allContainerTests.tests.push_back(testContainerTriple1);
	return &allContainerTests;
}

