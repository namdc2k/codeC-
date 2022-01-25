#include<bits/stdc++.h>
using namespace std;

int reverse(int n) {
	int reverse = 0;
	while (n != 0) {
		reverse = reverse * 10 + n % 10;
		n /= 10;
	}
	return reverse;
}

int checkBinPalindromic(int n) {
	int a[20], b = 0;
	if (!(n == reverse(n))) return 0;
	while (n >= 1) {
		a[b] = n % 2;
		n /= 2;
		b++;
	}
	for (int i = 0; i < b / 2; i++)
	{
		if (!(a[i] == a[b - 1 - i])) {
			return 0;
			break;
		}
	}
	return 1;
}
int main() {
	int sum = 0;
	for (int i = 1; i < 1000000; i++) {
		if (checkBinPalindromic(i))
			sum += i;
	}
	cout << sum;
}
