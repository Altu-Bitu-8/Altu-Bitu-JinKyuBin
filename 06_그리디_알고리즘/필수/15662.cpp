#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void rotation(vector<deque<char>>& wheels, vector<int>& rotate_dir, int t, int start, int dir) {
    if (dir == -1) { // 왼쪽
        for (int i = start - 1; i >= 0; --i) {
            if (wheels[i][2] != wheels[i + 1][6]) {
                rotate_dir[i] = -rotate_dir[i + 1];
            }
            else {
                break;
            }
        }
    }
    else { // 오른쪽
        for (int i = start + 1; i < t; ++i) {
            if (wheels[i - 1][2] != wheels[i][6]) {
                rotate_dir[i] = -rotate_dir[i - 1];
            }
            else {
                break;
            }
        }
    }
}

void rotate_wheels(vector<deque<char>>& wheels, const vector<int>& rotate_dir) {
    for (int i = 0; i < wheels.size(); ++i) {
        if (rotate_dir[i] == 1) { // 시계 방향
            char back = wheels[i].back();
            wheels[i].pop_back();
            wheels[i].push_front(back);
        }
        else if (rotate_dir[i] == -1) { // 반시계 방향
            char front = wheels[i].front();
            wheels[i].pop_front();
            wheels[i].push_back(front);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    vector<deque<char>> wheels(t);

    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            wheels[i].push_back(c);
        }
    }

    int k;
    cin >> k;

    while (k--) {
        int num, dir;
        cin >> num >> dir;
        num--; 

        vector<int> rotate_dir(t, 0);
        rotate_dir[num] = dir;

        rotation(wheels, rotate_dir, t, num, -1);
        rotation(wheels, rotate_dir, t, num, 1);

        rotate_wheels(wheels, rotate_dir);
    }

    int result = 0;
    for (int i = 0; i < t; ++i) {
        if (wheels[i][0] == '1') result++;
    }

    cout << result << "\n";

    return 0;
}