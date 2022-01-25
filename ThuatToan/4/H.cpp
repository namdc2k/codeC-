#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, l, pos;
	int t1 = 0;
	double lan[1001], lmax = 0,ans=0;
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> lan[i];
		if (lan[i] == 0) t1 = 1;
	}
	lan[0] = 0;
	sort(lan, lan + n + 1);
	for (int i = 1; i <= n; i++) {
		lmax = max(lmax, lan[i] - lan[i - 1]);
	}
	ans = lmax / 2;
	ans = max(ans, l - lan[n]);
	ans = max(ans, lan[1]);
	printf("%.9f", ans);
}
