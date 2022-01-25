#include<bits/stdc++.h>
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
typedef struct pair<ll, ll> ii;
typedef struct stack<ll> stll;
const int MOD = 1e9 + 7;
const int MX = 1e5 + 7;
const long double PI = 3.141592653589793238462643383279;
const char nl = '\n';
struct defaut {
	ll cnt = 0;
};
ll n, m, s, t;
ll res[MX];
vector<vector<ii>> a;
void input() {
	cin >> n >> m;
	a.resize(n + 1);
	for (int i = 0; i < m; i++){
		ll u, v, w;
		cin >> u >> v >> w;
		a[u].push_back(ii(v, w));
	}
	for (int i = 1; i <= n; i++){
		res[i] = iMax;
	}
}

void solve(ll tc) {
	input();
	cin >> s >> t;
	res[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> PQ;
	PQ.push(ii(res[s], s));
	while (!PQ.empty()){
		ll u = PQ.top().second;
		PQ.pop();
		for (int i = 0; i < sz(a[u]); i++){
			ll v = a[u][i].first;
			ll w = a[u][i].second;
			if (w + res[u] < res[v]) {
				res[v] = w + res[u];
				PQ.push(ii(res[v], v));
			}
		}
	}
	if (res[t] == iMax) cout << -1 << nl;
	else cout << res[t] << nl;
}

int main() {
	NDC;
	ll tc, i = 0;
	/*cin >> tc;
	for (i = 1; i <= tc; i++)*/
		solve(i); 
	return 0;
}