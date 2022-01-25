#include<bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
	return a / __gcd(a, b) * b;
}

long smallestMultiple(int n) {
	long long ans = 1;
	for (int i = 2; i <= n; i++) {
		ans = lcm(ans, i);
	}
	return ans;
}

int main() {
	cout << smallestMultiple(20) << endl;
	return 0;
}
