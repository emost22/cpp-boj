#include <iostream>
using namespace std;

int N;

void func() {
	int ret = 0;
	for (int i = 3; i <= N - 6; i += 3) {
		for (int j = 3; i + j <= N - 3; j += 3) {
			if ((N - i - j) % 3) continue;
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