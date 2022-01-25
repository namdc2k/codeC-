#include<bits/stdc++.h>
 
using namespace std;
 
priority_queue<long long> a,d;
 
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push(x);
	}
	int c = 1;
	while (!a.empty()){
		int b = a.top();
		a.pop();
		d.push(b + c);
		c++;
	}
	c = d.top();
	cout << c+1 << endl;
}
