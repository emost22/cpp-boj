#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

ull N;

void func() {
	ull l = 1LL;
	ull r = N;
	ull ret = 0;
	while (l <= r) {
		ull m = (l + r) / 2LL;
		if (m * (m + 1) <= N * 2LL) {
			ret = max(ret, m);
			l = m + 1;
		}
		else {
			r = m - 1;
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

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}