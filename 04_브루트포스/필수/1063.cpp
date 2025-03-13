#include <iostream>
#include <string>

using namespace std;

int rowMove[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int colMove[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
string moves[8] = { "R", "L", "B", "T", "RT", "LT", "RB", "LB" };

int main() {
    string k, s;
    int N;
    cin >> k >> s >> N;

    // 문자를 좌표로 변환
    int kX = k[0] - 'A', kY = k[1] - '1';
    int sX = s[0] - 'A', sY = s[1] - '1';

    while (N--) {
        string move;
        cin >> move;

        int i = 0;
        while (moves[i] != move) i++;

        int newKX = kX + rowMove[i];
        int newKY = kY + colMove[i];

        if (newKX >= 0 && newKX < 8 && newKY >= 0 && newKY < 8) {
            // 돌이 있는 위치라면 돌도 이동
            int newSX = sX, newSY = sY;
            if (newKX == sX && newKY == sY) {
                newSX += rowMove[i];
                newSY += colMove[i];

                // 돌이 체스판을 벗어난 경우
                if (newSX < 0 || newSX >= 8 || newSY < 0 || newSY >= 8) {
                    continue;
                }
            }

            kX = newKX;
            kY = newKY;
            sX = newSX;
            sY = newSY;
        }
    }

    // 좌표를 문자로 변환
    cout << char(kX + 'A') << kY + 1 << "\n";
    cout << char(sX + 'A') << sY + 1 << "\n";

    return 0;
}
