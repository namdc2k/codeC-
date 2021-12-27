#include<bits/stdc++.h>
using namespace std;

void printReverse(int arr[], int size) {
	int* ptr;
	ptr = &arr[size - 1];
	cout << "arr reverse: ";
	for (int i = 0; i < size; i++) {
		cout << *ptr << ' ';
		ptr--;
	}
	cout << endl;
}
void SumALL(int arr[], int size) {
	int sum = 0;
	int* ptr;
	ptr = &arr[size - 1];
	for (int i = 0; i < size; i++) {
		sum += *ptr;
		ptr--;
	}
	cout << "Sum arr: " << sum << endl;
}
void MinMax(int arr[], int size) {
	int m = INT_MAX;
	int M = INT_MIN;
	int* ptr;
	ptr = &arr[size - 1];
	for (int i = 0; i < size; i++) {
		m = min(m, *ptr);
		M = max(M, *ptr);
		ptr--;
	}
	cout << "Min of arr: " << m << endl;
	cout << "Max of arr: " << M << endl;

}

int main() {
	int size;
	cout << "Size arr: ";
	cin >> size;
	int arr[size];
	cout << "Input arr: ";
	for (int i = 0; i < size; i++)cin >> arr[i];
	printReverse(arr, size);
	SumALL(arr, size);
	MinMax(arr, size);
	return 0;
}
