#include <iostream>
using namespace std;

int N, k;

void func() {
	int ret = N;
	while (k--) {
		N *= 10;
		ret += N;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> k;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}