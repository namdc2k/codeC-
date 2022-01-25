#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>>Adj;
const int Max = 1e5 + 7;
bool mark[Max];
ll n, m;
 
void init() {
	cin >> n >> m;
	memset(mark, true, sizeof mark);
	Adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	
	}
}
void DFS(int u) {
	mark[u] = false;
	for (int v : Adj[u]) {
		if (mark[v]) DFS(v);
	}
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		if (mark[i]) {
			DFS(i);
			ans++;
		}
	}
	cout << ans;
	return 0;
}
