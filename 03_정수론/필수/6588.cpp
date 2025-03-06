#include <iostream>
#include <vector>
#include <cmath>  

using namespace std;

void isPrime(int n, vector<bool>& is_prime) {
    is_prime[0] = is_prime[1] = false; 

    for (int i = 2; i <= sqrt(n); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int MAX_N = 1000000;
    vector<bool> is_prime(MAX_N + 1, true);

    isPrime(MAX_N, is_prime);

    int n;
    while (cin >> n && n != 0) {
        bool found = false;

        for (int a = 3; a <= n / 2; a += 2) {
            int b = n - a;
            if (is_prime[a] && is_prime[b]) {
                cout << n << " = " << a << " + " << b << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}