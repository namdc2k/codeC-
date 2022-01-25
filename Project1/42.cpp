#include<bits/stdc++.h>
using namespace std;

int check(int n) {
	int a;
	n = 2 * n;
	a = (int)sqrt(n);
	a = a * (a + 1);
	if (n == a)
		return 1;
	else return 0;
}
int sumWord(string s) {
	char tmp;
	int sum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		tmp = (char)s[i];
		sum += (int)tmp;
	}
	return sum - 64 * s.size();
}
int main() {
	int count = 0, sum;
	string data, s, tmp;
	fstream f;
	f.open("D://data/words.txt", ios::in);
	getline(f, data);
	f.close();
	data = data + ',' + "end";

	while (1) {
		for (int i = 0; ; i++) {
			if (data[i] == ',') {
				s = data.substr(1, i - 2);
				data = data.substr(i + 1, data.size());
				break;
			}
		}

		sum = sumWord(s);

		if (check(sum))
			count++;
		if (data == "end")
			break;
	}
	cout << count << endl;
}
