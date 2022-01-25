#include <bits/stdc++.h>
using namespace std;

int main() {
	string data;
	int T;
	cin >> T;
	getline(cin, data);
	for (int i = 0; i < T; i++){
		getline(cin, data);
		if (data.size() > 10) {
			cout << data[0] << data.size() - 2 << data[data.size() - 1] << endl;
		}
		else cout << data << endl;
	}
}
