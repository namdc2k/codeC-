#include<bits/stdc++.h>
using namespace std;
long long n, cnt,tmp;
vector<long long> a;

void process() {
	tmp = a[0];
	for (unsigned int i = 1; i < a.size(); i++)
	{
		if (a[i] > tmp) tmp = a[i];
		else{
			cnt++;
			tmp = a[i];
		}
	}
	cout << cnt;
}

int main() {
	cnt = 1;
	cin >> n;
	while (n--){
		cin >> tmp;
		a.push_back(tmp);
	}
	process();
}
