#include<bits/stdc++.h>
using namespace std;
#define MAX 2e9
long long n, hmin = 0, ans = 0, f = 0;
long long h, hmax = 0;
vector<long long> a;
 
int compare(long long a, long long b) {
	if (a > b) return 1;
	else return 0;
}
 
long long solve(long long c) {
	long long S = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] - c >= 0)
			S += a[i] - c;
		else break;
	}
	return S;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> h;
	long long b, mid;
	for (int i = 0; i < n; i++) {
		cin >> b;
		a.push_back(b);
		hmax = max(hmax, a[i]);
	}
	sort(a.begin(), a.end(), compare);
	while (hmax >= hmin) {
		mid = (hmax + hmin) >> 1;
		f = solve(mid);
		if (f >= h) {
			hmin = mid + 1;
			ans = mid;
		}
		else {
			hmax = mid - 1;
		}
	}
	cout << ans << endl;
}
