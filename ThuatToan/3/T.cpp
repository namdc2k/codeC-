#include<bits/stdc++.h>
using namespace std;

int mt[14][14];
bool mark[14];
int n, m, cnt, cp;
int x[14];
bool diag1[24];
bool diag2[24];

void process(int k) {
	for (int i = 1; i <= n; i++) {
		if (mt[k][i] == 0 && x[i] == 0 && !diag1[k+i] && !diag2[k-i+n]) {
			x[i] = 1;
			diag1[k + i] = 1;
			diag2[k - i + n] = 1;
			mark[k] = i;
			if (k == n) {
				cnt++;
			}
			else process(k + 1);
			x[i] = 0;
			mark[k] = 0;
			diag1[k + i] = 0;
			diag2[k - i + n] = 0;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		memset(mt, 0, sizeof(mt));
		memset(diag1, 0, sizeof(diag1));
		memset(diag2, 0, sizeof(diag2));
		memset(mark, 0, sizeof(mark));
		memset(x, 0, sizeof(x));
		cnt = 0;
		if (m > 0) {
			for (int i = 0; i < m; i++) {
				int tmp1, tmp2;
				cin >> tmp1 >> tmp2;
				mt[tmp1][tmp2] = 1;
			}
		}
		process(1);
		cout << cnt << endl;
	}
}
