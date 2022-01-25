#include<bits/stdc++.h>
using namespace std;
int arr[10] = { 0,2,3,5,7,11,13,17,0,0 };

long long so(vector<int> a) {
	long long so = 0;
	for (int i = 0; i < a.size(); i++) {
		so *= 10;
		so += a[i];
	}
	return so;
}

int main() {
	vector<int> v;
	vector<int> u;
	long long sum = 0;
	int tmp, c;

	for (int i = 0; i <= 9; i++)
		v.push_back(i);
	do {
		c = 0;
		for (int i = 1; i < 8; i++) {
			for (int j = 0; j < 3; j++)
				u.push_back(v[i + j]);
			tmp = so(u) % arr[i];
			u.clear();
			if (tmp != 0)
				break;
			else c++;
		}
		if (c == 7) {
			sum += so(v);
		}

	} while (next_permutation(v.begin(), v.end()));

	cout << sum << endl;
}
