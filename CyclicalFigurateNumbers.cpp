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

bool isPolygonalThree(vector<int> v) {
    int a[3] = {};
    for (int num: v) {
        if (isTri(num)) a[0]++;
        else if (isSquare(num)) a[1]++;
        else if (isPent(num)) a[2]++;
    }
    
    return (a[0] == 1 && a[1] == 1 && a[2] == 1);
}

bool isPolygonalSix(vector<int> v) {
    int a[6] = {};
    for (int num: v) {
        if (isOct(num)) a[5]++;
        else if (isHept(num)) a[4]++;
        else if (isHex(num)) a[3]++;
        else if (isPent(num)) a[2]++;
        else if (isSquare(num)) a[1]++;
        else if (isTri(num)) a[0]++;
    }
    
    return (a[0] == 1 && a[1] == 1 && a[2] == 1
         && a[3] == 1 && a[4] == 1 && a[5] == 1);
}

void genCyclicThree() {
    vector<int> v;
    
    for (int a = 10; a < 100; a++) {
        for (int b = 10; b < 100; b++) {
            for (int c = 10; c < 100; c++) {
                v.clear();
                v.push_back(100*a + b);
                v.push_back(100*b + c);
                v.push_back(100*c + a);
                if (isPolygonalThree(v)) {
                    cout << v[0] << " " << v[1] << " " << v[2] << endl;
                }
            }
        }
    }
}

void genCyclicSix() {
    vector<int> v;
    
    for (int a = 10; a < 100; a++) {
        for (int b = 10; b < 100; b++) {
            if (!isPoly(100*a + b)) continue;
            for (int c = 10; c < 100; c++) {
                if (!isPoly(100*b + c)) continue;
                for (int d = 10; d < 100; d++) {
                    if (!isPoly(100*c + d)) continue;
                    for (int e = 10; e < 100; e++) {
                        if (!isPoly(100*d + e)) continue;
                        for (int f = 10; f < 100; f++) {
                            if (!isPoly(100*e + f)) continue;
                            if (!isPoly(100*f + a)) continue;
                            
                            v.clear();
                            v.push_back(100*a + b);
                            v.push_back(100*b + c);
                            v.push_back(100*c + d);
                            v.push_back(100*d + e);
                            v.push_back(100*e + f);
                            v.push_back(100*f + a);
                            if (isPolygonalSix(v)) {
                                int sum = 0;
                                for (int i: v) sum += i;
                                cout << v[0] << " " << v[1] << " " <<
                                v[2] << " " << v[3] << " " << v[4] <<
                                " " << v[5] << " = " << sum << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    genCyclicSix();
    return 0;
}
