#include <iostream>
using namespace std;

int N, M;

void func() {
	int ret = 0;
	int x = N;
	while (1) {
		ret += x;
		if (x < M) break;
		x /= M;
	}

	cout << ret << '\n';
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