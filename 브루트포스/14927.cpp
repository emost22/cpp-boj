#include <iostream>
#include <algorithm>
#define MAX 18
using namespace std;

int list[MAX][MAX], tmp[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N;

bool chkList() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tmp[i][j]) return false;
		}
	}

	return true;
}

void update(int x, int y) {
	tmp[x][y] = 1 - tmp[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		tmp[nx][ny] = 1 - tmp[nx][ny];
	}
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = list[i][j];
		}
	}
}

void func() {
	int ans = 1e9;
	for (int i = 0; i < (1 << N); i++) {
		int cnt = 0;
		init();

		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				update(0, j);
				cnt++;
			}
		}

		for (int x = 1; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (tmp[x - 1][y]) {
					update(x, y);
					cnt++;
				}
			}
		}

		if (chkList()) ans = min(ans, cnt);
	}

	if (ans == 1e9) cout << "-1\n";
	else cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
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