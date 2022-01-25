#include<bits/stdc++.h>
using namespace std;
long n, m, cnt, z,c;
int x[10001];
bool check[10001] = {};
 
void pr() {
	for (int i = 1; i <= n; i++)
		cout << x[i] << " ";
}
void process(int k) {
	for (int i = 0; i <= 1; i++) {
		x[k] = i;
		if (i == 0)
			c++;
		else c = 0;
		if (c == z) continue;
		if (k == n) {
			cnt++;
			if (cnt == m) {
				pr();
				exit(0);
			}
		}
		else
			process(k + 1);
	}
 
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin >> n >> m >> z;
	c = 0;
	x[0] = 0;
	process(1);
	cout << -1 << endl;
}
