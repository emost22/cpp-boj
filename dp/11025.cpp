#include <iostream>
using namespace std;

int N, K;

void func() {
	int R = 0;
	for (int i = 1; i <= N; i++) {
		R = (R + K) % i;
	}
	cout << R + 1 << '\n';
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