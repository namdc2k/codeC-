#include<bits/stdc++.h>
using namespace std;
 
int isPrimeNumber(int n) {
	if (n < 2)
		return 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
 
int main() {
	int n, m;
	int a[2000], b[2000], snt[2000];
	int a1[2000], b1[2000];
	memset(a1, 0, sizeof(a1));
	memset(b1, 0, sizeof(b1));
	cin >> m >> n;
	if (m > n / 2)
		m = n - m;
	unsigned long long res = 1, tmp;
	long long d = 1000000007;
	for (int i = 1; i <= m; i++, n--) {
		a[i] = n;
		b[i] = i;
	}
	int t = 0;
	for (int i = 2; i < 2000; i++) {
		if (isPrimeNumber(i)) {
			snt[t++] = i;
		}
	}
	for (int i = 1; i <= m; i++) {
		tmp = t;
		while (a[i] > 1) {
			while (a[i] % snt[t - tmp] == 0) {
				a1[snt[t - tmp]]++;
				a[i] /= snt[t - tmp];
			}
			tmp--;
		}
	}
	for (int i = 1; i <= m; i++) {
		tmp = t;
		while (b[i] > 1) {
			while (b[i] % snt[t - tmp] == 0) {
				b1[snt[t - tmp]]++;
				b[i] /= snt[t - tmp];
			}
			tmp--;
		}
	}
	for (int i = 2; i < 2000; i++) {
		a1[i] -= b1[i];
		res *= pow(i, a1[i]);
		res %= d;
	}
	cout << res;
}
