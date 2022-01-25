#include<iostream>
#include<math.h>

using namespace std;
int isPrimeNumber(int n) {
	if (n < 2)
		return 0;
	int i;
	int squareRoot = sqrt(n);
	for (i = 2; i <= squareRoot; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}
int main() {
	long max, n = 3;
	double ratio, count = 3, soDiagonal = 5;
	while (ratio > 0.1) {
		n += 2;
		max = n * n;
		soDiagonal += 4;
		if (isPrimeNumber(max))
			count++;
		if (isPrimeNumber(max - (n - 1)))
			count++;
		if (isPrimeNumber(max - 2 * (n - 1)))
			count++;
		if (isPrimeNumber(max - 3 * (n - 1)))
			count++;
		ratio = count / soDiagonal;
	}
	cout << n;
}
