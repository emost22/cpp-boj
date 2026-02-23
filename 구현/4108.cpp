#include <iostream>
#define MAX 110
using namespace std;

char list[MAX][MAX];
int direct[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
int N, M;

bool isOutOfBounds(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= M;
}

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j] == '*') continue;

			int cnt = 0;
			for (int d = 0; d < 8; d++) {
				int nx = i + direct[d][0];
				int ny = j + direct[d][1];
				if (isOutOfBounds(nx, ny)) continue;

				cnt += (list[nx][ny] == '*');
			}

			list[i][j] = (cnt + '0');
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
	if (!N) exit(0);

	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}