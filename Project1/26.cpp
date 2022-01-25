#include<bits/stdc++.h>
#include<string>
using namespace std;
#define MAX 1000
unsigned int n, max_n = 0, length, max_length = 0, a, b, appeared[MAX];

int main() {
	for (n = 3; n < MAX; n++) {
		a = 1;
		b = n;
		for (length = 0; ; length++) {
			a *= 10;
			a %= b;
			if (a) {
				if (appeared[a]) {
					length -= appeared[a];
					if (length > max_length) {
						max_n = n;
						max_length = length;
					}
					break;
				}
				appeared[a] = length;
			}
			else break;
		}
		memset(appeared, 0, sizeof(appeared));
	}
	cout << max_n << endl;
	return 0;
}
