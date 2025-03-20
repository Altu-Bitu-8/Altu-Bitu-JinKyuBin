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

        // 힙 크기가 n 초과 -> 가장 작은 값 pop
        if (min_heap.size() > n) {
            min_heap.pop(); 
        }
    }

    cout << min_heap.top() << "\n";

    return 0;
}
