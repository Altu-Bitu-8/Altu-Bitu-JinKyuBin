#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
	if (a.length() != b.length())
		return a.length() < b.length();

	int sumA = 0, sumB = 0;
	for (char c : a) if (isdigit(c)) sumA += (c - '0');
	for (char c : b) if (isdigit(c)) sumB += (c - '0');

	if (sumA != sumB) return sumA < sumB;

	return a < b;

}

int main() {
	int n;
	cin >> n;
	vector<string> serials(n);

	for (string& s : serials) {
		cin >> s;
	}

	sort(serials.begin(), serials.end(), cmp);

	for (const string& s : serials) {
		cout << s << endl;
	}

	return 0;
}