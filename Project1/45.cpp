#include<bits/stdc++.h>
using namespace std;

int main() {
	long long tri, pen, xHex;
	for (int i = 144; ; i++) {
		xHex = i * (2 * i - 1);
		tri = (sqrt(8 * xHex + 1) - 1) / 2;
		pen = (sqrt(24 * xHex + 1) + 1) / 6;
		if ((tri * (tri + 1) / 2) == (pen * (3 * pen - 1) / 2))
			break;
	}
	cout << xHex;
}
