#include <iostream>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, int> > q;
bool visit[182][182];
char map[182][182];
int sol[182][182];
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 }, N, M;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + x_direct[i];
			int yy = y + y_direct[i];

			if (xx < 0 || yy < 0 || xx >= N || yy >= M) continue;
			if (visit[xx][yy]) continue;

			sol[xx][yy] = cnt + 1;
			q.push(make_pair(make_pair(xx, yy), cnt + 1));
			visit[xx][yy] = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '1') {
				q.push(make_pair(make_pair(i, j), 0));
				visit[i][j] = true;
			}
		}
	}

	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << sol[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}