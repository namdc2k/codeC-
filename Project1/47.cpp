#include<iostream>
#include<math.h>
using namespace std;

int TSDB(int n) {
	int maxPrime = 0, count = 0, prime;
	while (n % 2 == 0) {
		maxPrime = 2;
		n /= 2;
	}
	if (maxPrime == 2) count++;
	for (int i = 3; i <= sqrt(n); i++) {
		while (n % i == 0) {
			prime = i;
			if (prime > maxPrime) {
				++count;
				maxPrime = prime;
			}
			n /= i;
		}
	}
	if (n > 2)
		count++;
	return count;
}

int main() {
	long first = 0;
	for (int i = 1000; ; i++){
		if (TSDB(i) == 4)
			if (TSDB(i + 1) == 4)
				if (TSDB(i + 2) == 4)
					if (TSDB(i + 3) == 4) {
						first = i;
						break;
					}
	}
	cout << first;
}
