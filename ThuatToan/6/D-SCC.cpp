#include <bits/stdc++.h>
using namespace std;

#define NDC ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define iMax INT_MAX
#define iMin INT_MIN
#define ll long long
#define ld long double
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

typedef struct vector<ll> vll;
typedef struct vector<ld> vld;
typedef struct vector<vll> vvll;
typedef struct vector<vld> vvld;
typedef struct priority_queue<ll> pq;
typedef struct pair<ll, ll> ii;
typedef struct stack<ll> stll;
const int MOD = 1e9 + 7;
const int MX = 1e5 + 7;
const long double PI = 3.141592653589793238462643383279;
const char nl = '\n';
struct home {
	ll cnt = 0;
};

ll n, m, t = 0;
ll num[MX];
ll low[MX];
vvll Adj;
stll scc;
ll cnt = 0;
bool inStack[MX];
void init() {
	cin >> n >> m;
	Adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		Adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++){
		num[i] = -1; inStack[i] = false;
	}
}
void DFS(ll u, ll pu) {
	t++; num[u] = t; low[u] = t;
	scc.push(u); inStack[u] = true;
	for (int i = 0; i < sz(Adj[u]); i++)
	{
		ll v = Adj[u][i];
		if (num[v] > 0) {
			if (inStack[v]) low[u] = min(low[u], num[v]);
		}
		else {
			DFS(v, u); low[u] = min(low[u], low[v]);
		}
	}
	if (num[u] == low[u]) {
		cnt++;
		while (true){
			ll x = scc.top(); scc.pop();
			inStack[x] = 0;
			if (x == u)break;
		}
	}
}
void solve(ll tc) {
	init();
	t = 0; cnt = 0;
	for (int i = 1; i <= n; i++){
		if (num[i] == -1)
			DFS(i, -1);
	}
	cout << cnt << nl;

}

int main() {
	NDC;
	ll tc;ll i = 0;
	/*cin >> tc;
	for (i = 1; i <= tc; i++)*/
		solve(i);
	return 0;
}