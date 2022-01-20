#include <iostream>
using namespace std;
#define ll long long

int UCLN(int a, int b) {
	if (b == 0) return a;
	return UCLN(b, a % b);
}
ll BCNN(int a, int b) {
	return a / UCLN(a, b) * b;
}

int main() {
	int a, b;
	int tc;
	cout << "so testcase: ";
	cin >> tc;
	while (tc--) {
		// nhap a,b > 0
		while (cin >> a >> b) {
			if (a > 0 and b > 0)break;
		}
		cout << "UCLN: " << UCLN(a, b) << endl;
		cout << "BCNN: " << BCNN(a, b) << endl;
	}
	return(0);
}
