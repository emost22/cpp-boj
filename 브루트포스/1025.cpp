#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#define MAX 10
using namespace std;

char list[MAX][MAX];
int N, M;

bool isSquare(int x) {
	int s = sqrt(x);
	return s * s == x;
}

bool isOutOfRange(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= M;
}

int getSquare(int x, int y, int dx, int dy) {
	int ret = -1;

	string str = "";
	int nx = x;
	int ny = y;
	while (1) {
		if (isOutOfRange(nx, ny)) break;
		str += list[nx][ny];
		nx += dx;
		ny += dy;

		int n = stoi(str);
		if (isSquare(n)) ret = max(ret, n);
	}

	return ret;
}

void func() {
	int ret = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp = list[i][j] - '0';
			if (isSquare(tmp)) ret = max(ret, tmp);

			for (int x = -N + 1; x < N; x++) {
				for (int y = -M + 1; y < M; y++) {
					if (!x && !y) continue;
					ret = max(ret, getSquare(i, j, x, y));
				}
			}
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
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