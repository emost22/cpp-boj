#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int, int> > virus, op;
int list[50][50], d[50][50], N, M, ans = -1, wall, viruson, zero;
int direct[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
bool visit[50][50], chk[10];

void bfs() {
	memset(d, 0, sizeof(d));
	memset(visit, false, sizeof(visit));
	viruson = 0;

	int virusoff = virus.size() - M;
	queue<pair<pair<int, int>, int> > q;
	for (int i = 0; i < op.size(); i++) {
		q.push({ op[i], 0 });
		visit[op[i].first][op[i].second] = true;
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (list[nx][ny] == 1 || visit[nx][ny]) continue;

			q.push({ {nx,ny},cnt + 1 });
			visit[nx][ny] = true;
			d[nx][ny] = d[x][y] + 1;
			if (list[nx][ny] == 0) viruson++;
		}
	}

	if (zero == viruson) {
		int movetime = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (list[i][j]) continue;

				movetime = max(movetime, d[i][j]);
			}
		}

		if (ans == -1) ans = movetime;
		else ans = min(ans, movetime);
	}
}

void func(int idx, int cnt) {
	if (cnt == M) {
		bfs();		
		return;
	}

	for (int i = idx; i < virus.size(); i++){
		if (chk[i]) continue;

		op.push_back(virus[i]);
		chk[i] = true;
		func(i + 1, cnt + 1);
		chk[i] = false;
		op.pop_back();
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
			if (list[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else if (list[i][j]) {
				wall++;
			}
			else zero++;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	if (wall + virus.size() == N*N) ans = 0;
	else func(0, 0);
	cout << ans << '\n';

	return 0;
}