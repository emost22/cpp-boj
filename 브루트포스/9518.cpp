#include <iostream>
#include <algorithm>
#define MAX 60
using namespace std;

const int direct[8][2] = { {1,0}, {1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
char list[MAX][MAX];
int N, M;

bool isOutOfRange(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= M;
}

void func() {
	int ret = 0;
	int mx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int cnt = 0;
			for (int d = 0; d < 8; d++) {
				int nx = i + direct[d][0];
				int ny = j + direct[d][1];

				if (isOutOfRange(nx, ny)) continue;
				if (list[nx][ny] == '.') continue;

				cnt++;
			}

			if (list[i][j] == '.') mx = max(mx, cnt);
			else ret += cnt;
		}
	}

	cout << (ret >> 1) + mx << '\n';
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