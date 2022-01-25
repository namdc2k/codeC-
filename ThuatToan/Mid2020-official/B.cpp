#include<bits/stdc++.h>
using namespace std;
int a[7];

int main() {
	int n, tmp, ans = 0;
	int w;
	cin >> n;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a[tmp]++;
	}

	while (n > 0) {
		w = 6;
		for (int i = 6; i > 0; i--) {
			while (w >= i && a[i] > 0) {
				w -= i;
				a[i]--;
				n--;
			}
		}
		ans++;
	}
	cout << ans << endl;
}
