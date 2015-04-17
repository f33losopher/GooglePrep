/*
 * GCD.h
 *
 *  Created on: Apr 17, 2015
 *      Author: Felix
 */

#ifndef GCD_H_
#define GCD_H_

#include <algorithm>
#include <cstdlib>

namespace GCD {

/**
 * Greatest Common Denominator
 */
int gcd(int a, int b) {
	if(a == b) return a;
	return (gcd((int)std::min(a,b), abs(a-b)));
}

int otherGcd(int a, int b) {
	if(b==0) return a;
	return otherGcd(b, a%b);
}

/**
 * Lease Common Multiple
 */
int LCM(int a, int b) {
	return(a*b)/gcd(a,b);
}
}



#endif /* GCD_H_ */
