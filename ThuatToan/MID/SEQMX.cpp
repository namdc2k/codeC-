#include<bits/stdc++.h>
using namespace std;

int main() {
	//code chua chinh xac 100%,
	//co the lam 3for O(n3) nhug se chi dc 50d
	int n, k, k2, k3 = 1;
	double sum = 0, tmp, f;
	vector<double> arr1, arr2;
	cin >> n >> k;
	arr1.push_back(0);
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		arr1.push_back(tmp);
		if (i <= k) sum += tmp;
	}
	k2 = k;
	f = sum / k;
	for (unsigned int i = k + 1; i <= n; i++) {
		sum += arr1[i];
		k2++;
		if (sum / k2 > f)
			f = sum / k2;
		while (k2 > k) {
			sum -= arr1[k3++];
			k2--;
			if (sum / k2 > f) {
				f = sum / k2;
				break;
			}
		}
	}
	printf("%.5lf", f);
}
