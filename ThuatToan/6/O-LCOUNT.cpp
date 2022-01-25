#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int Max = 1e5 + 7;
vector<vector<ll>>Adj;
ll a[Max];
bool check[Max];
ll n, tmp;
 
void init() {
	Adj.resize(n + 1);
	for (int i = 0; i < n-1; i++) {
		ll u, v;
		cin >> u >> v;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	queue<int> Q;
	set<int> S;
	init();
	Q.push(1);
	while (!Q.empty()){
		tmp = Q.front();
		Q.pop();
		for (auto x: Adj[tmp]){
			if (!check[x]) {
				Q.push(x);
				a[x] = tmp;
				check[x] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		S.insert(a[i]);
	}
	cout << n - S.size();
	return 0;
}
