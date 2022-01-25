#include<iostream>
using namespace std;

int isAbundant(int n) {
	int sum = 0;
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0)
			sum += i;
	}
	if (sum > n) return 1;
	else return 0;
}
int main() {

	int arr[28124], count = 0, abundant[7000], n, sum = 0;
	for (int i = 1; i < 28124; i++) {
		arr[i] = 0;
		if (isAbundant(i)) {
			count++;
			abundant[count] = i;
		}
	}
	for (int i = 1; i <= count; i++) {
		for (int j = i; j <= count; j++)
		{
			n = abundant[i] + abundant[j];
			if (n < 28124)
				arr[n] = n;
		}
	}
	for (int i = 1; i < 28124; i++)
	{
		if (arr[i] == 0)
			sum += i;
	}
	cout << sum << endl;

}
