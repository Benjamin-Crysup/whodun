#ifndef W_TEST
#define W_TEST 1

#include "whodun_tests.h"

/**
 * Grab tests for whodun_string.h
 * @return The tests.
 */
whodun::UnitTestSet* getStringTests();

/**
 * Grab tests for whodun_container.h
 * @return The tests.
 */
whodun::UnitTestSet* getContainerTests();

/**
 * Grab tests for whodun_compress.h
 * @return The tests.
 */
whodun::UnitTestSet* getCompressTests();

/**
 * Grab tests for whodun_sort.h
 * @return The tests.
 */
whodun::UnitTestSet* getSortTests();

#endif

