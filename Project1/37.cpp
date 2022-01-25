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

int check(int n) {
	int arr[20], size = 0, tmp, so = 0;

	while (tmp < n) {
		tmp = n;
		tmp = n % (int)pow(10, size + 1);
		if (!isPrimeNumber(tmp)) {
			return 0;
			break;
		}
		size++;
	}
	tmp = n;
	for (int i = 0; i < size; i++)
	{
		arr[i] = (int)(tmp / pow(10, (size - 1 - i)));
		tmp -= arr[i] * pow(10, (size - 1 - i));
	}
	for (int i = 0; i < size; i++)
	{
		so *= 10;
		so += arr[i];
		if (!isPrimeNumber(so))
		{
			return 0;
			break;
		}
	}
	return 1;
}
int main() {
	int count = 0, sum = 0;
	clock_t start = clock();
	for (int i = 23;; i += 2)
	{
		if (check(i)) {
			sum += i;
			count++;
		}
		if (count == 11)
			break;
	}
	cout << sum << endl;
}


