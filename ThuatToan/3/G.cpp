#include<bits/stdc++.h>
using namespace std;

#define MAX 50

int n, K, Q;
int d[MAX];
int x[MAX];
int y[MAX];
int load[MAX];
int visited[MAX];
int segments;
int nbRoutes;
int ans;

int checkX(int v, int k) {
	if (v > 0 && visited[v]) return 0;
	if (load[k] + d[v] > Q) return 0;
	return 1;
}
void input() {
	cin >> n >> K >> Q;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	d[0] = 0;
}

void TRY_X(int s, int k) {
	for (int v = 0; v <= n; v++) {
		if (checkX(v, k)) {
			x[s] = v;
			visited[v] = 1; load[k] += d[v]; segments++;
			if (v > 0) TRY_X(v, k);
			else {
				if (k == K) {
					if (segments == n + nbRoutes) ans++;
				}
				else TRY_X(y[k + 1], k + 1);
			}
			segments--; load[k] -= d[v]; visited[v] = 0;
		}
	}
}
int checkY(int v, int k) {
	if (v == 0) return 1;
	if (load[k] + d[v] > Q) return 0;
	return !visited[v];
}

void TRY_Y(int k) {
	for (int v = y[k - 1] + 1; v <= n; v++) {
		if (checkY(v, k)) {
			y[k] = v;
			segments += 1;
			visited[v] = 1; load[k] += d[v];
			if (k < K) {
				TRY_Y(k + 1);
			}
			else {
				nbRoutes = segments;
				TRY_X(y[1], 1);
			}
			load[k] -= d[v]; visited[v] = 0;
			segments -= 1;
		}
	}
}

void solve() {
	for (int v = 1; v <= n; v++) visited[v] = 0;
	y[0] = 0;
	ans = 0;
	TRY_Y(1);
	cout << ans << endl;
}
int main() {
	input();
	solve();
}
