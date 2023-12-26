#include <iostream>
using namespace std;

int N;

void func() {
	int ret = 1;
	while (ret < N) {
		ret <<= 1;
	}

	int cnt = 0;
	int k = ret;
	while (N) {
		if (N >= k) {
			N -= k;
		}
		else {
			k >>= 1;
			cnt++;
		}
	}

	cout << ret << ' ' << cnt << '\n';
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