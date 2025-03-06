#include <iostream>
#include <stack>

using namespace std;

//������ �켱���� ��ȯ
int priority(char ch) {
    switch (ch) {
    case '(': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
}

//���� ǥ��� -> ���� ǥ���
string postfix(string input) {
    string result = ""; //���� ǥ���
    stack<char> op; //������ �����ϴ� ����

    for (int i = 0; i < input.size(); i++) {
        char ch = input[i];

        switch (ch) {
            //���� ��ȣ: ������ push
        case '(':
            op.push(ch);
            break;

            //�ݴ� ��ȣ: ���� ��ȣ�� ���� ������ pop
        case ')':
            while (!op.empty() && op.top() != '(') {
                result += op.top();
                op.pop();
            }
            op.pop(); // ���� ��ȣ ����
            break;

            //������: ���ÿ� ����ִ� �����ڿ� �켱���� ��
        case '+': case '-': case '*': case '/':
            //���ÿ� ���� �����ں��� �켱������ ���� (= ���� ���Ǿ�� �ϴ�) �����ڰ� �ִ� ��� pop
            while (!op.empty() && priority(op.top()) >= priority(ch)) {
                result += op.top();
                op.pop();
            }
            op.push(ch); //���� ������ push
            break;

            //�ǿ�����: �ٷ� ����� �߰�
        default:
            result += ch;
        }
    }

    //���ÿ� �����ִ� ������ ����� �߰�
    while (!op.empty()) {
        result += op.top();
        op.pop();
    }

    return result;
}

/*
 * [���� ǥ��� -> ���� ǥ���]
 * 1. �ǿ����ڴ� ������ ������ �����Ƿ� �ٷ� ����� �߰��Ѵ�.
 * 2. �����ڴ� �켱������ ���� ������ ���ϹǷ� ���ÿ� ��� �����Ѵ�.
 * 3. ������ top�� �ִ� �����ڴ� �켱������ ���� ���ƾ� �Ѵ�.
 * 4. ������ top�� �ִ� �����ڰ� ���� �����ں��� �켱������ ���ų� ������ ���ÿ��� ���� ������ �Ѵ�.
 * 5. ���� ��ȣ�� ������ ���ÿ� �ִ´�.
 * 6. �ݴ� ��ȣ�� ������ ���� ��ȣ�� ���� ������ ���ÿ� �ִ� �����ڸ� ����� �߰��Ѵ�.
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input; // �Է°� (���� ǥ���)

    //�Է�
    cin >> input;

    //���� & ���
    cout << postfix(input);

    return 0;
}