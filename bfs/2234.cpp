#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

set<int> sideroom[2501];
int N, M, wall[4] = { 4, 8, 1, 2 };
int list[50][50], direct[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int roomnum, maxroomsize, Room[50][50], Roomsize[2501];
bool visit[50][50];

void sidechk(int sx, int sy, int num) {
	queue<pair<int, int> > q;
	q.push({ sx, sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (Room[nx][ny] != num) {
				sideroom[num].insert(Room[nx][ny]);
				continue;
			}
			if (visit[nx][ny]) continue;

			q.push({ nx, ny });
			visit[nx][ny] = true;
		}
	}
}

void bfs(int sx, int sy, int num) {
	queue<pair<int, int> > q;
	q.push({ sx, sy });
	visit[sx][sy] = true;
	for (int t = 1; ; t++) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		Room[x][y] = num;

		for (int i = 0; i < 4; i++) {
			if (wall[i] & list[x][y]) continue;
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (visit[nx][ny]) continue;
			q.push({ nx, ny });
			visit[nx][ny] = true;
		}

		if (q.empty()) {
			Roomsize[num] = t;
			maxroomsize = max(maxroomsize, t);
			break;
		}
	}
}

void solve() {
	int maxroomsum = 0;
	cout << roomnum << '\n' << maxroomsize << '\n';
	for (int i = 1; i <= roomnum; i++) {
		set<int>:: iterator iter;
		for (iter = sideroom[i].begin(); iter != sideroom[i].end(); iter++) {
			int s = *iter;

			maxroomsum = max(maxroomsum, Roomsize[i] + Roomsize[s]);
		}
	}

	cout << maxroomsum << '\n';
}

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j]) continue;
			bfs(i, j, ++roomnum);
		}
	}
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j]) continue;
			sidechk(i, j, Room[i][j]);
		}
	}
}

void input() {
	cin >> M >> N;
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
	func();
	solve();

	return 0;
}