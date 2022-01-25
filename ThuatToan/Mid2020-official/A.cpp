#include<bits/stdc++.h>
using namespace std;

int cnt;
int n;
int tmp;
int a[10];
bool check[10];

void process(int k) {
	for (int i = 0; i < 10; i++) {
		if (!check[i]) {
			if (i == 0 && (k == 0 || k == 1)) continue;
			a[k] = i;
			check[i] = 1;
			if (k == 5) {
				tmp = (a[0] * 100000 + a[1] * 10000 + a[2] * 1000 + a[3] * 100 + a[4] * 10 + a[1])
					+ a[1] * 1000 + a[1] * 100 + a[5] * 10 + a[2];
				if (tmp == n)
					cnt++;
			}
			else process(k + 1);
			check[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	cnt = 0;
	process(0);
	cout << cnt << endl;
	return 0;
}
