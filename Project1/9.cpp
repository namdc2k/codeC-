#include<iostream>
#include<math.h>
using namespace std;

unsigned long pythagorean(int n) {

	double sum;
	long long a, b;

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			sum = 0;
			sum = i + j + fabs(sqrt(i * i + j * j));
			if ((sum == n) && i < j) {
				a = i;b = j;
				break;
			}
		}
	}
	a = a * b * (n - a - b);
	return a;
}
int main() {
	cout << pythagorean(1000);
}


