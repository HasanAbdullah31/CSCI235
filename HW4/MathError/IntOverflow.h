/* Hasan Abdullah: IntOverflow.h - header file for the derived class dealing
   with short integer overflow */

#ifndef INT_OVERFLOW
#define INT_OVERFLOW

#include "MathError.h"

class IntOverflow : public MathError {
private:
 short a, b;
public:
 IntOverflow();
 IntOverflow(short x, short y);
 void Handler();
};

#endif /* INT_OVERFLOW */
