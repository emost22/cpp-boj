#include <iostream>
using namespace std;

int a, b, c;

void func() {
	int ans = 0;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k <= c; k++) {
				if (i % j == j % k && j % k == k % i) ans++;
			}
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> a >> b >> c;
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