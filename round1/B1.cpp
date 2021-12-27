#include<bits/stdc++.h>
using namespace std;

struct Employee {
	string name, gender, workingYears, level;
};

int main() {
	int n;
	cout << "so luong nhan vien N= ";
	cin >> n;
	cout << endl;
	Employee NV[n], tmp;
	// nhap thong tin nhan vien;
	for (int i = 0; i < n; i++) {
		cin >> tmp.name;
		cin >> tmp.gender;
		cin >> tmp.workingYears;
		cin >> tmp.level;
	}
	//xuat
	cout << "danh sach cac nhan vien" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Name: " << tmp.name << endl;
		cout << "Gender: " << tmp.gender << endl;
		cout << "Working years: " << tmp.workingYears << endl;
		cout << "Level: " << tmp.level << endl;
	}
	return 0;
}
