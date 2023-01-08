#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;
typedef pair<int, int> pii;

char list[MAX][MAX];
bool visit[MAX][MAX];
int direct[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
int N, M;

bool isNotMove(int x, int y) {
	return list[x][y] == '*' || visit[x][y];
}

void bfs(int sx, int sy) {
	queue<pii> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int d = 0; d < 8; d++) {
			int nx = x + direct[d][0];
			int ny = y + direct[d][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (isNotMove(nx, ny)) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}
}

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (isNotMove(i, j)) continue;
			bfs(i, j);
			ret++;
		}
	}

	cout << ret << '\n';
	memset(visit, false, sizeof(visit));
}

void input() {
	cin >> N >> M;
	if (!N) exit(0);

	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}
}