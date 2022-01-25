#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[305], k = 0, c, b, s = 0;

    a[k] = 1;

    for (int i = 1;i <= 1000;i++) {
        c = 0;
        for (int j = 0;j <= k;j++)
        {
            b = (2 * a[j] + c);
            a[j] = b % 10;
            c = b / 10;
        }
        if (c > 0)
            a[++k] = c % 10;
    }

    for (int i = k;i >= 0;i--)
        s += a[i];

    cout << s << endl;
    return 0;
}
