#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
 
struct edge {
	ll u;
	ll v;
	ll w;
};
vector<edge> E;
bool cmp(edge a,edge b) {
	return a.w < b.w;
}
 
struct  Union_Find {
	vector <ll> iParent;
	Union_Find(ll n) {
		iParent = vector <ll >(n);
		for (int i = 0; i < n; ++i) {
			iParent[i] = i;
		}
	}
	ll  Find(ll x) {
		if (iParent[x] == x) return x;
		else {
			iParent[x] = Find(iParent[x]);
			return  iParent[x];
		}
	}
	void Unite(ll x, ll y) {
		iParent[Find(x)] = Find(y);
	}
};
 
 
ll MST(ll n) {
	ll res = 0;
	Union_Find UF(n+1);
	sort(E.begin(), E.end(), cmp);
	for (int i = 0; i < E.size(); i++){
		ll u = E[i].u;
		ll v = E[i].v;
		ll w = E[i].w;
		if (UF.Find(u) != UF.Find(v)) {
			UF.Unite(u, v);
			res += w;
		}
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		edge e;
		cin >> e.u >> e.v >> e.w;
		E.push_back(e);
	}
	cout<< MST(n);
	return 0;
}
