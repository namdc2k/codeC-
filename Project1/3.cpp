#include <iostream> 
using namespace std;

int maxPrimeFactors(long long n) {
    int maxPrime = 1;
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }
    int k = 3;
    while (n > 1) {
        while (n % k == 0) {
            maxPrime = k;
            n /= k;
        }
        k += 2;
    }
    return maxPrime;
}

int main() {
    cout << maxPrimeFactors(600851475143);
}
