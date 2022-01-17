#include <iostream>
#include <algorithm>
using namespace std;

int N, K;

void func() {
	int ans = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 60; j++) {
			for (int k = 0; k < 60; k++) {
				int ii = i / 10;
				int jj = j / 10;
				int kk = k / 10;

				if (i % 10 == K || ii == K || j % 10 == K || jj == K || k % 10 == K || kk == K) {
					ans++;
				}
			}
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}