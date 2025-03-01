#include <iostream>
#define MAX_N 211
#define MAX_M 561
using namespace std;

char list[MAX_N][MAX_M];
int N, M;

void rightProblem(int x, int y) {
	int n = x + 2;
	int m = y + 7;
	if (list[x + 1][y + 6] == '.') m--;
	for (int i = x; i <= n; i++) {
		for (int j = y; j <= m; j++) {
			if (i == x && j == y) continue;
			if (i == x && j == m) continue;
			if (i == n && j == y) continue;
			if (i == n && j == m) continue;
			if (list[i][j] != '.') continue;
			list[i][j] = '*';
		}
	}
}

void wrongProblem(int x, int y) {
	list[x - 1][y + 2] = '/';
	list[x][y + 1] = '/';
	list[x + 1][y] = '/';
}

bool isNumber(char x) {
	return '0' <= x && x <= '9';
}

int getNumber(int x, int &y) {
	int ret = 0;
	while (1) {
		if (!isNumber(list[x][y])) {
			y++;
			return ret;
		}
		ret = ret * 10 + list[x][y] - '0';
		y++;
	}
	return ret;
}

bool isRightProblem(int x, int y) {
	int a = getNumber(x, y);
	int b = getNumber(x, y);
	int c = getNumber(x, y);
	return a + b == c;
}

void func() {
	for (int i = 1; i < N; i += 3) {
		for (int j = 1; j < M; j += 8) {
			if (isRightProblem(i, j)) {
				rightProblem(i - 1, j - 1);
			}
			else {
				wrongProblem(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << list[i][j];
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M;
	N *= 3;
	M <<= 3;
	for (int i = 0; i < N; i++) {
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