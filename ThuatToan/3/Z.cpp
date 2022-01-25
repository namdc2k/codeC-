#include<bits/stdc++.h>
using namespace std;
 
int W, H;
int n,S=0;
int hmax, wmax;
int itemW[15];
int itemH[15];
int main() {
	cin >> W >> H;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> itemW[i] >> itemH[i];
		S+= itemW[i]* itemH[i];
	}
	if (S > W * H) cout << 0;
	else cout << 1;
}
