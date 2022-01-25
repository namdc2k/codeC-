#include<iostream>
#include<math.h>

using namespace std;

unsigned long long paths(int n) { 
	long double a = 1;
	//double b = 0;
	for (double i = 1; i <= n; i += 1) {
		a *= (n + i) / i;
	}
	return a;
}

int main() {

	cout << paths(20);
}

