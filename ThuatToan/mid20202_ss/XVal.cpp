#include<bits/stdc++.h>
using namespace std;
 
int main() {
	string a;
	int n;
	int x = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a;
			if (a[1] == '+') x++;
			else x--;		
	}
	cout << x;
}
