#include<bits/stdc++.h>
using namespace std;
int np[10002];

int main(){
	int n;string a;
	cin >> n;
	cin >> a;
	for (int i = 1; i <= n; i++){
		np[i] = (a[i - 1]-'0');
	}
	
	int tmp = 0;
	for (int i = n; i > 0; i--){
		if (np[i] == 0) {
			np[i] = 1;
			tmp = i;
			break;
		}
	}
	if (tmp == 0) cout << -1 << endl;
	else{
		if (tmp < n) {
			for (int i = tmp+1; i <= n; i++){
				np[i] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << np[i];
		}
	}	
}
