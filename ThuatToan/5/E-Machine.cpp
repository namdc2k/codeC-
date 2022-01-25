#include<bits/stdc++.h>
#define ll long long
#define s first
#define t second
using namespace std;
 
typedef struct pair<ll, ll> ii;
ll MAX[2000001];
ii a[2000001];
ll n, tmp1, tmp2, res = 0;
 
bool cmp(ii a, ii b) {
	if (a.t > b.t) return 0;
	else {
		if (a.t == b.t && a.s > b.s) return 0;
		else return 1;
	}
}
 
bool check(int A, ll x){
	if (a[A].t < x) return true;
	return false;
}
int find_A(int L, int R, ll x)
{
	while (L < R)
	{
		int mid = (L + R + 1) / 2;
		if (check(mid, x) == true) L = mid;
		else R = mid - 1;
	}
	return L;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s >> a[i].t;
	}
	sort(a+1, a+n+1, cmp);
	MAX[0] = 0;
	for (int i = 1; i <= n; i++) MAX[i] = max(MAX[i - 1], a[i].t - a[i].s);
	for (int B = 1; B <= n; B++){
		int pos = find_A(1, B - 1, a[B].s);
 
		if (a[pos].t > a[B].s) pos--;
		if (pos != 0)
			res = max(res, a[B].t - a[B].s + MAX[pos]);
	}
	cout << res;
	return 0;
}
