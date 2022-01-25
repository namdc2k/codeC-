#include<bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main(){
    int n;
    cin >> n;
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = (4*dp[i - 1] - dp[i - 2] + MOD)%MOD;
    }
    cout << dp[n] << "\n";
}
