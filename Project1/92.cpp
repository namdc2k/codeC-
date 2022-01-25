#include<bits/stdc++.h>
using namespace std;
int arr[568] = { 0 };

int squareChains(int n) {
	int sum, a, tmp;
	a = n;
	do {
		sum = 0;
		do {
			tmp = a % 10;
			sum += tmp * tmp;
			a = a / 10;
		} while (a > 0);
		if (sum == 1 || sum == 89) {
			if (sum == 1) {
				return 1;
				break;
			}
			else {
				return 89;
				break;
			}
		}
		else	a = sum;
		if (arr[sum] == 1 || arr[sum] == 89) {
			if (arr[sum] == 1) {
				return 1;
				break;
			}
			else {
				return 89;
				break;
			}
		}
	} while (1);
}
int squareNumber(int n) {
	int sum, a, tmp;
	a = n;
	sum = 0;
	do
	{
		tmp = a % 10;
		sum += tmp * tmp;
		a = a / 10;
	} while (a > 0);
	return sum;
}
int main() {
	int count = 0;
	int tmp;
	memset(arr, 0, sizeof(arr));
	for (int i = 1; i < 568; i++) {
		tmp = squareChains(i);
		arr[i] = tmp;
	}
	for (int i = 1; i < 10000000; i++) {
		tmp = squareNumber(i);
		if (arr[tmp] == 89)
			count++;
	}
	cout << count;
}
