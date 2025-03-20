#include <iostream>
using namespace std;

int N;

void func() {
	int ret = 0;
	for (int i = 1; i <= (N >> 1); i++) {
		for (int j = i; j <= N - i - j; j++) {
			int k = N - i - j;
			if (i + j <= k) continue;
			ret++;
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}