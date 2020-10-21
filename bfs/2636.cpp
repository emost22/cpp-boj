#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int list[100][100], N, M, pre, ans;
int direct[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
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
			if (list[nx][ny] || visit[nx][ny]) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}
}

void func() {
	ans = pre;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (!list[i][j]) continue;

			for (int k = 0; k < 4; k++) {
				int nx = i + direct[k][0];
				int ny = j + direct[k][1];

				if (visit[nx][ny]) {
					list[i][j] = 0;
					ans--;
					break;
				}
			}
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
			if (list[i][j]) pre++;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	if (!pre) cout << "0\n0\n";
	for (int T = 1; pre ; T++) {
		bfs();
		func();
		if (!ans) {
			cout << T << '\n' << pre << '\n';
			break;
		}

		pre = ans;
	}

	return 0;
}