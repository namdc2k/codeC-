/**
 * author:  namdata4920
 * created: 16.01.2022  21:41:57
 *
 * from Hanoi University of Science & Technology
 *
 */
#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0) 
#define iMax INT_MAX
#define iMin INT_MIN
#define ll long long
#define ull unsigned
#define ld long double
#define sz(x) (int)(x).size()
#define pb push_back
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define getV(a,n) for (int i = 0; i < n ; i++) cin>>a[i]
#define vec<x> vector<x>
#define ins insert
#define nl '\n'
#define yes cout << "YES" << nl
#define no cout << "NO" << nl
#define pq priority_queue
typedef struct vector<ll> vll;
typedef struct vector<ld> vld;
typedef struct vector<vll> vvll;
typedef struct vector<vld> vvld;
typedef struct pair<ll, ll> ii;
const int MOD = (int)998244353;
const int MX = (int)2e5 + 5;
const long long INF = 1e18 + 7;
const long double PI = 3.141592653589793238462643383279;

ll M = MOD;
ll BinMul(ll a, ll b) {
	ll res = 0;
	ll a1 = a, b1 = b;
	while (a1 > 0) {
		if (a1 % 2)
			res = (res + b1) % M;
		a1 /= 2;
		b1 *= 2;
		b1 %= M;
	}
	return res;
}
ll BinPow(ll a, ll k) {
	ll ans = 1;
	while (k > 0) {
		if (k & 1)
			ans = BinMul(ans, a);
		a = BinMul(a, a);
		k >>= 1;
	}
	return ans;
}
ll CNK(ll n, ll k) {
	ll res1 = 1, res2 = 1;
	for (int i = 1; i <= k; i++) {
		res1 = BinMul(res1, n + 1 - i);
		res2 = BinMul(res2, i);
	}
	res2 = BinPow(res2, M - 2);
	return  BinMul(res1, res2);
}

ll addMod(ll a, ll b) {
	ll a1 = a % MOD;
	ll b1 = b % MOD;
	return (a1 + b1) % MOD;
}
//lcm
ll lcm(ll a, ll b) {
	return a / __gcd(a, b) * b;
}
//Prime test for large numbers
ll sqrt1(ll n) {
	if (n == 1) return 1;
	ll l = 0, r = min((ll)1e9 + 7, n);
	ll res = 0;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (mid * mid <= n) {
			res = mid;
			l = mid + 1;
		}
		else r = mid;
	}
	return res;
}
bool isPrime(ll k) {
	ll n = sqrt1(k);
	if (k == 2)return true;
	if ((k > 2 and k % 2 == 0) or k == 1) return false;
	for (int i = 3; i <= n; i += 2) {
		if (k % i == 0) return false;
	}
	return true;
}
struct union_find {
	vector<ll> iParent;
	union_find(ll n) {
		iParent = vector<ll>(n);
		for (int i = 0; i < n; ++i)
			iParent[i] = i;
	}
	ll find(ll x) {
		if (iParent[x] == x) return x;
		else {
			iParent[x] = find(iParent[x]);
			return iParent[x];
		}
	}
	void join(ll x, ll y) {
		iParent[find(x)] = find(y);
	}
};

// vector<bool> pr(MX, true);
// void setPr() {
// 	pr[0] = pr[1] = false;
// 	for (int i = 2; i < MX; i++) {
// 		if (pr[i]) {
// 			for (int j = i + i; j < MX; j += i) {
// 				pr[j] = false;
// 			}
// 		}
// 	}
// }

/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                                    code here                                        //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

ll calc(ll x, ll y) {
	return (y - x + 1) * (x + y) / 2;
}
bool cmp(pair<ll, ll>a, pair<ll, ll> b) {
	if (a.first == b.first)return a.second > b.second;
	else return a.first < b.first;
}
void solve(ll testcase) {
	int n;cin >> n;
	vll k(n), h(n);
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	vector<pair<ll, ll>> p;
	for (int i = 0; i < n; i++) {
		int res = k[i] - h[i];
		p.push_back(make_pair(res, k[i]));
	}
	sort(all(p), cmp);
	for (auto x : p)cout << x.first << ' ' << x.second << nl;
	ll ans = 0;
	int pos = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (res < p[i].first) {
			pos = i;
			res = p[i].second;
		}
	}
	cout << ans << nl;
}



int main() {
	fast;
	//cout << setprecision(20)<<fixed;
	//init();
	ll tc = 1;
	ll i = 1;
	cin >> tc;
	for (i = 1; i <= tc; i++)
		solve(i);
	//<3
	return (0 - 0);
}

/////////////////////////////////////////////////////////////////////////////////////////	
//                                                                                     //
//                               Coded by namdata4920                                  //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////
