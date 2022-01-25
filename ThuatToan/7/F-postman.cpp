#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<ll, ll>a, b;
priority_queue<pair<ll, ll>> S_plus;
priority_queue<pair<ll, ll>> S_sub;

int main() {
	ll n, k, x, m, tmp, ans = 0, pos = 0, t, mo;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> x >> m;
		if (x > 0)S_plus.push(make_pair(x, m));

		else S_sub.push(make_pair(abs(x), m));
	}
	S_plus.push(make_pair(0, 0));
	S_sub.push(make_pair(0, 0));

	while (!S_plus.empty()) {
		a = S_plus.top();
		S_plus.pop();
		t = a.second / k;
		mo = a.second % k;
		if (mo > 0) {
			ans += abs(a.first) * (2 * t + 1);
			tmp = k - mo;
			pos = abs(a.first);
			while (tmp > 0) {
				b = S_plus.top();
				S_plus.pop();
				if (b.first == 0) {
					ans += abs(pos - abs(b.first));
					break;
				}
				if (tmp > b.second) {
					tmp -= b.second;
					ans += abs(pos - abs(b.first));
					pos = abs(b.first);
				}
				else
				{
					S_plus.push(make_pair(b.first, b.second - tmp));
					ans += abs(pos - abs(b.first)) + abs(b.first);
					tmp = 0;
				}
			}
		}
		else	ans += abs(a.first) * 2 * t;
	}
	while (!S_sub.empty()) {
		a = S_sub.top();
		S_sub.pop();
		t = a.second / k;
		mo = a.second % k;
		if (mo > 0) {
			ans += abs(a.first) * (2 * t + 1);
			tmp = k - mo;
			pos = abs(a.first);
			while (tmp > 0) {
				b = S_sub.top();
				S_sub.pop();
				if (b.first == 0) {
					ans += abs(pos - abs(b.first));
					break;
				}
				if (tmp > b.second) {
					tmp -= b.second;
					ans += abs(pos - abs(b.first));
					pos = abs(b.first);
				}
				else
				{
					S_sub.push(make_pair(b.first, b.second - tmp));
					ans += abs(pos - abs(b.first)) + abs(b.first);
					tmp = 0;
				}
			}
		}
		else ans += abs(a.first) * 2 * t;
	}
	cout << ans;
	return 0;
}
