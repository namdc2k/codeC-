#include<iostream>
using namespace std;

int count;
int n;
int tmp;
int a[7];
bool check[10];

void process(int k) {
	for (int i = 1; i < 10; i++) {
		if (!check[i]) {
			check[i] = 1;
		a[k] = i;
		if (k == 6) {
			tmp = a[0] * 100 + a[1] * 10 + a[2] - a[6] * 100 - 62 + a[3] * 1000 + a[4] * 100 + a[5] * 10 + a[2];
			if (tmp == n)
				count++;
		}
		else process(k + 1);
		check[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	count = 0;
	process(0);
	cout << count << endl;
	return 0;
}
