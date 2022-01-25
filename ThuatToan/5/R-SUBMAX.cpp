#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	int a[n];
	int s[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	s[0] = a[0];
	long long max = a[0];
	for (int i = 1; i < n; i++){
		if (s[i - 1] > 0) s[i] = s[i - 1] + a[i];
		else s[i] = a[i];
		if (max < s[i])
			max = s[i];
	}
	cout << max<< endl;
}
