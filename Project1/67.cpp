#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	int value = 0;
	int arr[101][101];
	string data, s;
	fstream f;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			arr[i][j] = 0;
		}
	}
	f.open("D://data/input.txt", ios::in);
	for (int i = 1; i <= 100; i++) {
		getline(f, data);
		stringstream s(data);
		for (int j = 1; j <= i; j++)
		{
			s >> value;
			arr[i][j] = value;
		}
	}
	f.close();

	for (int i = 99; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] += max(arr[i + 1][j], arr[i + 1][j + 1]);
		}
	}
	cout << arr[1][1] << endl;
}
