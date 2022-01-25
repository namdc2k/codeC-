#include<iostream>

using namespace std;

int oneDigit(int n) {
	if (n == 1|| n == 2|| n == 6) return 3;
	if (n == 3|| n == 7|| n == 8) return 5;
	if (n == 4|| n == 5|| n == 9) return 4;
	return 0;
}

int twoDigitTeen(int n) {
	if (n == 11|| n == 12) return 6;
	if (n == 13|| n == 14) return 8;
	if (n == 15|| n == 16) return 7;
	if (n == 17)           return 9;
	if (n == 18|| n == 19) return 8;
	return 0;

}
int twoDigitMultOF10(int n) {
	if (n == 10)                     return 3;
	if (n == 20|| n == 30)           return 6;
	if (n == 40|| n == 50|| n == 60) return 5;
	if (n == 70)                     return 7;
	if (n == 80|| n == 90)           return 6;
	return 0;
}
int twoDigit(int n) {
	if (n % 10 == 0) return twoDigitMultOF10(n);
	else if (n >= 11 && n <= 19) return twoDigitTeen(n);
	else  return twoDigitMultOF10(n - (n % 10)) + oneDigit(n % 10);
}
int threeDigitAnd1000(int n) {
	if (n == 1000) return 11;
	if (n % 100 == 0 && n<1000) return oneDigit(n / 100) + 7;
	else if (n >= 101 && n <= 999) return oneDigit(n / 100) + 10 + twoDigit(n % 100);
	else return 0;
}

int main() {
	int sum=0;
	for (int i = 1; i < 1001; i++)
	{
		if (i >= 0 && i <= 9)  sum += oneDigit(i);
		if (i >= 10 && i <= 99) sum += twoDigit(i);
		else if (i >= 100 && i <= 1000) sum += threeDigitAnd1000(i);
	}
	cout << sum;
}
