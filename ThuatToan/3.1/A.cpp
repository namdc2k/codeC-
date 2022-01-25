#include<bits/stdc++.h>
using namespace std;
int n, m;
int x[31];
string a,b;

void pr20() {
	b.clear();
	for (int i = 1; i <= m; i++) {
		if (x[i]) b += '1';
		else b += '0';
	}
	a += b + '\n';
}
void process(int k) {
	for (int i = 0; i < 2; i++) {
		x[k] = i;
		if (k == m) {
		    pr20();
		}
		else process(k + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin >> n;
	m = n;
	process(1);
	cout << a;
}
