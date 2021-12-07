#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

bool list[MAX][MAX], tmp[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int ans;

bool chkList() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (tmp[i][j]) return false;
		}
	}
	return true;
}

void update(int x, int y) {
	tmp[x][y] = !tmp[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;
		tmp[nx][ny] = !tmp[nx][ny];
	}
}

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			tmp[i][j] = list[i][j];
		}
	}
}

void func() {
	ans = 1e9;
	for (int i = 0; i < (1 << MAX); i++) {
		int cnt = 0;

		init();

		for (int j = 0; j < MAX; j++) {
			if (i & (1 << j)) {
				update(0, j);
				cnt++;
			}
		}

		for (int x = 1; x < MAX; x++) {
			for (int y = 0; y < MAX; y++) {
				if (tmp[x - 1][y]) {
					update(x, y);
					cnt++;
				}
			}
		}

		if (chkList()) ans = min(ans, cnt);
	}

	if (ans == 1e9) cout << "-1\n";
	cout << ans << '\n';
}

void input() {
	char ch;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> ch;
			if (ch == 'O') list[i][j] = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}