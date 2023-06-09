#ifndef WHODUN_STAT_RANDOMS_H
#define WHODUN_STAT_RANDOMS_H 1

/**
 * @file
 * @brief RNG
 */

#include <stdint.h>

namespace whodun {

/**A random number generator.*/
class RandomGenerator{
public:
	/**Allow subclasses to clean up.*/
	virtual ~RandomGenerator();
	
	/**
	 * Get the number of bytes this needs as a seed.
	 * @return The number of needed bytes.
	 */
	virtual uintptr_t seedSize() = 0;
	/**
	 * Seed this generator.
	 * @param seedV THe seed value.
	 */
	virtual void seed(char* seedV) = 0;
	/**
	 * Get the next byte from this generator.
	 * @return The next random byte.
	 */
	virtual char next() = 0;
	
	/**
	 * Seed with an integer.
	 * @param seedV The seed value to use.
	 */
	virtual void seedI(uintmax_t seedV);
	/**
	 * Get some bytes.
	 * @param numDraw The number of bytes to get.
	 * @param toFill The place to put the bytes.
	 */
	virtual void draw(uintptr_t numDraw, char* toFill);
	/**
	 * Get random doubles between 0 and 1.
	 * @param numDraw The number of floats to get.
	 * @param toFill The place to put the doubles.
	 */
	virtual void draw(uintptr_t numDraw, float* toFill);
	/**
	 * Get random doubles between 0 and 1.
	 * @param numDraw The number of doubles to get.
	 * @param toFill The place to put the doubles.
	 */
	virtual void draw(uintptr_t numDraw, double* toFill);
};

/**The mersenne twister.*/
class MersenneTwisterGenerator : public RandomGenerator{
public:
	/**Set up.*/
	MersenneTwisterGenerator();
	/**Clean up.*/
	virtual ~MersenneTwisterGenerator();
	uintptr_t seedSize();
	void seed(char* seedV);
	char next();
	
	/**Whether this thing has been seeded.*/
	bool haveSeed;
	/**The state array.*/
	uint32_t mtarr[624];
	/**The next entry in the array to use.*/
	int nextEnt;
	/**The number of ready bytes.*/
	int numPG;
	/**Previously generated bytes.*/
	uint32_t prevGen;
};

}

#endif

