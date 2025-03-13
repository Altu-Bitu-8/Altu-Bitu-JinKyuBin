#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//��ū�� ��ȯ
vector<int> getNGE(int n, vector<int>& v) {
	vector<int> answer(n);
	stack<int> s;

	for (int i = 0; i < n; i++) {
		//���� ������ ��(�����ʿ� �ִ� ��)�� �ش� ������ ũ�� �ش簪�� ��ū���� �� �� ����
		while (!s.empty() && v[s.top()] < v[i]) {
			answer[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	//���ÿ� �����ִ� ���ڵ��� ��ū���� �����Ƿ� -1 ����
	while (!s.empty()) {
		answer[s.top()] = -1;
		s.pop();
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//�Է�
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	//����
	vector<int> answer = getNGE(n, v);

	//���
	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}