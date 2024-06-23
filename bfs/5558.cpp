#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

char list[MAX][MAX];
bool visit[MAX][MAX][11];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, K;
int sx, sy;

int bfs(int sx, int sy) {
	queue<pair<int, pii> > q;
	q.push({ 1, { sx,sy } });
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().second.first;
			int y = q.front().second.second;
			int p = q.front().first;
			q.pop();

			if (p == K + 1) return t;

			for (int d = 0; d < 4; d++) {
				int nx = x + direct[d][0];
				int ny = y + direct[d][1];
				int np = p;

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (list[nx][ny] == 'X') continue;
				if ('1' <= list[nx][ny] && list[nx][ny] <= '9') {
					if (list[nx][ny] - '0' == p) {
						np++;
					}
				}
				if (visit[nx][ny][np]) continue;

				q.push({ np, {nx,ny} });
				visit[nx][ny][np] = true;
			}
		}
	}

	return -1;
}

void func() {
	cout << bfs(sx, sy) << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		for (int j = 0; j < M; j++) {
			if (list[i][j] == 'S') {
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