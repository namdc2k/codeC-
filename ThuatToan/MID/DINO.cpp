#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,tmp;
	stack<int> ST1,ST2;
	queue<int> QE;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		ST2.push(tmp);
	}
	for (int i = 0; i < n; i++)
	{
		tmp = ST2.top();
		ST2.pop();
		ST1.push(tmp);
	}
	string data,a;
	cin >> data;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == 'C') {
			tmp = ST1.top();
			ST1.pop();
			QE.push(tmp);
		}
		else {
			tmp = QE.front();
			QE.pop();
			ST1.push(tmp);
		}
	}
	for (int i = 0; i < n; i++)
	{
		tmp = ST1.top();
		ST1.pop();
		cout << tmp << " ";
	}
}
