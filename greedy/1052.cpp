#include <iostream>
using namespace std;

int N, K;

void func() {
	if (N <= K) {
		cout << "0\n";
		return;
	}

	for (int t = 0; ; t++) {
		int tmp = N;
		int cnt = 0;

		while (tmp) {
			if (tmp & 1) cnt++;
			tmp >>= 1;
		}

		if (cnt <= K) {
			cout << t << '\n';
			return;
		}

		N++;
	}
}

void input() {
	cin >> N >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}