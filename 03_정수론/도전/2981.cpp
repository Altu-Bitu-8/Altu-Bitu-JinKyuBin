#include <algorithm>  // sort() �̿�
#include <iostream>
#include <vector>

using namespace std;

// �ִ�����(GCD) ��� �Լ�: ��Ŭ���� ȣ���� �̿�
int getGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGCD(b, a % b);
}

// ������ M �˻� �Լ�
vector<int> solution(int n, vector<int>& numbers) {
    vector<int> result;  // ������ M ����

    // 1. �˹��� ���� ������ �ִ�����(�ִ� M) ���
    // ������ �� �˹����� ���̸� ����ϱ� ���� ����
    sort(numbers.begin(), numbers.end());
    int gcd = numbers[1] - numbers[0];
    for (int i = 2; i < n; i++) {
        gcd = getGCD(gcd, numbers[i] - numbers[i - 1]);
    }

    // 2. ������ ��� M ã��: �ִ������� ��� ã��
    for (int i = 2; i <= gcd; i++) {
        if (gcd % i == 0) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    // �Է�
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // ����
    vector<int> result = solution(n, numbers);

    // ���
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}