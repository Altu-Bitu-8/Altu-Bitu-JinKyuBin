#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // 역순으로 계산
    long long speed = v[n - 1];

    for (int i = n - 2; i >= 0; --i) {
        long long vi = v[i];
        // 다음 speed가 vi의 배수 되도록
        long long multi = (speed + vi - 1) / vi;
        speed = multi * vi;
    }

    cout << speed << "\n";

    return 0;
}
