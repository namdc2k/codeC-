#include<bits/stdc++.h>
using namespace std;

const long long inf = (long long)1e18 + 7;

float Plus(float a, float b) {
	return a + b;
}
float Minus(float a, float b) {
	return a - b;
}
float Multiply(float a, float b) {
	return a * b;
}
float Divide(float a, float b) {
	if (b != 0)return a / b;
	else return inf;
}
float Mod(float a, float b) {
	// mod chi ap dung cho so nguyen
	if ((int)a == a and int(b) == b)
		if (b != 0)return (int)a % (int)b;
	return inf;
}
void print(float a, float b, float (*fun)(float, float)) {
	float result = fun(a, b);

	cout << result << endl;
}

int main() {
	cout << setprecision(7);// in 7 so co nghia sau day phay
	float a, b;
	string s;
	while (1) {
		cin >> s;
		if (s == "e")break;
		a = stof(s);// string to float
		cin >> b;
		cout << "Plus "; print(a, b, &Plus);
		cout << "Minus ";print(a, b, &Minus);
		cout << "Multiply ";print(a, b, &Multiply);
		cout << "Divide ";print(a, b, &Divide);
		cout << "Mod ";print(a, b, &Mod);
	}
	return 0;
}
