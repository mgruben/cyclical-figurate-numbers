#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

// Is the given number Square?
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
bool isPolygonalThree(vector<int> v) {
    char a[3] = {};
    for (int num: v) {
        if (isPent(num)) a[2]++;
        else if (isSquare(num)) a[1]++;
        else if (isTri(num)) a[0]++;
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

bool isPolygonalSix(vector<int> v) {
    char a[6] = {};
    for (int num: v) {
        if (isOct(num)) a[5]++;
        else if (isHept(num)) a[4]++;
        else if (isHex(num)) a[3]++;
        else if (isPent(num)) a[2]++;
        else if (isSquare(num)) a[1]++;
        else if (isTri(num)) a[0]++;
    }
    
    return (a[0] && a[1] && a[2] && a[3] && a[4] && a[5]);
}

void solveThree() {
    
    // Use iterable data structure
    vector<int> v;
    
    for (int a = 10; a < 100; a++) {
        for (int b = 10; b < 100; b++) {
            // Check if this number is polygonal
            if (!isPoly(100*a + b)) continue;
            for (int c = 10; c < 100; c++) {                
                // Check if this number is polygonal
                if (!isPoly(100*b + c)) continue;
                // Check if this number is polygonal
                if (!isPoly(100*c + a)) continue;
                
                // Store numbers in iterable data structure
                v.clear();
                v.push_back(100*a + b);
                v.push_back(100*b + c);
                v.push_back(100*c + a);
                
                // Check for mutually exclusive polygonality
                if (isPolygonalThree(v)) {
                    int sum = 0;
                    for (int i: v) sum += i;
                    cout << v[0] << "+" << v[1] << "+" << v[2]
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
    
    // Use iterable data structure
    vector<int> v;
    
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
                            
                            // Store numbers in iterable data structure
                            v.clear();
                            v.push_back(100*a + b);
                            v.push_back(100*b + c);
                            v.push_back(100*c + d);
                            v.push_back(100*d + e);
                            v.push_back(100*e + f);
                            v.push_back(100*f + a);
                            
                            // Check for mutually exclusive polygonality
                            if (isPolygonalSix(v)) {
                                int sum = 0;
                                for (int i: v) sum += i;
                                cout << v[0] << "+" << v[1] << "+" <<
                                v[2] << "+" << v[3] << "+" << v[4] <<
                                "+" << v[5] << " = " << sum << endl;
                                
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
