#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Employee {
    int D;       
    int H;      
    int lineIdx; 
    int pos;     

    bool operator<(const Employee& other) const {
        if (D != other.D) return D < other.D;   
        if (H != other.H) return H < other.H; 
        return lineIdx > other.lineIdx;       
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<pair<int, int>>> lines(M);

    // ��� ���� �Է� �� �� ��ġ
    for (int i = 0; i < N; i++) {
        int D, H;
        cin >> D >> H;
        lines[i % M].emplace_back(D, H);
    }

    priority_queue<Employee> pq;

    // ù ��° ��� ť�� ����
    for (int i = 0; i < M; i++) {
        if (!lines[i].empty()) {
            pq.push({ lines[i][0].first, lines[i][0].second, i, 0 });
        }
    }

    int cnt = 0;

    while (!pq.empty()) {
        Employee current = pq.top();
        pq.pop();

        // ��ī ���� ���� ����
        if (current.lineIdx == (K % M) && current.pos == (K / M)) {
            cout << cnt << "\n";

            return 0;
        }

        cnt++;

        // ���� ��� ť�� ����
        if (current.pos + 1 < lines[current.lineIdx].size()) {
            pq.push({ lines[current.lineIdx][current.pos + 1].first,
                     lines[current.lineIdx][current.pos + 1].second,
                     current.lineIdx,
                     current.pos + 1 });
        }
    }

    return 0;
}
