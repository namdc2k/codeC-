#include<bits/stdc++.h>
using namespace std;
 
int n, K, a[10][10], x[10],cnt;
bool visited[10];
 
void solution() {
	cnt++;
	for(int i=0; i<n; i++) {
		cout << x[i] <<" ";
	}
	cout <<endl;
}
 
bool check(int i, int k) {
	if(visited[i]) return false;
	for(int j = 0; j < k; j++) {
		if(a[x[j]][i] == 1) return false;
	}
	return true;
}
 
void Try(int k) {
	for(int i = 1; i <= n; i++) {
		if(check(i, k)) {
			x[k] = i;
			visited[i] = true;
			if(k == n - 1) solution();
			else Try(k + 1);
			visited[i] = false;
		}
	}
}
 
main() {
	cin >> n >> K;
	int x, y;
	for(int i = 0; i < K; i++) {
		cin >> x >> y;
		a[y][x] = 1;
	}
	cnt = 0;
	Try(0);
	cout << cnt;
}
