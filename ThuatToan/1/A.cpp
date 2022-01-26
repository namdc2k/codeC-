#include<bits/stdc++.h>
using namespace std;
 
int main() {
	unsigned long long a, b, c;
	int a1, b1, c1;
	cin >> a >> b;
	a1 = a % 10; b1 = b % 10;
	a /= 10; b /= 10;
	c1 = a1 + b1;
	c = a + b;
	if (c == 0) cout << c1;
	else if (c1 >= 10) {
		c++; c1 %= 10;
		cout << c << c1;
	}
	else {
		cout << c << c1;
	}
	return 0;
}
