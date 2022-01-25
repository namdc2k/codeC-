#include<bits/stdc++.h>
using namespace std;

const int limit = 2e5;

long long a[limit + 2];
long long maxL[limit + 2];
long long maxR[limit + 2];
int main() {
	long long n, b;
	long long ans = -1, tmp1, tmp2, M = -limit;
	cin >> n >> b;
	for (int i = 1; i < n + 1; i++) {
		cin >> a[i];
	}
	maxR[0] = -limit;
	for (int i = 1; i < n + 1; i++) {
		maxR[i] = max(maxR[i - 1], a[i]);
	}
	maxL[n + 1] = -limit;
	for (int i = n; i > 0; i--) {
		maxL[i] = max(maxL[i + 1], a[i]);
	}
	for (int i = 1; i <= n; i++) {
		tmp1 = maxL[i] - a[i];
		tmp2 = maxR[i] - a[i];
		if (tmp1 >= b && tmp2 >= b) {
			M = tmp1 + tmp2;
			if (M > ans)
				ans = M;
		}

	}
	cout << ans;
	return 0;
}

