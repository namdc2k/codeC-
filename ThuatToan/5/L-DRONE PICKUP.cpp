#include<bits/stdc++.h>
using namespace std;
#define ll long long
int N, K, a[3000 + 1], c[3000 + 1], W[3005][105];
using namespace std;
int main (){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
 
	for(int i = 1; i <= N; i++) cin >> c[i];
	for(int i = 1; i <= N; i++) cin >> a[i];
 
	for(int i = 1; i <= N; i++)
        for(int j = 1; j <= K + 1; j++)
            W[i][j] = INT_MIN;
 
	W[1][1] = c[1];
	for(int i = 1; i <= N; i++){
        for(int j = i + 1; j <= i + a[i]; j++){
            for(int k = 2; k <= K + 1; k++){
                W[j][k] = max(W[j][k], W[i][k - 1] + c[j]);
            }
        }
	}
    if(W[N][K + 1] == INT_MIN) cout << -1 << "\n";
    else cout << W[N][K + 1] << "\n";
}
