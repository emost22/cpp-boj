#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int list[100][100], N, M;
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
bool visit[100][100];

void bfs() {
	memset(visit, false, sizeof(visit));

	queue<pair<int, int> > q;
	q.push({ 0,0 });
	visit[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visit[nx][ny] || list[nx][ny]) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}
}

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!list[i][j]) continue;

			int cnt = 0;
			for (int x = 0; x < 4; x++) {
				int ni = i + direct[x][0];
				int nj = j + direct[x][1];

				if (visit[ni][nj]) cnt++;
			}

			if (cnt >= 2) list[i][j] = 0;
		}
	}
}

bool chk() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j]) return true;
		}
	}

	return false;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	for (int ans = 1; ; ans++) {
		bfs();
		func();
		if (!chk()) {
			cout << ans << '\n';
			break;
		}
	}

	return 0;
}