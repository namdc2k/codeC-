#include <iostream> 
using namespace std;

void larrgestPalindrome(int n) {
    int Min = 1, Max;
    while (n - 1 > 0) {
        Min *= 10;
        n--;
    }
    int ans = 0;
    Max = Min * 10;
    for (int i = Max; i >= Min; i--) {
        for (int j = Max; j >= Min; j--) {
            int res = i * j;
            int ok = 1;
            string s = to_string(res);
            for (int i = 0; i < s.size() / 2; i++) {
                if (s[i] != s[s.size() - 1 - i]) {
                    ok = 0;
                    break;
                }
            }
            if (ok)ans = max(ans, res);
        }
    }
    cout << ans << endl;
}

int main() {
    larrgestPalindrome(3);
}
