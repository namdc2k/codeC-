#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long n, q, count = 1;
	long t, p, c;
	long c1 = 1, c2 = 1, t1, t2;
	long way[100002], way2[100002];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		way[i] = t;
		way2[i] = t;
	}
	t = way[1];
	for (int i = 2; i <= n; i++) {
		if (way[i] != t) {
			count++;
			t = way[i];
		}
	}
	if (n < 60000) {
		cin >> q;
		for (int i = 0; i < q; i++) {
			count = 1;
			cin >> p >> c;
			way[p] = c;
			t = way[1];
			for (int i = 2; i <= n; i++) {
				if (way[i] != t) {
					count++;
					t = way[i];
				}
			}
			cout << count << endl;
		}
	}
	else {
		cin >> q;
		for (int i = 0; i < q; i++) {
			cin >> p >> c;
			if (p == 1) {
				if (way[1] != way[2]) {
					if (c == way[2]) {
						count--;
						way[p] = c;
						cout << count << endl;
						continue;
					}
					else {
						way[p] = c;
						cout << count << endl;
						continue;
					}
				}
				else {
					if (c == way[1]) {
						cout << count << endl;
						continue;
					}
					else {
						count++;
						way[p] = c;
						cout << count << endl;
						continue;
					}
				}
			}
			if (p == n) {
				if (way[p - 1] != way[p]) {
					if (c == way[p - 1]) {
						count--;
						way[p] = c;
						cout << count << endl;
						continue;
					}
					else {
						way[p] = c;
						cout << count << endl;
						continue;
					}
				}
				else {
					if (c == way[p - 1]) {
						cout << count << endl;
						continue;
					}
					else {
						count++;
						way[p] = c;
						cout << count << endl;
						continue;
					}
				}
			}
			if (c == way[p]) {
				cout << count << endl;
				continue;
			}
			c1 = c2 = 1;
			t1 = t2 = way[p - 1];
			way[p] = c;
			for (int j = p; j <= p + 1; j++)
			{
				if (t1 != way[j]) {
					c1++;
					t1 = way[j];
				}
				if (t2 != way2[j]) {
					c2++;
					t2 = way2[j];
				}
			}
			way2[p] = c;
			count = count + c1 - c2;
			cout << count << endl;
		}
	}

	return 0;
}
