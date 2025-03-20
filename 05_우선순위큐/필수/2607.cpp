#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isSimilar(const string& word1, const string& word2) {
    int freq1[26] = { 0 }, freq2[26] = { 0 };

    for (char ch : word1) freq1[ch - 'A']++;
    for (char ch : word2) freq2[ch - 'A']++;

    // 1. ���� ������ ���� ���
    bool isSame = true;
    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            isSame = false;
            break;
        }
    }
    if (isSame) return true;

    // 2. ���� �߰�/���� ���� Ȯ��
    int lengthDiff = abs((int)word1.size() - (int)word2.size());
    if (lengthDiff > 1) return false; // ���� ���� 2 �̻��̸� ������ false

    int dSum = 0, dCnt = 0;
    for (int i = 0; i < 26; i++) {
        int d = abs(freq1[i] - freq2[i]);
        dSum += d;
        if (d > 0) dCnt++;
    }

    // 2-1. �� ���� �߰�/����
    if (lengthDiff == 1 && dSum == 1) return true;

    // 2-2. �� ���� ����
    if (lengthDiff == 0 && dSum == 2 && dCnt == 2) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num, sCnt = 0;
    cin >> num;

    string words[100];
    for (int i = 0; i < num; i++) {
        cin >> words[i];
    }

    string firstWord = words[0]; // �Է����� �־��� ù ��° �ܾ�
    for (int i = 1; i < num; i++) {
        if (isSimilar(firstWord, words[i])) {
            sCnt++;
        }
    }

    cout << sCnt << "\n";

    return 0;
}
