#include <iostream>
#include <queue>
#define MAX 31
using namespace std;
typedef pair<int, int> pi;

int list[MAX][MAX], afterList[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;

void bfs(int sx, int sy, int k) {
	queue<pi> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;

	int tmp = list[sx][sy];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		list[x][y] = k;
		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visit[nx][ny] || list[nx][ny] != tmp) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}
}

void func() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j] == afterList[i][j]) continue;

			cnt++;
			bfs(i, j, afterList[i][j]);
		}
	}

	if (cnt <= 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (list[i][j] != afterList[i][j]) {
					cout << "NO\n";
					return;
				}
			}
		}
		cout << "YES\n";
	}
	else cout << "NO\n";
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> afterList[i][j];
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