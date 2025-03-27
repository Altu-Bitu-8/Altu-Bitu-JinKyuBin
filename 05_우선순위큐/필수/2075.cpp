#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    priority_queue<int, vector<int>, greater<int>> min_heap;  

    for (int i = 0; i < n * n; i++) {
        int num;
        cin >> num;

        min_heap.push(num);

        // �� ũ�Ⱑ n �ʰ� -> ���� ���� �� pop
        if (min_heap.size() > n) {
            min_heap.pop(); 
        }
    }

    cout << min_heap.top() << "\n";

    return 0;
}
