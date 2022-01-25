#include<bits/stdc++.h>
#define iMax INT_MAX
#define iMin INT_MIN
#define ll long long
#define NDC ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef struct vector<ll> vll;
map<ll, ll> MM;

void solve(ll tc) {
	ll n;
	ll ans = iMin;
	cin >> n;
	vll a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	MM.clear();
	for (int i = n-1; i >=0 ; i--){
		MM[a[i]] = MM[a[i] + 1] + 1;
		ans = max(MM[a[i]], ans);
	}
	cout << ans << nl;
}
int main() {
	NDC;
	ll tc;ll i = 0;
	/*cin >> tc;
	for (i = 1; i <= tc; i++)*/
	solve(i); 
	return 0;
}