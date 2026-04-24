#include <iostream>
#define MAX 1010
using namespace std;

const int direct[8][2] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
char list[MAX][MAX], ret[MAX][MAX];

int N;

bool isOutOfRange(int x, int y) {
	return x < 0 || y < 0 || x >= N || y >= N;
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ret[i][j] = '0';
		}
	}
}

void func() {
	init();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (list[i][j] == '.') continue;

			ret[i][j] = '*';
			for (int d = 0; d < 8; d++) {
				int nx = i + direct[d][0];
				int ny = j + direct[d][1];

				if (isOutOfRange(nx, ny)) continue;
				if (ret[nx][ny] == 'M' || list[nx][ny] != '.') continue;

				if (ret[nx][ny] - '0' + list[i][j] - '0' >= 10) ret[nx][ny] = 'M';
				else ret[nx][ny] = ret[nx][ny] += (list[i][j] - '0');
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ret[i][j];
		}
		cout << '\n';
	}
}

void input() {
	cin >> N;
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