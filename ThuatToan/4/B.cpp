#include<bits/stdc++.h>
using namespace std;

long long cnt[101] = { 0 };
int n;
string p, p1, p2;
string w[1001];
string fibo(int n) {
	if (!w[n].empty()) return w[n];
	if (n == 0) w[0] = '0';
	else if (n == 1) w[1] = '1';
	else {
		string b = fibo(n - 1) + fibo(n - 2);
		w[n] = b;
	}
	return w[n];
}
int dem(string p, string p1) {
	int demp = 0;
	for (int i = 0; i <= p1.length() - p.length(); i++) {
		string p0 = p1.substr(i, p.length());
		if (p0 == p) demp++;
	}
	return demp;
}
int main() {
	int k2 = 1;
	while (cin >> n){
		cin >> p;
		int t;
		int k = 1;
		string t1, t2, t3, t4, tmp1, tmp2;
		for (int i = 0; ; i++) {
			string tmp = fibo(i);
			if (tmp.length() >= p.length()) {
				p2 = tmp;
				p1 = fibo(i + 1);
				t = i;
				break;
			}
		}
		t1 = p2.substr(0, p.length() - 1);
		t2 = p2.substr(p2.length() - p.length() + 1, p.length() - 1);
		t3 = p1.substr(0, p.length() - 1);
		t4 = p1.substr(p1.length() - p.length() + 1, p.length() - 1);
		tmp1 = t4 + t1;
		tmp2 = t2 + t3;
		cnt[t] = dem(p, p2);
		cnt[++t] = dem(p, p1);
		while (t < n){
			t++;
			int demp = 0;
			if (k & 1) cnt[t] = cnt[t - 1] + cnt[t - 2] + dem(p, tmp1);
			else cnt[t] = cnt[t - 1] + cnt[t - 2] + dem(p, tmp2);
			k++;
		}
		cout << "Case " << k2 << ": " << cnt[n] << endl;
		k2++;
	}
}
