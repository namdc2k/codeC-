#include<bits/stdc++.h>
using namespace std;

long long mul(int n) {
	int a = n;
	long long b = 1;
	string tmp1, tmp2;
	string x = to_string(a);
	a = n;
	tmp1 = x;
	for (int i = 0; i < n; i++) {
		b *= n;
		tmp1 = to_string(b);
		if (tmp1.size() > 10) {
			tmp1 = tmp1.substr(tmp1.length() - 10, tmp1.length());
			b = stoll(tmp1);
		}
	}
	return b;
}

int main() {
	long long a = 405071317;
	long long b, sum;
	string tmp;

	for (int i = 11; i <= 999; i++){
		if (i % 10 == 0)
			continue;
		if (i == 11) {
			b = mul(11);
			sum = a + b;
			tmp = to_string(sum);
			if (tmp.size() > 10)
			tmp = tmp.substr(tmp.length() - 10, tmp.length());
			sum = stoll(tmp);

		}
		else {
			b = mul(i);
			sum = sum + b;
			tmp = to_string(sum);
			if (tmp.size() > 10)
			tmp = tmp.substr(tmp.length() - 10, tmp.length());
			sum = stoll(tmp);
		}
	}
	cout << sum;
}
