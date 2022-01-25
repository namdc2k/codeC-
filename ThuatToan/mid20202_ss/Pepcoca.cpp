#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	long tmp,pmax=0,pmin=INT_MAX,mid,ans=0;
	long mx, mn;
	vector<long> a;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		a.push_back(tmp);
		pmin = min(tmp, pmin);
		pmax = max(tmp, pmax);
	}
	sort(a.begin(), a.end());
	int q;
	cin >> q;
	while (q--){
		mx = n-1;
		mn = 0;
		cin >> tmp;
		if (tmp < pmin) {
			cout << 0 << endl;
			continue;
		}
		if (tmp > pmax) {
			cout << n << endl;
			continue;
		}
		while (mx>=mn){
			mid = (mx + mn) /2;
			if (tmp >= a[mid]) {
				ans = mid + 1;
				mn = mid + 1;
			}
			else
			{
				mx = mid - 1;
			}
		}
		cout << ans << endl;
	}
}
