#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string table;
    cin >> table;

    vector<bool> eaten(n, false);
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (table[i] != 'P') {
            continue;
        }

        for (int j = i - k; j <= i + k; ++j) {
            if (0 <= j && j < n && table[j] == 'H' && !eaten[j]) {
                eaten[j] = true;
                cnt++;
                break;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}
