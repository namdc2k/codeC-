#include <iostream>
using namespace std;

int sumGiaiThua(int n) {
	unsigned int dig[100], first = 0, last = 0, carry, x, sum = 0;
	dig[0] = 1;

	for (int i = 2; i <= n; i++) {
		carry = 0;
		for (x = first; x <= last; x++) {
			carry = dig[x] * i + carry;
			dig[x] = carry % 1000;
			if (x == first && !(carry % 1000))
				first++;
			carry /= 1000;
		}
		if (carry)
			dig[++last] = carry;
	}
	for (x = first; x <= last; x++)
		sum += dig[x] % 10 + (dig[x] / 10) % 10 + (dig[x] / 100);

	return sum;
}
int main() {
	cout << sumGiaiThua(100);
}
