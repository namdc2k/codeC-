#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int f[1000001] = { 0 };

int main() {
	int n, ans = 0, dau = 0;
	int res=0, tmp=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		if (a[i] == 0) continue;
		res = 1;
		tmp = a[i];
		if (a[i] > 0) {
			dau = 1;
		}
		else dau = 0;
		for (int j = i + 1; j <= n; j++) {
			if (a[j] == 0) continue;
			if (dau == 1) {
				if (a[j] < 0 && a[j] * (-1)>tmp) {
					res++;
					tmp = -1 * a[j];
					dau = 0;
				}
			}
			if (dau == 0) {
				if (a[j] > 0 && a[j] > tmp) {
					res++;
					tmp = a[j];
					dau = 1;
				}
			}
		}
		f[i] = res;
		ans = max(ans, f[i]);
	}
	cout << ans;
}
