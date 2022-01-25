#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll w, c, n, ans;
ll a[100];
ll b[100];
ll a1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 5;
	for (int i = 1; i <= 15; i++) {
		a1 = 4 * i;
		a[a1] = a[a1 - 4] * 10;
		a[1 + a1] = a[a1 + 1 - 4] * 10;
		a[2 + a1] = a[a1 + 2 - 4] * 10;
		a[3 + a1] = a[a1 + 3 - 4] * 10;
	}
	while (n--) {
		ll f = 1;
		ans = 0;
		memset(b, 0, sizeof(b));
		cin >> w >> c;
		if (w % 1000 != 0 || w < 1000) {
			cout << 0 << endl;
			continue;
		}
		w /= 1000;
		for (int i = 4 * c + 3; i >= 0; i--) {
			if (w >= a[i]) {
				ll k = w / a[i];
				w -= k * a[i];
				b[i] += k;
				ans += k;
			}
			if (w == 0) break;
		}
		for (int i = 0; i <= c; i++) {
			ll c6 = 0;
			ll c4 = 0;
			a1 = 4 * i;
			if (b[a1] > 0 && b[a1 + 3] > 0) c6 = min(b[a1], b[a1 + 3]);
			if (b[a1] > 0 && b[a1 + 2] > 0) c4 = min(b[a1], b[a1 + 2]);
			f *= (c4 + c6 + 1);
		}
		cout << ans << " " << f << endl;
	}
	return 0;
}
