#include<bits/stdc++.h>
using namespace std;
// bai route kho' nen khong lam` ae thong cam =))

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, T, c, res;
	long long ans = 0;
	int a[1001];
	//so test case
	cin >> T;
	while (T--) {
		ans = 0;
		memset(a, 0, sizeof(a));
		//input
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		//slove
		while (a[2] > 0) {
			c = 1;
			res = 0;
			while (a[2*c-1] > 0) {
				a[c] = a[2*c-1] + a[2*c];
				res = max(res, a[c]);
				c++;
			}
			ans += res;
			for (int i = c; i <= n; i++)
				a[i] = 0;
		}
		// dap an
		cout << ans << endl;
	}
	return 0;
}
