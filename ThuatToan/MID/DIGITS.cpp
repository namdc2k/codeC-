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
			if (i == 0 && (k == 0 || k == 2)) continue;
			a[k] = i;
			check[i] = 1;
			if (k == 6) {
				tmp = (a[0] * 1000 + a[1] * 100 + a[2]*10 +a[3])
					+ a[2] * 10000 + a[4] * 1000 + a[5] * 100 + a[6]*10 + a[3];
				if (tmp == n)
					cnt++;
			}
			else process(k + 1);
			check[i] = 0;
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--){
		cin >> n;
		cnt = 0;
		process(0);
		cout << cnt << endl;
	}
}
