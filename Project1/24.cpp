#include<iostream>
using namespace std;
int n;
int count, c;
int hv[20];
bool check[20];

void inHoanVi(int c) {
	count++;
	for (int i = 0; i <= n; i++) {
		if (count == c)
			cout << hv[i];
	}
}

void hoanVi(int k) {

	for (int i = 0; i <= n; i++)
	{
		if (!check[i]) {
			hv[k] = i;
			check[i] = true;
			if (n == k) {
				inHoanVi(1000000);
			}
			else hoanVi(k + 1);
			check[i] = false;
		}
	}
}

int main() {
	n = 9;
	count = 0;
	hoanVi(0);
}
