#include <iostream>

using namespace std;

bool IsPrimeIterative(int n) {
	if (n <= 1) return false; // 0 and 1 are not prime numbers
	if (n <= 3) return true;  // 2 and 3 are prime numbers
	// Check for factors from 2 to the square root of n
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false; // Found a factor, not prime
	}
	return true; // No factors found, n is prime
}