#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;
 
int p, n, a;
int count;
int c[31][31] = { 0 };
int hv[11];
bool chuaxet[100];
 
 
void TRY(int k) {
	for (int i = 1; i <= n; i++){
		if (!chuaxet[i]) {
			if(k==1)
			hv[k] = i;
			else {
				if (c[hv[k - 1]][i] == 1)
					hv[k] = i;
				else continue;
			}
			chuaxet[i] = true;
			if (k == p + 1) {
				count++;
			} else (TRY(k + 1));
			chuaxet[i] = false;
		}
	}
}
 
int main() {
	count = 0;
	string data;
	int tmp, tmp2;
 
	getline(cin, data);
	stringstream str(data);
	str >> n;
	str >> p;
 
	getline(cin, data);
	stringstream st(data);
	st >> a;
 
	for (int i = 1; i <= a; i++){
		getline(cin, data);
		stringstream str(data);
		for (int j = 1; j <= a; j++){
			str >> tmp;
			str >> tmp2;
			c[tmp][tmp2] = 1;
			c[tmp2][tmp] = 1;
		}
	}
	TRY(1);
	cout << count / 2;
}
