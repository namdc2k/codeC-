#include<iostream>

using namespace std;

int collatz(long long n) {
	int count = 0;
	if (n == 1) {
		count++;
		return count;
	}
	if (n % 2 == 0) {
		count = 1 + collatz(n / 2);
	}
	else {
		count = 2 + collatz((3 * n + 1) / 2);
	}
	return count;
}

int main() {
	int max = 0, start = 0;
	for (int i = 1; i < 1000000; i++) {
		if (collatz(i) > max) {
			max = collatz(i);
			start = i;
		}
	}
	cout << start;
}





