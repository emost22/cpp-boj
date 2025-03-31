#include <iostream>
using namespace std;
typedef long long ll;

int N;

void func() {
	int ret = 0;
	int l = 1;
	int r = 2e9;
	while (l <= r) {
		int m = ((ll)l + (ll)r) >> 1;
		int tmp = m - m / 3 - m / 5 + m / 15;
		if (tmp >= N) {
			ret = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	cout << ret << '\n';
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