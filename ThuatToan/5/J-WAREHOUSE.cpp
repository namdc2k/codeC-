#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1001];
ll t[1001];
ll F[1001][1001];
 
int main() {
	ll n, T, D;
	cin >> n >> T >> D;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> t[i];
 
	for (int i = 1; i < n + 1; i++) {
		for (int j = t[i]; j <=T; j++) {
			F[i][j] = a[i];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = T; j >= t[i]; j--)
		{
			for (int z = 1; z < i; z++)
			{
				if (i - z <= D)
					F[i][j] = max(F[i][j], F[z][j - t[i]] + a[i]);
 
			}
		}
	}
	ll res = 0;
	for (int i = 1; i <= n; i++)
	{
		res = max(res, F[i][T]);
	}
	cout << res;
}
