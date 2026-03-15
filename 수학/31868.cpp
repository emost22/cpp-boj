#include <iostream>
using namespace std;

int N, K;

void func() {
	int ret = K;
	for (int i = 1; i < N; i++) {
		ret >>= 1;
	}

	cout << ret << '\n';
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