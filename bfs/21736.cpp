#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 601
using namespace std;
typedef pair<int, int> pi;

char list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;
int sx, sy;

int bfs() {
	queue<pi> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	int ans = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (list[x][y] == 'P') ans++;

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (list[nx][ny] == 'X' || visit[nx][ny]) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}

	return ans;
}

void func() {
	int ans = bfs();
	if (ans) cout << ans << '\n';
	else cout << "TT\n";
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		for (int j = 0; j < M; j++) {
			if (list[i][j] == 'I') {
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