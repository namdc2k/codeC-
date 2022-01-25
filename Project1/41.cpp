#include<bits/stdc++.h>
using namespace std;

int isPrimeNumber(long n) {
	if (n < 2)	return 0;
	int i;
	int squareRoot = sqrt(n);
	for (i = 2; i <= squareRoot; i++)
		if (n % i == 0) return 0;
	return 1;
}
int so(vector<int> a) {
	long so = 0;
	for (int i = 0; i < a.size(); i++) {
		so *= 10;
		so += a[i];
	}
	return so;
}

int main() {
	vector<int> v;
	int arr[8];
	int max = 0, tmp;

	for (int n = 5; n <= 7; n++) {
		for (int i = 1; i <= n; i++)
			v.push_back(i);
		do {
			tmp = so(v);
			if (isPrimeNumber(tmp))
				if (tmp > max)
					max = tmp;
		} while (next_permutation(v.begin(), v.end()));
		v.erase(v.begin(), v.end());
	}
	cout << max << endl;
}
