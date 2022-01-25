#include<iostream>
#include<math.h>
using namespace std;


int isPrimeNumber(int n) {
	if (n < 2) {
		return 0;
	}
	int i;
	int squareRoot = sqrt(n);
	for (i = 2; i <= squareRoot; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int prime(int n) {
	int a;
	int b = 2;
	if (n == 2)
		a = 1;
	if (n > 2) {
		a = 1;
		do {
			b++;
			if (isPrimeNumber(b) == 1) {
				a++;
			}

		} while (a < n);
	}
	return b;
}
// 10001st prime
int main() {
	cout << prime(10001);
}
