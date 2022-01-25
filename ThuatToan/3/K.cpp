#include<bits/stdc++.h>
using namespace std;
unsigned long long  n, m, k;
int t;
unsigned long long mul(unsigned long long a, unsigned long long b) {
	unsigned long long res = 0;
	unsigned long long a1 = a, b1 = b;
	while (a1 > 0) {
		if (a1 % 2)
			res = (res + b1) % m;
		a1 /= 2;
		b1 *= 2;
		b1 %= m;
	}
	return res;
}

unsigned long long pow_(unsigned long long a1, unsigned long long b1) {
	unsigned long long tmp1, tmp2;
	unsigned long long a = a1, b = b1;
	tmp2 = tmp1 = a % m;
	b--;
	while (b > 1) {
		if (b % 2) {
			tmp2 = mul(tmp2, tmp1);
			b--;
		}
		tmp1 = mul(tmp1, tmp1);
		b /= 2;
	}
	return mul(tmp2,tmp1);
}

int main() {
	cin >> t;
	unsigned long long res1 = 1, res2 = 1;
	while (t--) {
		res1 = 1;
		res2 = 1;
		cin >> n >> k >> m;
		for (int i = 1; i <= k; i++) {
			res1 = mul(res1, n + 1 - i);
			res2 = mul(res2, i);
		}
		res2 = pow_(res2, m - 2);
		cout << mul(res1, res2) << endl;
	}
	return 0;
}
