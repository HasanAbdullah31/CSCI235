/* Hasan Abdullah: ZeroDivide.h - header file for the derived class dealing
   with divide-by-zero */

#ifndef ZERO_DIVIDE
#define ZERO_DIVIDE

#include "MathError.h"

class ZeroDivide : public MathError {
private:
 int a, b;
public:
 ZeroDivide(int x, int y);
 void Handler();
};

#endif /* ZERO_DIVIDE */
