#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll F[501][501];
ll a[501];
const int MOD = 1e9 + 7;
int main() {
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) { if (i % a[1] == 0) F[1][i] = 1; }
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				if (k >= j) continue;
				if ((j - k) % a[i] == 0) { 
					F[i][j] += F[i - 1][k];
					F[i][j] %= MOD;
				}
			}
 
		}
 
	}
	cout << F[n][m];
	return 0;
}
