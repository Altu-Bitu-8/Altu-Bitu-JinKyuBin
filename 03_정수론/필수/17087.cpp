#include <iostream>
#include <algorithm>

using namespace std;

int getGcdRecur(int a, int b) {
    if (b == 0) {
        return a;
    }

    return getGcdRecur(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S, A, D;
    cin >> N >> S >> A;
    D = abs(S - A);

    for (int i = 1; i < N; i++) {
        cin >> A;
        D = getGcdRecur(D, abs(S - A)); 
    }

    cout << D << "\n";
}
