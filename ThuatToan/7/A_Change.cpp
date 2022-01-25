#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int a[7] = { 0,1,5,10,50,100,500 };
	int n;
	cin >> n;
	n = 1000 - n;
	int ans = 0;
	for (int i = 6; i > 0; i--) {
		while (n >= a[i]) {
			n -= a[i];
			ans++;
		}
	}
	cout << ans;
}
