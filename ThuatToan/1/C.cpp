#include<bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long a, b, c;
	long d = 1000000007;
	int a1, b1, c1;
	cin >> a >> b;
	a %= d;
	b %= d;
	a += b;
	c = a % d;
	cout << c;
}
