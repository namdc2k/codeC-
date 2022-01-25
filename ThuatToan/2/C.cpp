#include<bits/stdc++.h>
using namespace std;
int map1[2005][2005];
vector<pair<int,int>> locate1,locate2;
int T,L,C;
int tmp1, tmp2 ,tmp3 ,tmp4;
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T>0){
		T--;
		cin >> L >> C;
		locate1.clear();
		locate2.clear();
		for (int i = 0; i < 2005; i++) {
			for (int j = 0; j < 2005; j++) {
				map1[i][j] = 0;
			}
		}
		for (int i = 0; i < L; i++)
			for (int j = 0; j < C; j++) {
				cin >> tmp1;
				if (tmp1 == 1)
					locate1.push_back({ i, j });
			}


		for (int i = 0; i < L; i++)
			for (int j = 0; j < C; j++) {
				cin >> tmp2;
				if (tmp2 == 1)
					locate2.push_back({ i, j });
			}
		ans = 0;
		for (auto x : locate1) {
			tmp1 = x.first;
			tmp2 = x.second;
			for (auto y : locate2) {
				tmp3 = y.first;
				tmp4 = y.second;
				map1[tmp1 - tmp3 + 1000][tmp2 - tmp4 + 1000]++;
				ans = max(map1[tmp1 - tmp3 + 1000][tmp2 - tmp4 + 1000], ans);
			}
		}
		cout << ans << endl;
	}
}
