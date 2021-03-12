#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

queue<pair<int, int> > q;
int direct[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
bool visit[8][8];
int list[8][8];
int N, M, ans;

void bfs() {
	queue<pair<int, int> > nq = q;
	int sum = 0;
	while (!nq.empty()) {
		int x = nq.front().first;
		int y = nq.front().second;
		nq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (list[nx][ny] != 0 || visit[nx][ny]) continue;
			visit[nx][ny] = true;
			nq.push({ nx,ny });
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j] != 0 || visit[i][j]) continue;
			sum++;
		}
	}

	ans = max(ans, sum);
}

void func(int x, int y, int cnt) {
	if (cnt == 3) {
		bfs();
		memset(visit, false, sizeof(visit));
		return;
	}

	int sx = x;
	int sy = y;
	for (int i = sx; i < N; i++) {
		for (int j = sy; j < M; j++) {
			if (list[i][j] != 0) continue;

			list[i][j] = 1;
			if (j == M - 1) func(i + 1, 0, cnt + 1);
			else func(i, j + 1, cnt + 1);
			list[i][j] = 0;
		}
		sy = 0;
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];

			if (list[i][j] == 2) {
				q.push({ i,j });
				visit[i][j] = true;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func(0, 0, 0);
	cout << ans << '\n';

	return 0;
}