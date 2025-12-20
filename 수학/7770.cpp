#include <iostream>
using namespace std;

int N;

void func() {
	int cnt = 0;
	int nx = 1;
	int ret = 0;
	for (int i = 0; ; i += 4) {
		if (cnt + nx + i > N) {
			cout << ret << '\n';
			return;
		}

		nx += i;
		cnt += nx;
		ret++;
	}
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