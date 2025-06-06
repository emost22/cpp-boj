#include <iostream>
using namespace std;

int N, M, x;

void func() {
	int* a = new int[] { 1, 1, 1, 1, 2, 2 };

	int ret = -1;
	int b = 0;
	int d = 0;
	while (1) {
		for (int i = 0; i < 6; i++) {
			ret += a[i];

			if (i & 1) d += a[i];
			else b += a[i];

			if (x && d >= M) {
				cout << (ret - (d - M)) % N << '\n';
				return;
			}

			if (!x && b >= M) {
				cout << (ret - (b - M)) % N << '\n';
				return;
			}
		}
		a[4]++;
		a[5]++;
	}
}

void input() {
	cin >> N >> M >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}