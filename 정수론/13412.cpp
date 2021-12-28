#include <iostream>
using namespace std;

int N;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void func() {
	int ans = 0;
	for (int i = 1; i * i <= N; i++) {
		if (N % i) continue;
		int j = N / i;

		if (gcd(i, j) == 1) ans++;
	}

	cout << ans << '\n';
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