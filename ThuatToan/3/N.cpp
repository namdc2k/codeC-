#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tmax=INT_MAX;
	int n;
	int a[10002];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int tmp, t;
	tmp = a[n];
	a[0] = 0;
	t = n;
	for (int i = n - 1; n >= 0; i--)
	{
		if (a[i] > tmp) {
			tmp = a[i];
			t = i;
		}
		else {
			t--;
			break;
		}
	}

	if (t == 0) cout << -1 << endl;
	else {
		if (t == n - 1)
			swap(a[n], a[n - 1]);
		else {
			for (int i = t+1; i <= n; i++)
			{
				if (a[i] > a[t]) {
					if (a[i] < tmax) {
						tmax = a[i];
						tmp = i;
					}
				}
			}
			//cout << t << endl;
			swap(a[tmp], a[t]);
			for (int i = 0; i <= (n - t - 1) / 2; i++)
			{
				swap(a[t + 1 + i], a[n - i]);
			}

		}
		for (int i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
	}
}
