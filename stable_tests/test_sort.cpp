#include "tests.h"

#include <string>
#include <vector>
#include <string.h>

#include "whodun_sort.h"

using namespace whodun;

UnitTestSet allSortTests;

const char* testSortPODComp0Func(){
	PODLessComparator<int> testC;
	if(testC.itemSize() != sizeof(int)){ return "Wrong size"; }
	int testA = 7;
	int testB = 8;
	if(!testC.compare(&testA,&testB)){ return "Wrong order!"; }
	return 0;
}
UnitTest testSortPODComp0 = {"compare 7 < 8",testSortPODComp0Func,__FILE__,__LINE__};

const char* testSortPODSearch0Func(){
	PODLessComparator<int> testC;
	PODSortOptions testO(&testC);
	int testD[] = {1,2,2,3,4,6};
	PODSortedDataChunk testSC(&testO, (char*)testD, 6);
	int huntV = 3;
	if(testSC.lowerBound((char*)&huntV) != 3){ return "Not right!"; }
	return 0;
}
UnitTest testSortPODSearch0 = {"lower bound (unique)",testSortPODSearch0Func,__FILE__,__LINE__};

const char* testSortPODSearch1Func(){
	PODLessComparator<int> testC;
	PODSortOptions testO(&testC);
	int testD[] = {1,2,2,3,4,6};
	PODSortedDataChunk testSC(&testO, (char*)testD,6);
	int huntV = 3;
	if(testSC.upperBound((char*)&huntV) != 4){ return "Not right!"; }
	return 0;
}
UnitTest testSortPODSearch1 = {"upper bound (unique)",testSortPODSearch1Func,__FILE__,__LINE__};

const char* testSortPODSearch2Func(){
	PODLessComparator<int> testC;
	PODSortOptions testO(&testC);
	int testD[] = {1,2,2,3,4,6};
	PODSortedDataChunk testSC(&testO, (char*)testD, 6);
	int huntV = 0;
	if(testSC.lowerBound((char*)&huntV) != 0){ return "Not right!"; }
	return 0;
}
UnitTest testSortPODSearch2 = {"lower bound (miss low)",testSortPODSearch2Func,__FILE__,__LINE__};

const char* testSortPODSearch3Func(){
	PODLessComparator<int> testC;
	PODSortOptions testO(&testC);
	int testD[] = {1,2,2,3,4,6};
	PODSortedDataChunk testSC(&testO, (char*)testD,6);
	int huntV = 0;
	if(testSC.upperBound((char*)&huntV) != 0){ return "Not right!"; }
	return 0;
}
UnitTest testSortPODSearch3 = {"upper bound (miss low)",testSortPODSearch3Func,__FILE__,__LINE__};

const char* testSortPODSearch4Func(){
	PODLessComparator<int> testC;
	PODSortOptions testO(&testC);
	int testD[] = {1,2,2,3,4,6};
	PODSortedDataChunk testSC(&testO, (char*)testD, 6);
	int huntV = 7;
	if(testSC.lowerBound((char*)&huntV) != 6){ return "Not right!"; }
	return 0;
}
UnitTest testSortPODSearch4 = {"lower bound (miss high)",testSortPODSearch4Func,__FILE__,__LINE__};

const char* testSortPODSearch5Func(){
	PODLessComparator<int> testC;
	PODSortOptions testO(&testC);
	int testD[] = {1,2,2,3,4,6};
	PODSortedDataChunk testSC(&testO, (char*)testD,6);
	int huntV = 7;
	if(testSC.upperBound((char*)&huntV) != 6){ return "Not right!"; }
	return 0;
}
UnitTest testSortPODSearch5 = {"upper bound (miss high)",testSortPODSearch5Func,__FILE__,__LINE__};

const char* testSortPODSearch6Func(){
	PODLessComparator<int> testC;
	PODSortOptions testO(&testC);
	int testD[] = {1,2,2,3,4,6};
	PODSortedDataChunk testSC(&testO, (char*)testD, 6);
	int huntV = 2;
	if(testSC.lowerBound((char*)&huntV) != 1){ return "Not right!"; }
	return 0;
}
UnitTest testSortPODSearch6 = {"lower bound (dupe)",testSortPODSearch6Func,__FILE__,__LINE__};

const char* testSortPODSearch7Func(){
	PODLessComparator<int> testC;
	PODSortOptions testO(&testC);
	int testD[] = {1,2,2,3,4,6};
	PODSortedDataChunk testSC(&testO, (char*)testD,6);
	int huntV = 2;
	if(testSC.upperBound((char*)&huntV) != 3){ return "Not right!"; }
	return 0;
}
UnitTest testSortPODSearch7 = {"upper bound (dupe)",testSortPODSearch7Func,__FILE__,__LINE__};

const char* testSortPODMerge0Func(){
	PODLessComparator<int> testC;
	PODSortOptions testO(&testC);
	PODSortedDataMerger doMer(&testO);
	int dataA[] = {1,2,3};
	int dataB[] = {2,3,4};
	int dataM[6];
	doMer.merge(3, (char*)dataA, 3, (char*)dataB, (char*)dataM);
	int dataT[] = {1,2,2,3,3,4};
	if(memcmp(dataM,dataT,6*sizeof(int))){ return "Not right!"; }
	return 0;
}
UnitTest testSortPODMerge0 = {"merge",testSortPODMerge0Func,__FILE__,__LINE__};

const char* testSortPODMergeSort0Func(){
	PODLessComparator<int> testC;
	PODSortOptions testO(&testC);
	PODInMemoryMergesort doMer(&testO);
	int dataA[] = {8,6,7,5,3,0,9};
	doMer.sort(7,(char*)dataA);
	int dataT[] = {0,3,5,6,7,8,9};
	if(memcmp(dataA,dataT,7*sizeof(int))){ return "Not right!"; }
	return 0;
}
UnitTest testSortPODMergeSort0 = {"sort Jenny",testSortPODMergeSort0Func,__FILE__,__LINE__};

UnitTestSet* getSortTests(){
	allSortTests.name = "whodun_sort";
	allSortTests.tests.push_back(testSortPODComp0);
	allSortTests.tests.push_back(testSortPODSearch0);
	allSortTests.tests.push_back(testSortPODSearch1);
	allSortTests.tests.push_back(testSortPODSearch2);
	allSortTests.tests.push_back(testSortPODSearch3);
	allSortTests.tests.push_back(testSortPODSearch4);
	allSortTests.tests.push_back(testSortPODSearch5);
	allSortTests.tests.push_back(testSortPODSearch6);
	allSortTests.tests.push_back(testSortPODSearch7);
	allSortTests.tests.push_back(testSortPODMerge0);
	allSortTests.tests.push_back(testSortPODMergeSort0);
	return &allSortTests;
}


