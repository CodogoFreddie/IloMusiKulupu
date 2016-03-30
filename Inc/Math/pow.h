#ifndef MATH_POW_H_
#define MATH_POW_H_

namespace math{
const int ipow(int base, int exp){
    int result = 1;
    while(exp){
        if(exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}
}
#endif
