#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n, k, x, m, tmp, ans = 0, pos = 0, t, mo;
	pair<ll, ll>a, b;
	priority_queue<pair<ll, ll>> Shipper_plus;
	priority_queue<pair<ll, ll>> Shipper_sub;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> x >> m;
		if (x > 0)Shipper_plus.push(make_pair(x, m));

		else Shipper_sub.push(make_pair(abs(x), m));
	}
	Shipper_plus.push(make_pair(0, 0));
	Shipper_sub.push(make_pair(0, 0));

	while (!Shipper_plus.empty()) {
		a = Shipper_plus.top();
		Shipper_plus.pop();
		t = a.second / k;
		mo = a.second % k;
		if (mo > 0) {
			ans += abs(a.first) * (2 * t + 1);
			tmp = k - mo;
			pos = abs(a.first);
			while (tmp > 0) {
				b = Shipper_plus.top();
				Shipper_plus.pop();
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
					Shipper_plus.push(make_pair(b.first, b.second - tmp));
					ans += abs(pos - abs(b.first)) + abs(b.first);
					tmp = 0;
				}
			}
		}
		else	ans += abs(a.first) * 2 * t;
	}
	while (!Shipper_sub.empty()) {
		a = Shipper_sub.top();
		Shipper_sub.pop();
		t = a.second / k;
		mo = a.second % k;
		if (mo > 0) {
			ans += abs(a.first) * (2 * t + 1);
			tmp = k - mo;
			pos = abs(a.first);
			while (tmp > 0) {
				b = Shipper_sub.top();
				Shipper_sub.pop();
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
					Shipper_sub.push(make_pair(b.first, b.second - tmp));
					ans += abs(pos - abs(b.first)) + abs(b.first);
					tmp = 0;
				}
			}
		}
		else	ans += abs(a.first) * 2 * t;
	}
	cout << ans;
}
