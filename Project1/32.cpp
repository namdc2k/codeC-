#include<bits/stdc++.h>
using namespace std;

bool check(int a, int b, int c) {
	int arr[10];
	int n, tmp, count = 0;
	memset(arr, 0, sizeof(arr));
	n = a;
	while (n > 0) {
		count++;
		tmp = n % 10;
		n /= 10;
		arr[tmp] = tmp;
	}
	n = b;
	while (n > 0) {
		count++;
		tmp = n % 10;
		n /= 10;
		arr[tmp] = tmp;
	}
	n = c;
	while (n > 0) {
		count++;
		tmp = n % 10;
		n /= 10;
		arr[tmp] = tmp;
	}
	if (count > 9 || count < 9) return false;
	else
	{
		for (int i = 1; i < 10; i++)
		{
			if (arr[i] == 0) {
				return false;
				break;
			}
		}
		return true;
	}
}
int main() {
	int sum = 0;
	set<int> s;
	for (int i = 1234; i < 5000; i++) {
		for (int j = 2; j < 9; j++)
		{
			if (check(i, j, i * j)) {
				s.insert(i * j);
			}
		}
	}
	for (int i = 123; i <= 999; i++) {
		for (int j = 11; j <= 99; j++)
		{
			if (check(i, j, i * j)) {
				s.insert(i * j);
			}
		}
	}
	for (auto x : s)
		sum += x;
	cout << sum;
}
