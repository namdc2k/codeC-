#include <iostream>

using namespace std;

int factor(int n) {
	if (n == 0 || n == 1) return 1;
	else return n * factor(n - 1);
}
int facto(int n) {
	int a, b;
	a = 0;
	b = n;
	while (b > 0) {
		a += factor(b % 10);
		b /= 10;
	}
	if (a == n) return 1;
	else return 0;
}

int main() {
	long long sum = 0;
	for (int i = 10; i < 41000; i++){
		if (facto(i)) {
			sum += i;
			cout << i << endl;
		}
	}
	cout << sum;
}
