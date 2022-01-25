#include <bits/stdc++.h>

using namespace std;
int main()
{
	set<double>powers;
	clock_t start = clock();
	for (int a = 2; a <= 100; ++a)
		for (int b = 2; b <= 100; ++b)
			powers.insert(pow(a, b));
	cout << powers.size() << endl;
	return 0;
}
