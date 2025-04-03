#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (sequence[j] < sequence[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_length = *max_element(dp.begin(), dp.end());
    cout << max_length << "\n";

    return 0;
}
