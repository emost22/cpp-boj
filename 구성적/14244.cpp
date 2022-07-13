#include <iostream>
using namespace std;

int N, M;

void func() {
	for (int i = 0; i < N - M; i++) {
		cout << i << ' ' << i + 1 << '\n';
	}

	for (int i = N - M + 1; i < N; i++) {
		cout << N - M << ' ' << i << '\n';
	}
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}