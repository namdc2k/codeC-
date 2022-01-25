#include<bits/stdc++.h>
using namespace std;
 
int n, m,ans=INT_MAX,ans1=-1;
int mt[32][32];
int a[32][32];
int x[32];
int dem[12];
int c[12];
vector<vector<int>> bca;
 
void pr() {
	for (int i = 1; i < n; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}
 
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(c, 0, sizeof(c));
	cin >> m >> n;
	bca.resize(n + 2);
	int tmp,tmp2;
	for (int i = 1; i <= m; i++){
		cin >> tmp;
		for (int j = 1; j <= tmp; j++){
			cin >> tmp2;
			bca[tmp2].push_back(i);
			mt[tmp2][i] = 1;
		}
	}
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> tmp >> tmp2;
		a[tmp][tmp2] = 1;
		a[tmp2][tmp] = 1;
	}
 
}
 
int check(int k,int y) {
	for (int i = 1; i < k; i++){
		if (a[k][i] && x[i] == y) {
			return 0;
		}
	}
	return 1;
}
void tinh() {
	memset(dem, 0, sizeof(dem));
	ans1 = 0;
	for (int i = 1; i <= n; i++){
		dem[x[i]]++;
		ans1 = dem[x[i]]> ans1? dem[x[i]]: ans1;
	}
 
	 ans = min(ans, ans1);
}
void process(int k) {
	for (unsigned int i = 0; i < bca[k].size(); i++)
	{
		if (mt[k][bca[k][i]]) {
			if (check(k, bca[k][i])) {
				x[k] = bca[k][i];
				c[x[k]]++;
				if (k == n) {
					tinh();
				}
				else {
					int fmax = 0;
					for (int i = 1; i <= m; i++) fmax = max(c[i], fmax);
					if(fmax<ans) process(k + 1);
				}
				c[x[k]]--;
			}
		}
	}
 
}
int main() {
	input();
	process(1);
	if(ans==INT_MAX) cout << -1 << endl;
	else cout << ans << endl;
}

