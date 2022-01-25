#include<bits/stdc++.h>
using namespace std;
int n, m, S, cmin = INT_MAX;
int Smax = INT_MAX;
int c[30][30];
int people, x[30];
bool cmark[50] = {};

void pr() {
	for (int i = 0; i <= 2 * n; i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;
}
void process(int k) {
	for (int i = 1; i <= 2 * n; i++) {
		if (i <= n) {
			if (people < m) {
				if (cmark[i] == false) {
					x[k] = i;
					cmark[i] = true;
					people++;
					S += c[x[k - 1]][x[k]];
					if (S + (2 * n + 1 - k)* cmin < Smax) process(k + 1);
					
					cmark[i] = false;
					people--;
					S -= c[x[k - 1]][x[k]];
				}
			}
		}
		else{
			if (cmark[i - n]) {
				if (cmark[i] == false) {
					x[k] = i;
					cmark[i] = true;
					people--;
					S += c[x[k - 1]][x[k]];
					if (2 * n == k) {
						Smax = min(S + c[x[k]][x[0]], Smax);
					}
					else if (S + (2 * n + 1 - k)* cmin < Smax) process(k + 1);
					cmark[i] = false;
					people++;
					S -= c[x[k - 1]][x[k]];
				}
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < 2 * n + 1; i++)
		for (int j = 0; j < 2 * n + 1; j++) {
			cin >> c[i][j];
			if (i == j) continue;
			cmin = min(c[i][j], cmin);
		}
	x[0] = 0;
	S = 0;
	people = 0;
	process(1);
	cout << Smax << endl;
	return 0;
}
