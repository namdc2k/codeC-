#include<bits/stdc++.h>
using namespace std;
 
int n, m, f = INT_MAX, f0 = 0, tmp1, tmp2;
int value[101];
int b[4];
int check[101] = { 0 };
int mark[101][101] = { 0 };
 
void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> tmp1 >> tmp2;
		mark[tmp1][tmp2] = 1;
		mark[tmp2][tmp1] = 1;
	}
}
 
int check2() {
	if (mark[b[1]][b[3]] 
		&& mark[b[1]][b[2]]
		&& mark[b[2]][b[3]]) return 1;
	else return 0;
}
void process(int k) {
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			check[i] = 1;
			b[k] = i;
			f0 += value[i];
			if (k == 3) {
				if (check2())
					f = min(f0, f);
			}
			else {
				if (f0 < f) process(k + 1);
			}
			check[i] = 0;
			f0 -= value[i];
		}
 
	}
}
int main() {
	input();
	process(1);
	if (f == INT_MAX) cout << -1;
	else cout << f;
}
