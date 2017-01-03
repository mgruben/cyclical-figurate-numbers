#include <iostream>
#include <math.h>

using namespace std;

// Is the given number Triangular?
bool isTri(int num) {
    double n_est = (-1 + sqrt(1+8*num)) / 2;
    return fmod(n_est, 1) == 0;
}

// Is the given number Square?
bool isSquare(int num) {
    double n_est = sqrt(num);
    return fmod(n_est, 1) == 0;
}

// Is the given number Pentagonal?
bool isPent(int num) {
    double n_est = (1 + sqrt(1+24*num)) / 6;
    return fmod(n_est, 1) == 0;
}

// Is the given number Hexagonal?
bool isHex(int num) {
    double n_est = (1 + sqrt(1+8*num)) / 4;
    return fmod(n_est, 1) == 0;
}

// Is the given number Heptagonal?
bool isHept(int num) {
    double n_est = (3 + sqrt(9+40*num)) / 10;
    return fmod(n_est, 1) == 0;
}

// Is the given number Octagonal?
bool isOct(int num) {
    double n_est = (2 + sqrt(4+12*num)) / 6;
    return fmod(n_est, 1) == 0;
}

// Is the given number any kind of Polygonal?
bool isPoly(int num) {
    return (isTri(num) || isSquare(num) || isPent(num) ||
           isHex(num) || isHept(num) || isOct(num));
}

/**
 * Do the integers in the given vector v each represent a different
 * polygonal type?
 * 
 * This check is mutually exclusive, so an integer which is triangular
 * cannot count as a square integer, and vice versa.
 */
bool isPolygonalThree(int nums[]) {
    // use char rather than int, since a[i] < 3 for all i
    char a[3] = {};
    for (int i = 0; i < 3; i++) {
        if (isPent(nums[i])) a[2]++;
        else if (isSquare(nums[i])) a[1]++;
        else if (isTri(nums[i])) a[0]++;
    }
    
    return (a[0] && a[1] && a[2]);
}

/**
 * Do the integers in the given vector v each represent a different
 * polygonal type?
 * 
 * This check is mutually exclusive, so an integer which is hexagonal
 * cannot count as a triangular integer, and vice versa.
 */

bool isPolygonalSix(int nums[]) {
    // use char rather than int, since a[i] < 6 for all i
    char a[6] = {};
    for (int i = 0; i < 6; i++) {
        if (isOct(nums[i])) a[5]++;
        else if (isHept(nums[i])) a[4]++;
        else if (isHex(nums[i])) a[3]++;
        else if (isPent(nums[i])) a[2]++;
        else if (isSquare(nums[i])) a[1]++;
        else if (isTri(nums[i])) a[0]++;
    }
    
    return (a[0] && a[1] && a[2] && a[3] && a[4] && a[5]);
}

void solveThree() {
    
    // Store our nums in an array
    int nums[3] = {};
    
    // Iterate over all cyclic sets
    for (int a = 10; a < 100; a++) {
        for (int b = 10; b < 100; b++) {
            // Check if this number is polygonal
            int first = 100*a + b
            if (!isPoly(first)) continue;
            for (int c = 10; c < 100; c++) {                
                // Check if this number is polygonal
                if (!isPoly(100*b + c)) continue;
                // Check if this number is polygonal
                if (!isPoly(100*c + a)) continue;
                
                // Store numbers
                nums[0] = 100*a + b;
                nums[1] = 100*b + c;
                nums[2] = 100*c + a;
                
                // Check for mutually exclusive polygonality
                if (isPolygonalThree(nums)) {
                    int sum = 0;
                    for (int i = 0; i < 3; i++) sum += nums[i];
                    cout << nums[0] << "+" << nums[1] << "+" << nums[2]
                    << " = " << sum << endl;
                    
                    /**
                     * We are guaranteed that there is only one
                     * solution, so we can return once we find one.
                     * 
                     * Otherwise, we will find 3 different
                     * orderings of the same solution.
                     * 
                     * e.g. a+b+c, b+c+a, c+a+b.
                     */
                    return;
                }
            }
        }
    }
}

void solveSix() {
    
    // Store our nums in an array
    int nums[6] = {};
    
    // Iterate over all cyclic sets
    for (int a = 10; a < 100; a++) {
        for (int b = 10; b < 100; b++) {
            // Check if this number is polygonal
            if (!isPoly(100*a + b)) continue;
            for (int c = 10; c < 100; c++) {
                // Check if this number is polygonal
                if (!isPoly(100*b + c)) continue;
                for (int d = 10; d < 100; d++) {
                    // Check if this number is polygonal
                    if (!isPoly(100*c + d)) continue;
                    for (int e = 10; e < 100; e++) {
                        // Check if this number is polygonal
                        if (!isPoly(100*d + e)) continue;
                        for (int f = 10; f < 100; f++) {
                            // Check if this number is polygonal
                            if (!isPoly(100*e + f)) continue;
                            // Check if this number is polygonal
                            if (!isPoly(100*f + a)) continue;
                            
                            // Store numbers
                            nums[0] = 100*a + b;
                            nums[1] = 100*b + c;
                            nums[2] = 100*c + d;
                            nums[3] = 100*d + e;
                            nums[4] = 100*e + f;
                            nums[5] = 100*f + a;
                            
                            // Check for mutually exclusive polygonality
                            if (isPolygonalSix(nums)) {
                                int sum = 0;
                                for (int i = 0; i < 6; i++){
                                    sum += nums[i];
                                }
                                cout << nums[0] << "+" << nums[1] << "+"
                                << nums[2] << "+" << nums[3] << "+" <<
                                nums[4] << "+" << nums[5] << " = " <<
                                sum << endl;
                                
                                /**
                                 * We are guaranteed that there is
                                 * only one solution, so we can return
                                 * once we find one.
                                 * 
                                 * Otherwise, we will find 6 different
                                 * orderings of the same solution.
                                 * 
                                 * e.g. a+b+c+d+e+f, b+c+d+e+f+a, etc.
                                 */
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    solveSix();
    return 0;
}
