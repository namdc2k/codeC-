#include <bits/stdc++.h>
using namespace std;

long penta(int n) {
	return n * (3 * n - 1) / 2;
}

bool isPenta(int n) {
	int exp;
	exp = (int)(1 + sqrt(1 + 24 * n)) / 6;
	if (penta(exp) == n)
		return true;
	else return false;
}

int main() {
	int k = 2;
	bool check = false;
	while (true) {
		for (int j = 1; j < k; j++) {
			if (isPenta(penta(k) + penta(j)) && isPenta(penta(k) - penta(j))) {
				cout << penta(k) - penta(j);
				check = true;
				break;
			}
		}
		if (check) break;
		k++;
	}

	return 0;
}
