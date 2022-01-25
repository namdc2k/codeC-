#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;

int pythagorean(int n) {

	double sum;
	int a, b;
	int count = 0;

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			sum = 0;
			sum = i + j + abs(sqrt(i * i + j * j));
			if ((sum == n) && i < j) {
				count++;
			}
		}
	}
	return count;
}
int main() {
	//cout<<pythagorean(120);
	int countMax = 0, max = 0;
	int count;
	for (int i = 10; i < 1000; i++)
	{
		count = pythagorean(i);
		if (count > countMax) {
			max = i;
			countMax = count;
		}
	}
	cout << max << endl;
}
