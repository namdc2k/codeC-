#include<iostream>
using namespace std;

long matrixSpiral(int n) {
	// ch? �p d?ng n l� s? l?
	long sum = 0, square = 0;
	for (int i = 3; i <= n; i += 2) {
		square = i * i;
		sum += square + (square - (i - 1)) + (square - 2 * (i - 1)) + (square - 3 * (i - 1));
	}
	return sum + 1;
}

int main() {
	cout << matrixSpiral(1001);
}
