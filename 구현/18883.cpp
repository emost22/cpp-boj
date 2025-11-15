#include <iostream>
using namespace std;

int N, M;

void func() {
	int ret = 1;
	for (int i = 0; i < N; i++) {
		cout << ret++;
		for (int j = 1; j < M; j++) {
			cout << ' ' << ret++;
		}
		cout << '\n';
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