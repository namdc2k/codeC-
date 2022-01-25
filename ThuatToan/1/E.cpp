#include<bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long ans = 0, tmp;
	int n;
	const long long c = 1000000007;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		ans = (ans + tmp) % c;
	}
	cout << ans;
}

