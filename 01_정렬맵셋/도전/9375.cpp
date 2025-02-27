#include <iostream>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		map<string, int> item;
		string name, cat;

		for (int i = 0; i < n; i++) {
			cin >> name >> cat;
			item[cat]++;
		}

		int ans = 1;

		for (auto iter = item.begin(); iter != item.end(); iter++) {
			ans *= (iter->second + 1);
		}
		ans--;

		cout << ans << "\n";
	}
}