#include<bits/stdc++.h>
using namespace std;
const int Max = 10001;
int n,m,k;
int x[Max];
int cnt = 0,d = 0;
void solution(){
 
    cnt++;
    if(cnt == k){
        for(int i = 1; i <= m; i++){
            cout << x[i] << " ";
        }
        exit(0);
    }
}
 
void Try(int i){
    for(int j = x[i - 1] + 1; j <= n - m + i; j++){
        x[i] = j;
        if(i == m) solution();
        else Try(i + 1);
    }
}
 
int main(){
    cin >> n >> m >> k;
    x[0] = 0;
    Try(1);
    if(cnt < k) cout << -1 << endl;
}
