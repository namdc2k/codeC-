#include <bits/stdc++.h>
using namespace std;
int n, W, H, w[1000], h[1000], ans[1000][1000];
 
using namespace std;
int main() {
	cin >> W >> H;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> h[i];
	}
 
	for (int i = 1; i <= W; i++)
		for (int j = 1; j <= H; j++) {
			ans[i][j] = i * j;
			for (int k = 1; k <= n; k++) {
				if (i == w[k] && j == h[k]) ans[i][j] = 0;
			}
			for (int k = 1; k < i; k++) {
				ans[i][j] = min(ans[i][j], ans[k][j] + ans[i - k][j]);
			}
			for (int k = 1; k < j; k++) {
				ans[i][j] = min(ans[i][j], ans[i][k] + ans[i][j - k]);
			}
		}
	cout << ans[W][H];
}
