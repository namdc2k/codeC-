
#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<long long> VT;
	int n;
	long long tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		VT.push_back(tmp);
	}
	sort(VT.begin(), VT.end());
	for (int i = 0; i < n; i++) {
		cout << VT[i] << " ";
	}
}
