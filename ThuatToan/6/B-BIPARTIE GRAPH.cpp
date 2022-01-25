#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>>Adj;
const int Max = 1e5 + 7;
ll a[Max];
ll n, m;
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		ll u, v;
		cin >> u >> v;
		if (a[u] == 0 && a[v] == 0) { a[u] = 1; a[v] = 2;}
 
		if (a[u] == 1 && a[v] == 0) { a[v] = 2; }
		if (a[u] == 2 && a[v] == 0) { a[v] = 1; }
 
		if (a[u] == 0 && a[v] == 2) { a[u] = 1; }
		if (a[u] == 0 && a[v] == 1) { a[u] = 2; }
 
		if (a[u] == 1 && a[v] == 1) { ans = 1; break; }
		if (a[u] == 2 && a[v] == 2) { ans = 1; break; }
	}
	if (ans) cout << 0;
	else cout << 1;
	return 0;
}
