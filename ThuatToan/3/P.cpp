#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	int t = 1;
	int a[20002];
	cin >> n >> m;
	a[0] = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	t = m;
	while (a[t] == n - m + t) 
			t--;
	a[t]++;
	if (t == 0) cout << -1;
	else {
		for (int i = t + 1; i <= m; i++)
		{
			a[i] = a[t] + i - t;
		}
		for (int i = 1; i <= m; i++)
		{
			cout << a[i] << " ";
		}
	}
}
