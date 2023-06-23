#include "tests.h"

#include <string>
#include <vector>
#include <string.h>

#include "whodun_compress.h"

using namespace whodun;

UnitTestSet allCompressTests;

const char* testCompressRoundTrip(CompressionFactory* doFac, SizePtrString startV){
	CompressionMethod* doZip = doFac->makeZip();
	DecompressionMethod* doUZip = doFac->makeUnzip();
	doZip->compressData(startV);
	doUZip->expandData(doZip->compData);
	const char* errM = 0;
	if(doUZip->theData != startV){ errM = "Did not match."; }
	delete(doZip);
	delete(doUZip);
	return errM;
}

#define RUN_ROUND_TRIP_TEST(testName,facType,testStr,descStr) \
const char* testName ## Func(){\
	facType doFac;\
	SizePtrString startV = toSizePtr(testStr);\
	return testCompressRoundTrip(&doFac,startV);\
}\
UnitTest testName = {descStr,testName ## Func,__FILE__,__LINE__};

RUN_ROUND_TRIP_TEST(testCompressRaw0,RawCompressionFactory,"","raw empty")
RUN_ROUND_TRIP_TEST(testCompressRaw1,RawCompressionFactory,"Hello","raw Hello")

RUN_ROUND_TRIP_TEST(testCompressZlib0,DeflateCompressionFactory,"","zlib empty")
RUN_ROUND_TRIP_TEST(testCompressZlib1,DeflateCompressionFactory,"Hello","zlib Hello")

UnitTestSet* getCompressTests(){
	allCompressTests.name = "whodun_compress";
	allCompressTests.tests.push_back(testCompressRaw0);
	allCompressTests.tests.push_back(testCompressRaw1);
	allCompressTests.tests.push_back(testCompressZlib0);
	allCompressTests.tests.push_back(testCompressZlib1);
	return &allCompressTests;
}

