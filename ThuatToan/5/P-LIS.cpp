#include<bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int>a(n);
	for (int& x : a) cin >> x;
	multiset<int>s;
	for (int x : a) {
		auto it = s.lower_bound(x);
		if (it != s.end()) {
			s.erase(it);
		}
		s.insert(x);
	}
	cout << s.size();
}
