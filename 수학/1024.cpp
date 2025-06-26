#include <iostream>
using namespace std;

int N, L;

void func() {
	for (int i = L; i <= 100; i++) {
		int lx = N - (((i - 1) * i) >> 1);
		if (lx % i) continue;

		int s = lx / i;
		if (s < 0) continue;
		for (int j = s; j < s + i; j++) {
			cout << j << ' ';
		}
		cout << '\n';
		return;
	}

	cout << "-1\n";
}

void input() {
	cin >> N >> L;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}