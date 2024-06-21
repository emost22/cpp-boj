#include <iostream>
#include <queue>
#define MAX 310
using namespace std;
typedef pair<int, int> pii;

char list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { { 0,1 }, { 1,0 }, { 0,-1 }, { -1,0 } };
int N, M;
int sx, sy, ex, ey;

int bfs() {
	queue<pii> q;
	q.push({sx,sy});
	visit[0][0] = true;
	for (int t = 0; !q.empty(); t++) {
		queue<pii> next;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == ex && y == ey) return t;

			for (int d = 0; d < 4; d++) {
				int nx = x + direct[d][0];
				int ny = y + direct[d][1];

				if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
				if (visit[nx][ny]) continue;

				visit[nx][ny] = true;
				if (list[nx][ny] == '0') {
					q.push({ nx,ny });
				}
				if (list[nx][ny] == '1' || list[nx][ny] == '#') {
					list[nx][ny] = '0';
					next.push({ nx,ny });
				}
			}
		}

		while (!next.empty()) {
			q.push(next.front());
			next.pop();
		}
	}

	return -1;
}

void func() {
	cout << bfs() << '\n';
}

void input() {
	cin >> N >> M >> sx >> sy >> ex >> ey;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
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