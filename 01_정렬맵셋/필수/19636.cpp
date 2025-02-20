#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int w0, i0, t, d, I, A;
	cin >> w0 >> i0 >> t;
	cin >> d >> I >> A;

	int w1 = w0;
	int i1 = i0;

	for (int i = 0; i < d; i++) {
		w0 += I - (i0 + A);
		if (w0 <= 0) {
			cout << "Danger Diet" << endl;
			break;
		}
	}

	if (w0 > 0) {
		cout << w0 << " " << i0 << endl;
	}

	for (int i = 0; i < d; i++) {
		int e = I - (i1 + A);
		w1 += e;

		if (w1 <= 0) {
			cout << "Danger Diet" << endl;
			return 0;
		}

		if (abs(e) > t) {
			i1 += floor(e / 2.0);
		}


		if (i1 <= 0) {
			cout << "Danger Diet" << endl;
			return 0;
		}
	}

	cout << w1 << " " << i1 << " ";

	cout << (i0 > i1 ? "YOYO" : "NO") << endl;

	return 0;
}
