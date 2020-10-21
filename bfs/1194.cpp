#include <iostream>
#include <queue>
using namespace std;

typedef struct st {
	int x;
	int y;
	int k;
	int cnt;
}st;

char list[50][50];
bool visit[50][50][64], escape[50][50];
int direct[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int N, M, sx, sy;

void bfs() {
	queue<st> q;
	q.push({ sx,sy,0,0 });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int key = q.front().k;
		int cnt = q.front().cnt;
		q.pop();

		if (escape[x][y]) {
			cout << cnt << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (list[nx][ny] == '#' || visit[nx][ny][key]) continue;
			if ('A' <= list[nx][ny] && list[nx][ny] <= 'F') {
				int n = list[nx][ny] - 'A';
				if (!((1 << n) & key)) continue;
			}

			visit[nx][ny][key] = true;
			if ('a' <= list[nx][ny] && list[nx][ny] <= 'f') {
				int n = list[nx][ny] - 'a';
				q.push({ nx,ny,key | (1 << n),cnt + 1 });
			}
			else q.push({ nx,ny,key,cnt + 1 });
		}
	}

	cout << "-1\n";
	return;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
			if (list[i][j] == '0') {
				sx = i;
				sy = j;
			}
			else if (list[i][j] == '1') {
				escape[i][j] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}