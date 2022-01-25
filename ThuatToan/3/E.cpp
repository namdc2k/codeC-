#include<bits/stdc++.h>
using namespace std;
#define MAX 20
 
int a[MAX][MAX], x[MAX], load[MAX] = { 0 }, c[MAX];
int n, m, rs = INT_MAX, maxload = 0;
 
void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
}
 
bool check(int v, int k) {
	for (int i = 1; i < k; i++) {
		if (a[i][k] == 1 && x[i] >= v) return false;
		if (a[k][i] == 1 && x[i] <= v) return false;
	}
	return true;
}
 
void process(int k) {
	for (int v = 1; v <= m; v++) {
		if (check(v, k)) {
			x[k] = v;
			load[v] += c[k];
			if (k == n) {
				maxload = 0;
				for (int i = 1; i <= m; i++) {
					maxload = max(maxload, load[i]);
				}
				rs = min(rs, maxload);
			}
			else process(k + 1);
			load[v] -= c[k];
		}
	}
}
 
 
int main() {
	ios_base::sync_with_stdio(false);  cin.tie(0);
	input();
	process(1);
	cout << rs;
	return 0;
}
