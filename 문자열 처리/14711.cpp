#include <iostream>
#define MAX 1001
using namespace std;

char list[MAX][MAX], tmp[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N;

void func() {
	for (int i = 0; i < N; i++) {
		if (list[0][i] == '#') {
			tmp[0][i] = tmp[0][i] == '#' ? '.' : '#';
			for (int d = 0; d < 4; d++) {
				int nx = direct[d][0];
				int ny = i + direct[d][1];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				tmp[nx][ny] = tmp[nx][ny] == '#' ? '.' : '#';
			}
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (tmp[i - 1][j] == '.') {
				list[i][j] = '.';
				continue;
			}

			list[i][j] = '#';
			tmp[i][j] = tmp[i][j] == '#' ? '.' : '#';
			tmp[i][j] = tmp[i][j] == '#' ? '.' : '#';
			for (int d = 0; d < 4; d++) {
				int nx = i + direct[d][0];
				int ny = j + direct[d][1];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				tmp[nx][ny] = tmp[nx][ny] == '#' ? '.' : '#';
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << list[i][j];
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> list[0];
	for (int i = 0; i < N; i++) {
		tmp[0][i] = list[0][i];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = '.';
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