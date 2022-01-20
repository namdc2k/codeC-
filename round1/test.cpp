#include<bits/stdc++.h>
using namespace std;

unsigned int sumDigits(unsigned int n) {
    unsigned int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
unsigned int reverse(unsigned int n) {
    unsigned int res = 0;
    while (n > 0) {
        res *= 10;
        res += n % 10;
        n /= 10;
    }
    return res;
}

bool isPerpect(int n) {
    int res = 1;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)res += i;
    }
    if (n == res)return true;
    else return false;
}
bool isPrime(int n) {
    int k = sqrt(n);
    if (n % 2 == 0)return false;
    for (int i = 3; i <= k; i += 2) {
        if (n % i == 0)return false;
    }
    return true;
}
void factor(int n) {
    int res = n;
    map<int, int> mp;
    while (n % 2 == 0) {
        mp[2]++;
        n /= 2;
    }
    int k = 3;
    while (n > 1) {
        if (n % k == 0) {
            while (n % k == 0) {
                mp[k]++;
                n /= k;
            }
        }
        k += 2;
    }
    k = 0;
    cout << res << " = ";
    for (auto x : mp) {
        if (k > 0)cout << "* ";
        cout << x.first << ' ';
        if (x.second > 1)cout << "^ " << x.second << ' ';
        k++;
    }

}

int main() {
    cout << "Nhap N: ";
    int n;cin >> n;
    cout << "Tong cac chu so cua N: " << sumDigits(n) << endl;
    cout << "So co cac chu so nguoc N: " << reverse(n) << endl;
    cout << "N co phai so hoan hao khong: " << (isPerpect(n) ? "Co" : "Khong") << endl;
    cout << "N co phai so nguyen to khong: " << (isPrime(n) ? "Co" : "Khong") << endl;
    cout << "Ket qua phan tich thanh phan snt: ";
    factor(n);
}
