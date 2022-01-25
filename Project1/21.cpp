#include<iostream>
using namespace std;

long sumDivisor(int n) {
	//h�m tr? v? t?ng gi� tr? c�c u?c c?a n v� b� hon n
	long sum = 0;
	for (int i = 1; i <= n / 2; i++) {
		if ((n % i) == 0) sum += i;
	}
	return sum;
}
int sumAmicableNumbers(int n) {
	// h�m tr? v? t?ng gi� tr? c?a c�c s? ho�n h?o b� hon n
	long m, sum = 0;
	int* a;
	a = new int[n + 1];
	a[0] = 0;
	//luu t?ng c�c u?c c?a i v�o m?ng v?i i tuong ?ng
	for (int i = 1; i <= n; i++)
		a[i] = sumDivisor(i);
	for (int i = 1; i <= n; i++) {
		m = a[i];
		if (m >= n) continue;
		if (i == a[m])
			if (i != m) sum += i;
	}
	delete[]a;
	return sum;
}

int main() {
	cout << sumAmicableNumbers(10000);
}
