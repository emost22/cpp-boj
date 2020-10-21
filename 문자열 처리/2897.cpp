#include <iostream>
using namespace std;

char list[50][50];
int R, C, ans[5];

void func() {
	for (int i = 0; i < R - 1; i++) {
		for (int j = 0; j < C - 1; j++) {
			if (list[i][j] == '#' || list[i + 1][j] == '#' || list[i][j + 1] == '#' || list[i + 1][j + 1] == '#') continue;

			int cnt = 0;
			for (int x = i; x <= i + 1; x++) {
				for (int y = j; y <= j + 1; y++) {
					if (list[x][y] == 'X') cnt++;
				}
			}
			ans[cnt]++;
		}
	}

	for (int i = 0; i < 5; i++) {
		cout << ans[i] << '\n';
	}
}

void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
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