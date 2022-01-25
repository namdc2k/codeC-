#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
	ll l1, l2, n, ans = 0;
	ll a[1000001];
	ll f[1000001];
	priority_queue<pair<ll, int>> Q;
	cin >> n >> l1 >> l2;
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= l1; i++) {
		f[i] = a[i];
	}
	
	int t = 1;
	for (int i = l1 + 1; i <= n; i++) {
		Q.push(make_pair(f[t], t));
		while (!Q.empty() and  i - Q.top().second>l2) Q.pop();
		if (!Q.empty())
			f[i] = max(a[i],a[i] + Q.top().first);
		ans = max(ans, f[i]);
		t++;
	}
	cout << ans;
}
