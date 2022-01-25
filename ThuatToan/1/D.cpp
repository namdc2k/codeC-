#include<bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long a, b, tmp1, tmp2;
	const long long c = 1000000007;
	cin >> a >> b;
	tmp2 = tmp1 = a % c;
	b--;
	while (b > 1) {
		if (b % 2) {
			tmp2 *= tmp1;
			tmp2 %= c;
			b--;
		}
		tmp1 *= tmp1;
		tmp1 %= c;
		b /= 2;
	}
	cout << (tmp2 * tmp1) % c;
}
