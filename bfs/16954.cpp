#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 8
using namespace std;
typedef pair<int, int> pi;

char list[MAX][MAX];
bool visit[MAX][MAX][MAX + 1];
int direct[9][2] = { {0,0},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };

void moveList() {
	for (int j = 0; j < MAX; j++) {
		for (int i = MAX - 1; i > 0; i--) {
			list[i][j] = list[i - 1][j];
		}
	}
}

int bfs() {
	queue<pi> q;
	q.push({ MAX - 1, 0 });
	visit[MAX - 1][0][0] = true;

	for (int t = 0; !q.empty(); t++) {
		if (t == 9) return 1;
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == 0 && y == MAX - 1) {
				return 1;
			}

			if (list[x][y] == '#') continue;

			for (int i = 0; i < 9; i++) {
				int nx = x + direct[i][0];
				int ny = y + direct[i][1];

				if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;
				if (list[nx][ny] == '#' || visit[nx][ny][t + 1]) continue;

				q.push({ nx,ny });
				visit[nx][ny][t + 1] = true;
			}
		}

		moveList();
	}

	return 0;
}

void func() {
	cout << bfs() << '\n';
}

void input() {
	char x;
	for (int i = 0; i < MAX; i++) {
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