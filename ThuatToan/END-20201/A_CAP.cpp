#include<bits/stdc++.h>
using namespace std;

int main() {
	set<int>a, b, c;
	int n, m, T;
	cin >> T;
	while (T--) {
		a.clear();
		b.clear();
		c.clear();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			a.insert(tmp);
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			int tmp;
			cin >> tmp;
			b.insert(tmp);
		}
		for (auto x : a)
			for (auto y : b)
				if (x == y)
					c.insert(x);

		cout << c.size() << endl;
	}
}
