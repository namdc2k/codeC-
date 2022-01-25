#include<iostream>
#include<math.h>
using namespace std;

int divisors(int n) {
	int  c = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			c++;
	}
	return c;
}
int minStart(int n) {
	int start, b, c, d;
	start = 1;
	do
	{
		start++;
		d = 0;
		if (start % 2 == 0) {
			b = divisors(start / 2);
			c = divisors(start + 1);
		}
		else {
			b = divisors(start);
			c = divisors((start + 1) / 2);
		}
		d = b * c;

	} while ((d - 1) < n);
	return start;
}

int main() {
	double start;
	start = minStart(500);
	cout << (long)(start * (start + 1) / 2);
}


