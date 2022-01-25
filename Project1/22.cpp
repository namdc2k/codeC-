#include<bits/stdc++.h>
using namespace std;

int sumName(string s) {
	string tmp;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		tmp = s[i];
		sum += s[i] - 'A';
	}
	return sum;
}
int main() {
	vector <string> name;
	int count;
	long long answer = 0;
	string data, s, tmp;
	fstream f;
	f.open("D://data/names.txt", ios::in);
	getline(f, data);
	f.close();
	data = data + ',' + "end";

	for (count = 1; ;count++) {
		for (int i = 0; ; i++) {
			if (data[i] == ',') {
				s = data.substr(1, i - 2);
				data = data.substr(i + 1, data.length());
				break;
			}
		}
		name.push_back(s);
		if (data == "end")
			break;
	}
	sort(name.begin(), name.end());
	for (int i = 0; i < count; i++) {
		tmp = name[i];
		answer += (i + 1) * sumName(tmp);
	}
	cout << answer << endl;
}
