#include<iostream>
using namespace std;

int sumqSuareDifference(int n){
	int a = 0;
	int b = 0;
	int c;
	for (int i = 1; i <= n; i++){
		a += i;
		b += i * i;
	}
	 c = a * a - b;
	return c;
}

int main() {
	cout << sumqSuareDifference(100);
}
