#include <iostream>
#include<vector>
using namespace std;
#define ll long long

int n;
vector<int> a, b;
void input() {
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
}
void add(vector<int> a, vector<int> b) {
    vector<int> c;
    c.resize(n);
    cout << "mang C: ";
    for (int i = 0; i < n; i++) c[i] = a[i] + b[i], cout << c[i] << ' ';
    cout << endl;
}
void sub(vector<int> a, vector<int> b) {
    vector<int> c;
    c.resize(n);
    cout << "mang C: ";
    for (int i = 0; i < n; i++) c[i] = a[i] - b[i], cout << c[i] << ' ';
    cout << endl;
}

int main() {
    cout << "Nhap n: ";cin >> n;
    while (1) {
        cout << "1: nhap mang A va B " << endl;
        cout << "2: cong mang c = A + B " << endl;
        cout << "3: tru mang c = A - B  " << endl;
        cout << "4: thoat chuong trinh  " << endl;
        cout << "Choose : ";
        int choose;
        cin >> choose;
        switch (choose) {
        case 1:
            input();
            break;
        case 2:
            add(a, b);
            break;
        case 3:
            sub(a, b);
            break;
        case 4: {
            cout << "nhan K hoac k de thoat? ";
            char c;
            cin >> c;
            if (c == 'k' or c == 'K') exit(0);
            else break;
        }
        }
    }
    return(0);
}
