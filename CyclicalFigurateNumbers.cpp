#include <iostream>
#include <math.h>

using namespace std;

/**
 * Returns the nth Hexagonal number.
 * 
 * Note that all Hexagonal numbers must be triangular.
 */
long long hexagon(int n) {
    return (long long)n * ((long long)n*2 - 1);
}

// Is the given number Pentagonal?
bool isPent(long long num) {
    double n_est = (1 + sqrt(1+24*num)) / 6;
    return fmod(n_est, 1) == 0;
}

// Is the given number Hexagonal?
bool isHex(long long num) {
    double n_est = (1 + sqrt(1+8*num)) / 4;
    return fmod(n_est, 1) == 0;
}

int main() {
    return 0;
}
