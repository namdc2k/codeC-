#include<bits/stdc++.h>
using namespace std;

#define MAX 100
int last, sum, first, cmin = INT_MAX;
int n, arr[MAX], c[MAX][MAX];
int best;
int a;
int hv[100];
bool chuaxet[100];

void TRY(int k) {
	for (int i = 2; i < last; i++) {
		if (c[hv[k - 1]][arr[i]] != 0) {
			if (!chuaxet[i]) {
				hv[k] = arr[i];
				chuaxet[i] = true;
				sum += c[hv[k - 1]][arr[i]];
				if (k == last - 1) {
					if (c[hv[k]][arr[last]] != 0)
						if (sum + c[hv[k]][arr[last]] < best)
							best = sum + c[hv[k]][arr[last]];
				}
				else if (sum + (last - k)*cmin < best) TRY(k + 1);
				chuaxet[i] = false;
				sum -= c[hv[k - 1]][arr[i]];
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string data, data1;
	int p;
	int tmp;
	getline(cin, data);
	stringstream str(data);
	str >> n >> p;
	for (int i = 1; i <= n; i++) {
		getline(cin, data);
		stringstream str(data);
		for (int j = 1; j <= n; j++)
		{
			str >> tmp;
			c[i][j] = tmp;
			if (tmp > 0)
				cmin = min(cmin, tmp);
		}
	}

	for (int i = 1; i <= p; i++) {
		best = INT_MAX;
		getline(cin, data1);
		a = 0;
		stringstream str(data1);
		while (str >> tmp) {
			a++;
			arr[a] = tmp;
		}
		memset(chuaxet, 0, sizeof(chuaxet));
		last = a;
		hv[1] = arr[1];
		sum = 0;
		if (last <= 2) {
			if (c[arr[1]][arr[2]] != 0) {
				best = c[arr[1]][arr[2]];
				cout << best << endl;
			}
			else cout << 0 << endl;
		}
		else {
			TRY(2);
			if (best == INT_MAX)
				cout << 0 << endl;
			else cout << best << endl;
		}
	}
}
