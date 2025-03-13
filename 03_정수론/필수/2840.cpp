#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, K;
    cin >> N >> K;

    vector<char> wheel(N, '?');
    vector<bool> used(26, false);  // 알파벳 사용 여부 체크
    int arrow = 0; 

    for (int i = 0; i < K; i++) {
        int cnt;
        char alpha;
        cin >> cnt >> alpha;
        cnt %= N;
        arrow = (arrow - cnt + N) % N;

        // 칸에 이미 다른 알파벳 있는 경우
        if (wheel[arrow] != '?' && wheel[arrow] != alpha) {
            cout << "!\n";

            return 0;
        }

        // 같은 알파벳 중복되는 경우
        if (used[alpha - 'A'] && wheel[arrow] != alpha) {
            cout << "!\n";

            return 0;
        }

        wheel[arrow] = alpha;
        used[alpha - 'A'] = true;
    }

    for (int i = 0; i < N; i++) {
        cout << wheel[(arrow + i) % N];
    }
    cout << '\n';

    return 0;
}
