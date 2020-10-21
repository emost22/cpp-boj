#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, int> > > q;
char list[50][50];
int direct[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int N;
bool visit[50][50];

void bfs() {
	q.push({ 0, {0, 0} });
	visit[0][0] = true;
	while (!q.empty()) {
		int x = q.top().second.first;
		int y = q.top().second.second;
		int cnt = -q.top().first;
		q.pop();

		if (x == N - 1 && y == N - 1) {
			cout << cnt << '\n';
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visit[nx][ny]) continue;
			visit[nx][ny] = true;

			if (list[nx][ny] == '0') q.push({ -(cnt + 1), {nx, ny} });
			else q.push({ -cnt, { nx, ny } });
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}