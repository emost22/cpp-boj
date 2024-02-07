#include <iostream>
using namespace std;

int N;

void func() {
	int ret1 = (N * (N + 1)) >> 1;
	int ret2 = ret1 * ret1;
	int ret3 = 0;
	for (int i = 1; i <= N; i++) {
		ret3 += (i * i * i);
	}

	cout << ret1 << '\n' << ret2 << '\n' << ret3 << '\n';
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