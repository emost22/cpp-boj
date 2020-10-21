#include <iostream>
using namespace std;

int N, M, ans[5];
char list[501][501];

void func() {
	int sx = 1;
	int y = 1;
	while (N--) {
		for (int T = 0; T < M; T++) {
			for (int x = sx; x < sx + 4; x++) {
				if (list[x][y] == '.') {
					ans[x - sx]++;
					break;
				}
				if (x == sx + 3) ans[4]++;
			}
			y += 5;
		}
		sx += 5;
		y = 1;
	}

	for (int i = 0; i < 5; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < 5 * N + 1; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}