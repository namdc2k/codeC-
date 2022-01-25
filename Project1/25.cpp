#include <iostream>
using namespace std;

int main()
{
    const int digits = 1000;
    const double ten = 10.0;
    int count = 1;
    double fiboA = 1, fiboB = 1, fiboC;
    for (int i = 3; ; i++) {
        fiboC = fiboA + fiboB;
        fiboA = fiboB;
        fiboB = fiboC;
        if (fiboC >= ten) {
            count++;
            fiboA = fiboA / ten;
            fiboB = fiboB / ten;
            fiboC = fiboC / ten;
        }
        if (count >= digits) {
            cout << i << endl;
            break;
        }
    }
}
