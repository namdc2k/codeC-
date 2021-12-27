#include<bits/stdc++.h>
using namespace std;

int binToDe(string s) {
	int res = 0;
	int i = 0;
	while (!s.empty()) {
		if (s.back() == '1') {
			res += (1 << i);
		}
		s.pop_back();
		i++;
	}
	return res;
}

int main() {
	while (1) {
		string s, ib;
		cin >> s;
		if (s == "exit" or s == "done" or s == "quit")break;
		int a = binToDe(s);
		int b;
		cin >> ib;
		cin >> s;
		if (s == ">>" or s == "<<") {
			b = stoi(ib);
			if (s == ">>")
				cout << "a >> b = " << (a >> b) << endl;
			else cout << "a << b = " << (a << b) << endl;
		}
		else {
			b = binToDe(ib);
			if (s == "&")cout << "a & b =" << (a & b) << endl;
			else if (s == "|")cout << "a | b =" << (a | b) << endl;
			else if (s == "^")cout << "a ^ b =" << (a ^ b) << endl;
			else {
				cout << "~b =" << (~b) << endl;
				cout << "~a =" << (~a) << endl;
			}
		}
	}
	return 0;
}
