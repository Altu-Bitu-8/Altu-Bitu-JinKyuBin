#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int calcPpl(const vector<pi>& score) {
	int len = score.size().cnt = 1, max_rank = score[0].second;

	for (int i = 1; i < len; i++) {
		if (score[i].second < max_rank) {
			cnt++;
			max_rank = score[i].second;
		}
	}

	return cnt;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		vector<pi> score(n);

		for (int i = 0; i < n; i++) {
			cin >> score[i].fist >> score[i].second;
		}

		sort(score.begin(), score.end());

		int ans = calcPpl(score);
		cout << ans << "\n";
	}

	return 0;
}