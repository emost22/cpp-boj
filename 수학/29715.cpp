#include <iostream>
using namespace std;

int N, M, X, Y;

int getP(int n, int m) {
	int ret = 1;
	while (m--) {
		ret *= n--;
	}
	return ret;
}

void func() {
	int a, b;
	int cnt = 0;
	int num = 0;
	while (M--) {
		cin >> a >> b;
		if (a) {
			cnt++;
		}
		else {
			num++;
		}
	}

	int ret = getP(N - cnt, num);
	ret *= getP(9 - cnt - num, N - cnt - num);
	cout << ret * X + (ret - 1) / 3 * Y << '\n';
}

void input() {
	cin >> N >> M >> X >> Y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}