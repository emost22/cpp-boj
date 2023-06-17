#include <iostream>
using namespace std;

int N;

void func() {
	int ret = 2;
	for (int i = 0; i < N; i++) {
		ret += (ret - 1);
	}

	cout << ret * ret << '\n';
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