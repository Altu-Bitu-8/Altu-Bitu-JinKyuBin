#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, S = 0;
    cin >> M;

    while (M--) {
        string calc;
        int x;

        cin >> calc;

        if (calc == "add") {
            cin >> x;
            S |= (1 << x);
        }
        else if (calc == "remove") {
            cin >> x;
            S &= ~(1 << x);
        }
        else if (calc == "check") {
            cin >> x;
            if (S & (1 << x)) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }

        }
        else if (calc == "toggle") {
            cin >> x;
            S ^= (1 << x);
        }
        else if (calc == "all") {
            S = (1 << 21) - 1;
        }
        else if (calc == "empty") {
            S = 0;
        }
    }

    return 0;
}
