#include <iostream>
using namespace std;

int Min(int x, int y) {
	return x < y ? x : y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int Testcase, N;
	cin >> Testcase;
	while (Testcase--) {
		int cnt2 = 0, cnt5 = 0;
		cin >> N;

		for (int i = 2; i <= N; i*=2) {
			cnt2 += N / i;
		}

		for (int i = 5; i <= N; i *= 5) {
			cnt5 += N / i;
		}

		cout << Min(cnt2, cnt5) << '\n';
	}

	return 0;
}