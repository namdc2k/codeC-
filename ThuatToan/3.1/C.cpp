#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[31];
bool check[31] = {};
 
void pr() {
	for (int i = 1; i <= m; i++)
		cout << x[i] << " ";
	cout << endl;
}
void process(int k) {
	for (int i = 1; i <= n; i++) {
		if (!check[i]&&x[k-1]<i) {
			x[k] = i;
			check[i] = true;
			if (k == m)
				pr();
			else
				process(k + 1);
			check[i] = false;
		}
 
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin >> n>>m;
	x[0] = 0;
	process(1);
}
