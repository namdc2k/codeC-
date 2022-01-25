#include<bits/stdc++.h>
using namespace std;
int n, S, cmin = 1000;
int Smax = 1e9;
int c[30][30];
int taxi[13], x[13];
bool cmark[20];

void process(int k) {
	for (int i = 1; i <= n; i++) {
		if (k > 1 && S + ((n - k) * 2+1 )* cmin > Smax) continue;
		if (cmark[i] == false) {
			x[k] = i;
			cmark[i] = true;
			if (k == 1) {
				S = taxi[x[k]];
				S += c[x[0]][x[k]];
			}
			else
			{
				S += taxi[x[k]];
				S += c[x[k-1]+n][x[k]];
			}
			if (n == k) {
				Smax = min(S + c[x[k] + n][x[k+1]], Smax);
			}
			else process(k + 1);
			cmark[i] = false;
			S -= taxi[x[k]];
			S -= c[x[k-1] + n][x[k]];
			
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 2 * n + 1; i++)
		for (int j = 0; j < 2 * n + 1; j++) {
			cin >> c[i][j];
			cmin = min(c[i][j], cmin);
		}

	for (int i = 1; i <= n; i++) {
		taxi[i] = c[i][i + n];
	}
	x[0] = 0;
	x[n + 1] = 0;
	process(1);
	cout << Smax << endl;
	return 0;
}
