#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

char list[MAX][MAX], ans[MAX][MAX];
int direct[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
int N;

void func() {
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (ans[i][j] == '.') continue;
			if (list[i][j] == '*') {
				flag = true;
				continue;
			}

			int cnt = 0;
			for (int d = 0; d < 8; d++) {
				int nx = i + direct[d][0];
				int ny = j + direct[d][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (list[nx][ny] == '.') continue;
				cnt++;
			}

			ans[i][j] = (char)(cnt + '0');
		}
	}

	if (flag) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (list[i][j] == '*') ans[i][j] = '*';
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> ans[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}