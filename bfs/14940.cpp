#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

int list[MAX][MAX], ans[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, sx, sy;

void bfs() {
	queue<pii> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	for(int t=0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			ans[x][y] = t;
			for (int d = 0; d < 4; d++) {
				int nx = x + direct[d][0];
				int ny = y + direct[d][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visit[nx][ny] || !list[nx][ny]) continue;

				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

void func() {
	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j] && !visit[i][j]) ans[i][j] = -1;
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];

			if (list[i][j] == 2) {
				sx = i;
				sy = j;
			}
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