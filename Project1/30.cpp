#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;

int so(int n) {
	int arr[6], size = 0, tmp, so = 0;
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
	for (int i = 0; i < size; i++)
	{
		so += (int)pow(arr[i], 5);
	}
	if (so == n)
		return 1;
	return 0;
}

int main() {
	int sum = 0;
	for (int i = 2; i < 200000; i++)
	{
		if (so(i)) {
			sum += i;
			cout << i << endl;
		}
	}
	cout << sum;

}
