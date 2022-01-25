#include<bits/stdc++.h>
using namespace std;

int isPrimeNumber(int n) {
	if (n < 2)
		return 0;
	int i;
	int squareRoot = sqrt(n);
	for (i = 2; i <= squareRoot; i++)
		if (n % i == 0) return 0;
	return 1;
}

int rotate(int arr[], int size) {
	int tmp, so = 0;
	tmp = arr[0];
	for (int i = 0; i < size - 1; i++)
		arr[i] = arr[i + 1];
	arr[size - 1] = tmp;

	for (int i = 0; i < size; i++)
		so += arr[i] * pow(10, size - i - 1);
	return so;
}

int check(int n) {
	int arr[7], size = 0, tmp, so;
	tmp = n;
	do {
		size++;
		tmp /= 10;
	} while (tmp > 0);
	tmp = n;
	for (int i = 0; i < size; i++)
	{
		arr[i] = (int)(tmp / pow(10, (size - 1 - i)));
		tmp -= arr[i] * pow(10, (size - 1 - i));
	}

	if (isPrimeNumber(n)) {

		for (int i = 0;; i++) {
			so = rotate(arr, size);
			if (!isPrimeNumber(so)) {
				return 0;
				break;
			}
			if (so == n) {
				return 1;
				break;
			}
		}
	}
	else return 0;
}

int main() {
	int count = 0;
	for (int i = 3; i < 1000000; i += 2) {
		if (check(i))
			count++;
	}
	cout << count + 1 << endl;
}

