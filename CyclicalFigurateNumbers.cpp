#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/**
 * Returns the nth Hexagonal number.
 * 
 * Note that all Hexagonal numbers must be triangular.
 */
long long hexagon(int n) {
    return (long long)n * ((long long)n*2 - 1);
}

// Is the given number Square?
bool isTri(long long num) {
    double n_est = (-1 + sqrt(1+8*num)) / 2;
    return fmod(n_est, 1) == 0;
}

// Is the given number Square?
bool isSquare(long long num) {
    double n_est = sqrt(num);
    return fmod(n_est, 1) == 0;
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

// Is the given number Heptagonal?
bool isHept(long long num) {
    double n_est = (3 + sqrt(9+40*num)) / 10;
    return fmod(n_est, 1) == 0;
}

// Is the given number Octagonal?
bool isOct(long long num) {
    double n_est = (2 + sqrt(4+12*num)) / 6;
    return fmod(n_est, 1) == 0;
}

bool isPolygonalThree(vector<long long> v) {
    int a[3] = {};
    for (long long num: v) {
        if (isTri(num)) a[0]++;
        else if (isSquare(num)) a[1]++;
        else if (isPent(num)) a[2]++;
    }
    
    return (a[0] == 1 && a[1] == 1 && a[2] == 1);
}

void testTri() {
    for (int i: {1,2,3,5,6,9,10,11,15}) {
        cout << i << ": " << isTri(i) << endl;
    }
}

void testSquare() {
    for (int i: {1,3,4,8,9,15,16,24,25}) {
        cout << i << ": " << isSquare(i) << endl;
    }
}

void testPent() {
    for (int i: {1,4,5,11,12,21,22,34,35}) {
        cout << i << ": " << isPent(i) << endl;
    }
}

void testHex() {
    for (int i: {1,5,6,14,15,27,28,44,45}) {
        cout << i << ": " << isHex(i) << endl;
    }
}

void testHept() {
    for (int i: {1,6,7,17,18,33,34,54,55}) {
        cout << i << ": " << isHept(i) << endl;
    }
}

void testOct() {
    for (int i: {1,7,8,20,21,39,40,64,65}) {
        cout << i << ": " << isOct(i) << endl;
    }
}

int main() {
    vector<long long> v = {8128, 2882, 8281};
    cout << isPolygonalThree(v) << endl;
    return 0;
}
