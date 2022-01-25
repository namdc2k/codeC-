#include<iostream>
using namespace std;

int main() {
	int ans, x1 = 1, x2 = 1;
	long n;
	cin >> n;
	n -= 2;
	while (n--) {
		ans = x1 % 100 + x2 % 100;
		x1 = x2;
		x2 = ans;
	}
	cout << ans % 10;
}





