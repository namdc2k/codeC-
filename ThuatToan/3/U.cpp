#include<bits/stdc++.h>
using namespace std;
int n, k1, k2, d = 0;
 
void nurse(int a[], int x) {
	int i;
	if (x == n) {
		if ((a[x - 1] >= k1 && a[x - 1] <= k2) || a[x - 1] == 0) {
			d = (d + 1) % 1000000007;
		}
	}
	else {
		if (a[x - 1] < k2) {
			a[x] = a[x - 1] + 1;
			nurse(a, x + 1);
		}
		if (a[x - 1] >= k1) {
			a[x] = 0;
			nurse(a, x + 1);
		}
	}
}
 
int main() {
	cin >> n >> k1 >> k2;
	int a[1001];
	a[0] = 1;
	nurse(a, 1);
	a[0] = 0;
	nurse(a, 1);
	cout << d;
}
