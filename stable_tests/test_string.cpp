#include "tests.h"

#include <string>
#include <vector>
#include <string.h>

#include "whodun_string.h"

using namespace whodun;

UnitTestSet allStringTests;

const char* testStringEq0Func(){
	char testArr[] = "abcabc";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(!(testStrA == testStrB)){ return "Not equal!"; }
	return 0;
}
UnitTest testStringEq0 = {"SizePtrString abc == abc",testStringEq0Func,__FILE__,__LINE__};

const char* testStringEq1Func(){
	char testArr[] = "abc123";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(testStrA == testStrB){ return "Equal!"; }
	return 0;
}
UnitTest testStringEq1 = {"SizePtrString abc == 123",testStringEq1Func,__FILE__,__LINE__};

const char* testStringEq2Func(){
	char testArr[] = "abcabcd";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {4, testArr+3};
	if(testStrA == testStrB){ return "Equal!"; }
	return 0;
}
UnitTest testStringEq2 = {"SizePtrString abc == abcd",testStringEq2Func,__FILE__,__LINE__};

const char* testStringNeq0Func(){
	char testArr[] = "abc123";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(!(testStrA != testStrB)){ return "Equal!"; }
	return 0;
}
UnitTest testStringNeq0 = {"SizePtrString abc != 123",testStringNeq0Func,__FILE__,__LINE__};

const char* testStringNeq1Func(){
	char testArr[] = "abcabc";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(testStrA != testStrB){ return "Not Equal!"; }
	return 0;
}
UnitTest testStringNeq1 = {"SizePtrString abc != abc",testStringNeq1Func,__FILE__,__LINE__};

const char* testStringNeq2Func(){
	char testArr[] = "abcabcd";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {4, testArr+3};
	if(!(testStrA != testStrB)){ return "Equal!"; }
	return 0;
}
UnitTest testStringNeq2 = {"SizePtrString abc != abcd",testStringNeq2Func,__FILE__,__LINE__};

const char* testStringLt0Func(){
	char testArr[] = "abcabc";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(testStrA < testStrB){ return "Less than!"; }
	return 0;
}
UnitTest testStringLt0 = {"SizePtrString abc < abc",testStringLt0Func,__FILE__,__LINE__};

const char* testStringLt1Func(){
	char testArr[] = "abcabd";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(!(testStrA < testStrB)){ return "Not less than!"; }
	return 0;
}
UnitTest testStringLt1 = {"SizePtrString abc < abd",testStringLt1Func,__FILE__,__LINE__};

const char* testStringLt2Func(){
	char testArr[] = "abdabc";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(testStrA < testStrB){ return "Less than!"; }
	return 0;
}
UnitTest testStringLt2 = {"SizePtrString abd < abc",testStringLt2Func,__FILE__,__LINE__};

const char* testStringLt3Func(){
	char testArr[] = "abcabcd";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {4, testArr+3};
	if(!(testStrA < testStrB)){ return "Not less than!"; }
	return 0;
}
UnitTest testStringLt3 = {"SizePtrString abc < abcd",testStringLt3Func,__FILE__,__LINE__};

const char* testStringLt4Func(){
	char testArr[] = "abcdabc";
	SizePtrString testStrA = {4, testArr};
	SizePtrString testStrB = {3, testArr+4};
	if(testStrA < testStrB){ return "Less than!"; }
	return 0;
}
UnitTest testStringLt4 = {"SizePtrString abcd < abc",testStringLt4Func,__FILE__,__LINE__};

const char* testStringGt0Func(){
	char testArr[] = "abcabc";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(testStrA > testStrB){ return "Greater than!"; }
	return 0;
}
UnitTest testStringGt0 = {"SizePtrString abc > abc",testStringGt0Func,__FILE__,__LINE__};

const char* testStringGt1Func(){
	char testArr[] = "abcabd";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(testStrA > testStrB){ return "Greater than!"; }
	return 0;
}
UnitTest testStringGt1 = {"SizePtrString abc > abd",testStringGt1Func,__FILE__,__LINE__};

const char* testStringGt2Func(){
	char testArr[] = "abdabc";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(!(testStrA > testStrB)){ return "Not greater than!"; }
	return 0;
}
UnitTest testStringGt2 = {"SizePtrString abd > abc",testStringGt2Func,__FILE__,__LINE__};

const char* testStringGt3Func(){
	char testArr[] = "abcabcd";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {4, testArr+3};
	if(testStrA > testStrB){ return "Greater than!"; }
	return 0;
}
UnitTest testStringGt3 = {"SizePtrString abc > abcd",testStringGt3Func,__FILE__,__LINE__};

const char* testStringGt4Func(){
	char testArr[] = "abcdabc";
	SizePtrString testStrA = {4, testArr};
	SizePtrString testStrB = {3, testArr+4};
	if(!(testStrA > testStrB)){ return "Not greater than!"; }
	return 0;
}
UnitTest testStringGt4 = {"SizePtrString abcd > abc",testStringGt4Func,__FILE__,__LINE__};

const char* testStringLte0Func(){
	char testArr[] = "abcabc";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(!(testStrA <= testStrB)){ return "Not equal!"; }
	return 0;
}
UnitTest testStringLte0 = {"SizePtrString abc <= abc",testStringLte0Func,__FILE__,__LINE__};

const char* testStringLte1Func(){
	char testArr[] = "abcabd";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(!(testStrA <= testStrB)){ return "Not less than!"; }
	return 0;
}
UnitTest testStringLte1 = {"SizePtrString abc <= abd",testStringLte1Func,__FILE__,__LINE__};

const char* testStringLte2Func(){
	char testArr[] = "abdabc";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(testStrA <= testStrB){ return "Less than!"; }
	return 0;
}
UnitTest testStringLte2 = {"SizePtrString abd <= abc",testStringLte2Func,__FILE__,__LINE__};

const char* testStringLte3Func(){
	char testArr[] = "abcabcd";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {4, testArr+3};
	if(!(testStrA <= testStrB)){ return "Not less than!"; }
	return 0;
}
UnitTest testStringLte3 = {"SizePtrString abc <= abcd",testStringLte3Func,__FILE__,__LINE__};

const char* testStringLte4Func(){
	char testArr[] = "abcdabc";
	SizePtrString testStrA = {4, testArr};
	SizePtrString testStrB = {3, testArr+4};
	if(testStrA <= testStrB){ return "Less than!"; }
	return 0;
}
UnitTest testStringLte4 = {"SizePtrString abcd <= abc",testStringLte4Func,__FILE__,__LINE__};

const char* testStringGte0Func(){
	char testArr[] = "abcabc";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(!(testStrA >= testStrB)){ return "Not equal!"; }
	return 0;
}
UnitTest testStringGte0 = {"SizePtrString abc >= abc",testStringGte0Func,__FILE__,__LINE__};

const char* testStringGte1Func(){
	char testArr[] = "abcabd";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(testStrA >= testStrB){ return "Greater than!"; }
	return 0;
}
UnitTest testStringGte1 = {"SizePtrString abc >= abd",testStringGte1Func,__FILE__,__LINE__};

const char* testStringGte2Func(){
	char testArr[] = "abdabc";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {3, testArr+3};
	if(!(testStrA >= testStrB)){ return "Not greater than!"; }
	return 0;
}
UnitTest testStringGte2 = {"SizePtrString abd >= abc",testStringGte2Func,__FILE__,__LINE__};

const char* testStringGte3Func(){
	char testArr[] = "abcabcd";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = {4, testArr+3};
	if(testStrA >= testStrB){ return "Greater than!"; }
	return 0;
}
UnitTest testStringGte3 = {"SizePtrString abc >= abcd",testStringGte3Func,__FILE__,__LINE__};

const char* testStringGte4Func(){
	char testArr[] = "abcdabc";
	SizePtrString testStrA = {4, testArr};
	SizePtrString testStrB = {3, testArr+4};
	if(!(testStrA >= testStrB)){ return "Not greater than!"; }
	return 0;
}
UnitTest testStringGte4 = {"SizePtrString abcd >= abc",testStringGte4Func,__FILE__,__LINE__};

const char* testStringToSizePtr0Func(){
	char testArr[] = "abc";
	SizePtrString testStrA = {3, testArr};
	SizePtrString testStrB = toSizePtr("abc");
	if(testStrA != testStrB){ return "Not equal."; }
	return 0;
}
UnitTest testStringToSizePtr0 = {"toSizePtr(string literal)",testStringToSizePtr0Func,__FILE__,__LINE__};

const char* testStringToSizePtr1Func(){
	char testArr[] = "abc";
	SizePtrString testStrA = {3, testArr};
	std::string testStrBS = "abc";
	SizePtrString testStrB = toSizePtr(&testStrBS);
	if(testStrA != testStrB){ return "Not equal."; }
	return 0;
}
UnitTest testStringToSizePtr1 = {"toSizePtr(std::string)",testStringToSizePtr1Func,__FILE__,__LINE__};

const char* testStringToSizePtr2Func(){
	char testArr[] = "abc";
	SizePtrString testStrA = {3, testArr};
	std::vector<char> testStrBV;
		testStrBV.push_back('a');
		testStrBV.push_back('b');
		testStrBV.push_back('c');
	SizePtrString testStrB = toSizePtr(&testStrBV);
	if(testStrA != testStrB){ return "Not equal."; }
	return 0;
}
UnitTest testStringToSizePtr2 = {"toSizePtr(std::vector<char>)",testStringToSizePtr2Func,__FILE__,__LINE__};

const char* testStringParseInt0Func(){
	SizePtrString testStrA = toSizePtr("123");
	intptr_t parsedI = parseInt(testStrA);
	if(parsedI != 123){ return "Bad parse."; }
	return 0;
}
UnitTest testStringParseInt0 = {"parseInt(123)",testStringParseInt0Func,__FILE__,__LINE__};

const char* testStringParseInt1Func(){
	SizePtrString testStrA = toSizePtr("+123");
	intptr_t parsedI = parseInt(testStrA);
	if(parsedI != 123){ return "Bad parse."; }
	return 0;
}
UnitTest testStringParseInt1 = {"parseInt(+123)",testStringParseInt1Func,__FILE__,__LINE__};

const char* testStringParseInt2Func(){
	SizePtrString testStrA = toSizePtr("-123");
	intptr_t parsedI = parseInt(testStrA);
	if(parsedI != -123){ return "Bad parse."; }
	return 0;
}
UnitTest testStringParseInt2 = {"parseInt(-123)",testStringParseInt2Func,__FILE__,__LINE__};

const char* testStringParseInt3Func(){
	SizePtrString testStrA = toSizePtr("abc");
	try{
		parseInt(testStrA);
	}
	catch(std::exception& errE){
		return 0;
	}
	return "Did not throw.";
}
UnitTest testStringParseInt3 = {"parseInt(abc)",testStringParseInt3Func,__FILE__,__LINE__};

const char* testStringParseFloat0Func(){
	SizePtrString testStrA = toSizePtr("123");
	double parsedF = parseFloat(testStrA);
	if(parsedF != 123.0){ return "Bad parse."; }
	return 0;
}
UnitTest testStringParseFloat0 = {"parseFloat(123)",testStringParseFloat0Func,__FILE__,__LINE__};

const char* testStringParseFloat1Func(){
	SizePtrString testStrA = toSizePtr("+0123.00e0");
	double parsedF = parseFloat(testStrA);
	if(parsedF != 123.0){ return "Bad parse."; }
	return 0;
}
UnitTest testStringParseFloat1 = {"parseFloat(+0123.00e0)",testStringParseFloat1Func,__FILE__,__LINE__};

const char* testStringParseFloat2Func(){
	SizePtrString testStrA = toSizePtr("nan");
	double parsedF = parseFloat(testStrA);
	if(parsedF == parsedF){ return "Bad parse."; }
	return 0;
}
UnitTest testStringParseFloat2 = {"parseFloat(nan)",testStringParseFloat2Func,__FILE__,__LINE__};

const char* testStringParseFloat3Func(){
	SizePtrString testStrA = toSizePtr("inf");
	double parsedF = parseFloat(testStrA);
	if(parsedF != (1.0/0.0)){ return "Bad parse."; }
	return 0;
}
UnitTest testStringParseFloat3 = {"parseFloat(inf)",testStringParseFloat3Func,__FILE__,__LINE__};

const char* testStringParseFloat4Func(){
	SizePtrString testStrA = toSizePtr("-inf");
	double parsedF = parseFloat(testStrA);
	if(parsedF != (-1.0/0.0)){ return "Bad parse."; }
	return 0;
}
UnitTest testStringParseFloat4 = {"parseFloat(-inf)",testStringParseFloat4Func,__FILE__,__LINE__};

const char* testStringMemoryShuttlerMemcpy0Func(){
	StandardMemoryShuttler doShut;
	char testA[] = "Hello";
	char testB[] = "World";
	doShut.memcpy(testB, testA, 5);
	if(memcmp(testB, "Hello", 5) != 0){ return "Not copied."; }
	return 0;
}
UnitTest testStringMemoryShuttlerMemcpy0 = {"memcpy 0",testStringMemoryShuttlerMemcpy0Func,__FILE__,__LINE__};

const char* testStringMemoryShuttlerMemset0Func(){
	StandardMemoryShuttler doShut;
	char testA[] = "Hello";
	doShut.memset(testA, 'H', 5);
	if(memcmp(testA, "HHHHH", 5) != 0){ return "Not set."; }
	return 0;
}
UnitTest testStringMemoryShuttlerMemset0 = {"memset 0",testStringMemoryShuttlerMemset0Func,__FILE__,__LINE__};

const char* testStringMemoryShuttlerMemswap0Func(){
	StandardMemoryShuttler doShut;
	char testA[] = "Hello";
	char testB[] = "World";
	doShut.memswap(testB, testA, 5);
	if(memcmp(testB, "Hello", 5) != 0){ return "Not copied."; }
	if(memcmp(testA, "World", 5) != 0){ return "Not copied."; }
	return 0;
}
UnitTest testStringMemoryShuttlerMemswap0 = {"memswap 0",testStringMemoryShuttlerMemswap0Func,__FILE__,__LINE__};

const char* testStringMemoryShuttlerMemcsset0Func(){
	StandardMemoryShuttler doShut;
	char testA[] = "Hello__Hello__";
	char testB[] = "World";
	doShut.memcsset(testA, testB, 5, 7, 2);
	if(memcmp(testA, "World__World__", 14) != 0){ return "Not copied."; }
	return 0;
}
UnitTest testStringMemoryShuttlerMemcsset0 = {"memcsset 0",testStringMemoryShuttlerMemcsset0Func,__FILE__,__LINE__};

const char* testStringMemoryShuttlerMemcscpy0Func(){
	StandardMemoryShuttler doShut;
	char testA[] = "Hello__World__";
	char testB[] = "Their____There____";
	doShut.memcscpy(testA, testB, 5, 7, 9, 2);
	if(memcmp(testA, "Their__There__", 14) != 0){ return "Not copied."; }
	return 0;
}
UnitTest testStringMemoryShuttlerMemcscpy0 = {"memcscpy 0",testStringMemoryShuttlerMemcscpy0Func,__FILE__,__LINE__};

const char* testStringMemorySearcherMemcmp0Func(){
	StandardMemorySearcher doShut;
	char testA[] = "Hello";
	char testB[] = "World";
	if(doShut.memcmp(testA,testB,5) >= 0){ return "Incorrect comparison."; }
	return 0;
}
UnitTest testStringMemorySearcherMemcmp0 = {"memcmp Hello World",testStringMemorySearcherMemcmp0Func,__FILE__,__LINE__};

const char* testStringMemorySearcherMemchr0Func(){
	StandardMemorySearcher doShut;
	char testA[] = "Hello";
	char* foundL = (char*)(doShut.memchr(testA, 'l', 5));
	if(foundL != (testA + 2)){ return "Not found."; }
	return 0;
}
UnitTest testStringMemorySearcherMemchr0 = {"memchr l in Hello",testStringMemorySearcherMemchr0Func,__FILE__,__LINE__};

const char* testStringMemorySearcherMemcspn0Func(){
	StandardMemorySearcher doShut;
	char testA[] = "Hello";
	char testB[] = "qro";
	if(doShut.memcspn(testA,5,testB,3) != 4){ return "Incorrect comparison."; }
	return 0;
}
UnitTest testStringMemorySearcherMemcspn0 = {"memcspn qro from Hello",testStringMemorySearcherMemcspn0Func,__FILE__,__LINE__};

const char* testStringMemorySearcherMemspn0Func(){
	StandardMemorySearcher doShut;
	char testA[] = "Hello";
	char testB[] = "Hel";
	if(doShut.memspn(testA,5,testB,3) != 4){ return "Incorrect comparison."; }
	return 0;
}
UnitTest testStringMemorySearcherMemspn0 = {"memspn Hel from Hello",testStringMemorySearcherMemspn0Func,__FILE__,__LINE__};

const char* testStringMemorySearcherMemmem0Func(){
	StandardMemorySearcher doShut;
	char testA[] = "Hello my baby!";
	char testB[] = "my";
	char* foundIt = doShut.memmem(testA,14,testB,2);
	if(foundIt != (testA + 6)){ return "Incorrect comparison."; }
	return 0;
}
UnitTest testStringMemorySearcherMemmem0 = {"memmem my in Hello my baby!",testStringMemorySearcherMemmem0Func,__FILE__,__LINE__};

const char* testStringMemorySearcherMemendswith0Func(){
	StandardMemorySearcher doShut;
	char testA[] = "file.txt";
	char testB[] = ".txt";
	if(!(doShut.memendswith(testA,8,testB,4))){ return "Not matched."; }
	return 0;
}
UnitTest testStringMemorySearcherMemendswith0 = {"file.txt ends with .txt",testStringMemorySearcherMemendswith0Func,__FILE__,__LINE__};

const char* testStringMemorySearcherMemstartswith0Func(){
	StandardMemorySearcher doShut;
	char testA[] = "www.hello.com";
	char testB[] = "www.";
	if(!(doShut.memstartswith(testA,13,testB,4))){ return "Not matched."; }
	return 0;
}
UnitTest testStringMemorySearcherMemstartswith0 = {"www.hello.com starts with www.",testStringMemorySearcherMemstartswith0Func,__FILE__,__LINE__};

const char* testStringBytePacker64BE0Func(){
	char packTgt[8];
	BytePacker packM(packTgt);
	packM.packBE64(1234);
	if(memcmp(packTgt,"\x00\x00\x00\x00\x00\x00\x04\xD2",8) != 0){ return "Bad pack."; }
	return 0;
}
UnitTest testStringBytePacker64BE0 = {"Pack 1234 big endian 8",testStringBytePacker64BE0Func,__FILE__,__LINE__};

const char* testStringBytePacker32BE0Func(){
	char packTgt[4];
	BytePacker packM(packTgt);
	packM.packBE32(1234);
	if(memcmp(packTgt,"\x00\x00\x04\xD2",4) != 0){ return "Bad pack."; }
	return 0;
}
UnitTest testStringBytePacker32BE0 = {"Pack 1234 big endian 4",testStringBytePacker32BE0Func,__FILE__,__LINE__};

const char* testStringBytePacker16BE0Func(){
	char packTgt[2];
	BytePacker packM(packTgt);
	packM.packBE16(1234);
	if(memcmp(packTgt,"\x04\xD2",2) != 0){ return "Bad pack."; }
	return 0;
}
UnitTest testStringBytePacker16BE0 = {"Pack 1234 big endian 2",testStringBytePacker16BE0Func,__FILE__,__LINE__};

const char* testStringBytePacker64LE0Func(){
	char packTgt[8];
	BytePacker packM(packTgt);
	packM.packLE64(1234);
	if(memcmp(packTgt,"\xD2\x04\x00\x00\x00\x00\x00\x00",8) != 0){ return "Bad pack."; }
	return 0;
}
UnitTest testStringBytePacker64LE0 = {"Pack 1234 little endian 8",testStringBytePacker64LE0Func,__FILE__,__LINE__};

const char* testStringBytePacker32LE0Func(){
	char packTgt[4];
	BytePacker packM(packTgt);
	packM.packLE32(1234);
	if(memcmp(packTgt,"\xD2\x04\x00\x00",4) != 0){ return "Bad pack."; }
	return 0;
}
UnitTest testStringBytePacker32LE0 = {"Pack 1234 little endian 4",testStringBytePacker32LE0Func,__FILE__,__LINE__};

const char* testStringBytePacker16LE0Func(){
	char packTgt[2];
	BytePacker packM(packTgt);
	packM.packLE16(1234);
	if(memcmp(packTgt,"\xD2\x04",2) != 0){ return "Bad pack."; }
	return 0;
}
UnitTest testStringBytePacker16LE0 = {"Pack 1234 little endian 2",testStringBytePacker16LE0Func,__FILE__,__LINE__};

const char* testStringBytePackerBEDbl0Func(){
	char packTgt[8];
	BytePacker packM(packTgt);
	packM.packBEDbl(1.0);
	if(memcmp(packTgt,"\x3F\xF0\x00\x00\x00\x00\x00\x00",8) != 0){ return "Bad pack."; }
	return 0;
}
UnitTest testStringBytePackerBEDbl0 = {"Pack 1.0 big endian 8",testStringBytePackerBEDbl0Func,__FILE__,__LINE__};

const char* testStringBytePackerBEFlt0Func(){
	char packTgt[4];
	BytePacker packM(packTgt);
	packM.packBEFlt(1.0);
	if(memcmp(packTgt,"\x3F\x80\x00\x00",4) != 0){ return "Bad pack."; }
	return 0;
}
UnitTest testStringBytePackerBEFlt0 = {"Pack 1.0 big endian 4",testStringBytePackerBEFlt0Func,__FILE__,__LINE__};

const char* testStringBytePackerLEDbl0Func(){
	char packTgt[8];
	BytePacker packM(packTgt);
	packM.packLEDbl(1.0);
	if(memcmp(packTgt,"\x00\x00\x00\x00\x00\x00\xF0\x3F",8) != 0){ return "Bad pack."; }
	return 0;
}
UnitTest testStringBytePackerLEDbl0 = {"Pack 1.0 little endian 8",testStringBytePackerLEDbl0Func,__FILE__,__LINE__};

const char* testStringBytePackerLEFlt0Func(){
	char packTgt[4];
	BytePacker packM(packTgt);
	packM.packLEFlt(1.0);
	if(memcmp(packTgt,"\x00\x00\x80\x3F",4) != 0){ return "Bad pack."; }
	return 0;
}
UnitTest testStringBytePackerLEFlt0 = {"Pack 1.0 little endian 4",testStringBytePackerLEFlt0Func,__FILE__,__LINE__};

const char* testStringByteUnpacker64BE0Func(){
	char packTgt[] = "\x00\x00\x00\x00\x00\x00\x04\xD2";
	ByteUnpacker packM(packTgt);
	if(packM.unpackBE64() != 1234){ return "Bad unpack."; }
	return 0;
}
UnitTest testStringByteUnpacker64BE0 = {"Unpack 1234 big endian 8",testStringByteUnpacker64BE0Func,__FILE__,__LINE__};

const char* testStringByteUnpacker32BE0Func(){
	char packTgt[] = "\x00\x00\x04\xD2";
	ByteUnpacker packM(packTgt);
	if(packM.unpackBE32() != 1234){ return "Bad unpack."; }
	return 0;
}
UnitTest testStringByteUnpacker32BE0 = {"Unpack 1234 big endian 4",testStringByteUnpacker32BE0Func,__FILE__,__LINE__};

const char* testStringByteUnpacker16BE0Func(){
	char packTgt[] = "\x04\xD2";
	ByteUnpacker packM(packTgt);
	if(packM.unpackBE16() != 1234){ return "Bad unpack."; }
	return 0;
}
UnitTest testStringByteUnpacker16BE0 = {"Unpack 1234 big endian 2",testStringByteUnpacker16BE0Func,__FILE__,__LINE__};

const char* testStringByteUnpacker64LE0Func(){
	char packTgt[] = "\xD2\x04\x00\x00\x00\x00\x00\x00";
	ByteUnpacker packM(packTgt);
	if(packM.unpackLE64() != 1234){ return "Bad unpack."; }
	return 0;
}
UnitTest testStringByteUnpacker64LE0 = {"Unpack 1234 little endian 8",testStringByteUnpacker64LE0Func,__FILE__,__LINE__};

const char* testStringByteUnpacker32LE0Func(){
	char packTgt[] = "\xD2\x04\x00\x00";
	ByteUnpacker packM(packTgt);
	if(packM.unpackLE32() != 1234){ return "Bad unpack."; }
	return 0;
}
UnitTest testStringByteUnpacker32LE0 = {"Unpack 1234 little endian 4",testStringByteUnpacker32LE0Func,__FILE__,__LINE__};

const char* testStringByteUnpacker16LE0Func(){
	char packTgt[] = "\xD2\x04";
	ByteUnpacker packM(packTgt);
	if(packM.unpackLE16() != 1234){ return "Bad unpack."; }
	return 0;
}
UnitTest testStringByteUnpacker16LE0 = {"Unpack 1234 little endian 2",testStringByteUnpacker16LE0Func,__FILE__,__LINE__};

const char* testStringByteUnpackerBEDbl0Func(){
	char packTgt[] = "\x3F\xF0\x00\x00\x00\x00\x00\x00";
	ByteUnpacker packM(packTgt);
	if(packM.unpackBEDbl() != 1.0){ return "Bad unpack."; }
	return 0;
}
UnitTest testStringByteUnpackerBEDbl0 = {"Unpack 1.0 big endian 8",testStringByteUnpackerBEDbl0Func,__FILE__,__LINE__};

const char* testStringByteUnpackerBEFlt0Func(){
	char packTgt[] = "\x3F\x80\x00\x00";
	ByteUnpacker packM(packTgt);
	if(packM.unpackBEFlt() != 1.0){ return "Bad unpack."; }
	return 0;
}
UnitTest testStringByteUnpackerBEFlt0 = {"Unpack 1.0 big endian 4",testStringByteUnpackerBEFlt0Func,__FILE__,__LINE__};

const char* testStringByteUnpackerLEDbl0Func(){
	char packTgt[] = "\x00\x00\x00\x00\x00\x00\xF0\x3F";
	ByteUnpacker packM(packTgt);
	if(packM.unpackLEDbl() != 1.0){ return "Bad unpack."; }
	return 0;
}
UnitTest testStringByteUnpackerLEDbl0 = {"Unpack 1.0 little endian 8",testStringByteUnpackerLEDbl0Func,__FILE__,__LINE__};

const char* testStringByteUnpackerLEFlt0Func(){
	char packTgt[] = "\x00\x00\x80\x3F";
	ByteUnpacker packM(packTgt);
	if(packM.unpackLEFlt() != 1.0){ return "Bad unpack."; }
	return 0;
}
UnitTest testStringByteUnpackerLEFlt0 = {"Unpack 1.0 little endian 4",testStringByteUnpackerLEFlt0Func,__FILE__,__LINE__};

UnitTestSet* getStringTests(){
	allStringTests.name = "whodun_string";
	allStringTests.tests.push_back(testStringEq0);
	allStringTests.tests.push_back(testStringEq1);
	allStringTests.tests.push_back(testStringEq2);
	allStringTests.tests.push_back(testStringNeq0);
	allStringTests.tests.push_back(testStringNeq1);
	allStringTests.tests.push_back(testStringNeq2);
	allStringTests.tests.push_back(testStringLt0);
	allStringTests.tests.push_back(testStringLt1);
	allStringTests.tests.push_back(testStringLt2);
	allStringTests.tests.push_back(testStringLt3);
	allStringTests.tests.push_back(testStringLt4);
	allStringTests.tests.push_back(testStringGt0);
	allStringTests.tests.push_back(testStringGt1);
	allStringTests.tests.push_back(testStringGt2);
	allStringTests.tests.push_back(testStringGt3);
	allStringTests.tests.push_back(testStringGt4);
	allStringTests.tests.push_back(testStringLte0);
	allStringTests.tests.push_back(testStringLte1);
	allStringTests.tests.push_back(testStringLte2);
	allStringTests.tests.push_back(testStringLte3);
	allStringTests.tests.push_back(testStringLte4);
	allStringTests.tests.push_back(testStringGte0);
	allStringTests.tests.push_back(testStringGte1);
	allStringTests.tests.push_back(testStringGte2);
	allStringTests.tests.push_back(testStringGte3);
	allStringTests.tests.push_back(testStringGte4);
	allStringTests.tests.push_back(testStringToSizePtr0);
	allStringTests.tests.push_back(testStringToSizePtr1);
	allStringTests.tests.push_back(testStringToSizePtr2);
	allStringTests.tests.push_back(testStringParseInt0);
	allStringTests.tests.push_back(testStringParseInt1);
	allStringTests.tests.push_back(testStringParseInt2);
	allStringTests.tests.push_back(testStringParseInt3);
	allStringTests.tests.push_back(testStringParseFloat0);
	allStringTests.tests.push_back(testStringParseFloat1);
	allStringTests.tests.push_back(testStringParseFloat2);
	allStringTests.tests.push_back(testStringParseFloat3);
	allStringTests.tests.push_back(testStringParseFloat4);
	allStringTests.tests.push_back(testStringMemoryShuttlerMemcpy0);
	allStringTests.tests.push_back(testStringMemoryShuttlerMemset0);
	allStringTests.tests.push_back(testStringMemoryShuttlerMemswap0);
	allStringTests.tests.push_back(testStringMemoryShuttlerMemcsset0);
	allStringTests.tests.push_back(testStringMemoryShuttlerMemcscpy0);
	allStringTests.tests.push_back(testStringMemorySearcherMemcmp0);
	allStringTests.tests.push_back(testStringMemorySearcherMemchr0);
	allStringTests.tests.push_back(testStringMemorySearcherMemcspn0);
	allStringTests.tests.push_back(testStringMemorySearcherMemspn0);
	allStringTests.tests.push_back(testStringMemorySearcherMemmem0);
	allStringTests.tests.push_back(testStringMemorySearcherMemendswith0);
	allStringTests.tests.push_back(testStringMemorySearcherMemstartswith0);
	allStringTests.tests.push_back(testStringBytePacker64BE0);
	allStringTests.tests.push_back(testStringBytePacker32BE0);
	allStringTests.tests.push_back(testStringBytePacker16BE0);
	allStringTests.tests.push_back(testStringBytePacker64LE0);
	allStringTests.tests.push_back(testStringBytePacker32LE0);
	allStringTests.tests.push_back(testStringBytePacker16LE0);
	allStringTests.tests.push_back(testStringBytePackerBEDbl0);
	allStringTests.tests.push_back(testStringBytePackerBEFlt0);
	allStringTests.tests.push_back(testStringBytePackerLEDbl0);
	allStringTests.tests.push_back(testStringBytePackerLEFlt0);
	allStringTests.tests.push_back(testStringByteUnpacker64BE0);
	allStringTests.tests.push_back(testStringByteUnpacker32BE0);
	allStringTests.tests.push_back(testStringByteUnpacker16BE0);
	allStringTests.tests.push_back(testStringByteUnpacker64LE0);
	allStringTests.tests.push_back(testStringByteUnpacker32LE0);
	allStringTests.tests.push_back(testStringByteUnpacker16LE0);
	allStringTests.tests.push_back(testStringByteUnpackerBEDbl0);
	allStringTests.tests.push_back(testStringByteUnpackerBEFlt0);
	allStringTests.tests.push_back(testStringByteUnpackerLEDbl0);
	allStringTests.tests.push_back(testStringByteUnpackerLEFlt0);
	return &allStringTests;
}


