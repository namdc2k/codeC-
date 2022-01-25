#include<bits/stdc++.h>
using namespace std;
int n;
int x[31];
bool check[31] = {};
 
void pr() {
	for (int i = 1; i <= n; i++)
		cout << x[i]<<" ";
	cout << endl;
}
void process(int k) {
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			x[k] = i;
			check[i] = true;
			if (k == n)
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
	cin >> n;
	process(1);
}
