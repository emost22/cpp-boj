#include <iostream>
#include <algorithm>
using namespace std;

int list[1 << 21];
int N, ans;

void func() {
	for (int i = N; i > 0; i--) {
		for (int j = (1 << i); j < (1 << (i + 1)); j += 2) {
			ans += abs(list[j] - list[j + 1]);

			list[j / 2] += max(list[j], list[j + 1]);
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 2; i < (1 << N + 1); i++) {
		cin >> list[i];
		ans += list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}