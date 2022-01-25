#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c,t1=0,t2 = 0,t3 = 0,t4 = 0;
	int ans1=-1,ans2=-1,c1=0,c2=0;
	int tmp;
	cin >> a >> b >> c;
	if (b > a) swap(a, b);
	int t = 1000;
	while (1) {
		t--;
		if (t == 0) break;
		if (t1 == 0) {
			t1 = a;
			c1++;
		}
		tmp = t1 > b - t2 ? b - t2 : t1;
		t2 += tmp;
		t1 -= tmp;
		c1++;
		
			
		if (t1 == c) {
			ans1 = c1;
			break;
		}
		if (t2 == c) {
			ans1 = c1;
			break;
		}
		if (t2 == b) {
			t2 = 0;
			c1++;
		}
		
	}
	t = 1000;
	while (true){
		t--;
		if (t == 0) break;
		if (t3 == 0) {
			t3 = b;
			c2++;
		}
			
		tmp = t3 > (a - t4) ? (a - t4) : t3;
		t4 += tmp;
		t3 -= tmp;
		c2++;		
		if (t3 == c) {
			ans2 = c2;
			break;
			
		}
		if (t4 == c) {
			ans2 = c2;
			break;
		}
		if (t4 >= a) {
			t4 = 0;
			c2++;
		}
	}
	ans1 = min(ans1, ans2);
	cout << ans1;
}
