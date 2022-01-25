#include<bits/stdc++.h>
using namespace std;
long long n, m, cnt, c;
long long x[10001], y[20],z[20];
bool check[10001] = {};

void pr() {
	for (int i = 1; i <= n; i++)
		cout << x[i] << " ";
}
void pr2() {
	for (int i = 1; i <= n-c+1; i++)
		cout << x[i] << " ";
	for (int j = 1; j <= c-1; j++)
		cout << z[j] << " ";
}
void process(int k) {
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			x[k] = i;
			check[i] = true;
			if (k == n) {
				cnt++;
				if (cnt == m) {
					pr();
					exit(0);
				}
			}
			else
				process(k + 1);
			check[i] = false;
		}

	}
}
void process2(int k) {
	for (int i = 1; i <= c-1; i++) {
		if (!check[i]) {
			z[k] = y[i];
			check[i] = true;
			if (k == c-1) {
				cnt++;
				if (cnt == m) {
					pr2();
					exit(0);
				}
			}
			else process2(k + 1);
			check[i] = false;
		}
	}
}
int main() {
	cnt = 0;
	cin >> n >> m;
	if (m > 3628800&&m<= 39916800) {
		int h = m / 3628800;
		c = 1;
		m = m - h * 3628800;
		if (h == 11) {
			h = 10;
			m = 3628800-1;
		}
		for (int i = 1; i <= n - 10; i++) {
			x[i] = i;
		}
		for (int i = n - 9; i <= n; i++) {
			y[c++] = i;
		}
		x[n - 10] = y[h];
		y[h] = n - 10;
		sort(y, y + c - 1);
		process2(1);
	}
	else {
		if (m > 362880 && m <= 3628800) {
			int h = m / 362880;
			c = 1;
			m = m - h * 362880;
			if (h == 10) {
				h = 9;
				m = 362880-1;
			}
			for (int i = 1; i <= n - 9; i++) {
				x[i] = i;
			}
			for (int i = n - 8; i <= n; i++) {
				y[c++] = i;
			}
			x[n - 9] = y[h];
			y[h] = n - 9;
			sort(y, y + c - 1);
			process2(1);
		}
		else {
			if (m > 39916800) {
				int h = m / 39916800;
				c = 1;
				m = m - h * 39916800;
				for (int i = 1; i <= n - 11; i++) {
					x[i] = i;
				}
				for (int i = n - 10; i <= n; i++) {
					y[c++] = i;
				}
				x[n - 11] = y[h];
				y[h] = n - 11;
				sort(y, y + c - 1);
				process2(1);
			}
			else {
				process(1);
				cout << -1 << endl;
			}
		}
	}
}


