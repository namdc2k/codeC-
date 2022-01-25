#include <bits/stdc++.h>
using namespace std;

int main() {
	long n, m, tmp;
	long tmp1;
	long  x = 0, y = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		tmp1 = 1;
		tmp1 = tmp1 << tmp;
		x += tmp1;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		tmp1 = 1;
		tmp1 = tmp1 << tmp;
		y += tmp1;
	}
	x = x & y;
	if (x == y) cout << 1;
	else cout << 0;
}
