#include <iostream>
#define MAX 101
using namespace std;

char list[MAX][MAX];
int direct[8][2] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
int N;

void eraseNum(int x, int y) {
	for (int d = 0; d < 8; d++) {
		int nx = x + direct[d][0];
		int ny = y + direct[d][1];
		if (list[nx][ny] == -1 || list[nx][ny] == '#') continue;
		list[nx][ny] -= 1;
	}
}

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (list[i][j] != '#') continue;

			bool flag = true;
			for (int d = 0; d < 8; d++) {
				int nx = i + direct[d][0];
				int ny = j + direct[d][1];

				if (list[nx][ny] == '0') {
					flag = false;
					break;
				}
			}

			if (flag) {
				ret++;
				list[i][j] = -1;
				eraseNum(i, j);
			}
		}
	}
	cout << ret << '\n';
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