#include<bits/stdc++.h>
using namespace std;
int  iMem[10001][10001];
int a[10001];
int b[10001];
 
int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(iMem, 0, sizeof(iMem));
	int n, m,ans=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){	
			if (a[i - 1] == b[j - 1]) iMem[i][j] = iMem[i - 1][j - 1] + 1;
			else{
				iMem[i][j] = max(iMem[i - 1][j], iMem[i][j - 1]);
				ans = max(ans, iMem[i][j]);
			}
		}
	}
	cout << ans;
}
