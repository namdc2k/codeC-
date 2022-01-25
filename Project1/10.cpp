#include<iostream>
#include<math.h>
using namespace std;

int isPrimeNumber(long n) {
	if (n < 2) {
		return 0;
	}
	long squareRoot = abs(sqrt(n));
	for (int i = 2; i <= squareRoot; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	long long sum = 0;
	for (long i = 3; i < 2000000; i += 2) {
		if (isPrimeNumber(i))
			sum += i;
	}
	cout << sum + 2;
	return 0;
}
