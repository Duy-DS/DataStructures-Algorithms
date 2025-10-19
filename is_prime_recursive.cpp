#include <iostream>
using namespace std;

bool isPrimeRecursive(int n, int i = 2) {
    if (n <= 1) return false;
    if (i * i > n ) return true;
    if (n % i == 0) return false;
    return isPrimeRecursive(n, i + 1);
}